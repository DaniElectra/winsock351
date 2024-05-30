#include <winsock.h>
#include "events.h"

#define WSAAPI __stdcall
#define WSA_INVALID_EVENT ((WSAEVENT)NULL)
#define WSA_WAIT_FAILED ((DWORD)-1L)

typedef unsigned int GROUP;
typedef ULONG SERVICETYPE;

typedef struct _WSABUF {
    u_long      len;     /* the length of the buffer */
    char FAR *  buf;     /* the pointer to the buffer */
} WSABUF, FAR * LPWSABUF;

typedef struct _flowspec {
    ULONG       TokenRate;              /* In Bytes/sec */
    ULONG       TokenBucketSize;        /* In Bytes */
    ULONG       PeakBandwidth;          /* In Bytes/sec */
    ULONG       Latency;                /* In microseconds */
    ULONG       DelayVariation;         /* In microseconds */
    SERVICETYPE ServiceType;
    ULONG       MaxSduSize;             /* In Bytes */
    ULONG       MinimumPolicedSize;     /* In Bytes */

} FLOWSPEC, *PFLOWSPEC, * LPFLOWSPEC;

typedef struct _QualityOfService {
    FLOWSPEC      SendingFlowspec;       /* the flow spec for data sending */
    FLOWSPEC      ReceivingFlowspec;     /* the flow spec for data receiving */
    WSABUF        ProviderSpecific;      /* additional provider specific stuff */
} QOS, FAR * LPQOS;

typedef struct _WSAOVERLAPPED {
  DWORD    Internal;
  DWORD    InternalHigh;
  DWORD    Offset;
  DWORD    OffsetHigh;
  WSAEVENT hEvent;
} WSAOVERLAPPED, *LPWSAOVERLAPPED;

typedef
int
(CALLBACK * LPCONDITIONPROC)(
    LPWSABUF lpCallerId,
    LPWSABUF lpCallerData,
    LPQOS lpSQOS,
    LPQOS lpGQOS,
    LPWSABUF lpCalleeId,
    LPWSABUF lpCalleeData,
    GROUP FAR * g,
    DWORD dwCallbackData
    );

typedef
void
(CALLBACK * LPWSAOVERLAPPED_COMPLETION_ROUTINE)(
    DWORD dwError,
    DWORD cbTransferred,
    LPWSAOVERLAPPED lpOverlapped,
    DWORD dwFlags
    );

#ifdef __cplusplus
extern "C" {
#endif

int WSAAPI WINSOCK351_getsockopt(SOCKET s, int level, int optname, char* optval, int* optlen);
int WSAAPI WINSOCK351_ioctlsocket(SOCKET s, long cmd, u_long* argp);
int WSAAPI WINSOCK351_select(int nfds, fd_set* readfds, fd_set* writefds, fd_set* exceptfds, const timeval* timeout);
int WSAAPI WINSOCK351_setsockopt(SOCKET s, int level, int optname, char* optval, int optlen);
BOOL WSAAPI WINSOCK351_WSACloseEvent(WSAEVENT hEvent);
WSAEVENT WSAAPI WINSOCK351_WSACreateEvent();
int WSAAPI WINSOCK351_WSAEnumNetworkEvents(SOCKET s, WSAEVENT hEventObject, LPWSANETWORKEVENTS lpNetworkEvents);
int WSAAPI WINSOCK351_WSAEventSelect(SOCKET s, WSAEVENT hEventObject, long lNetworkEvents);
int WSAAPI WINSOCK351_WSAIoctl(
	SOCKET s,
	DWORD dwIoControlCode,
	const LPVOID lpvInBuffer,
	DWORD cbInBuffer,
	LPVOID lpvOutBuffer,
	DWORD cbOutBuffer,
	LPDWORD lpcbBytesReturned,
	const LPWSAOVERLAPPED lpOverlapped,
	const LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
BOOL WSAAPI WINSOCK351_WSAResetEvent(WSAEVENT hEvent);
BOOL WSAAPI WINSOCK351_WSASetEvent(WSAEVENT hEvent);
int WSAAPI WINSOCK351_WSAStartup(WORD wVersionRequested, LPWSADATA lpWSAData);
int WSAAPI WINSOCK351_WSACleanup();
DWORD WSAAPI WINSOCK351_WSAWaitForMultipleEvents(
	DWORD cEvents,
	const LPWSAEVENT lphEvents,
	BOOL fWaitAll,
	DWORD dwTimeout,
	BOOL fAlertable);
void WSAAPI WINSOCK351_freeaddrinfo();
int WSAAPI WINSOCK351_getaddrinfo();

#ifdef __cplusplus
}
#endif
