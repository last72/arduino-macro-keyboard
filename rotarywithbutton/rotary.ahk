#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.


; Cheatsheet
; #: Win
; !: Alt
; ^: Ctrl
; +: Shift


F15 & 1::
Send, {Right}
Return

F15 & 2::
Send, {Left}
Return

F15 & 3:: 
Send, {Enter}
Return

; ^+F11::
; ExitApp
