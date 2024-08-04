global _start

section __TEXT,__text

_start:
    mov rax, op1
    ;add rax, op2

section __DATA,__data
    op1 equ 1
    ;op2 DB 2
