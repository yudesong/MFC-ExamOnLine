# Microsoft Developer Studio Project File - Name="ExamOnline" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=ExamOnline - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ExamOnline.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ExamOnline.mak" CFG="ExamOnline - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ExamOnline - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ExamOnline - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ExamOnline - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "ExamOnline - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "ExamOnline - Win32 Release"
# Name "ExamOnline - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ADOConn.cpp
# End Source File
# Begin Source File

SOURCE=.\ChoceSubject.cpp
# End Source File
# Begin Source File

SOURCE=.\DanXuanDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DuoXuanDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EamDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EamInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\ExamInfoManager.cpp
# End Source File
# Begin Source File

SOURCE=.\ExamOnline.cpp
# End Source File
# Begin Source File

SOURCE=.\ExamOnline.rc
# End Source File
# Begin Source File

SOURCE=.\ExamOnlineDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\FindPasswdDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\JieDaDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ManagerDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\SubjectManager.cpp
# End Source File
# Begin Source File

SOURCE=.\SubjectModify.cpp
# End Source File
# Begin Source File

SOURCE=.\TestManager.cpp
# End Source File
# Begin Source File

SOURCE=.\TestModify.cpp
# End Source File
# Begin Source File

SOURCE=.\UserManager.cpp
# End Source File
# Begin Source File

SOURCE=.\UserModify.cpp
# End Source File
# Begin Source File

SOURCE=.\ZhuCeDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ADOConn.h
# End Source File
# Begin Source File

SOURCE=.\ChoceSubject.h
# End Source File
# Begin Source File

SOURCE=.\DanXuanDlg.h
# End Source File
# Begin Source File

SOURCE=.\DuoXuanDlg.h
# End Source File
# Begin Source File

SOURCE=.\EamDlg.h
# End Source File
# Begin Source File

SOURCE=.\EamInfo.h
# End Source File
# Begin Source File

SOURCE=.\ExamInfoManager.h
# End Source File
# Begin Source File

SOURCE=.\ExamOnline.h
# End Source File
# Begin Source File

SOURCE=.\ExamOnlineDlg.h
# End Source File
# Begin Source File

SOURCE=.\FindPasswdDlg.h
# End Source File
# Begin Source File

SOURCE=.\JieDaDlg.h
# End Source File
# Begin Source File

SOURCE=.\ManagerDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\SubjectManager.h
# End Source File
# Begin Source File

SOURCE=.\SubjectModify.h
# End Source File
# Begin Source File

SOURCE=.\TestManager.h
# End Source File
# Begin Source File

SOURCE=.\TestModify.h
# End Source File
# Begin Source File

SOURCE=.\UserManager.h
# End Source File
# Begin Source File

SOURCE=.\UserModify.h
# End Source File
# Begin Source File

SOURCE=.\ZhuCeDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\ExamOnline.ico
# End Source File
# Begin Source File

SOURCE=.\res\ExamOnline.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
