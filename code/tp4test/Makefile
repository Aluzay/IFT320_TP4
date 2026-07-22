# use normal make for this Makefile
#
# Makefile for building user programs to run on top of Nachos
#
# Several things to be aware of:
#
#    Nachos assumes that the location of the program startup routine (the
# 	location the kernel jumps to when the program initially starts up)
#       is at location 0.  This means: start.o must be the first .o passed 
# 	to ld, in order for the routine "Start" to be loaded at location 0
#

# if you are cross-compiling, you need to point to the right executables
# and change the flags to ld and the build procedure for as

#GCCDIR = /opt/mips/decstation-ultrix/bin/
##GCCDIR = /home/ubuntu/NachosLinuxUdes.dev/gnu-decstation-ultrix/decstation-ultrix/2.95.3/
##LDFLAGS = -T script -N
##ASFLAGS = 
##CPPFLAGS = $(INCDIR)


# if you aren't cross-compiling:
#GCCDIR = 
#LDFLAGS = -N -T 0
#ASFLAGS =
#CPPFLAGS = -P $(INCDIR)


##CC = $(GCCDIR)gcc
##AS = $(GCCDIR)as
##LD = $(GCCDIR)ld

##CPP = /usr/bin/cpp
INCDIR =-I../userprog -I../threads
#CFLAGS = -G 0 -c $(INCDIR)
#CFLAGS = -g -Wall -Wshadow -traditional $(INCPATH) $(DEFINES) $(HOST) -DCHANGED
##CFLAGS = -c $(INCDIR)
#
GCCDIR = ../../../gnu-decstation-ultrix/decstation-ultrix/2.95.3/

LDFLAGS = -T script -N
ASFLAGS = -mips2
CPPFLAGS = $(INCDIR)

# if you aren't cross-compiling:
# GCCDIR =
# LDFLAGS = -N -T 0
# ASFLAGS =
# CPPFLAGS = -P $(INCDIR)

PATH = $(GCCDIR):/lib:/usr/bin:/bin

CC = $(GCCDIR)gcc -B../../../gnu-decstation-ultrix/
AS = $(GCCDIR)as
LD = $(GCCDIR)ld

CPP = gcc -E
#INCDIR =-I../userprog -I../threads
CFLAGS = -G 0 -c $(INCDIR)

#
all: ExitTest LogTest CreateTest OpenWriteTest ReadLogTest ReadWriteTest ExecTest \
SubExecTest YieldTest YieldTest2 SubYieldTest2 JoinTest SubJoinTest SubJoinTest2 \
SubJoinTest3 SubJoinTest4 SubJoinTest5 MiniJoinTest SubMiniJoinTest FullTest \
SubFullTest SubFullTest2 PriorityTest SubPriorityTest SubPriorityTest2 Bouclalinfini \
RobinTest SubRobinTest SubRobinTest2 SubRobinTest3 HrnTest SubHrnTest SubHrnTest2 SubHrnTest3 \
ErrorTest1 ErrorTest2 ErrorTest3 PrimeTest SubPrimeTest SwapTest SqrtTest SuperPrimeTest \
SubSuperPrimeTest SuperSqrtTest


clean: 
	rm -f *.o
	rm -f *.coff
	rm -f ExitTest
	rm -f LogTest
	rm -f CreateTest
	rm -f OpenWriteTest
	rm -f ReadLogTest
	rm -f ReadWriteTest
	rm -f ExecTest
	rm -f SubExecTest
	rm -f YieldTest
	rm -f SubYieldTest
	rm -f JoinTest
	rm -f SubJoinTest
	rm -f SubJoinTest2
	rm -f SubJoinTest3
	rm -f SubJoinTest4
	rm -f SubJoinTest5
	rm -f MiniJoinTest
	rm -f SubMiniJoinTest
	rm -f FullTest
	rm -f SubFullTest
	rm -f SubFullTest2
	rm -f PriorityTest
	rm -f SubPriorityTest
	rm -f SubPriorityTest2
	rm -f Bouclalinfini
	rm -f HrnTest
	rm -f SubHrnTest
	rm -f SubHrnTest2
	rm -f SubHrnTest3
	rm -f RobinTest
	rm -f SubRobinTest
	rm -f SubRobinTest2
	rm -f SubRobinTest3
	rm -f ErrorTest1
	rm -f ErrorTest2
	rm -f ErrorTest3
	rm -f PrimeTest
	rm -f SubPrimeTest
	rm -f SwapTest
	rm -f SqrtTest
	rm -f SuperPrimeTest
	rm -f SubSuperPrimeTest
	rm -f SubSqrtTest
		
