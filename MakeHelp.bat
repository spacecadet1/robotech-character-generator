@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by ROBOTECH.HPJ. >"hlp\Robotech.hm"
echo. >>"hlp\Robotech.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\Robotech.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\Robotech.hm"
echo. >>"hlp\Robotech.hm"
echo // Prompts (IDP_*) >>"hlp\Robotech.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\Robotech.hm"
echo. >>"hlp\Robotech.hm"
echo // Resources (IDR_*) >>"hlp\Robotech.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\Robotech.hm"
echo. >>"hlp\Robotech.hm"
echo // Dialogs (IDD_*) >>"hlp\Robotech.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\Robotech.hm"
echo. >>"hlp\Robotech.hm"
echo // Frame Controls (IDW_*) >>"hlp\Robotech.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\Robotech.hm"
REM -- Make help for Project ROBOTECH


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\Robotech.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\Robotech.hlp" goto :Error
if not exist "hlp\Robotech.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\Robotech.hlp" Debug
if exist Debug\nul copy "hlp\Robotech.cnt" Debug
if exist Release\nul copy "hlp\Robotech.hlp" Release
if exist Release\nul copy "hlp\Robotech.cnt" Release
echo.
goto :done

:Error
echo hlp\Robotech.hpj(1) : error: Problem encountered creating help file

:done
echo.
