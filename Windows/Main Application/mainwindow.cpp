#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_dialog.h"
#include "ui_abort.h"

Abort::Abort(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Abort)
{
	ui->setupUi(this);
}


Dialog::Dialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog)
{
	ui->setupUi(this);
}

void Dialog::setTxt(QString txt) {
	ui->errtxt->setText(txt);
}

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	MainWindow::dual, MainWindow::count = 0;
	connect(ui->impBu, SIGNAL(released()), this, SLOT(iBut()));
	connect(ui->clearBu, SIGNAL(released()), this, SLOT(cBut()));
	connect(ui->goBu, SIGNAL(released()), this, SLOT(split()));
	connect(ui->abBu, SIGNAL(released()), this, SLOT(halt()));
	ui->abBu->setDisabled(true);
	ui->clearBu->setDisabled(true);
	ui->goBu->setDisabled(true);
	connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(ex()));
	connect(ui->actionBatch, SIGNAL(triggered()), this, SLOT(batch()));
	connect(ui->actionImport, SIGNAL(triggered()), this, SLOT(iBut()));
	MainWindow::stop = false;
	model = new QStandardItemModel;
	ui->inView->setModel(model);
	model2 = new QStandardItemModel;
	proPal = ui->progressBar->palette();
	process = new QProcess(this);
	process->setProcessChannelMode(QProcess::MergedChannels);
	ui->outView->setModel(model2);
	ui->statusbar->showMessage("Ready.");
	setAcceptDrops(true);
	connect(process, SIGNAL(readyReadStandardOutput()), this, SLOT(opu()));
	connect(process, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(dtTrigger(int, QProcess::ExitStatus)));
	if (QApplication::arguments().size() > 1) {
		MainWindow::cue = QApplication::arguments().at(1);
		fImport();
	}
}

void MainWindow::halt() {
	Abort abt;
	if (abt.exec()) {
		MainWindow::stop = true;
		process->kill();
		abt.deleteLater();
	}
	else {
		abt.deleteLater();
	}
}

void MainWindow::batch() {
	QProcess::startDetached("CUEy-Batch.exe");
	QApplication::quit();
}

void MainWindow::ex() {
	QApplication::quit();
}

void MainWindow::dtTrigger(int d, QProcess::ExitStatus) {
	doTrack(d);
}

void MainWindow::dragEnterEvent(QDragEnterEvent *e)
{
	const QMimeData* mimeData = e->mimeData();
	if (mimeData->hasUrls()) {
		e->acceptProposedAction();
	}
	else {
		e->ignore();
	}
}

void MainWindow::dropEvent(QDropEvent *e)
{
	const QMimeData* mimeData = e->mimeData();
	if (mimeData->hasUrls()) {
		QString ifile;
		QList<QUrl> urlList = mimeData->urls();
		if (urlList.size() == 1) {
			rA(0);
			ifile = urlList.at(0).toLocalFile();
			MainWindow::cue = ifile;
			MainWindow::fImport();
		}
		else {
			ui->statusbar->showMessage("ERROR: Can only import 1 File.");
			e->ignore();
		}
	}
}
void MainWindow::iBut() {
	QString filter = "CUE Files (*.cue)";
	MainWindow::cue = QFileDialog::getOpenFileName(this, "Select a file...", QDir::homePath(), filter);
	if (MainWindow::cue.isEmpty()) {
		ui->statusbar->showMessage("ERROR: No File Specified.");
		return;
	}
	MainWindow::fImport();
}

void MainWindow::cBut() {
	rA(0);
}


