#pragma once
class HttpSocket :public HttpBaseSocket
{
public:
	HttpSocket(ISocketHandler& h);
	~HttpSocket(void);
public:
	void IHttpServer_OnExec(const HttpRequest& req);
	void IHttpServer_Respond(const HttpResponse& res);
	void IHttpServer_OnResponseComplete();
private:
	HttpRequest mreq;
	HttpResponse mres;
};

