#include "stdafx.h"
#include "bolgsdownload.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	BolgsDownload w;
	w.show();
	return a.exec();
}
