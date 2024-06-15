// We can't avoid this when using maps
#pragma warning(push)
#pragma warning(disable:4786)

#include <map>
#include "events.h"

std::map<SOCKET, WSAEventData> events;
HANDLE events_mutex;
HINSTANCE events_instance;
HWND events_window;
static const char* events_window_name = "WINSOCK351";

void SetEventData(SOCKET socket, const WSAEventData& data) {
	const DWORD wait_result = WaitForSingleObject(events_mutex, INFINITE);
	switch (wait_result) {
	case WAIT_OBJECT_0:
		events[socket] = data;
		ReleaseMutex(events_mutex);
	case WAIT_ABANDONED:
		return;
	}
}

int GetEventData(SOCKET socket, WSAEventData* data) {
	const DWORD wait_result = WaitForSingleObject(events_mutex, INFINITE);
	switch (wait_result) {
	case WAIT_OBJECT_0:
		if (events.find(socket) == events.end())
			return -1;

		*data = events[socket];
		ReleaseMutex(events_mutex);
	case WAIT_ABANDONED:
		return -1;
	}

	return 0;
}

void DeleteEventData(SOCKET socket) {
	const DWORD wait_result = WaitForSingleObject(events_mutex, INFINITE);
	switch (wait_result) {
	case WAIT_OBJECT_0:
		events.erase(socket);
		ReleaseMutex(events_mutex);
	case WAIT_ABANDONED:
		return;
	}
}

void DeleteEvents() {
	const DWORD wait_result = WaitForSingleObject(events_mutex, INFINITE);
	switch (wait_result) {
	case WAIT_OBJECT_0:
		events.clear();
		ReleaseMutex(events_mutex);
	case WAIT_ABANDONED:
		return;
	}
}

LRESULT CALLBACK EventsWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	if (uMsg > WM_USER) {
		const WSAEVENT event = reinterpret_cast<WSAEVENT>(uMsg - WM_USER);
		WSAEventData data;
		int err = GetEventData(wParam, &data);
		if (err != 0)
			return FALSE;

		data.lNetworkEvents = WSAGETSELECTEVENT(lParam);
		SetEventData(wParam, data);

		return SetEvent(event);
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void SetEventsInstance(HINSTANCE hinstance) {
	events_instance = hinstance;
}

HWND GetEventsWindow() {
	return events_window;
}

int StartupEvents() {
	events_mutex = CreateMutex(NULL, TRUE, NULL);
	if (events_mutex == NULL)
		return GetLastError();

	// In order to receive WSAAsync events locally we will create an
	// invisible window to receive those messages
	// HWND_MESSAGE didn't exist on NT 3.51 so we have to do it this way
	WNDCLASS wc; 

	// Register the main window class
	wc.style = 0; 
	wc.lpfnWndProc = EventsWndProc; 
	wc.cbClsExtra = 0; 
	wc.cbWndExtra = 0; 
	wc.hInstance = events_instance; 
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); 
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); 
	wc.hbrBackground = NULL; 
	wc.lpszMenuName =  NULL; 
	wc.lpszClassName = events_window_name;
	RegisterClass(&wc);
	events_window = CreateWindow(events_window_name, NULL, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL);

	return 0;
}

int CleanupEvents() {
	DeleteEvents();
	const int err = CloseHandle(events_mutex);
	if (err != 0) {
		return err;
	}

	DestroyWindow(events_window);
	UnregisterClass(events_window_name, NULL);
	return 0;
}

#pragma warning(pop)