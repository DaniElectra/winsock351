#include <winsock.h>

#define WSAEVENT HANDLE
#define LPWSAEVENT LPHANDLE
#define FD_MAX_EVENTS 10

typedef struct _WSANETWORKEVENTS {
  long lNetworkEvents;
  int  iErrorCode[FD_MAX_EVENTS];
} WSANETWORKEVENTS, *LPWSANETWORKEVENTS;

struct WSAEventData {
	long lNetworkEvents;
};

void SetEventData(SOCKET socket, const WSAEventData& data);
int GetEventData(SOCKET socket, WSAEventData* data);
void DeleteEventData(SOCKET socket);
void SetEventsInstance(HINSTANCE hinstance);
HWND GetEventsWindow();
int StartupEvents();
int CleanupEvents();