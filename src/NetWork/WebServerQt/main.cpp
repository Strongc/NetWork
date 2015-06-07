#include "stdafx.h"
#include "webserverqt.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication::addLibraryPath("./plugins");
	QApplication a(argc, argv);
	QTranslator qtTranslator;
	qtTranslator.load("webserverqt_zh.qm");
	a.installTranslator(&qtTranslator);
	WebServerQt w;
	w.show();
	return a.exec();
}