void MainWindow::fImport() {
	bool first = true;
	int trackCount = 0;
	int linecount = 0;
	QStringList lines;
	QFile file(MainWindow::cue);
	file.open(QIODevice::ReadOnly);
	QTextStream in(&file);
	QString line;
	do {
		line = in.readLine();
		lines.append(line);
	} while (!line.isNull());
	foreach(const QString &str, lines)
	{
		QMap<QString, QString> tmap;
		linecount++;
		QString sr = str.simplified();
		if (sr.contains("PERFORMER", Qt::CaseSensitive)) {
			MainWindow::pa = sr.mid(11);
			MainWindow::pa.chop(1);
		}
		else if (sr.contains("REM DATE", Qt::CaseSensitive)) {
			MainWindow::year = sr.right(4);
		}
		else if (sr.contains("REM GENRE", Qt::CaseSensitive)) {
			MainWindow::genre = sr.mid(10);
			MainWindow::genre.remove("\"");
		}
		else if (sr.contains("FILE", Qt::CaseSensitive)) {
			QString fs = str.mid(6);
			fs.chop(6);
			QVariant lcf(linecount);
			QString flc = lcf.toString();
			QMap<QString, QString> fmap;
			fmap["file"] = fs;
			fmap["lind"] = flc;
			fmap["aArt"] = MainWindow::pa;
			MainWindow::Files.append(fmap);
		}
		else if (sr.contains("TITLE", Qt::CaseSensitive)) {
			MainWindow::tra = sr.mid(7);
			MainWindow::tra.chop(1);
			if (first == true) {
				first = false;
			}
			else {
				trackCount++;
			}QVariant tcs(trackCount);
			MainWindow::tc = tcs.toString();
		}
		else if (sr.contains("TRACK 01", Qt::CaseSensitive)) {
			MainWindow::al = MainWindow::tra;
		}
		else if (sr.contains("INDEX 01", Qt::CaseSensitive)) {
			QString tind = sr.right(8);
			QVariant lcs(linecount);
			QString lc = lcs.toString();
			tmap["num"] = MainWindow::tc;
			tmap["tind"] = tind;
			tmap["lind"] = lc;
			tmap["title"] = MainWindow::tra;
			if (!pa.isEmpty()) {
				tmap["artist"] = MainWindow::pa;
			}
			if (!year.isEmpty()) {
				tmap["year"] = MainWindow::year;
			}if (!genre.isEmpty()) {
				tmap["genre"] = MainWindow::genre;
			}MainWindow::Tracks.append(tmap);
		}
	}
	first = true;
	QVectorIterator<QMap<QString, QString>> fIt(MainWindow::Files);
	while (fIt.hasNext()) {
		if (fIt.peekNext().value("file").contains(".flac")) {
			QFileInfo fld(MainWindow::cue);
			QString dir = fld.absolutePath();
			QString file = dir + "/" + fIt.peekNext().value("file");
			if (!QFileInfo(file).exists()) {
				ui->statusbar->showMessage("ERROR: Input file(s) does not exist.");
				rA(1);
				return;
			}
			else {
				QStandardItem *q = new QStandardItem(fIt.next().value("file"));
				MainWindow::model->appendRow(q);
			}
		}
		else {
			ui->statusbar->showMessage("ERROR: Input file(s) not in FLAC format.");
			rA(1);
			return;
		}
	}
	QVectorIterator<QMap<QString, QString>> tIt(MainWindow::Tracks);
	while (tIt.hasNext()) {
		QStandardItem *q = new QStandardItem("Track " + tIt.peekNext().value("num") + " - " + tIt.peekNext().value("title"));
		tIt.next();
		MainWindow::model2->appendRow(q);
	}
	ui->cueLab->setText("Current CUE File: " + MainWindow::cue);
	QVariant fc(MainWindow::Files.size());
	QString fcs = fc.toString();
	ui->statusbar->showMessage("Successfully Imported CUE File (" + tIt.peekPrevious().value("num") + " Tracks Across " + fcs + " Files).");
	ui->goBu->setDisabled(false);
	ui->clearBu->setDisabled(false);
}

void MainWindow::rA(int e) {
	ui->progressBar->setValue(0);
	MainWindow::model->clear();
	MainWindow::model2->clear();
	MainWindow::Files.clear();
	MainWindow::Tracks.clear();
	MainWindow::cmds.clear();
	MainWindow::count = 0;
	MainWindow::cue.clear();
	MainWindow::errs.clear();
	ui->goBu->setDisabled(true);
	if (e != 1) {
		ui->cmdout->clear();
		ui->statusbar->showMessage("Ready.");
	}ui->cueLab->setText("Current CUE File: None.");
}

