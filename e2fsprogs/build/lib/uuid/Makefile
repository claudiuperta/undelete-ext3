# Makefile for the UUID library
#

srcdir = ../../../lib/uuid
top_srcdir = ../../..
VPATH = ../../../lib/uuid
top_builddir = ../..
my_dir = lib/uuid
INSTALL = /bin/install -c

# Beginning of file MCONFIG

all::

check::

SHELL = /bin/sh

COMPRESS_EXT = gz bz2 bz Z

prefix = /usr
root_prefix = 
exec_prefix = ${prefix}
root_bindir = ${root_prefix}/bin
root_sbindir = ${root_prefix}/sbin
root_libdir = ${root_prefix}/lib
datarootdir = ${prefix}/share
bindir = ${exec_prefix}/bin
sbindir = ${exec_prefix}/sbin
libdir = ${exec_prefix}/lib
datadir= ${datarootdir}
localedir = $(datadir)/locale
root_sysconfdir= ${root_prefix}/etc
includedir = ${prefix}/include
mandir = ${datarootdir}/man
man1dir = $(mandir)/man1
man3dir = $(mandir)/man3
man5dir = $(mandir)/man5
man8dir = $(mandir)/man8
infodir = ${datarootdir}/info
datadir = ${datarootdir}



CC = cc
BUILD_CC = cc
DEFS = -DLOCALEDIR=\"$(localedir)\" -DROOT_SYSCONFDIR=\"$(root_sysconfdir)\" -DPACKAGE_NAME=\"\" -DPACKAGE_TARNAME=\"\" -DPACKAGE_VERSION=\"\" -DPACKAGE_STRING=\"\" -DPACKAGE_BUGREPORT=\"\" -DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 -DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 -DENABLE_HTREE=1 -DCONFIG_TESTIO_DEBUG=1 -DTLS=__thread -DUSE_UUIDD=1 -DPACKAGE=\"e2fsprogs\" -DVERSION=\"0.14.1\" -DHAVE_LONG_LONG=1 -DHAVE_LONG_DOUBLE=1 -DHAVE_WCHAR_T=1 -DHAVE_WINT_T=1 -DHAVE_INTTYPES_H_WITH_UINTMAX=1 -DHAVE_STDINT_H_WITH_UINTMAX=1 -DHAVE_INTMAX_T=1 -DHAVE_POSIX_PRINTF=1 -DHAVE_ALLOCA_H=1 -DHAVE_ALLOCA=1 -DHAVE_STDLIB_H=1 -DHAVE_UNISTD_H=1 -DHAVE_GETPAGESIZE=1 -DHAVE_MMAP=1 -DINTDIV0_RAISES_SIGFPE=1 -DHAVE_UNSIGNED_LONG_LONG=1 -DHAVE_UINTMAX_T=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_STDINT_H=1 -DHAVE_ARGZ_H=1 -DHAVE_LIMITS_H=1 -DHAVE_LOCALE_H=1 -DHAVE_NL_TYPES_H=1 -DHAVE_MALLOC_H=1 -DHAVE_STDDEF_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_UNISTD_H=1 -DHAVE_SYS_PARAM_H=1 -DHAVE_ASPRINTF=1 -DHAVE_FWPRINTF=1 -DHAVE_GETCWD=1 -DHAVE_GETEGID=1 -DHAVE_GETEUID=1 -DHAVE_GETGID=1 -DHAVE_GETUID=1 -DHAVE_MEMPCPY=1 -DHAVE_MUNMAP=1 -DHAVE_PUTENV=1 -DHAVE_SETENV=1 -DHAVE_SETLOCALE=1 -DHAVE_SNPRINTF=1 -DHAVE_STPCPY=1 -DHAVE_STRCASECMP=1 -DHAVE_STRDUP=1 -DHAVE_STRTOUL=1 -DHAVE_TSEARCH=1 -DHAVE_WCSLEN=1 -DHAVE___ARGZ_COUNT=1 -DHAVE___ARGZ_STRINGIFY=1 -DHAVE___ARGZ_NEXT=1 -DHAVE___FSETLOCKING=1 -DHAVE_DECL__SNPRINTF=0 -DHAVE_DECL__SNWPRINTF=0 -DHAVE_DECL_FEOF_UNLOCKED=1 -DHAVE_DECL_FGETS_UNLOCKED=0 -DHAVE_DECL_GETC_UNLOCKED=1 -DHAVE_ICONV=1 -DICONV_CONST= -DHAVE_LANGINFO_CODESET=1 -DHAVE_LC_MESSAGES=1 -DENABLE_NLS=1 -DHAVE_GETTEXT=1 -DHAVE_DCGETTEXT=1 -DHAVE_DIRENT_H=1 -DHAVE_ERRNO_H=1 -DHAVE_GETOPT_H=1 -DHAVE_MALLOC_H=1 -DHAVE_MNTENT_H=1 -DHAVE_PATHS_H=1 -DHAVE_SEMAPHORE_H=1 -DHAVE_SETJMP_H=1 -DHAVE_SIGNAL_H=1 -DHAVE_STDARG_H=1 -DHAVE_STDINT_H=1 -DHAVE_STDLIB_H=1 -DHAVE_TERMIOS_H=1 -DHAVE_TERMIO_H=1 -DHAVE_UNISTD_H=1 -DHAVE_UTIME_H=1 -DHAVE_LINUX_FD_H=1 -DHAVE_LINUX_MAJOR_H=1 -DHAVE_NETINET_IN_H=1 -DHAVE_SYS_FILE_H=1 -DHAVE_SYS_IOCTL_H=1 -DHAVE_SYS_MMAN_H=1 -DHAVE_SYS_PRCTL_H=1 -DHAVE_SYS_QUEUE_H=1 -DHAVE_SYS_RESOURCE_H=1 -DHAVE_SYS_SELECT_H=1 -DHAVE_SYS_SOCKET_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_SYS_SYSCALL_H=1 -DHAVE_SYS_SYSMACROS_H=1 -DHAVE_SYS_TIME_H=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_SYS_UN_H=1 -DHAVE_SYS_WAIT_H=1 -DHAVE_SYS_MOUNT_H=1 -DHAVE_NET_IF_H=1 -DHAVE_VPRINTF=1 -DHAVE_RECLEN_DIRENT=1 -DHAVE_TYPE_SSIZE_T=1 -DHAVE_LSEEK64_PROTOTYPE=1 -DSIZEOF_SHORT=2 -DSIZEOF_INT=4 -DSIZEOF_LONG=4 -DSIZEOF_LONG_LONG=8 -DHAVE_INTTYPES_H=1 -DHAVE_INTPTR_T=1 -DHAVE_GETRUSAGE=1 -DHAVE_LLSEEK=1 -DHAVE_LSEEK64=1 -DHAVE_OPEN64=1 -DHAVE_FSTAT64=1 -DHAVE_FTRUNCATE64=1 -DHAVE_STRTOULL=1 -DHAVE_STRCASECMP=1 -DHAVE_SRANDOM=1 -DHAVE_JRAND48=1 -DHAVE_FCHOWN=1 -DHAVE_MALLINFO=1 -DHAVE_FDATASYNC=1 -DHAVE_STRNLEN=1 -DHAVE_STRPTIME=1 -DHAVE_STRDUP=1 -DHAVE_SYSCONF=1 -DHAVE_PATHCONF=1 -DHAVE_POSIX_MEMALIGN=1 -DHAVE_MEMALIGN=1 -DHAVE_VALLOC=1 -DHAVE___SECURE_GETENV=1 -DHAVE_PRCTL=1 -DHAVE_MMAP=1 -DHAVE_UTIME=1 -DHAVE_SETRESUID=1 -DHAVE_SETRESGID=1 -DHAVE_USLEEP=1 -DHAVE_NANOSLEEP=1 -DHAVE_DLOPEN=1 -DHAVE_SEM_INIT=1 -DHAVE_EXT2_IOCTLS=1
CFLAGS = -g
CPPFLAGS =  -I$(top_builddir)/lib -I$(top_srcdir)/lib 
INTL_FLAGS = 
ALL_CFLAGS = $(CPPFLAGS) $(DEFS) $(USE_WFLAGS) $(CFLAGS) $(XTRA_CFLAGS) \
	$(INTL_FLAGS) $(LINUX_INCLUDE) 
