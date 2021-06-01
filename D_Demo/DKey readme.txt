DKey returns VK Code by process exit code, when a key is pressed.

----- Example Code -----
@echo off
:a
DKey
if %errorlevel% == 37 echo LEFT & goto a
if %errorlevel% == 39 echo RIGHT & goto a
if %errorlevel% == 38 echo UP & goto a
if %errorlevel% == 40 echo DOWN & goto a
if %errorlevel% == 13 echo ENTER & goto a
goto a
----- End Example Code -----
