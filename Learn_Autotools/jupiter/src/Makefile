# src/Makefile.  Generated from Makefile.in by configure.

# Package-specific substituion variables
package=Jupiter
version=1.0
tarname=jupiter
distdir=${tarname}-${version}

# Prefix-specific substituion variables
prefix=/usr/local
exec_prefix=${prefix}
bindir=${exec_prefix}/bin

# VPATH-sepecific substituion variables
srcdir=.


# Tool-specific subsitution variables
CC=gcc
DEFS=-DHAVE_CONFIG_H
LIBS=
CFLAGS=-g -O2
CPPFLAGS=
INSTALL=/usr/bin/install -c
INSTALL_DATA=${INSTALL} -m 644
INSTALL_PROGRAM=${INSTALL}
INSTALL_SCRIPT=${INSTALL}

all : jupiter

jupiter : main.c
	${CC} ${CFLAGS} ${CPPFLAGS} -I . -I ${srcdir} -I .. -o $@ main.c ${LIBS}

clean :
	-rm jupiter

check : all
	./jupiter | grep "Hello from .*jupiter!"
	@echo "*** ALL TESTS PASSED ***"

install :
	# "install" is a shell script provided by UNIX
	# "install -d" is used to create a directory
	${INSTALL} -d ${DESTDIR}${bindir}
	# "install -m" is used to set up alternate mode
	${INSTALL_PROGRAM} -m 0755 jupiter ${DESTDIR}${bindir}

uninstall :
	-rm ${DESTDIR}${bindir}/jupiter

Makefile : Makefile.in ../config.status
	cd .. && ./config.status src/@

../config.status : ../configure
	cd .. && ./config.status --recheck

.PHONY : all clean
