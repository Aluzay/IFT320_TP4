# NOTE: this is a GNU Makefile.  You must use "gmake" rather than "make".
#
# Makefile for the threads assignment.  The threads assignment must
#  be done first!
#
# Copyright (c) 1992 The Regents of the University of California.
# All rights reserved.  See copyright.h for copyright notice and limitation 
# of liability and disclaimer of warranty provisions.

DEFINES = -DTHREADS
INCPATH = -I../threads -I../machine
HFILES = $(THREAD_H)
CFILES = $(THREAD_C)
C_OFILES = $(THREAD_O)

include ../Makefile.common
include ../Makefile.dep
#-----------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend uses it
# DEPENDENCIES MUST END AT END OF FILE
main.o: ../threads/main.cc ../threads/copyright.h ../threads/utility.h \
  ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdio.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdarg.h \
  /usr/include/sys/feature_tests.h /usr/include/sys/ccompile.h \
  /usr/include/sys/isa_defs.h /usr/include/iso/stdio_iso.h \
  /usr/include/sys/va_list.h /usr/include/stdio_tag.h \
  /usr/include/stdio_impl.h /usr/include/iso/stdio_c99.h \
  /usr/include/string.h /usr/include/iso/string_iso.h ../threads/system.h \
  ../threads/thread.h ../threads/scheduler.h ../threads/list.h \
  ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
  ../machine/timer.h ../threads/utility.h
list.o: ../threads/list.cc ../threads/copyright.h ../threads/list.h \
  ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
  ../threads/copyright.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdio.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdarg.h \
  /usr/include/sys/feature_tests.h /usr/include/sys/ccompile.h \
  /usr/include/sys/isa_defs.h /usr/include/iso/stdio_iso.h \
  /usr/include/sys/va_list.h /usr/include/stdio_tag.h \
  /usr/include/stdio_impl.h /usr/include/iso/stdio_c99.h \
  /usr/include/string.h /usr/include/iso/string_iso.h
scheduler.o: ../threads/scheduler.cc ../threads/copyright.h \
  ../threads/scheduler.h ../threads/list.h ../threads/utility.h \
  ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdio.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdarg.h \
  /usr/include/sys/feature_tests.h /usr/include/sys/ccompile.h \
  /usr/include/sys/isa_defs.h /usr/include/iso/stdio_iso.h \
  /usr/include/sys/va_list.h /usr/include/stdio_tag.h \
  /usr/include/stdio_impl.h /usr/include/iso/stdio_c99.h \
  /usr/include/string.h /usr/include/iso/string_iso.h ../threads/thread.h \
  ../threads/system.h ../machine/interrupt.h ../threads/list.h \
  ../machine/stats.h ../machine/timer.h ../threads/utility.h
synch.o: ../threads/synch.cc ../threads/copyright.h ../threads/synch.h \
  ../threads/thread.h ../threads/utility.h ../threads/bool.h \
  ../machine/sysdep.h ../threads/copyright.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdio.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdarg.h \
  /usr/include/sys/feature_tests.h /usr/include/sys/ccompile.h \
  /usr/include/sys/isa_defs.h /usr/include/iso/stdio_iso.h \
  /usr/include/sys/va_list.h /usr/include/stdio_tag.h \
  /usr/include/stdio_impl.h /usr/include/iso/stdio_c99.h \
  /usr/include/string.h /usr/include/iso/string_iso.h ../threads/list.h \
  ../threads/system.h ../threads/scheduler.h ../machine/interrupt.h \
  ../threads/list.h ../machine/stats.h ../machine/timer.h \
  ../threads/utility.h
synchlist.o: ../threads/synchlist.cc ../threads/copyright.h \
  ../threads/synchlist.h ../threads/list.h ../threads/utility.h \
  ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdio.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdarg.h \
  /usr/include/sys/feature_tests.h /usr/include/sys/ccompile.h \
  /usr/include/sys/isa_defs.h /usr/include/iso/stdio_iso.h \
  /usr/include/sys/va_list.h /usr/include/stdio_tag.h \
  /usr/include/stdio_impl.h /usr/include/iso/stdio_c99.h \
  /usr/include/string.h /usr/include/iso/string_iso.h ../threads/synch.h \
  ../threads/thread.h
