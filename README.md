## 06/22/2024
Getting error due to EXC_BAD_ACCESS (code=2, address=0x100003f9c) (from LLDB), looks like it may have to do with alignment?
Using lea rsi, [rel message] in place of rsi line works, but trying to use mov rsi does not. Linked gives morning that alignment of 4 is too small, but why would that be the case if the message is only one byte?

## 06/23/2024
Restored error by using lea instead of rsi - looks like the root of the error was that the memory *address* needs to be passed to the register, rather than the value of the var itself. In future, can look for syscall argument descriptions using "man 2 {syscall name}"

## 07/11/2024
After learning some material about how CPU architecture, I understand some of the context for using "lea rsi, [rel message]". [rel message] is meant to get the address of the message *relative* to the instruction pointer, since macOS binaries use position-independent code (PCI), which expects addresses to be relative to wherever the IP is.

What I noticed is that changing "lea rsi, [rel message]" to "mov rsi, [rel message]" allows the program to compile and run, but nothing is printed out. I will have to do more research as to why that is later.

## 07/21/2024
LEA will move operands (which should represent addresses) to the specified register *without* dereferencing the address. MOV will attempt to dereference the address.

So when using "mov rsi, [rel message]", we were storing the data referenced by message's address in RSI, which is not what is required by the WRITE syscall's specification. This resulted in a blank message, either because the data at that faulty memory location was blank or junk that wasn't able to be printed out correctly.