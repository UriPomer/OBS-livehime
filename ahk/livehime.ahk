#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.
SysGet, VirtualHeight, 79
SysGet, VirtualWidth, 78

__ImageFilePath:="./2.png"
gui,add,picture,hwnd__mypic,%__ImageFilePath%
if FileExist(__ImageFilePath){
    controlgetpos,,,__img_w,__img_h,,ahk_id %__mypic%
    CoordMode Pixel
    ImageSearch, __FoundX, __FoundY, 0, 0, VirtualWidth, VirtualHeight,%__ImageFilePath%
    CoordMode Mouse
    PicX:=__FoundX + __img_w/2
    PicY:=__FoundY + __img_h/2
    if (ErrorLevel=0) {
        MouseGetPos, NowX, NowY
        CoordMode, Mouse , Screen
        __ClickX:=PicX
        __ClickY:=PicY
        __ClickTimes:=2
        Click %__ClickX%, %__ClickY%, %__ClickTimes%
        __ClickX:=NowX
        __ClickY:=NowY
        __ClickTimes:=0
        Click %__ClickX%, %__ClickY%, %__ClickTimes%
    } else {
    }
} else {
}
sleep, 600
__ImageFilePath:="./3.png"
gui,add,picture,hwnd__mypic,%__ImageFilePath%
if FileExist(__ImageFilePath){
    controlgetpos,,,__img_w,__img_h,,ahk_id %__mypic%
    CoordMode Pixel
    ImageSearch, __FoundX, __FoundY, 0, 0, VirtualWidth, VirtualHeight,%__ImageFilePath%
    CoordMode Mouse
    PicX:=__FoundX + __img_w/2
    PicY:=__FoundY + __img_h/2
    if (ErrorLevel=0) {
        MouseGetPos, NowX, NowY
        CoordMode, Mouse , Screen
        __ClickX:=PicX
        __ClickY:=PicY
        __ClickTimes:=2
        Click %__ClickX%, %__ClickY%, %__ClickTimes%
        __ClickX:=NowX
        __ClickY:=NowY
        __ClickTimes:=0
        Click %__ClickX%, %__ClickY%, %__ClickTimes%
    } else {
    }
} else {
}
ExitApp