LDFLAGS = 
ALL_LDFLAGS = $(LDFLAGS) 
LDFLAGS_STATIC = $(LDFLAGS) 
BUILD_CFLAGS = -g
BUILD_LDFLAGS = 
RM = /bin/rm
LN = /bin/ln
LN_S = ln -s
MV = /bin/mv
CP = /bin/cp
CHMOD = /bin/chmod
AR = ar
AWK = gawk
SED = /bin/sed
PERL = /usr/bin/perl
RANLIB = ranlib
STRIP = strip
LD = $(PURE) cc
ARUPD = $(AR) r
ARGEN = $(AR) rc
LDCONFIG = /sbin/ldconfig
INSTALL_PROGRAM = ${INSTALL}
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_SCRIPT = ${INSTALL}
MKINSTALLDIRS = $(top_builddir)/../config/mkinstalldirs

#
# Library definitions
#
LIB = $(top_builddir)/lib
LIBSS = $(LIB)/libss.a  -ldl
LIBCOM_ERR = $(LIB)/libcom_err.a  -lpthread
LIBE2P = $(LIB)/libe2p.a
LIBEXT2FS = $(LIB)/libext2fs.a
LIBUUID = $(LIB)/libuuid.a 
LIBBLKID = $(LIB)/libblkid.a  $(LIBUUID)
LIBINTL = 
DEPLIBSS = $(LIB)/libss.a
DEPLIBUUID = $(LIB)/libuuid.a
DEPLIBBLKID = $(LIB)/libblkid.a  $(LIBUUID)