start.o: start.s 
	$(CPP) $(CPPFLAGS) start.c > strt.s
	$(AS) $(ASFLAGS) -o start.o strt.s
	rm strt.s

ExitTest.o: ExitTest.c
	$(CC) $(CFLAGS) -c ExitTest.c
ExitTest: ExitTest.o start.o
	$(LD) $(LDFLAGS) start.o ExitTest.o -o ExitTest.coff
	./coff2noff ExitTest.coff ExitTest
	rm -f ExitTest.coff
	
	
LogTest.o: LogTest.c
	$(CC) $(CFLAGS) -c LogTest.c
LogTest: LogTest.o start.o
	$(LD) $(LDFLAGS) start.o LogTest.o -o LogTest.coff
	./coff2noff LogTest.coff LogTest
	rm -f LogTest.coff

CreateTest.o: CreateTest.c
	$(CC) $(CFLAGS) -c CreateTest.c
CreateTest: CreateTest.o start.o
	$(LD) $(LDFLAGS) start.o CreateTest.o -o CreateTest.coff
	./coff2noff CreateTest.coff CreateTest
	rm -f CreateTest.coff
	
OpenWriteTest.o: OpenWriteTest.c
	$(CC) $(CFLAGS) -c OpenWriteTest.c
OpenWriteTest: OpenWriteTest.o start.o
	$(LD) $(LDFLAGS) start.o OpenWriteTest.o -o OpenWriteTest.coff
	./coff2noff OpenWriteTest.coff OpenWriteTest
	rm -f OpenWriteTest.coff
	
ReadLogTest.o: ReadLogTest.c
	$(CC) $(CFLAGS) -c ReadLogTest.c
ReadLogTest: ReadLogTest.o start.o
	$(LD) $(LDFLAGS) start.o ReadLogTest.o -o ReadLogTest.coff
	./coff2noff ReadLogTest.coff ReadLogTest
	rm -f ReadLogTest.coff

ReadWriteTest.o: ReadWriteTest.c
	$(CC) $(CFLAGS) -c ReadWriteTest.c
ReadWriteTest: ReadWriteTest.o start.o
	$(LD) $(LDFLAGS) start.o ReadWriteTest.o -o ReadWriteTest.coff
	./coff2noff ReadWriteTest.coff ReadWriteTest
	rm -f ReadWriteTest.coff

ExecTest.o: ExecTest.c
	$(CC) $(CFLAGS) -c ExecTest.c
ExecTest: ExecTest.o start.o
	$(LD) $(LDFLAGS) start.o ExecTest.o -o ExecTest.coff
	./coff2noff ExecTest.coff ExecTest
	rm -f ExecTest.coff
	
SubExecTest.o: SubExecTest.c
	$(CC) $(CFLAGS) -c SubExecTest.c
SubExecTest: SubExecTest.o start.o
	$(LD) $(LDFLAGS) start.o SubExecTest.o -o SubExecTest.coff
	./coff2noff SubExecTest.coff SubExecTest
	rm -f SubExecTest.coff
	
	
YieldTest.o: YieldTest.c
	$(CC) $(CFLAGS) -c YieldTest.c
YieldTest: YieldTest.o start.o
	$(LD) $(LDFLAGS) start.o YieldTest.o -o YieldTest.coff
	./coff2noff YieldTest.coff YieldTest
	rm -f YieldTest.coff
	
YieldTest2.o: YieldTest2.c
	$(CC) $(CFLAGS) -c YieldTest2.c
YieldTest2: YieldTest2.o start.o
	$(LD) $(LDFLAGS) start.o YieldTest2.o -o YieldTest2.coff
	./coff2noff YieldTest2.coff YieldTest2
	rm -f YieldTest2.coff
	
SubYieldTest2.o: SubYieldTest2.c
	$(CC) $(CFLAGS) -c SubYieldTest2.c
SubYieldTest2: SubYieldTest2.o start.o
	$(LD) $(LDFLAGS) start.o SubYieldTest2.o -o SubYieldTest2.coff
	./coff2noff SubYieldTest2.coff SubYieldTest2
	rm -f SubYieldTest2.coff
	
