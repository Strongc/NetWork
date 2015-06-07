// TestSocketWebServer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

extern "C"
{
#include <openssl/applink.c>
}

#ifdef _WIN32
#pragma warning(disable:4786)
#endif
#include <Sockets/HttpBaseSocket.h>
#include <Sockets/StdoutLog.h>
#include <Sockets/ListenSocket.h>
#include <Sockets/SocketHandlerEp.h>
#include <Sockets/TcpSocket.h>
#include <Sockets/HttpDebugSocket.h>
#include <Sockets/Json.h>


class MySocket : public HttpBaseSocket
{
public:
	MySocket(ISocketHandler& h)
		:HttpBaseSocket(h)
	{

	}
	~MySocket()
	{
		
	}
	void IHttpServer_OnExec(const HttpRequest& req)
	{
		mreq = req;
		mres.SetHttpStatusCode(200);
		mres.SetHttpStatusMsg("OK");
		mres.SetFile("e:\\201501230819_1.mp4");
		mres.SetContentType("video/mpeg4");
		mres.SetHeader("Server","DayBreakZhang Server");

		IHttpServer_Respond(mres);

	}
	void IHttpServer_Respond(const HttpResponse& res)
	{
		m_res = res;

		SetHttpVersion( m_res.HttpVersion() );
		SetStatus( Utility::l2string(m_res.HttpStatusCode()) );
		SetStatusText( m_res.HttpStatusMsg() );

		if (!ResponseHeaderIsSet("content-length"))
		{
			AddResponseHeader( "content-length", Utility::l2string( m_res.GetFile().size() ) );
		}
		for (Utility::ncmap<std::string>::const_iterator it = m_res.Headers().begin(); it != m_res.Headers().end(); ++it)
		{
			AddResponseHeader( it -> first, it -> second );
		}
		std::list<std::string> vec = m_res.CookieNames();
		for (std::list<std::string>::iterator it2 = vec.begin(); it2 != vec.end(); ++it2)
		{
			AppendResponseHeader( "set-cookie", m_res.Cookie(*it2) );
		}
		SendResponse();

		OnTransferLimit();
	}
	void IHttpServer_OnResponseComplete()
	{
		mreq.Reset();
		mres.Reset();
	}
private:
	HttpRequest mreq;
	HttpResponse mres;
};

int main(int argc,char *argv[])
{
	bool quit = false;
	bool g_b_http = false;
	bool g_b_nobuf = false;
	port_t port = 2222;
	bool enableLog = false;
	int queue = 20;
	int thread = 10;
	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "-port") && i < argc - 1)
			port = atoi(argv[++i]);
		if (!strcmp(argv[i], "-log"))
			enableLog = true;
		if (!strcmp(argv[i], "-queue") && i < argc - 1)
			queue = atoi(argv[++i]);
		if (!strcmp(argv[i], "-thread") && i < argc - 1)
			thread = atoi(argv[++i]);
		if (!strcmp(argv[i], "-nobuf"))
			g_b_nobuf = true;
		if (!strcmp(argv[i], "-h"))
		{
			printf("Usage: %s [ options ] [-ssl]\n", *argv);
			printf(" -port nn   listen on port nn\n");
			printf(" -log       enable sockethandler debug log\n");
			printf(" -queue nn  listen queue size (default 20)\n");
			printf(" -thread nn Number of threads (default 10)\n");
			printf(" -nobuf     echo raw data\n");
			exit(-1);
		}
	}
	if (g_b_nobuf)
	{
		printf("Nobuf does not work together\n");
		exit(-1);
	}
	StdoutLog *log = enableLog ? new StdoutLog() : NULL;
	SocketHandlerEp h(log);
	ListenSocket<MySocket> l(h);
	h.SetNumberOfThreads(thread);
	if (!g_b_http)
	{
		if (l.Bind(port, queue))
		{
			fprintf(stderr, "Bind to port %d failed\n", port);
			return -1;
		}
		fprintf(stderr, "Listening on port %d\n", port);
		h.Add(&l);
	}
	while (!quit)
	{
		h.Select(1, 0);
	}
	fprintf(stderr, "\nExiting...\n");
	if (log)
	{
		delete log;
	}
	return 0;
}


