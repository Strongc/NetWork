#ifndef BOLGSDOWNLOAD_H
#define BOLGSDOWNLOAD_H

#include <QtGui/QWidget>
#include "ui_bolgsdownload.h"

class BolgsDownload : public QWidget
{
	Q_OBJECT

public:
	BolgsDownload(QWidget *parent = 0, Qt::WFlags flags = 0);
	~BolgsDownload();

private:
	Ui::BolgsDownloadClass ui;
};

#endif // BOLGSDOWNLOAD_H
