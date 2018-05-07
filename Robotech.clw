; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=SkillSet
LastTemplate=CRecordset
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Robotech.h"
LastPage=0

ClassCount=17
Class1=CRobotechApp
Class2=CRobotechDoc
Class3=CRobotechView
Class4=CMainFrame

ResourceCount=8
Resource1=IDR_MAINFRAME
Resource2=IDD_ROBOTECH_FORM
Resource3=IDD_MOS
Class5=CAboutDlg
Class6=CPersonalPage
Resource4=IDD_SKILLS
Class7=CSkillPage
Resource5=IDD_ABOUTBOX
Class8=CFinalPage
Class9=OCCSet
Class10=MOSSet
Class11=SkillSet
Class12=CMOSPage
Class13=BonusSet
Resource6=IDD_PERSONAL
Resource7=IDD_FINAL
Class14=RaceSet
Class15=CSelectDlg
Class16=CSplashWnd
Class17=CExtra
Resource8=IDD_SELECT

[CLS:CRobotechApp]
Type=0
HeaderFile=Robotech.h
ImplementationFile=Robotech.cpp
Filter=N
LastObject=CRobotechApp

[CLS:CRobotechDoc]
Type=0
HeaderFile=RobotechDoc.h
ImplementationFile=RobotechDoc.cpp
Filter=T
LastObject=CRobotechDoc
BaseClass=CDocument
VirtualFilter=DC

[CLS:CRobotechView]
Type=0
HeaderFile=RobotechView.h
ImplementationFile=RobotechView.cpp
Filter=T
BaseClass=CFormView
VirtualFilter=VWC
LastObject=CRobotechView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=C
LastObject=ROBO_HELPTOPIC
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=Robotech.cpp
ImplementationFile=Robotech.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_APP_EXIT
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_VIEW_TOOLBAR
Command14=ID_VIEW_STATUS_BAR
Command15=ROBO_HELPTOPIC
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
Command15=ID_CONTEXT_HELP
Command16=ID_HELP
CommandCount=16

[DLG:IDD_ROBOTECH_FORM]
Type=1
Class=CRobotechView
ControlCount=1
Control1=IDC_TAB1,SysTabControl32,1342177280

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ROBO_HELP
CommandCount=9

[DLG:IDD_PERSONAL]
Type=1
Class=CPersonalPage
ControlCount=28
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_NAME,edit,1350631552
Control6=IDC_SDC,edit,1350631552
Control7=IDC_OCC,combobox,1344340995
Control8=IDC_RACE,combobox,1344341251
Control9=IDC_STATIC,static,1476526080
Control10=IDC_ROLL,button,1342275584
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_EDIT2,edit,1350641793
Control20=IDC_EDIT3,edit,1350641793
Control21=IDC_EDIT4,edit,1350641793
Control22=IDC_EDIT5,edit,1350641793
Control23=IDC_EDIT6,edit,1350641793
Control24=IDC_EDIT7,edit,1350641793
Control25=IDC_EDIT8,edit,1350641793
Control26=IDC_EDIT9,edit,1350641793
Control27=IDC_STATIC,static,1342308352
Control28=IDC_DISP,combobox,1344340995

[CLS:CPersonalPage]
Type=0
HeaderFile=CPersonalPage.h
ImplementationFile=CPersonalPage.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_OCC
VirtualFilter=dWC

[DLG:IDD_SKILLS]
Type=1
Class=CSkillPage
ControlCount=9
Control1=IDC_LIST1,listbox,1352728835
Control2=IDC_LIST2,listbox,1352728835
Control3=IDC_ADD,button,1342275584
Control4=IDC_REMOVE,button,1342275584
Control5=IDC_STATIC,static,1342308352
Control6=IDC_OCC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_LIMIT,static,1342308352
Control9=IDC_VIEW,button,1342242816

[CLS:CSkillPage]
Type=0
HeaderFile=CSkillPage.h
ImplementationFile=CSkillPage.cpp
BaseClass=CDialog
Filter=D
LastObject=CSkillPage
VirtualFilter=dWC

[DLG:IDD_FINAL]
Type=1
Class=CFinalPage
ControlCount=9
Control1=IDC_LIST1,SysListView32,1350631453
Control2=IDC_UP,button,1342242816
Control3=IDC_DOWN,button,1342242816
Control4=IDC_VIEWER,button,1073807360
Control5=IDC_NEWSKILL,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_HP,static,1342308353
Control8=IDC_STATIC,static,1342308352
Control9=IDC_LEVEL,static,1342308352

[CLS:CFinalPage]
Type=0
HeaderFile=CFinalPage.h
ImplementationFile=CFinalPage.cpp
BaseClass=CDialog
Filter=D
LastObject=CFinalPage
VirtualFilter=dWC

[CLS:OCCSet]
Type=0
HeaderFile=OCCSet.h
ImplementationFile=OCCSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=OCCSet

