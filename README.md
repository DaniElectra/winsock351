# winsock351

This is a reimplementation of `ws2_32.dll` (Winsock 2) around `wsock32.dll` (Winsock 1.1) in order to support Winsock 2 applications under operating systems that don't support it, such as Windows NT 3.51.

## What's supported

The following is the list of Winsock 2 exclusive functions that are supported by this library. Not all functions may be listed, since there are functions which target interaction with the network drivers directly which isn't a priority:

- :heavy_check_mark: **Full support**
- :warning: **Partial support**
- :x: **Not supported yet**

| Ordinal | Function                        | Support            | Notes                               |
|---------|---------------------------------|--------------------|-------------------------------------|
| 7       | `getsockopt`                    | :warning:          | May have Winsock2-exclusive opts    |
| 10      | `ioctlsocket`                   | :warning:          | May have Winsock2-exclusive cmds    |
| 21      | `setsockopt`                    | :warning:          | May have Winsock2-exclusive opts    |
| 24      | `WSApSetPostRoutine`            | :x:                |                                     |
| 25      | `FreeAddrInfoEx`                | :x:                |                                     |
| 26      | `FreeAddrInfoExW`               | :x:                |                                     |
| 27      | `FreeAddrInfoW`                 | :x:                |                                     |
| 28      | `GetAddrInfoExA`                | :x:                |                                     |
| 29      | `GetAddrInfoExCancel`           | :x:                |                                     |
| 30      | `GetAddrInfoExOverlappedResult` | :x:                |                                     |
| 31      | `GetAddrInfoExW`                | :x:                |                                     |
| 32      | `GetAddrInfoW`                  | :x:                |                                     |
| 33      | `GetHostNameW`                  | :x:                |                                     |
| 34      | `GetNameInfoW`                  | :x:                |                                     |
| 35      | `InetNtopW`                     | :x:                |                                     |
| 36      | `InetPtonW`                     | :x:                |                                     |
| 37      | `SetAddrInfoExA`                | :x:                |                                     |
| 38      | `SetAddrInfoExW`                | :x:                |                                     |
| 41      | `WSAAccept`                     | :x:                |                                     |
| 42      | `WSAAddressToStringA`           | :x:                |                                     |
| 43      | `WSAAddressToStringW`           | :x:                |                                     |
| 45      | `WSACloseEvent`                 | :heavy_check_mark: |                                     |
| 46      | `WSAConnect`                    | :x:                |                                     |
| 47      | `WSAConnectByList`              | :x:                |                                     |
| 48      | `WSAConnectByNameA`             | :x:                |                                     |
| 49      | `WSAConnectByNameW`             | :x:                |                                     |
| 50      | `WSACreateEvent`                | :heavy_check_mark: |                                     |
| 64      | `WSAEnumNetworkEvents`          | :heavy_check_mark: |                                     |
| 67      | `WSAEventSelect`                | :heavy_check_mark: | Implemented around `WSAAsyncSelect` |
| 74      | `WSAHtonl`                      | :x:                |                                     |
| 75      | `WSAHtons`                      | :x:                |                                     |
| 78      | `WSAIoctl`                      | :x:                | Stubbed                             |
| 86      | `WSANtohl`                      | :x:                |                                     |
| 87      | `WSANtohs`                      | :x:                |                                     |
| 88      | `WSAPoll`                       | :x:                |                                     |
| 91      | `WSARecv`                       | :x:                |                                     |
| 92      | `WSARecvDisconnect`             | :x:                |                                     |
| 93      | `WSARecvFrom`                   | :x:                |                                     |
| 95      | `WSAResetEvent`                 | :heavy_check_mark: |                                     |
| 96      | `WSASend`                       | :x:                |                                     |
| 97      | `WSASendDisconnect`             | :x:                |                                     |
| 98      | `WSASendMsg`                    | :x:                |                                     |
| 99      | `WSASendTo`                     | :x:                |                                     |
| 100     | `WSASetEvent`                   | :heavy_check_mark: |                                     |
| 119     | `WSASocketA`                    | :x:                |                                     |
| 119     | `WSASocketw`                    | :x:                |                                     |
| 120     | `WSAAddressToStringA`           | :x:                |                                     |
| 121     | `WSAStringToAddressW`           | :x:                |                                     |
| 124     | `WSAWaitForMultipleEvents`      | :heavy_check_mark: |                                     |
| 175     | `freeaddrinfo`                  | :x:                | Stubbed                             |
| 176     | `getaddrinfo`                   | :x:                | Stubbed                             |
| 177     | `getnameinfo`                   | :x:                |                                     |

## Usage

In order to use this library, you can simply drop it on the same path as the target application. Alternatively if you want to install the library globally, you can drop it along the rest of the libraries on your system on `%WINDIR%\system32`.

## Build requirements

At the moment Visual C++ 6.0 is required to build the project, but Visual C++ 4.2 support may be considered in the future.

## Supported systems

`winsock351` has only been tested under Windows NT 3.51, but other systems such as early versions of Windows 95 may work too.

## Credits

This project has been partly inspired by [MattKC's backport of .NET to Windows 9x](https://github.com/itsmattkc/dotnet9x). The MSVC workflows have been adapted from there.
