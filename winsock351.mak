# Microsoft Developer Studio Generated NMAKE File, Based on winsock351.dsp
!IF "$(CFG)" == ""
CFG=winsock351 - Win32 Debug
!MESSAGE No configuration specified. Defaulting to winsock351 - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "winsock351 - Win32 Release" && "$(CFG)" != "winsock351 - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "winsock351.mak" CFG="winsock351 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "winsock351 - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "winsock351 - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "winsock351 - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\ws2_32.dll"


CLEAN :
	-@erase "$(INTDIR)\events.obj"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\winsock2.obj"
	-@erase "$(OUTDIR)\ws2_32.dll"
	-@erase "$(OUTDIR)\ws2_32.exp"
	-@erase "$(OUTDIR)\ws2_32.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "WINSOCK351_EXPORTS" /Fp"$(INTDIR)\winsock351.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\winsock351.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\ws2_32.pdb" /machine:I386 /def:".\ws2_32.def" /out:"$(OUTDIR)\ws2_32.dll" /implib:"$(OUTDIR)\ws2_32.lib" 
DEF_FILE= \
	".\ws2_32.def"
LINK32_OBJS= \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\winsock2.obj" \
	"$(INTDIR)\events.obj"

"$(OUTDIR)\ws2_32.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "winsock351 - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\ws2_32.dll"


CLEAN :
	-@erase "$(INTDIR)\events.obj"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\winsock2.obj"
	-@erase "$(OUTDIR)\ws2_32.dll"
	-@erase "$(OUTDIR)\ws2_32.exp"
	-@erase "$(OUTDIR)\ws2_32.ilk"
	-@erase "$(OUTDIR)\ws2_32.lib"
	-@erase "$(OUTDIR)\ws2_32.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "WINSOCK351_EXPORTS" /Fp"$(INTDIR)\winsock351.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\winsock351.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /dll /incremental:yes /pdb:"$(OUTDIR)\ws2_32.pdb" /debug /machine:I386 /def:".\ws2_32.def" /out:"$(OUTDIR)\ws2_32.dll" /implib:"$(OUTDIR)\ws2_32.lib" /pdbtype:sept 
DEF_FILE= \
	".\ws2_32.def"
LINK32_OBJS= \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\winsock2.obj" \
	"$(INTDIR)\events.obj"

"$(OUTDIR)\ws2_32.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("winsock351.dep")
!INCLUDE "winsock351.dep"
!ELSE 
!MESSAGE Warning: cannot find "winsock351.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "winsock351 - Win32 Release" || "$(CFG)" == "winsock351 - Win32 Debug"
SOURCE=.\events.cpp

"$(INTDIR)\events.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\main.cpp

"$(INTDIR)\main.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\winsock2.cpp

"$(INTDIR)\winsock2.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF 

