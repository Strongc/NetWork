#include "stdafx.h"
#include "bolgsdownload.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication::addLibraryPath("./plugins");
	QApplication a(argc, argv);
	QTranslator qtTranslator;
	qtTranslator.load("bolgsdownload_zh.qm");
	a.installTranslator(&qtTranslator);

	BolgsDownload w;
	
	w.show();
	return a.exec();
}
