#       @(#)Makefile    5.3 (Berkeley) 5/12/90

PROG=	gzip
SRCS=	gzip.c zip.c deflate.c trees.c bits.c unzip.c inflate.c util.c \
	crypt.c lzw.c unlzw.c unpack.c getopt.c match.S
MAN1=	gzip.0 zcmp.0 zmore.0 znew.0 zforce.0 gzexe.0
CFLAGS+=-DASMV -DHAVE_UNISTD_H=1 -DDIRENT=1
MLINKS=	zcmp.1 zdiff.1  gzip.1 gunzip.1  gzip.1 zcat.1

afterinstall:
	install -c -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
	   ${.CURDIR}/zforce ${.CURDIR}/gzexe ${.CURDIR}/znew \
	   ${.CURDIR}/zmore ${.CURDIR}/zdiff ${.CURDIR}/zcmp \
	   ${DESTDIR}${BINDIR}

match.o: match.S
	$(CPP) ${.CURDIR}/match.S >_match.s
	$(CC) -c _match.s
	mv _match.o match.o
	rm -f _match.s

.include <bsd.prog.mk>
