#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFileInfo>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QProcess>
#include <QTextStream>
#include <QDialog>
#include <QDirIterator>

namespace Ui {
class Dialog;
class MainWindow;
}

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
    QString MainWindow::cue, MainWindow::pa, MainWindow::tra, MainWindow::genre, MainWindow::year, MainWindow::tc, MainWindow::al, MainWindow::bDir;
    QStandardItemModel *MainWindow::model;
    QStandardItemModel *MainWindow::model2;
    QProcess *MainWindow::process;
    QStringList MainWindow::cmds, MainWindow::errs, MainWindow::errList, MainWindow::jobs;
    QVector<QMap<QString,QString>> MainWindow::Files, MainWindow::Tracks;
    int MainWindow::dual, MainWindow::count, MainWindow::jSize, MainWindow::bCount;
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
};

#endif // MAINWINDOW_H
