; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRotateDrawDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "rotateDraw.h"

ClassCount=3
Class1=CRotateDrawApp
Class2=CRotateDrawDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_ROTATEDRAW_DIALOG

[CLS:CRotateDrawApp]
Type=0
HeaderFile=rotateDraw.h
ImplementationFile=rotateDraw.cpp
Filter=N

[CLS:CRotateDrawDlg]
Type=0
HeaderFile=rotateDrawDlg.h
ImplementationFile=rotateDrawDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDOK

[CLS:CAboutDlg]
Type=0
HeaderFile=rotateDrawDlg.h
ImplementationFile=rotateDrawDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ROTATEDRAW_DIALOG]
Type=1
Class=CRotateDrawDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDC_ANGLE,edit,1350639744
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,button,1342177287
Control5=IDC_SHAPE_RECTANGLE,button,1342308361
Control6=IDC_SHAPE_ELLIPSE,button,1342177289
Control7=IDC_STATIC_DRAW,button,1073741831
Control8=IDC_BTN_UPDATE,button,1342242816

