# 1 "start.s"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "start.s"
# 10 "start.s"
# 1 "/usr/include/syscall.h" 1 3 4
# 1 "/usr/include/i386-linux-gnu/sys/syscall.h" 1 3 4
# 24 "/usr/include/i386-linux-gnu/sys/syscall.h" 3 4
# 1 "/usr/include/i386-linux-gnu/asm/unistd.h" 1 3 4







# 1 "/usr/include/i386-linux-gnu/asm/unistd_32.h" 1 3 4
# 9 "/usr/include/i386-linux-gnu/asm/unistd.h" 2 3 4
# 25 "/usr/include/i386-linux-gnu/sys/syscall.h" 2 3 4






# 1 "/usr/include/i386-linux-gnu/bits/syscall.h" 1 3 4
# 32 "/usr/include/i386-linux-gnu/sys/syscall.h" 2 3 4
# 1 "/usr/include/syscall.h" 2 3 4
# 11 "start.s" 2

        .text
        .align 2
# 24 "start.s"
 .globl __start
 .ent __start
__start:
 jal main
 move $4,$0
 jal Exit
 .end __start
# 45 "start.s"
 .globl Halt
 .ent Halt
Halt:
 addiu $2,$0,SC_Halt
 syscall
 j $31
 .end Halt

 .globl Exit
 .ent Exit
Exit:
 addiu $2,$0,SC_Exit
 syscall
 j $31
 .end Exit

 .globl Exec
 .ent Exec
Exec:
 addiu $2,$0,SC_Exec
 syscall
 j $31
 .end Exec

 .globl Join
 .ent Join
Join:
 addiu $2,$0,SC_Join
 syscall
 j $31
 .end Join

 .globl Create
 .ent Create
Create:
 addiu $2,$0,SC_Create
 syscall
 j $31
 .end Create

 .globl Open
 .ent Open
Open:
 addiu $2,$0,SC_Open
 syscall
 j $31
 .end Open

 .globl Read
 .ent Read
Read:
 addiu $2,$0,SC_Read
 syscall
 j $31
 .end Read

 .globl Write
 .ent Write
Write:
 addiu $2,$0,SC_Write
 syscall
 j $31
 .end Write

 .globl Close
 .ent Close
Close:
 addiu $2,$0,SC_Close
 syscall
 j $31
 .end Close

 .globl Fork
 .ent Fork
Fork:
 addiu $2,$0,SC_Fork
 syscall
 j $31
 .end Fork

 .globl Yield
 .ent Yield
Yield:
 addiu $2,$0,SC_Yield
 syscall
 j $31
 .end Yield


        .globl __main
        .ent __main
__main:
        j $31
        .end __main