void MainWindow::split() {
	ui->clearBu->setDisabled(true);
	ui->goBu->setDisabled(true);
	ui->abBu->setDisabled(false);
	ui->impBu->setDisabled(true);
	if (MainWindow::Files.size() == 1) {
		MainWindow::dual = 1;
	}
	else {
		MainWindow::dual = 2;
	}
	if (MainWindow::cue.isEmpty() || MainWindow::Tracks.isEmpty() || MainWindow::Files.isEmpty()) {
		ui->statusbar->showMessage("ERROR: Nothing to split.");
		return;
	}
	if (MainWindow::dual == 0) {
		ui->statusbar->showMessage("ERROR: Invalid Format.");
		return;
	}bool first = true;
	bool last = false;
	int bcount = 0;
	QFileInfo fld(MainWindow::cue);
	QString wdir = fld.absolutePath();
	QVectorIterator<QMap<QString, QString>> tIt(MainWindow::Tracks);
	tIt.next();
	while (tIt.hasNext()) {
		QStringList start, end;
		QString tn, namestr, amestr, side, ifile, cmd;
		QMap<QString, QString> it;
		ifile = MainWindow::Files[0].value("file");
		if (last == true) {
			it = tIt.peekNext();
		}
		else {
			it = tIt.peekPrevious();
		}if (MainWindow::dual == 2) {
			if (MainWindow::Files.size() == 2) {
				if (last == true) {
					side = "B";
				}
				else {
					tn = tIt.peekPrevious().value("num");
				}if (tIt.peekPrevious().value("lind").toInt() < MainWindow::Files[1].value("lind").toInt()) {
					side = "A";
				}
				else {
					side = "B";
				}if (side.contains("B")) {
					ifile = MainWindow::Files[1].value("file");
					bcount++;
					QVariant bc(bcount);
					QString bcs = bc.toString();
					tn = bcs;
				}
			}
			else {
				ui->statusbar->showMessage("ERROR: CUEs with over 2 input files not currently supported.");
				return;
			}if (first) {
				end = tIt.peekNext().value("tind").split(":");
			}
			else if (last == true) {
				start = tIt.peekNext().value("tind").split(":");
			}
			else {
				if (tIt.peekNext().value("tind").contains("00:00:00")) {
					start = tIt.peekPrevious().value("tind").split(":");
				}
				else if (tIt.peekPrevious().value("tind").contains("00:00:00")) {
					end = tIt.peekNext().value("tind").split(":");
				}
				else {
					start = tIt.peekPrevious().value("tind").split(":");
					end = tIt.peekNext().value("tind").split(":");
				}
			}amestr = side + tn + " - " + it.value("title") + ".flac";

		}
		else {
			if (first) {
				end = tIt.peekNext().value("tind").split(":");
			}
			else if (last == true) {
				start = tIt.peekNext().value("tind").split(":");
			}
			else {
				start = tIt.peekPrevious().value("tind").split(":");
				end = tIt.peekNext().value("tind").split(":");
			}if (it.value("num").length() == 1) {
				tn = "0" + it.value("num");
			}
			else {
				tn = it.value("num");
			}amestr = tn + " - " + it.value("title") + ".flac";
		}namestr = validateNamestr(amestr);
		QString c = "flac.exe --best ";
		if (it.contains("artist")) {
			c = c + "-T \"ARTIST= " + it.value("artist") + "\" ";
		}if (it.contains("year")) {
			c = c + "-T \"DATE= " + it.value("year") + "\" ";
		}if (it.contains("genre")) {
			c = c + "-T \"GENRE= " + it.value("genre") + "\" ";
		}if (start.isEmpty()) {
			cmd = c + "-T \"TRACKNUMBER=" + tIt.peekPrevious().value("num") + "\" -T \"ALBUM=" + MainWindow::al + "\" " + "-T \"TITLE=" + tIt.peekPrevious().value("title") + "\" " + "--until=" + end[0] + ":" + end[1] + "." + end[2] + " \"" + wdir + "/" + ifile + "\" -o \"" + wdir + "/" + namestr + "\"";
		}
		else if (end.isEmpty()) {
			cmd = c + "-T \"TRACKNUMBER=" + it.value("num") + "\" -T \"ALBUM=" + MainWindow::al + "\" " + "-T \"TITLE=" + it.value("title") + "\" " + "--skip=" + start[0] + ":" + start[1] + "." + start[2] + " \"" + wdir + "/" + ifile + "\" -o \"" + wdir + "/" + namestr + "\"";
		}
		else {
			cmd = c + "-T \"TRACKNUMBER=" + tIt.peekPrevious().value("num") + "\" -T \"ALBUM=" + MainWindow::al + "\" " + "-T \"TITLE=" + tIt.peekPrevious().value("title") + "\" " + "--skip=" + start[0] + ":" + start[1] + "." + start[2] + " --until=" + end[0] + ":" + end[1] + "." + end[2] + " \"" + wdir + "/" + ifile + "\" -o \"" + wdir + "/" + namestr + "\"";
		}MainWindow::cmds.append(cmd);
		first = false;
		tIt.next();
		if (!tIt.hasNext()) {
			if (last) {
				QVariant fas(MainWindow::Tracks.size());
				QString fass = fas.toString();
				ui->statusbar->showMessage("Encoding file 1 of " + fass + ".");
				break;
			}
			else {
				tIt.previous();
				last = true;
			}
		}
	}doTrack(0);
}

