lldb ./minish_alb "<< 1 cat"

ME informa de : 
settings set -- target.run-args  "<< 1 cat"

b main_cli_alb.c:144      // esto permite que se pare el debug en esta linea

process launch

al pulsar CTRL+\ me imprime

```sh
Stack dump:
0.	Program arguments: /Library/Developer/CommandLineTools/usr/bin/lldb ./minish_alb << 1 cat
0  lldb                     0x000000010dca8575 llvm::sys::PrintStackTrace(llvm::raw_ostream&) + 37
1  lldb                     0x000000010dca7b55 llvm::sys::RunSignalHandlers() + 85
2  lldb                     0x000000010dca8dd6 SignalHandler(int) + 262
3  libsystem_platform.dylib 0x00007fff6adb75fd _sigtramp + 29
4  libsystem_platform.dylib 0x000000010dcef080 _sigtramp + 18446603343250029216
5  LLDB                     0x000000011178cd01 IOHandlerProcessSTDIO::Run() + 497
6  LLDB                     0x00000001115e5cf9 lldb_private::Debugger::ExecuteIOHandlers() + 105
7  LLDB                     0x00000001116c06cc lldb_private::CommandInterpreter::RunCommandInterpreter(bool, bool, lldb_private::CommandInterpreterRunOptions&) + 156
8  LLDB                     0x000000011143b695 lldb::SBDebugger::RunCommandInterpreter(bool, bool) + 469
9  lldb                     0x000000010dc91517 Driver::MainLoop() + 2679
10 lldb                     0x000000010dc92c01 main + 1681
11 libdyld.dylib            0x00007fff6abbecc9 start + 1
12 libdyld.dylib            0x0000000000000003 start + 18446603338725462843
```
