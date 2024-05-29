# winsock351

This is a reimplementation of `ws2_32.dll` (Winsock 2) around `wsock32.dll` (Winsock 1.1) in order to support Winsock 2 applications under operating systems that don't support it, such as Windows NT 3.51.

## Usage

In order to use this library, you can simply drop it on the same path as the target application. Alternatively if you want to install the library globally, you can drop it along the rest of the libraries on your system on `%WINDIR%\system32`.

## Supported systems

`winsock351` has only been tested under Windows NT 3.51, but other systems such as early versions of Windows 95 may work too.