#ifndef BLOGSDOWNLOADENGINE_H
#define BLOGSDOWNLOADENGINE_H

#include <QObject>

class BlogsDownloadEngine : public QObject
{
	Q_OBJECT

public:
	BlogsDownloadEngine(QObject *parent);
	~BlogsDownloadEngine();

private:
	
};

#endif // BLOGSDOWNLOADENGINE_H