[DB:OCCSet]
DB=1
DBType=ODBC
ColumnCount=8
Column1=[OCC], -1, 2147483646
Column2=[OCC Skills], -1, 2147483646
Column3=[Other], -1, 2147483646
Column4=[NumOther], 4, 4
Column5=[NumSecondary], 4, 4
Column6=[MOS], -7, 1
Column7=[Bonus], -1, 2147483646
Column8=[SDC], 4, 4

[CLS:MOSSet]
Type=0
HeaderFile=MOSSet.h
ImplementationFile=MOSSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=MOSSet

[DB:MOSSet]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[MOS], 12, 100
Column2=[Skills], -1, 2147483646
Column3=[Select], -1, 2147483646
Column4=[Bonus], 4, 4
Column5=[Limit], 4, 4

[CLS:SkillSet]
Type=0
HeaderFile=SkillSet.h
ImplementationFile=SkillSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=SkillSet

[DB:SkillSet]
DB=1
DBType=ODBC
ColumnCount=6
Column1=[ID], 4, 4
Column2=[Skill], 12, 100
Column3=[Category], 12, 100
Column4=[Base], 4, 4
Column5=[Experience], 4, 4
Column6=[Keywords], -1, 2147483646

[DB:RaceSet]
DB=1
DBType=ODBC
ColumnCount=25
Column1=[Race], 12, 100
Column2=[IQx], 4, 4
Column3=[IQ+], 4, 4
Column4=[IQx+], 4, 4
Column5=[MEx], 4, 4
Column6=[ME+], 4, 4
Column7=[MEx+], 4, 4
Column8=[MAx], 4, 4
Column9=[MA+], 4, 4
Column10=[MAx+], 4, 4
Column11=[PSx], 4, 4
Column12=[PS+], 4, 4
Column13=[PSx+], 4, 4
Column14=[PPx], 4, 4
Column15=[PP+], 4, 4
Column16=[PPx+], 4, 4
Column17=[PEx], 4, 4
Column18=[PE+], 4, 4
Column19=[PEx+], 4, 4
Column20=[PBx], 4, 4
Column21=[PB+], 4, 4
Column22=[PBx+], 4, 4
Column23=[SPDx], 4, 4
Column24=[SPD+], 4, 4
Column25=[SPDx+], 4, 4

[CLS:BonusSet]
Type=0
HeaderFile=BonusSet.h
ImplementationFile=BonusSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=BonusSet

[DB:BonusSet]
DB=1
DBType=ODBC
ColumnCount=8
Column1=[Score], 4, 4
Column2=[IQ], 4, 4
Column3=[ME], 4, 4
Column4=[MA], 4, 4
Column5=[PS], 4, 4
Column6=[PP], 4, 4
Column7=[PE], 12, 100
Column8=[PB], 4, 4

[DLG:IDD_MOS]
Type=1
Class=CMOSPage
ControlCount=7
Control1=IDC_LIST1,listbox,1352728835
Control2=IDC_ADD2,button,1342275584
Control3=IDC_REMOVE2,button,1342275584
Control4=IDC_LIST2,listbox,1352728835
Control5=IDC_SELECT,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_LIMIT,static,1342308352

[CLS:CMOSPage]
Type=0
HeaderFile=CMOSPage.h
ImplementationFile=CMOSPage.cpp
BaseClass=CDialog
Filter=D
LastObject=CMOSPage
VirtualFilter=dWC

[DLG:IDD_SELECT]
Type=1
Class=CSelectDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_COMBO1,combobox,1344341251

[DB:CRaceSet]
DB=1
DBType=ODBC
ColumnCount=25
Column1=[Race], 12, 100
Column2=[IQx], 4, 4
Column3=[IQ+], 4, 4
Column4=[IQx+], 4, 4
Column5=[MEx], 4, 4
Column6=[ME+], 4, 4
Column7=[MEx+], 4, 4
Column8=[MAx], 4, 4
Column9=[MA+], 4, 4
Column10=[MAx+], 4, 4
Column11=[PSx], 4, 4
Column12=[PS+], 4, 4
Column13=[PSx+], 4, 4
Column14=[PPx], 4, 4
Column15=[PP+], 4, 4
Column16=[PPx+], 4, 4
Column17=[PEx], 4, 4
Column18=[PE+], 4, 4
Column19=[PEx+], 4, 4
Column20=[PBx], 4, 4
Column21=[PB+], 4, 4
Column22=[PBx+], 4, 4
Column23=[SPDx], 4, 4
Column24=[SPD+], 4, 4
Column25=[SPDx+], 4, 4

[CLS:RaceSet]
Type=0
HeaderFile=RaceSet.h
ImplementationFile=RaceSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=RaceSet

[CLS:CSelectDlg]
Type=0
HeaderFile=CSelectDlg.h
ImplementationFile=CSelectDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSelectDlg
VirtualFilter=dWC

[CLS:CSplashWnd]
Type=0
HeaderFile=CSplash.h
ImplementationFile=CSplash.cpp
BaseClass=CWnd

[CLS:CExtra]
Type=0
HeaderFile=CExtra.h
ImplementationFile=CExtra.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CExtra

[DB:CExtra]
DB=1
DBType=ODBC
ColumnCount=2
Column1=[ID], 4, 4
Column2=[Info], -1, 2147483646