STATIC_LIBSS = $(LIB)/libss.a -ldl
STATIC_LIBCOM_ERR = $(LIB)/libcom_err.a -lpthread
STATIC_LIBE2P = $(LIB)/libe2p.a
STATIC_LIBEXT2FS = $(LIB)/libext2fs.a
STATIC_LIBUUID = $(LIB)/libuuid.a  
STATIC_LIBBLKID = $(LIB)/libblkid.a
DEPSTATIC_LIBSS = $(LIB)/libss.a
DEPSTATIC_LIBUUID = $(LIB)/libuuid.a
DEPSTATIC_LIBBLKID = $(LIB)/libblkid.a

PROFILED_LIBSS = $(LIB)/libss -ldl
PROFILED_LIBCOM_ERR = $(LIB)/libcom_err
PROFILED_LIBE2P = $(LIB)/libe2p
PROFILED_LIBEXT2FS = $(LIB)/libext2fs
PROFILED_LIBUUID = $(LIB)/libuuid  
PROFILED_LIBBLKID = $(LIB)/libblkid
DEPPROFILED_LIBUUID = $(LIB)/libuuid
DEPPROFILED_LIBBLKID = $(LIB)/libblkid

# An include directive pointing to a directory holding enough linux-like
# include files to satisfy some programs here
LINUX_INCLUDE=

#
# A fast substitution command for fixing up man pages, shell scripts, etc.
#
SUBST_CONF=$(top_builddir)/util/subst.conf
SUBSTITUTE= $(top_builddir)/util/subst -f $(SUBST_CONF)
SUBSTITUTE_UPTIME= $(top_builddir)/util/subst -t -f $(SUBST_CONF)
DEP_SUBSTITUTE= $(top_builddir)/util/subst $(SUBST_CONF)

