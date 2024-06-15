#include <cstdio>
#include "winsock2.h"

#ifdef _DEBUG
void DebugLog(const char* fmt, ...) {
	va_list args;
	va_start(args, fmt);

	char* buf = new char[256];
	_vsnprintf(buf, 255, fmt, args);
	va_end(args);

	MessageBox(NULL, buf, "WINSOCK351", 0);
}
#else
#define DebugLog
#endif

int WSAAPI WINSOCK351_getsockopt(SOCKET s, int level, int optname, char* optval, int* optlen) {
	DebugLog("getsockopt: socket: %d, level: 0x%X, optname: 0x%X, optlen: %d",
		s, level, optname, optlen != NULL ? *optlen : 0);
	return getsockopt(s, level, optname, optval, optlen);
}

int WSAAPI WINSOCK351_ioctlsocket(SOCKET s, long cmd, u_long* argp) {
	DebugLog("ioctlsocket: socket: %d, cmd: 0x%X, argp: 0x%X",
		s, cmd, argp != NULL ? *argp : 0);
	return ioctlsocket(s, cmd, argp);
}

int WSAAPI WINSOCK351_select(int nfds, fd_set* readfds, fd_set* writefds, fd_set* exceptfds, const timeval* timeout)
 {
	DebugLog("select: nfds: %d, timeout: %d", nfds, timeout != NULL ? timeout->tv_sec * 1000000 + timeout->tv_usec : 0);
	return select(nfds, readfds, writefds, exceptfds, timeout);
}

int WSAAPI WINSOCK351_setsockopt(SOCKET s, int level, int optname, char* optval, int optlen) {
	DebugLog("setsockopt: socket: %d, level: 0x%X, optname: 0x%X, optlen: %d",
		s, level, optname, optlen);
	return setsockopt(s, level, optname, optval, optlen);
}

BOOL WSAAPI WINSOCK351_WSACloseEvent(WSAEVENT hEvent) {
	DebugLog("WSACloseEvent: hEvent: %d", hEvent);
	return CloseHandle(hEvent);
}

WSAEVENT WSAAPI WINSOCK351_WSACreateEvent() {
	DebugLog("WSACreateEvent");
	const WSAEVENT event = CreateEvent(NULL, TRUE, FALSE, NULL);
	if (event == NULL) {
		// TODO: Set proper error
		WSASetLastError(GetLastError());
		return WSA_INVALID_EVENT;
	}

	return event;
}

int WSAAPI WINSOCK351_WSAEnumNetworkEvents(SOCKET s, WSAEVENT hEventObject, LPWSANETWORKEVENTS lpNetworkEvents) {
	DebugLog("WSAEnumNetworkEvents: socket: %d, hEventObject: %d", s, hEventObject);
	if (lpNetworkEvents == NULL) {
		WSASetLastError(WSAEFAULT);
		return SOCKET_ERROR;
	}

	WSAEventData data;
	const int err = GetEventData(s, &data);
	if (err != 0) {
		WSASetLastError(WSAENOTSOCK);
		return SOCKET_ERROR;
	}

	lpNetworkEvents->lNetworkEvents = data.lNetworkEvents;

	return 0;
}

int WSAAPI WINSOCK351_WSAEventSelect(SOCKET s, WSAEVENT hEventObject, long lNetworkEvents) {
	DebugLog("WSAEventSelect: socket: %d, hEventObject: %d, lNetworkEvents: 0x%X",
		s, hEventObject, lNetworkEvents);

	// Check for overflow
	if (WM_USER + reinterpret_cast<unsigned int>(hEventObject) < WM_USER) {
		WSASetLastError(WSAEINVAL);
		return SOCKET_ERROR;
	}

	return WSAAsyncSelect(s, GetEventsWindow(), WM_USER + reinterpret_cast<unsigned int>(hEventObject), lNetworkEvents);
}

// STUB
int WSAAPI WINSOCK351_WSAIoctl(
	SOCKET s,
	DWORD dwIoControlCode,
	const LPVOID lpvInBuffer,
	DWORD cbInBuffer,
	LPVOID lpvOutBuffer,
	DWORD cbOutBuffer,
	LPDWORD lpcbBytesReturned,
	const LPWSAOVERLAPPED lpOverlapped,
	const LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) {
	DebugLog("WSAIoctl: socket: %d, dwIoControlCode: 0x%X, cbInBuffer: %d, cbOutBuffer: %d",
		s, dwIoControlCode, cbInBuffer, cbOutBuffer);
	return SOCKET_ERROR;
}

int WSAAPI WINSOCK351_WSAStartup(WORD wVersionRequested, LPWSADATA lpWSAData) {
	DebugLog("WSAStartup: wVersionRequested: 0x%X", wVersionRequested);
	const int err = WSAStartup(wVersionRequested, lpWSAData);
	if (err != 0)
		return err;

	// TODO: Check for errors
	StartupEvents();

	// Spoof the version returned
	if (lpWSAData->wVersion != wVersionRequested)
		lpWSAData->wVersion = wVersionRequested;

	return 0;
}

int WSAAPI WINSOCK351_WSACleanup() {
	DebugLog("WSACleanup");
	const int err = WSACleanup();
	if (err != 0)
		return err;

	// TODO: Check for errors
	CleanupEvents();

	return 0;
}

BOOL WSAAPI WINSOCK351_WSAResetEvent(WSAEVENT hEvent) {
	DebugLog("WSAResetEvent: hEvent: %d", hEvent);
	// TODO: Set WSALastError
	return ResetEvent(hEvent);
}

BOOL WSAAPI WINSOCK351_WSASetEvent(WSAEVENT hEvent) {
	DebugLog("WSAResetEvent: hEvent: %d", hEvent);
	// TODO: Set WSALastError
	return SetEvent(hEvent);
}

DWORD WSAAPI WINSOCK351_WSAWaitForMultipleEvents(
	DWORD cEvents,
	const LPWSAEVENT lphEvents,
	BOOL fWaitAll,
	DWORD dwTimeout,
	BOOL fAlertable) {
	DebugLog("WSAWaitForMultipleEvents: cEvents: %d, fWaitAll: %d, dwTimeout: %d, fAlertable: %d",
		cEvents, fWaitAll, dwTimeout, fAlertable);
	// TODO: Set WSALastError
	return WaitForMultipleObjectsEx(cEvents, lphEvents, fWaitAll, dwTimeout, fAlertable);
}

// STUB
void WSAAPI WINSOCK351_freeaddrinfo() {
	DebugLog("freeaddrinfo");
	return;
}

// STUB
int WSAAPI WINSOCK351_getaddrinfo() {
	DebugLog("getaddrinfo");
	return SOCKET_ERROR;
}
