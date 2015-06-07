#include "StdAfx.h"
#include "webserverthread.h"
#include "HttpSocket.h"


WebServerThread::WebServerThread(QObject *parent,int port /*= 8080*/,int threadd /*= 10*/,int queue_q /*= 10*/)
	: QThread(parent)
	,mPort(port)
	,mThread(threadd)
	,mQueue(queue_q)
	,mThradFalgs(true)
{

}

WebServerThread::~WebServerThread()
{
	
}

void WebServerThread::run()
{
	mThradFalgs = true;
	SocketHandlerEp h;
	ListenSocket<HttpSocket> l(h);
	h.SetNumberOfThreads(mThread);
	if (l.Bind(mPort, mQueue))
	{
		emit sig_returnMessagae(tr("Bind to port %1 failed").arg(QString::number(mPort)));
		return;
	}
	h.Add(&l);
	emit sig_returnMessagae(tr("Listening on port %1").arg(QString::number(mPort)));
	while (mThradFalgs)
	{
		h.Select(1, 0);
	}
	emit sig_returnMessagae(tr("Exiting..."));
}

void WebServerThread::setDate(int port,int threadd,int _queue)
{
	mPort = port;
	mThread = threadd;
	mQueue = _queue;
}

void WebServerThread::setFlags(bool f)
{

}

void WebServerThread::finishThread()
{
	mThradFalgs = false;
}
