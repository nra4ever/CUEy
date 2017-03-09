#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFileInfo>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QProcess>
#include <QTextStream>
#include <QDirIterator>

namespace Ui {
class MainWindow;
class Abort;
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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString cue, pa, tra, genre, year, tc, al, bDir;
    QStandardItemModel *model;
    QStandardItemModel *model2;
    QProcess *process;
    QStringList cmds, errs, errList, jobs;
    QVector<QMap<QString,QString>> Files, Tracks;
    int dual, count, jSize, bCount;
    bool stop;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void processCUE();
    void rA(int);
    QString validateNamestr(QString);
    void doTrack(int);
    void dtTrigger(int , QProcess::ExitStatus);
    void opu();
    void batchInit();
    void batchDo();
    void bTrigger();
	void halt();
};

#endif // MAINWINDOW_H