system.o: ../threads/system.cc ../threads/copyright.h ../threads/system.h \
  ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
  ../threads/copyright.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdio.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdarg.h \
  /usr/include/sys/feature_tests.h /usr/include/sys/ccompile.h \
  /usr/include/sys/isa_defs.h /usr/include/iso/stdio_iso.h \
  /usr/include/sys/va_list.h /usr/include/stdio_tag.h \
  /usr/include/stdio_impl.h /usr/include/iso/stdio_c99.h \
  /usr/include/string.h /usr/include/iso/string_iso.h ../threads/thread.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../threads/list.h ../machine/stats.h ../machine/timer.h \
  ../threads/utility.h
thread.o: ../threads/thread.cc ../threads/copyright.h ../threads/thread.h \
  ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
  ../threads/copyright.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdio.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdarg.h \
  /usr/include/sys/feature_tests.h /usr/include/sys/ccompile.h \
  /usr/include/sys/isa_defs.h /usr/include/iso/stdio_iso.h \
  /usr/include/sys/va_list.h /usr/include/stdio_tag.h \
  /usr/include/stdio_impl.h /usr/include/iso/stdio_c99.h \
  /usr/include/string.h /usr/include/iso/string_iso.h ../threads/switch.h \
  ../threads/synch.h ../threads/list.h ../threads/system.h \
  ../threads/scheduler.h ../machine/interrupt.h ../threads/list.h \
  ../machine/stats.h ../machine/timer.h ../threads/utility.h
utility.o: ../threads/utility.cc ../threads/copyright.h \
  ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
  ../threads/copyright.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdio.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdarg.h \
  /usr/include/sys/feature_tests.h /usr/include/sys/ccompile.h \
  /usr/include/sys/isa_defs.h /usr/include/iso/stdio_iso.h \
  /usr/include/sys/va_list.h /usr/include/stdio_tag.h \
  /usr/include/stdio_impl.h /usr/include/iso/stdio_c99.h \
  /usr/include/string.h /usr/include/iso/string_iso.h
threadtest.o: ../threads/threadtest.cc ../threads/copyright.h \
  ../threads/system.h ../threads/utility.h ../threads/bool.h \
  ../machine/sysdep.h ../threads/copyright.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdio.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdarg.h \
  /usr/include/sys/feature_tests.h /usr/include/sys/ccompile.h \
  /usr/include/sys/isa_defs.h /usr/include/iso/stdio_iso.h \
  /usr/include/sys/va_list.h /usr/include/stdio_tag.h \
  /usr/include/stdio_impl.h /usr/include/iso/stdio_c99.h \
  /usr/include/string.h /usr/include/iso/string_iso.h ../threads/thread.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../threads/list.h ../machine/stats.h ../machine/timer.h \
  ../threads/utility.h
interrupt.o: ../machine/interrupt.cc ../threads/copyright.h \
  ../machine/interrupt.h ../threads/list.h ../threads/copyright.h \
  ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdio.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdarg.h \
  /usr/include/sys/feature_tests.h /usr/include/sys/ccompile.h \
  /usr/include/sys/isa_defs.h /usr/include/iso/stdio_iso.h \
  /usr/include/sys/va_list.h /usr/include/stdio_tag.h \
  /usr/include/stdio_impl.h /usr/include/iso/stdio_c99.h \
  /usr/include/string.h /usr/include/iso/string_iso.h ../threads/system.h \
  ../threads/thread.h ../threads/scheduler.h ../threads/list.h \
  ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
  ../threads/utility.h
