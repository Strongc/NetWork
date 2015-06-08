#include "stdafx.h"
#include "bolgsdownload.h"

BolgsDownload::BolgsDownload(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);

	ui.label_4->setPixmap(QPixmap(":/BolgsDownload/touxiang"));
}

BolgsDownload::~BolgsDownload()
{

}
