#ifndef WEBSERVERQT_H
#define WEBSERVERQT_H

#include <QtGui/QMainWindow>

class WebServerThread;
class WebServerQt : public QWidget
{
	Q_OBJECT

public:
	WebServerQt(QWidget *parent = 0, Qt::WFlags flags = 0);
	~WebServerQt();
private:
	void setpui();
public slots:
	void slot_closetUI();
	void slot_startWebServer();
	void slot_colseWebServer();
	void slot_threadReturnMessage(QString);
	void slot_packmenuAcquire();
protected:
	void paintEvent(QPaintEvent*);
	void mouseMoveEvent(QMouseEvent*);

private:
	QWidget *mMainWidget;
	QPushButton *mColosePushButton;
	QPushButton *mStartServerPushButton;
	QPushButton *mColoseServerPushButton;

	QPushButton *mSettingPushButton;
	QPushButton *mAboutPushButton;

	QPushButton *mPacketAnalysisPushButton;
	QPushButton *mOperationPushButton;

	QPushButton *mLogPushButton;

	QMenu *mPacketMenu;
	QAction *mPackAcquireAction;

	QMenu *mOperationMenu;
	QAction *mOperationDBAction;

	QLabel *mDisplayLabel;
	QLabel *mStartMessageLabel;

	QGridLayout *mGridLayout;
	QHBoxLayout *mDisplayLayout;
	QVBoxLayout *mMainLayou;

	WebServerThread *mWebServer;
};

#endif // WEBSERVERQT_H
