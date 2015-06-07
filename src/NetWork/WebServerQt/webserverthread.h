#ifndef WEBSERVERTHREAD_H
#define WEBSERVERTHREAD_H

#include <QThread>

class WebServerThread : public QThread
{
	Q_OBJECT

public:
	WebServerThread(QObject *parent,int port = 8080,int thread = 10,int queue_q = 10);
	~WebServerThread();
	void setDate(int port,int thread,int _queue);
	void setFlags(bool f);
	void finishThread();
signals:
	void sig_returnMessagae(QString);
protected:
	void run();

private:
	int mPort;
	int mThread;
	int mQueue;
	bool mThradFalgs;
};

#endif // WEBSERVERTHREAD_H
