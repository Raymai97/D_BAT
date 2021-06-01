@echo off
setlocal enableDelayedExpansion
color 0f
call :menuInit 10 Apple Ball Croc Dagger Egg Fish Girl Hospital "Ice Cream" Jellyfish
cls
echo.
echo. --- D_Demo --- Press UP/DOWN/ENTER, or ESC to quit ---
echo.
:a
DCls 3
call :menuDisp
echo.
DKey
if %errorlevel% == 40 call :menuSelNext & goto a
if %errorlevel% == 38 call :menuSelPrev & goto a
if %errorlevel% == 27 exit/b
if %errorlevel% == 13 goto b
goto a

:b
DCls 1e
echo. Selected item %iMenuSel% which is "!menuItem%iMenuSel%!".
goto a

:menuInit
set a=0
set nMenuItem=%~1
set iMenuSel=1
:_menuInit_
set /a a=a+1
shift /1
set menuItem%a%=%~1
set "menuItemSel%a%= "
if not "%a%"=="%nMenuItem%" goto _menuInit_
exit/b

:menuDisp
set a=0
:_menuDisp_
set /a a=a+1
set "menuItemSel%a%= "
if not "%a%"=="%nMenuItem%" goto _menuDisp_
set a=0
set "menuItemSel%iMenuSel%=>"
:_menuDisp__
set /a a=a+1
if "%a%"=="%iMenuSel%" ( DColor f0 ) else ( DColor 0f )
echo. !menuItemSel%a%! !menuItem%a%!
if not "%a%"=="%nMenuItem%" goto _menuDisp__
exit/b

:menuSelPrev
set /a iMenuSel=iMenuSel-1
if %iMenuSel% LSS 1 set iMenuSel=%nMenuItem%
exit/b

:menuSelNext
set /a iMenuSel=iMenuSel+1
if %iMenuSel% GTR %nMenuItem% set iMenuSel=1
exit/b