JoinTest.o: JoinTest.c
	$(CC) $(CFLAGS) -c JoinTest.c
JoinTest: JoinTest.o start.o
	$(LD) $(LDFLAGS) start.o JoinTest.o -o JoinTest.coff
	./coff2noff JoinTest.coff JoinTest
	rm -f JoinTest.coff
	
SubJoinTest.o: SubJoinTest.c
	$(CC) $(CFLAGS) -c SubJoinTest.c
SubJoinTest: SubJoinTest.o start.o
	$(LD) $(LDFLAGS) start.o SubJoinTest.o -o SubJoinTest.coff
	./coff2noff SubJoinTest.coff SubJoinTest
	rm -f SubJoinTest.coff
	
SubJoinTest2.o: SubJoinTest2.c
	$(CC) $(CFLAGS) -c SubJoinTest2.c
SubJoinTest2: SubJoinTest2.o start.o
	$(LD) $(LDFLAGS) start.o SubJoinTest2.o -o SubJoinTest2.coff
	./coff2noff SubJoinTest2.coff SubJoinTest2
	rm -f SubJoinTest2.coff
	
SubJoinTest3.o: SubJoinTest3.c
	$(CC) $(CFLAGS) -c SubJoinTest3.c
SubJoinTest3: SubJoinTest3.o start.o
	$(LD) $(LDFLAGS) start.o SubJoinTest3.o -o SubJoinTest3.coff
	./coff2noff SubJoinTest3.coff SubJoinTest3
	rm -f SubJoinTest3.coff
	
SubJoinTest4.o: SubJoinTest4.c
	$(CC) $(CFLAGS) -c SubJoinTest4.c
SubJoinTest4: SubJoinTest4.o start.o
	$(LD) $(LDFLAGS) start.o SubJoinTest4.o -o SubJoinTest4.coff
	./coff2noff SubJoinTest4.coff SubJoinTest4
	rm -f SubJoinTest4.coff
	
SubJoinTest5.o: SubJoinTest5.c
	$(CC) $(CFLAGS) -c SubJoinTest5.c
SubJoinTest5: SubJoinTest5.o start.o
	$(LD) $(LDFLAGS) start.o SubJoinTest5.o -o SubJoinTest5.coff
	./coff2noff SubJoinTest5.coff SubJoinTest5
	rm -f SubJoinTest5.coff
	
MiniJoinTest.o: MiniJoinTest.c
	$(CC) $(CFLAGS) -c MiniJoinTest.c
MiniJoinTest: MiniJoinTest.o start.o
	$(LD) $(LDFLAGS) start.o MiniJoinTest.o -o MiniJoinTest.coff
	./coff2noff MiniJoinTest.coff MiniJoinTest
	rm -f MiniJoinTest.coff
	
SubMiniJoinTest.o: SubMiniJoinTest.c
	$(CC) $(CFLAGS) -c SubMiniJoinTest.c
SubMiniJoinTest: SubMiniJoinTest.o start.o
	$(LD) $(LDFLAGS) start.o SubMiniJoinTest.o -o SubMiniJoinTest.coff
	./coff2noff SubMiniJoinTest.coff SubMiniJoinTest
	rm -f SubMiniJoinTest.coff
	
FullTest.o: FullTest.c
	$(CC) $(CFLAGS) -c FullTest.c
FullTest: FullTest.o start.o
	$(LD) $(LDFLAGS) start.o FullTest.o -o FullTest.coff
	./coff2noff FullTest.coff FullTest
	rm -f FullTest.coff
	
SubFullTest.o: SubFullTest.c
	$(CC) $(CFLAGS) -c SubFullTest.c
SubFullTest: SubFullTest.o start.o
	$(LD) $(LDFLAGS) start.o SubFullTest.o -o SubFullTest.coff
	./coff2noff SubFullTest.coff SubFullTest
	rm -f SubFullTest.coff
	
SubFullTest2.o: SubFullTest2.c
	$(CC) $(CFLAGS) -c SubFullTest2.c
SubFullTest2: SubFullTest2.o start.o
	$(LD) $(LDFLAGS) start.o SubFullTest2.o -o SubFullTest2.coff
	./coff2noff SubFullTest2.coff SubFullTest2
	rm -f SubFullTest2.coff
	
