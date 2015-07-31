; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTestManager
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ExamOnline.h"

ClassCount=19
Class1=CExamOnlineApp
Class2=CExamOnlineDlg
Class3=CAboutDlg

ResourceCount=21
Resource1=IDD_TESTMODIFY_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG5
Class4=CChoceSubject
Resource4=IDD_DIALOG10
Class5=CEamDlg
Resource5=IDD_DIALOG6
Class6=CEamInfo
Resource6=IDD_DIALOG14
Class7=CManagerDlg
Resource7=IDD_DIALOG12
Resource8=IDD_DIALOG8
Resource9=IDD_DIALOG4
Resource10=IDD_DIALOG9
Resource11=IDD_DIALOG11
Class8=DanXuanDlg
Class9=DuoXuanDlg
Class10=JieDaDlg
Resource12=IDD_DIALOG1
Class11=CZhuCeDlg
Resource13=IDD_ABOUTBOX
Class12=CFindPasswdDlg
Resource14=IDD_DIALOG7
Class13=CUserManager
Resource15=IDD_SUBJECTMODIFY_DIALOG
Class14=CSubjectManager
Resource16=IDD_EXAMONLINE_DIALOG
Class15=CTestManager
Resource17=IDD_DIALOG15
Class16=CExamInfoManager
Resource18=IDD_DIALOG2
Class17=CUserModify
Resource19=IDD_DIALOG13
Class18=CSubjectModify
Resource20=IDD_DIALOG3
Class19=CTestModify
Resource21=IDR_MENU1

[CLS:CExamOnlineApp]
Type=0
HeaderFile=ExamOnline.h
ImplementationFile=ExamOnline.cpp
Filter=N

[CLS:CExamOnlineDlg]
Type=0
HeaderFile=ExamOnlineDlg.h
ImplementationFile=ExamOnlineDlg.cpp
Filter=D
LastObject=CExamOnlineDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ExamOnlineDlg.h
ImplementationFile=ExamOnlineDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_EXAMONLINE_DIALOG]
Type=1
Class=CExamOnlineDlg
ControlCount=9
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350632864
Control5=IDC_STATIC,static,1342308352
Control6=IDC_COMBO1,combobox,1344341251
Control7=IDC_BUTTON1,button,1342242816
Control8=IDC_BUTTON2,button,1342242816
Control9=IDC_STATIC,button,1342177287

[DLG:IDD_DIALOG1]
Type=1
Class=CChoceSubject
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_COMBO1,combobox,1344341379

[CLS:CChoceSubject]
Type=0
HeaderFile=ChoceSubject.h
ImplementationFile=ChoceSubject.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_COMBO1

[DLG:IDD_DIALOG2]
Type=1
Class=CEamDlg
ControlCount=8
Control1=IDC_TAB1,SysTabControl32,1350565888
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC2,static,1342308352
Control4=IDC_BUTTON1,button,1342242816
Control5=IDC_BUTTON3,button,1342242816
Control6=IDC_BUTTON4,button,1342242816
Control7=IDC_STATIC,static,1342308492
Control8=IDC_STATIC1,static,1342308352

[CLS:CEamDlg]
Type=0
HeaderFile=EamDlg.h
ImplementationFile=EamDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_TAB1

[DLG:IDD_DIALOG3]
Type=1
Class=CEamInfo
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC1,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC2,static,1342308352
Control5=IDC_DATAGRID1,{CDE57A43-8B86-11D0-B3C6-00A0C90AEA82},1342242816
Control6=IDC_ADODC1,{67397AA3-7FB1-11D0-B148-00A0C922E820},1073741824

[CLS:CEamInfo]
Type=0
HeaderFile=EamInfo.h
ImplementationFile=EamInfo.cpp
BaseClass=CDialog
Filter=D
LastObject=CEamInfo

[DLG:IDD_DIALOG4]
Type=1
Class=CManagerDlg
ControlCount=1
Control1=IDC_TAB1,SysTabControl32,1342177280

[CLS:CManagerDlg]
Type=0
HeaderFile=ManagerDlg.h
ImplementationFile=ManagerDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_TAB1
VirtualFilter=dWC

[DLG:IDD_DIALOG5]
Type=1
Class=?
ControlCount=2
Control1=IDC_DATAGRID1,{CDE57A43-8B86-11D0-B3C6-00A0C90AEA82},1342242816
Control2=IDC_ADODC1,{67397AA3-7FB1-11D0-B148-00A0C922E820},1342177280

[DLG:IDD_DIALOG6]
Type=1
Class=DanXuanDlg
ControlCount=7
Control1=IDC_STATIC2,static,1342308352
Control2=IDC_RADIO1,button,1342177289
Control3=IDC_RADIO2,button,1342177289
Control4=IDC_RADIO3,button,1342177289
Control5=IDC_RADIO4,button,1342177289
Control6=IDC_BUTTON1,button,1342242816
Control7=IDC_BUTTON2,button,1342242816

[DLG:IDD_DIALOG7]
Type=1
Class=DuoXuanDlg
ControlCount=7
Control1=IDC_STATIC2,static,1342308352
Control2=IDC_BUTTON1,button,1342242816
Control3=IDC_BUTTON2,button,1342242816
Control4=IDC_CHECK1,button,1342242819
Control5=IDC_CHECK2,button,1342242819
Control6=IDC_CHECK3,button,1342242819
Control7=IDC_CHECK4,button,1342242819

[DLG:IDD_DIALOG8]
Type=1
Class=JieDaDlg
ControlCount=5
Control1=IDC_STATIC2,static,1342308352
Control2=IDC_BUTTON1,button,1342242816
Control3=IDC_BUTTON2,button,1342242816
Control4=IDC_EDIT1,edit,1352730692
Control5=IDC_STATIC,static,1342308352