$(top_builddir)/util/subst:
	cd $(top_builddir)/util ; $(MAKE) subst

#
# Warning flags
#
# Run make gcc-wall to do a build with warning messages.
#
#
WFLAGS=		-std=c99 -D_XOPEN_SOURCE=600 -D_GNU_SOURCE \
			-pedantic $(WFLAGS_EXTRA) \
			-Wall -W -Wwrite-strings -Wpointer-arith \
			-Wcast-qual -Wcast-align -Wno-variadic-macros \
			-Wstrict-prototypes -Wmissing-prototypes \
			-Wformat-security  -Wformat-nonliteral \
			-Wmissing-format-attribute -O2 -Wstrict-aliasing \
			-Wnested-externs -Winline -DNO_INLINE_FUNCS -Wshadow \
			-UENABLE_NLS

gcc-wall-new:
	(make USE_WFLAGS="$(WFLAGS)" > /dev/null) 2>&1 | sed -f $(top_srcdir)/util/gcc-wall-cleanup 

gcc-wall:
	make clean > /dev/null
	make gcc-wall-new

#
# Installation user and groups
#
BINGRP=		bin
BINOWN=		bin
BINMODE=	555
INCGRP=		bin
INCOWN=		bin
INCMODE=	444
LIBOWN=		bin
LIBGRP=		bin
LIBMODE=	444
MANGRP=		bin
MANOWN=		bin
MANMODE=	444

#
# Autoconf magic...
#

DEP_LIB_MAKEFILES = $(top_srcdir)/lib/Makefile.elf-lib  \
	$(top_srcdir)/lib/Makefile.bsd-lib $(top_srcdir)/lib/Makefile.darwin-lib \
	$(top_srcdir)/lib/Makefile.solaris-lib $(top_srcdir)/lib/Makefile.checker \
	$(top_srcdir)/lib/Makefile.profile

$(top_builddir)/config.status: $(top_srcdir)/configure
	cd $(top_builddir); ./config.status --recheck

$(top_builddir)/MCONFIG: $(top_srcdir)/MCONFIG.in $(top_builddir)/config.status
	cd $(top_builddir); CONFIG_FILES=MCONFIG ./config.status

$(top_builddir)/lib/substitute_sh: $(top_srcdir)/lib/substitute_sh.in \
		$(top_builddir)/config.status
	cd $(top_builddir); CONFIG_FILES=lib/substitute_sh ./config.status

$(top_builddir)/util/subst.conf: $(top_srcdir)/util/subst.conf.in \
		$(top_builddir)/config.status
	cd $(top_builddir); CONFIG_FILES=util/subst.conf ./config.status

Makefile: $(srcdir)/Makefile.in $(top_builddir)/MCONFIG \
		$(DEP_MAKEFILE) $(top_builddir)/config.status
	cd $(top_builddir); CONFIG_FILES=$(my_dir)/Makefile ./config.status

#$(top_srcdir)/configure: $(top_srcdir)/configure.in
#	cd $(top_srcdir) && autoconf

#
# Make depend magic...
#

.depend: Makefile $(SRCS) $(top_srcdir)/depfix.sed $(top_srcdir)/wordwrap.pl
	if test -n "$(SRCS)" ; then \
		$(CC) -M $(ALL_CFLAGS) $(SRCS) | \
			$(SED) -f $(top_srcdir)/depfix.sed \
			    -e 's; $(srcdir)/; $$(srcdir)/;g' \
			    -e 's; $(top_srcdir)/; $$(top_srcdir)/;g' \
			    -e 's; $(top_builddir)/; $$(top_builddir)/;g' \
			    -e 's; \./; ;g' \
			    -e '/^#/d' \
			    -e '/^ *\\$$/d' | \
			$(PERL) $(top_srcdir)/wordwrap.pl > .depend; \
	else :; fi