PriorityTest.o: PriorityTest.c
	$(CC) $(CFLAGS) -c PriorityTest.c
PriorityTest: PriorityTest.o start.o
	$(LD) $(LDFLAGS) start.o PriorityTest.o -o PriorityTest.coff
	./coff2noff PriorityTest.coff PriorityTest
	rm -f PriorityTest.coff
	
SubPriorityTest.o: SubPriorityTest.c
	$(CC) $(CFLAGS) -c SubPriorityTest.c
SubPriorityTest: SubPriorityTest.o start.o
	$(LD) $(LDFLAGS) start.o SubPriorityTest.o -o SubPriorityTest.coff
	./coff2noff SubPriorityTest.coff SubPriorityTest
	rm -f SubPriorityTest.coff
	
SubPriorityTest2.o: SubPriorityTest2.c
	$(CC) $(CFLAGS) -c SubPriorityTest2.c
SubPriorityTest2: SubPriorityTest2.o start.o
	$(LD) $(LDFLAGS) start.o SubPriorityTest2.o -o SubPriorityTest2.coff
	./coff2noff SubPriorityTest2.coff SubPriorityTest2
	rm -f SubPriorityTest2.coff
	
RobinTest.o: RobinTest.c
	$(CC) $(CFLAGS) -c RobinTest.c
RobinTest: RobinTest.o start.o
	$(LD) $(LDFLAGS) start.o RobinTest.o -o RobinTest.coff
	./coff2noff RobinTest.coff RobinTest
	rm -f RobinTest.coff
	
Bouclalinfini.o: Bouclalinfini.c
	$(CC) $(CFLAGS) -c Bouclalinfini.c
Bouclalinfini: Bouclalinfini.o start.o
	$(LD) $(LDFLAGS) start.o Bouclalinfini.o -o Bouclalinfini.coff
	./coff2noff Bouclalinfini.coff Bouclalinfini
	rm -f Bouclalinfini.coff

SubRobinTest.o: SubRobinTest.c
	$(CC) $(CFLAGS) -c SubRobinTest.c
SubRobinTest: SubRobinTest.o start.o
	$(LD) $(LDFLAGS) start.o SubRobinTest.o -o SubRobinTest.coff
	./coff2noff SubRobinTest.coff SubRobinTest
	rm -f SubRobinTest.coff
	
SubRobinTest2.o: SubRobinTest2.c
	$(CC) $(CFLAGS) -c SubRobinTest2.c
SubRobinTest2: SubRobinTest2.o start.o
	$(LD) $(LDFLAGS) start.o SubRobinTest2.o -o SubRobinTest2.coff
	./coff2noff SubRobinTest2.coff SubRobinTest2
	rm -f SubRobinTest2.coff
	
SubRobinTest3.o: SubRobinTest3.c
	$(CC) $(CFLAGS) -c SubRobinTest3.c
SubRobinTest3: SubRobinTest3.o start.o
	$(LD) $(LDFLAGS) start.o SubRobinTest3.o -o SubRobinTest3.coff
	./coff2noff SubRobinTest3.coff SubRobinTest3
	rm -f SubRobinTest3.coff
	
HrnTest.o: HrnTest.c
	$(CC) $(CFLAGS) -c HrnTest.c
HrnTest: HrnTest.o start.o
	$(LD) $(LDFLAGS) start.o HrnTest.o -o HrnTest.coff
	./coff2noff HrnTest.coff HrnTest
	rm -f HrnTest.coff
	
SubHrnTest.o: SubHrnTest.c
	$(CC) $(CFLAGS) -c SubHrnTest.c
SubHrnTest: SubHrnTest.o start.o
	$(LD) $(LDFLAGS) start.o SubHrnTest.o -o SubHrnTest.coff
	./coff2noff SubHrnTest.coff SubHrnTest
	rm -f SubHrnTest.coff

SubHrnTest2.o: SubHrnTest2.c
	$(CC) $(CFLAGS) -c SubHrnTest2.c
SubHrnTest2: SubHrnTest2.o start.o
	$(LD) $(LDFLAGS) start.o SubHrnTest2.o -o SubHrnTest2.coff
	./coff2noff SubHrnTest2.coff SubHrnTest2
	rm -f SubHrnTest2.coff
	
