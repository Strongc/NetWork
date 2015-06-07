#pragma once

#include <QtCore/QtCore>
#include <QtGui/QtGui>

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

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <fstream>
#include <winsock2.h>
#include <Windows.h>
#include <shellapi.h>
#include <Shlwapi.h>
#include <conio.h>        // For _kbhit() on Windows
#include <direct.h>        // For mkdir(path) on Windows
#include "time.h"
#include <stdio.h>
#include <stdlib.h> 
#include <queue>
#include <MMSystem.h>
#define snprintf sprintf_s    // Visual Studio on Windows comes with sprintf_s() instead of snprintf()
#pragma comment(lib,"Shlwapi.lib")
#pragma comment(lib, "DbgHelp.lib")
#include <string>
using namespace std;

#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/thread/condition.hpp>