[CLS:DanXuanDlg]
Type=0
HeaderFile=DanXuanDlg.h
ImplementationFile=DanXuanDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=DanXuanDlg
VirtualFilter=dWC

[CLS:DuoXuanDlg]
Type=0
HeaderFile=DuoXuanDlg.h
ImplementationFile=DuoXuanDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=DuoXuanDlg

[CLS:JieDaDlg]
Type=0
HeaderFile=JieDaDlg.h
ImplementationFile=JieDaDlg.cpp
BaseClass=CDialog
Filter=D

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_MENUITEM32772
Command2=ID_MENUITEM32773
Command3=ID_MENUITEM32774
CommandCount=3

[DLG:IDD_DIALOG9]
Type=1
Class=CZhuCeDlg
ControlCount=17
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT1,edit,1350631552
Control10=IDC_EDIT2,edit,1350631584
Control11=IDC_EDIT3,edit,1350631584
Control12=IDC_COMBO2,combobox,1344341251
Control13=IDC_RADIO1,button,1342177289
Control14=IDC_RADIO2,button,1342177289
Control15=IDC_COMBO3,combobox,1344341251
Control16=IDC_STATIC,static,1342308352
Control17=IDC_EDIT4,edit,1350631552

[CLS:CZhuCeDlg]
Type=0
HeaderFile=ZhuCeDlg.h
ImplementationFile=ZhuCeDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CZhuCeDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG10]
Type=1
Class=CFindPasswdDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT3,edit,1350631552
Control8=IDC_STATIC2,static,1073872896
Control9=IDC_STATIC1,static,1342308352
Control10=IDC_STATIC3,static,1342308352

[CLS:CFindPasswdDlg]
Type=0
HeaderFile=FindPasswdDlg.h
ImplementationFile=FindPasswdDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_STATIC2
VirtualFilter=dWC

[DLG:IDD_DIALOG11]
Type=1
Class=CUserManager
ControlCount=6
Control1=IDC_LIST1,SysListView32,1350631429
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_BUTTON1,button,1342242816
Control5=IDC_BUTTON2,button,1342242816
Control6=IDC_BUTTON3,button,1342242816

[CLS:CUserManager]
Type=0
HeaderFile=UserManager.h
ImplementationFile=UserManager.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_LIST1

[DLG:IDD_DIALOG12]
Type=1
Class=CSubjectManager
ControlCount=6
Control1=IDC_LIST1,SysListView32,1350633477
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_BUTTON1,button,1342242816
Control5=IDC_BUTTON2,button,1342242816
Control6=IDC_BUTTON3,button,1342242816

[CLS:CSubjectManager]
Type=0
HeaderFile=SubjectManager.h
ImplementationFile=SubjectManager.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CSubjectManager

[DLG:IDD_DIALOG13]
Type=1
Class=CTestManager
ControlCount=9
Control1=IDC_LIST1,SysListView32,1350633733
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_COMBO1,combobox,1344341251
Control6=IDC_BUTTON1,button,1342242816
Control7=IDC_BUTTON2,button,1342242816
Control8=IDC_BUTTON3,button,1342242816
Control9=IDC_BUTTON4,button,1342242816

[CLS:CTestManager]
Type=0
HeaderFile=TestManager.h
ImplementationFile=TestManager.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CTestManager

[DLG:IDD_DIALOG14]
Type=1
Class=CExamInfoManager
ControlCount=1
Control1=IDC_LIST1,SysListView32,1350631685

[CLS:CExamInfoManager]
Type=0
HeaderFile=ExamInfoManager.h
ImplementationFile=ExamInfoManager.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CExamInfoManager

[DLG:IDD_DIALOG15]
Type=1
Class=CUserModify
ControlCount=15
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT1,edit,1350631552
Control9=IDC_EDIT2,edit,1350631584
Control10=IDC_COMBO2,combobox,1344341251
Control11=IDC_RADIO1,button,1342177289
Control12=IDC_RADIO2,button,1342177289
Control13=IDC_COMBO3,combobox,1344341251
Control14=IDC_STATIC,static,1342308352
Control15=IDC_EDIT4,edit,1350631552

[CLS:CUserModify]
Type=0
HeaderFile=UserModify.h
ImplementationFile=UserModify.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT4

[DLG:IDD_SUBJECTMODIFY_DIALOG]
Type=1
Class=CSubjectModify
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1342244992
Control4=IDC_EDIT2,edit,1350631552
Control5=IDC_BUTTON1,button,1342242816
Control6=IDC_BUTTON2,button,1342242816

[CLS:CSubjectModify]
Type=0
HeaderFile=SubjectModify.h
ImplementationFile=SubjectModify.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CSubjectModify

[DLG:IDD_TESTMODIFY_DIALOG]
Type=1
Class=CTestModify
ControlCount=23
Control1=IDOK,button,1342242817
Control2=IDUPDATE,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT1,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_COMBO1,combobox,1344341251
Control15=IDC_COMBO4,combobox,1344341251
Control16=IDC_EDIT2,edit,1350631552
Control17=IDC_EDIT5,edit,1350631552
Control18=IDC_EDIT6,edit,1350631552
Control19=IDC_EDIT7,edit,1350631552
Control20=IDC_EDIT8,edit,1350631552
Control21=IDC_EDIT9,edit,1350631552
Control22=IDC_EDIT10,edit,1350631552
Control23=IDOK2,button,1342242817

[CLS:CTestModify]
Type=0
HeaderFile=TestModify.h
ImplementationFile=TestModify.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CTestModify