depend:: .depend
	if test -n "$(SRCS)" ; then \
		sed -e '/^# +++ Dependency line eater +++/,$$d' \
			< $(srcdir)/Makefile.in | cat - .depend \
			> $(srcdir)/Makefile.in.new; \
	if cmp -s $(srcdir)/Makefile.in $(srcdir)/Makefile.in.new ; then \
		$(RM) $(srcdir)/Makefile.in.new ; \
	else \
		$(MV) $(srcdir)/Makefile.in $(srcdir)/Makefile.in.old; \
		$(MV) $(srcdir)/Makefile.in.new $(srcdir)/Makefile.in; \
	fi ; else :; fi

# End of file MCONFIG

all:: 

SMANPAGES=	uuid.3 uuid_clear.3 uuid_compare.3 uuid_copy.3 \
		uuid_generate.3 uuid_is_null.3 uuid_parse.3 \
		uuid_time.3 uuid_unparse.3

OBJS=		clear.o \
		compare.o \
		copy.o \
		gen_uuid.o \
		isnull.o \
		pack.o \
		parse.o \
		unpack.o \
		unparse.o \
		uuid_time.o

SRCS=		$(srcdir)/clear.c \
		$(srcdir)/compare.c \
		$(srcdir)/copy.c \
		$(srcdir)/gen_uuid.c \
		$(srcdir)/isnull.c \
		$(srcdir)/pack.c \
		$(srcdir)/parse.c \
		$(srcdir)/unpack.c \
		$(srcdir)/unparse.c \
		$(srcdir)/uuid_time.c

LIBRARY= libuuid
LIBDIR= uuid

ELF_VERSION = 1.2
ELF_SO_VERSION = 1
ELF_IMAGE = libuuid
ELF_MYDIR = uuid
ELF_INSTALL_DIR = $(root_libdir)
ELF_OTHER_LIBS = 

BSDLIB_VERSION = 1.1
BSDLIB_IMAGE = libuuid
BSDLIB_MYDIR = uuid
BSDLIB_INSTALL_DIR = $(root_libdir)

all:: subdirs $(LIBRARY).a

install-shlibs::

uninstall-shlibs::

real-subdirs::

subdirs:: Makefile
	@$(MAKE) -s real-subdirs
	@touch subdirs

clean::
	@$(RM) -f subdirs

$(LIBRARY).a: $(OBJS)
	@echo "	GEN_LIB $@"
	@(if test -r $@; then $(RM) -f $@.bak && $(MV) $@ $@.bak; fi)
	@$(ARGEN) $@ $(OBJS)
	-@$(RANLIB) $@
	@$(RM) -f ../$@
	@$(LN) $@ ../$@

$(LIB)/$(LIBRARY).a: $(LIBRARY).a

.c.o:
	@echo "	CC $<"
	@$(CC) $(ALL_CFLAGS) -c $< -o $@
#	@$(CC) $(ALL_CFLAGS) -g -pg -o profiled/$*.o -c $<
#	@$(CC) $(ALL_CFLAGS) -checker -g -o checker/$*.o -c $<
#	@$(CC) $(ALL_CFLAGS) -fPIC -o elfshared/$*.o -c $<
#	@$(CC) $(ALL_CFLAGS) $(BSDLIB_PIC_FLAG) -o pic/$*.o -c $<

all:: tst_uuid uuid_time $(SMANPAGES) uuid.pc

$(top_builddir)/lib/uuid/uuid_types.h: $(srcdir)/uuid_types.h.in $(top_builddir)/config.status
	cd $(top_builddir); CONFIG_FILES=$(my_dir)/uuid_types.h ./config.status

tst_uuid.o: $(srcdir)/tst_uuid.c
	@echo "	CC $@"
	@$(CC) $(ALL_CFLAGS) -c $(srcdir)/tst_uuid.c -o tst_uuid.o

