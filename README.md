## 06/22/2024
Getting error due to EXC_BAD_ACCESS (code=2, address=0x100003f9c) (from LLDB), looks like it may have to do with alignment?
Using lea rsi, [rel message] in place of rsi line works, but trying to use mov rsi does not. Linked gives morning that alignment of 4 is too small, but why would that be the case if the message is only one byte?