sysdep.o: ../machine/sysdep.cc ../threads/copyright.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdio.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdarg.h \
  /usr/include/sys/feature_tests.h /usr/include/sys/ccompile.h \
  /usr/include/sys/isa_defs.h /usr/include/iso/stdio_iso.h \
  /usr/include/sys/va_list.h /usr/include/stdio_tag.h \
  /usr/include/stdio_impl.h /usr/include/iso/stdio_c99.h \
  /usr/include/string.h /usr/include/iso/string_iso.h \
  /usr/include/errno.h /usr/include/sys/errno.h /usr/include/signal.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/sys/types.h \
  /usr/include/sys/machtypes.h /usr/include/sys/int_types.h \
  /usr/include/sys/select.h /usr/include/sys/time_impl.h \
  /usr/include/sys/time.h /usr/include/time.h /usr/include/iso/time_iso.h \
  /usr/include/iso/signal_iso.h /usr/include/sys/iso/signal_iso.h \
  /usr/include/sys/unistd.h /usr/include/sys/signal.h \
  /usr/include/sys/siginfo.h /usr/include/sys/machsig.h \
  /usr/include/sys/ucontext.h /usr/include/sys/regset.h \
  /usr/include/v7/sys/privregs.h /usr/include/v7/sys/psr.h \
  /usr/include/sys/fsr.h /usr/include/sys/procset.h \
  /usr/include/sys/socket.h /usr/include/sys/uio.h \
  /usr/include/sys/socket_impl.h /usr/include/sys/un.h \
  /usr/include/net/if_dl.h /usr/include/sys/netconfig.h \
  /usr/include/netinet/in.h /usr/include/sys/stream.h \
  /usr/include/sys/vnode.h /usr/include/sys/t_lock.h \
  /usr/include/sys/machlock.h /usr/include/sys/param.h \
  /usr/include/sys/mutex.h /usr/include/sys/rwlock.h \
  /usr/include/sys/semaphore.h /usr/include/sys/condvar.h \
  /usr/include/sys/rwstlock.h /usr/include/sys/ksynch.h \
  /usr/include/sys/cred.h /usr/include/sys/resource.h \
  /usr/include/vm/seg_enum.h /usr/include/sys/kstat.h \
  /usr/include/sys/kmem.h /usr/include/sys/vmem.h /usr/include/sys/poll.h \
  /usr/include/sys/strmdep.h /usr/include/sys/model.h \
  /usr/include/sys/strft.h /usr/include/sys/byteorder.h \
  /usr/include/sys/file.h /usr/include/sys/mman.h /usr/include/fcntl.h \
  /usr/include/sys/stat.h /usr/include/sys/stat_impl.h \
  /usr/include/sys/fcntl.h ../machine/interrupt.h ../threads/list.h \
  ../threads/copyright.h ../threads/utility.h ../threads/bool.h \
  ../machine/sysdep.h ../threads/system.h ../threads/thread.h \
  ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
  ../machine/stats.h ../machine/timer.h ../threads/utility.h
stats.o: ../machine/stats.cc ../threads/copyright.h ../threads/utility.h \
  ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdio.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdarg.h \
  /usr/include/sys/feature_tests.h /usr/include/sys/ccompile.h \
  /usr/include/sys/isa_defs.h /usr/include/iso/stdio_iso.h \
  /usr/include/sys/va_list.h /usr/include/stdio_tag.h \
  /usr/include/stdio_impl.h /usr/include/iso/stdio_c99.h \
  /usr/include/string.h /usr/include/iso/string_iso.h ../machine/stats.h
timer.o: ../machine/timer.cc ../threads/copyright.h ../machine/timer.h \
  ../threads/utility.h ../threads/copyright.h ../threads/bool.h \
  ../machine/sysdep.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdio.h \
  /opt/csw/gcc3/lib/gcc/sparc-sun-solaris2.8/3.4.6/include/stdarg.h \
  /usr/include/sys/feature_tests.h /usr/include/sys/ccompile.h \
  /usr/include/sys/isa_defs.h /usr/include/iso/stdio_iso.h \
  /usr/include/sys/va_list.h /usr/include/stdio_tag.h \
  /usr/include/stdio_impl.h /usr/include/iso/stdio_c99.h \
  /usr/include/string.h /usr/include/iso/string_iso.h ../threads/system.h \
  ../threads/utility.h ../threads/thread.h ../threads/scheduler.h \
  ../threads/list.h ../machine/interrupt.h ../threads/list.h \
  ../machine/stats.h ../machine/timer.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