tst_uuid: tst_uuid.o $(DEPSTATIC_LIBUUID)
	@echo "	LD $@"
	@$(CC) $(ALL_LDFLAGS) -o tst_uuid tst_uuid.o $(STATIC_LIBUUID)

uuid_time: $(srcdir)/uuid_time.c $(DEPLIBUUID)
	@echo "	LD $@"
	@$(CC) $(ALL_CFLAGS) -DDEBUG -o uuid_time $(srcdir)/uuid_time.c \
		$(LIBUUID)

uuid.3: $(DEP_SUBSTITUTE) $(srcdir)/uuid.3.in
	@echo "	SUBST $@"
	@$(SUBSTITUTE_UPTIME) $(srcdir)/uuid.3.in uuid.3

uuid_clear.3: $(DEP_SUBSTITUTE) $(srcdir)/uuid_clear.3.in
	@echo "	SUBST $@"
	@$(SUBSTITUTE_UPTIME) $(srcdir)/uuid_clear.3.in uuid_clear.3

uuid_compare.3: $(DEP_SUBSTITUTE) $(srcdir)/uuid_compare.3.in
	@echo "	SUBST $@"
	@$(SUBSTITUTE_UPTIME) $(srcdir)/uuid_compare.3.in uuid_compare.3

uuid_copy.3: $(DEP_SUBSTITUTE) $(srcdir)/uuid_copy.3.in
	@echo "	SUBST $@"
	@$(SUBSTITUTE_UPTIME) $(srcdir)/uuid_copy.3.in uuid_copy.3

uuid_generate.3: $(DEP_SUBSTITUTE) $(srcdir)/uuid_generate.3.in
	@echo "	SUBST $@"
	@$(SUBSTITUTE_UPTIME) $(srcdir)/uuid_generate.3.in uuid_generate.3

uuid_is_null.3: $(DEP_SUBSTITUTE) $(srcdir)/uuid_is_null.3.in
	@echo "	SUBST $@"
	@$(SUBSTITUTE_UPTIME) $(srcdir)/uuid_is_null.3.in uuid_is_null.3

uuid_parse.3: $(DEP_SUBSTITUTE) $(srcdir)/uuid_parse.3.in
	@echo "	SUBST $@"
	@$(SUBSTITUTE_UPTIME) $(srcdir)/uuid_parse.3.in uuid_parse.3

uuid_time.3: $(DEP_SUBSTITUTE) $(srcdir)/uuid_time.3.in
	@echo "	SUBST $@"
	@$(SUBSTITUTE_UPTIME) $(srcdir)/uuid_time.3.in uuid_time.3

uuid_unparse.3: $(DEP_SUBSTITUTE) $(srcdir)/uuid_unparse.3.in
	@echo "	SUBST $@"
	@$(SUBSTITUTE_UPTIME) $(srcdir)/uuid_unparse.3.in uuid_unparse.3

uuid.pc: $(srcdir)/uuid.pc.in $(top_builddir)/config.status
	@echo "	CONFIG.STATUS $@"
	@cd $(top_builddir); CONFIG_FILES=lib/uuid/uuid.pc ./config.status

installdirs::
	@echo "	MKINSTALLDIRS $(libdir) $(includedir)/uuid $(man3dir)"
	@$(MKINSTALLDIRS) $(DESTDIR)$(libdir)  \
		$(DESTDIR)$(includedir)/uuid $(DESTDIR)$(man3dir) \
		$(DESTDIR)$(libdir)/pkgconfig

