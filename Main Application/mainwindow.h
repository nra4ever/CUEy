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
#include <QPalette>

namespace Ui {
class Dialog;
class MainWindow;
class Metadata;
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
    QPalette MainWindow::proPal;
    QStringList MainWindow::cmds, MainWindow::errs;
    QVector<QMap<QString,QString>> MainWindow::Files, MainWindow::Tracks;
    explicit MainWindow(QWidget *parent = 0);
    int MainWindow::dual, MainWindow::count;
    ~MainWindow();

protected:
    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);

private:
    Ui::MainWindow *ui;

private slots:
    void ex();
    void batch();
    void fImport();
    void rA(int);
    void split();
    void iBut();
    void cBut();
    QString validateNamestr(QString);
    void doTrack(int);
    void dtTrigger(int , QProcess::ExitStatus);
    void opu();
};

#endif // MAINWINDOW_H