SubHrnTest3.o: SubHrnTest3.c
	$(CC) $(CFLAGS) -c SubHrnTest3.c
SubHrnTest3: SubHrnTest3.o start.o
	$(LD) $(LDFLAGS) start.o SubHrnTest3.o -o SubHrnTest3.coff
	./coff2noff SubHrnTest3.coff SubHrnTest3
	rm -f SubHrnTest3.coff
	
ErrorTest1.o: ErrorTest1.c
	$(CC) $(CFLAGS) -c ErrorTest1.c
ErrorTest1: ErrorTest1.o start.o
	$(LD) $(LDFLAGS) start.o ErrorTest1.o -o ErrorTest1.coff
	./coff2noff ErrorTest1.coff ErrorTest1
	rm -f ErrorTest1.coff
	
ErrorTest2.o: ErrorTest2.c
	$(CC) $(CFLAGS) -c ErrorTest2.c
ErrorTest2: ErrorTest2.o start.o
	$(LD) $(LDFLAGS) start.o ErrorTest2.o -o ErrorTest2.coff
	./coff2noff ErrorTest2.coff ErrorTest2
	rm -f ErrorTest2.coff
	
ErrorTest3.o: ErrorTest3.c
	$(CC) $(CFLAGS) -c ErrorTest3.c
ErrorTest3: ErrorTest3.o start.o
	$(LD) $(LDFLAGS) start.o ErrorTest3.o -o ErrorTest3.coff
	./coff2noff ErrorTest3.coff ErrorTest3
	rm -f ErrorTest3.coff
	
PrimeTest.o: PrimeTest.c
	$(CC) $(CFLAGS) -c PrimeTest.c
PrimeTest: PrimeTest.o start.o
	$(LD) $(LDFLAGS) start.o PrimeTest.o -o PrimeTest.coff
	./coff2noff PrimeTest.coff PrimeTest
	rm -f PrimeTest.coff
	
SubPrimeTest.o: SubPrimeTest.c
	$(CC) $(CFLAGS) -c SubPrimeTest.c
SubPrimeTest: SubPrimeTest.o start.o
	$(LD) $(LDFLAGS) start.o SubPrimeTest.o -o SubPrimeTest.coff
	./coff2noff SubPrimeTest.coff SubPrimeTest
	rm -f SubPrimeTest.coff
	
SwapTest.o: SwapTest.c
	$(CC) $(CFLAGS) -c SwapTest.c
SwapTest: SwapTest.o start.o
	$(LD) $(LDFLAGS) start.o SwapTest.o -o SwapTest.coff
	./coff2noff SwapTest.coff SwapTest
	rm -f SwapTest.coff
	
SqrtTest.o: SqrtTest.c
	$(CC) $(CFLAGS) -c SqrtTest.c
SqrtTest: SqrtTest.o start.o
	$(LD) $(LDFLAGS) start.o SqrtTest.o -o SqrtTest.coff
	./coff2noff SqrtTest.coff SqrtTest
	rm -f SqrtTest.coff

SuperPrimeTest.o: SuperPrimeTest.c
	$(CC) $(CFLAGS) -c SuperPrimeTest.c
SuperPrimeTest: SuperPrimeTest.o start.o
	$(LD) $(LDFLAGS) start.o SuperPrimeTest.o -o SuperPrimeTest.coff
	./coff2noff SuperPrimeTest.coff SuperPrimeTest
	rm -f SuperPrimeTest.coff
	
SuperSqrtTest.o: SuperSqrtTest.c
	$(CC) $(CFLAGS) -c SuperSqrtTest.c
SuperSqrtTest: SuperSqrtTest.o start.o
	$(LD) $(LDFLAGS) start.o SuperSqrtTest.o -o SuperSqrtTest.coff
	./coff2noff SuperSqrtTest.coff SuperSqrtTest
	rm -f SuperSqrtTest.coff

SubSuperPrimeTest.o: SubSuperPrimeTest.c
	$(CC) $(CFLAGS) -c SubSuperPrimeTest.c
SubSuperPrimeTest: SubSuperPrimeTest.o start.o
	$(LD) $(LDFLAGS) start.o SubSuperPrimeTest.o -o SubSuperPrimeTest.coff
	./coff2noff SubSuperPrimeTest.coff SubSuperPrimeTest
	rm -f SubSuperPrimeTest.coff	