install:: all installdirs 
	@echo "	INSTALL_DATA $(libdir)/libuuid.a"
	@$(INSTALL_DATA) libuuid.a $(DESTDIR)$(libdir)/libuuid.a
	@-$(RANLIB) $(DESTDIR)$(libdir)/libuuid.a
	@$(CHMOD) $(LIBMODE) $(DESTDIR)$(libdir)/libuuid.a
	@echo "	INSTALL_DATA $(includedir)/uuid/uuid.h"
	@$(INSTALL_DATA) $(srcdir)/uuid.h $(DESTDIR)$(includedir)/uuid/uuid.h
	@for i in $(SMANPAGES); do \
		$(RM) -f $(DESTDIR)$(man3dir)/$$i.gz; \
		echo "	INSTALL_DATA $(man3dir)/$$i"; \
		$(INSTALL_DATA) $$i $(DESTDIR)$(man3dir)/$$i; \
	done
	@$(RM) -f $(DESTDIR)$(man3dir)/uuid_generate_random.3.gz \
		$(DESTDIR)$(man3dir)/uuid_generate_time.3.gz
	@echo "	LINK $(man3dir)/uuid_generate_random.3"
	@$(LN) -f $(DESTDIR)$(man3dir)/uuid_generate.3 $(DESTDIR)$(man3dir)/uuid_generate_random.3
	@echo "	LINK $(man3dir)/uuid_generate_time.3"
	@$(LN) -f $(DESTDIR)$(man3dir)/uuid_generate.3 $(DESTDIR)$(man3dir)/uuid_generate_time.3
	@echo "	INSTALL_DATA $(libdir)/pkgconfig/uuid.pc"
	@$(INSTALL_DATA) uuid.pc $(DESTDIR)$(libdir)/pkgconfig/uuid.pc

uninstall::
	$(RM) -f $(DESTDIR)$(libdir)/libuuid.a \
		$(DESTDIR)$(libdir)/pkgconfig/uuid.pc
	for i in $(SMANPAGES); do \
		$(RM) -f $(DESTDIR)$(man3dir)/$$i; \
	done
	$(RM) -f $(DESTDIR)$(man3dir)/uuid_generate_random.3 $(DESTDIR)$(man3dir)/uuid_generate_time.3

clean::
	$(RM) -f \#* *.s *.o *.a *~ *.bak core profiled/* checker/*
	$(RM) -f ../libuuid.a ../libuuid_p.a tst_uuid uuid_time $(SMANPAGES)

check:: tst_uuid
	LD_LIBRARY_PATH=$(LIB) DYLD_LIBRARY_PATH=$(LIB) ./tst_uuid

mostlyclean:: clean
distclean:: clean
	$(RM) -f .depend Makefile uuid.pc \
		$(srcdir)/TAGS $(srcdir)/Makefile.in.old

#
# Hack to parallel makes recognize dependencies correctly.
#
../../lib/libuuid.a: libuuid.a
../../lib/libuuid.so: image
../../lib/libuuid.dylib: image

$(OBJS): subdirs

# +++ Dependency line eater +++
# 
# Makefile dependencies follow.  This must be the last section in
# the Makefile.in file
#
clear.o: $(srcdir)/clear.c $(srcdir)/uuidP.h $(srcdir)/uuid.h
compare.o: $(srcdir)/compare.c $(srcdir)/uuidP.h $(srcdir)/uuid.h
copy.o: $(srcdir)/copy.c $(srcdir)/uuidP.h $(srcdir)/uuid.h
gen_uuid.o: $(srcdir)/gen_uuid.c $(srcdir)/uuidP.h $(srcdir)/uuid.h \
 $(srcdir)/uuidd.h
isnull.o: $(srcdir)/isnull.c $(srcdir)/uuidP.h $(srcdir)/uuid.h
pack.o: $(srcdir)/pack.c $(srcdir)/uuidP.h $(srcdir)/uuid.h
parse.o: $(srcdir)/parse.c $(srcdir)/uuidP.h $(srcdir)/uuid.h
unpack.o: $(srcdir)/unpack.c $(srcdir)/uuidP.h $(srcdir)/uuid.h
unparse.o: $(srcdir)/unparse.c $(srcdir)/uuidP.h $(srcdir)/uuid.h
uuid_time.o: $(srcdir)/uuid_time.c $(srcdir)/uuidP.h $(srcdir)/uuid.h
