#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFileInfo>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QProcess>
#include <QTextStream>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QDialog>

namespace Ui {
	class Dialog;
	class Abort;
	class MainWindow;
	class Metadata;
}

class Abort : public QDialog
{
	Q_OBJECT
public:
	explicit Abort(QWidget *parent = 0);
	~Abort();
private:
	Ui::Abort *ui;
};

class Dialog : public QDialog
{
	Q_OBJECT
public:
	explicit Dialog(QWidget *parent = 0);
	~Dialog();
private:
	Ui::Dialog *ui;
	public slots:
	void setTxt(QString);
};

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
    QString cue, pa, tra, genre, year, tc, al, bDir;
    QStandardItemModel *model;
    QStandardItemModel *model2;
    QProcess *process;
    bool stop;
    QStringList cmds, errs;
    QVector<QMap<QString, QString>> Files, Tracks;
	explicit MainWindow(QWidget *parent = 0);
    int dual, count;
	~MainWindow();

protected:
	void dragEnterEvent(QDragEnterEvent *e);
	void dropEvent(QDropEvent *e);

private:
	Ui::MainWindow *ui;

	private slots:
	void halt();
	void ex();
	void batch();
	void fImport();
	void rA(int);
	void split();
	void iBut();
	void cBut();
	QString validateNamestr(QString);
	void doTrack(int);
	void dtTrigger(int, QProcess::ExitStatus);
	void opu();
};

#endif // MAINWINDOW_H
