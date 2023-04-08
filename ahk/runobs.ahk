; 启动 cmd 并输入指令 --minimize-to-tray
arg1 := A_Args[1]

Run, cmd.exe /k start /d "%arg1%" obs64.exe --startstreaming& exit, ,Hide

