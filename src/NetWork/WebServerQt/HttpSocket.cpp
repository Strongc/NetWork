#include "StdAfx.h"
#include "HttpSocket.h"


HttpSocket::HttpSocket(ISocketHandler& h)
	:HttpBaseSocket(h)
{
}


HttpSocket::~HttpSocket(void)
{
}

void HttpSocket::IHttpServer_OnExec(const HttpRequest& req)
{
	mreq = req;
	mres.SetHeader("Server","DayBreakZhang Web Server");
	std::string _tempuri = mreq.Uri();


	IHttpServer_Respond(mres);
}

void HttpSocket::IHttpServer_Respond(const HttpResponse& res)
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

void HttpSocket::IHttpServer_OnResponseComplete()
{
	mreq.Reset();
	mres.Reset();
}
