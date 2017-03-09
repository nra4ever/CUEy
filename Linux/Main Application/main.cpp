#include "mainwindow.h"
#include <QApplication>
#include <QDialog>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    a.setWindowIcon(QIcon("/opt/CUEy/icon.ico"));
	MainWindow w;
	w.show();
	return a.exec();
}
