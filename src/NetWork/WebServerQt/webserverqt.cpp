#include "stdafx.h"
#include "webserverqt.h"
#include "webserverthread.h"

WebServerQt::WebServerQt(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏 
	setpui();
	setGeometry(QRect(90, 55, 350, 150));//可设置窗口显示的方位与大小 
	mWebServer = new WebServerThread(this);
	mWebServer->setDate(8080,20,20);
	connect(mWebServer,SIGNAL(sig_returnMessagae(QString)),this,SLOT(slot_threadReturnMessage(QString)));
}

WebServerQt::~WebServerQt()
{
	if(mWebServer->isRunning())
		mWebServer->terminate();
}

void WebServerQt::paintEvent(QPaintEvent*)
{
	QBitmap bmp(this->size());  
	bmp.fill();  
	QPainter p(&bmp);  
	p.setPen(Qt::NoPen);  
	p.setBrush(Qt::black);  
	p.setRenderHint(QPainter::Antialiasing);  
	p.drawRoundedRect(bmp.rect(), 20, 20); //四个角都是圆弧   
	setMask(bmp);  
}
void WebServerQt::mouseMoveEvent(QMouseEvent*e)
{
	int x =e->globalX();
	int y = e->globalY();
	setGeometry(QRect(x, y, 350, 150));
}

void WebServerQt::slot_closetUI()
{
	this->close();
}

void WebServerQt::setpui()
{	
	//mMainWidget = new QWidget(this);
	mMainLayou = new QVBoxLayout(this);
	mDisplayLayout = new QHBoxLayout(this);
	mGridLayout = new QGridLayout(this);
	
	

	mDisplayLabel = new QLabel(tr("Start:"),this);
	mStartMessageLabel = new QLabel(tr(""),this);

	mDisplayLayout->addWidget(mDisplayLabel);
	mDisplayLayout->addWidget(mStartMessageLabel);

	mColosePushButton = new QPushButton(this);
	mColosePushButton->setText(tr("Close"));

	mStartServerPushButton = new QPushButton(this);
	mStartServerPushButton->setText(tr("Start Server"));

	mColoseServerPushButton = new QPushButton(this);
	mColoseServerPushButton->setText(tr("Close Server"));

	mSettingPushButton = new QPushButton(tr("Setting"),this);
	mAboutPushButton = new QPushButton(tr("About"),this);

	mLogPushButton = new QPushButton(tr("LOG"),this);

	mPacketAnalysisPushButton = new QPushButton(tr("PacketAnaly"),this);
	mPacketMenu = new QMenu(this);
	mPackAcquireAction = new QAction(mPacketMenu);
	mPackAcquireAction->setText(tr("Acquire"));
	mPacketMenu->addAction(mPackAcquireAction);
	mPacketAnalysisPushButton->setMenu(mPacketMenu);

	mOperationPushButton = new QPushButton(tr("Operation"),this);
	mOperationMenu = new QMenu(this);
	mOperationDBAction=new QAction(mOperationMenu);
	mOperationDBAction->setText(tr("DataBase"));
	mOperationMenu->addAction(mOperationDBAction);
	mOperationPushButton->setMenu(mOperationMenu);



	mGridLayout->addWidget(mColosePushButton,0,0,1,2);
	mGridLayout->addWidget(mStartServerPushButton,1,0,1,1);
	mGridLayout->addWidget(mColoseServerPushButton,1,1,1,1);
	mGridLayout->addWidget(mPacketAnalysisPushButton,2,0,1,1);
	mGridLayout->addWidget(mOperationPushButton,2,1,1,1);
	mGridLayout->addWidget(mSettingPushButton,3,0,1,1);
	mGridLayout->addWidget(mAboutPushButton,3,1,1,1);
	mGridLayout->addWidget(mLogPushButton,4,0,1,2);

	mMainLayou->addSpacing(20);
	mMainLayou->addLayout(mGridLayout);	
	mMainLayou->addLayout(mDisplayLayout);
	mMainLayou->addSpacing(20);
	this->setLayout(mMainLayou);
	 
	connect(mColosePushButton,SIGNAL(clicked()),this,SLOT(slot_closetUI()));
	connect(mStartServerPushButton,SIGNAL(clicked()),this,SLOT(slot_startWebServer()));
	connect(mColoseServerPushButton,SIGNAL(clicked()),this,SLOT(slot_colseWebServer()));
	connect(mPackAcquireAction,SIGNAL(triggered()),this,SLOT(slot_packmenuAcquire()));
	
}

void WebServerQt::slot_startWebServer()
{
	if(!mWebServer->isRunning())
		mWebServer->start();
}

void WebServerQt::slot_colseWebServer()
{
	mWebServer->finishThread();
}

void WebServerQt::slot_threadReturnMessage(QString a)
{
	mStartMessageLabel->setText(a);
}

void WebServerQt::slot_packmenuAcquire()
{

}