QString MainWindow::validateNamestr(QString str) {
	QString illChars = "\\ | / : ? ! \" < >";
	QStringList illCharArr = illChars.split(" ", QString::SkipEmptyParts);
	QList<QString>::iterator ici;
	for (ici = illCharArr.begin(); ici != illCharArr.end(); ++ici) {
		str.remove(*ici);
	}return str;
}

void MainWindow::doTrack(int ex) {
	if (MainWindow::stop) {
		QVariant c(MainWindow::count - 1);
		ui->statusbar->showMessage("Job aborted after " + c.toString() + " tracks.");
		MainWindow::stop = false;
		ui->abBu->setDisabled(true);
		ui->clearBu->setDisabled(false);
		ui->impBu->setDisabled(false);
		rA(1);
		return;
	}if (MainWindow::cmds.size() != MainWindow::Tracks.size()) {
		if (MainWindow::count != 0) {
			if (ex == 1) {
				QVariant c(MainWindow::count);
				QString cs = c.toString();
				MainWindow::errs.append(cs);
			}
		}
	}if (MainWindow::cmds.size() == 0) {
		if (!MainWindow::errs.isEmpty()) {
			QString err = MainWindow::errs.join(", ");
			Dialog dia;
			ui->statusbar->showMessage("Encode completed with errors.");
			ui->progressBar->setValue(100);
			dia.setTxt("The following tracks failed to encode: " + err + ".");
			dia.exec();
		}
		else {
			ui->statusbar->showMessage("Encode completed, ready.");
			ui->progressBar->setValue(100);
		}ui->abBu->setDisabled(true);
		ui->clearBu->setDisabled(false);
		ui->impBu->setDisabled(false);
	}
	else {
		QVariant c(MainWindow::count + 1);
		QString cs = c.toString();
		QVariant ts(MainWindow::Tracks.size());
		QString tss = ts.toString();
		ui->statusbar->showMessage("Encoding file " + cs + " of " + tss + ".");
		process->start(MainWindow::cmds[0]);
		MainWindow::cmds.removeFirst();
		int cc = MainWindow::Tracks.size() - 1;
		int progress = 100 / cc;
		int cpro = progress * MainWindow::count;
		ui->progressBar->setValue(cpro);
		MainWindow::count++;
	}
}

void MainWindow::opu() {
	QString otpt(process->readAllStandardOutput());
	if (otpt.contains(", ratio=")) {
		QTextCursor storeCursorPos = ui->cmdout->textCursor();
		ui->cmdout->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
		ui->cmdout->moveCursor(QTextCursor::StartOfLine, QTextCursor::MoveAnchor);
		ui->cmdout->moveCursor(QTextCursor::End, QTextCursor::KeepAnchor);
		ui->cmdout->textCursor().removeSelectedText();
		ui->cmdout->textCursor().deletePreviousChar();
		ui->cmdout->setTextCursor(storeCursorPos);
	}
	ui->cmdout->append(otpt);
}

Dialog::~Dialog()
{
	delete ui;
}

Abort::~Abort()
{
	delete ui;
}

MainWindow::~MainWindow()
{
	delete ui;
}
