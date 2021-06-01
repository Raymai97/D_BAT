DColor works like "color" command but doesn't change color of existing printed characters.

----- Example Code -----
@echo off
cls
DColor a0
set/p =Hello <nul
DColor b0
set/p =World <nul
DColor c0
set/p =with <nul
DColor df
set/p =DColor <nul
DColor e0
set/p =in <nul
DColor f0
echo BAT
pause
----- End Example Code -----
