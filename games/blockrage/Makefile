# New Ports collection makefile for:	blockrage
# Date created:		2012-04-28
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	blockrage
PORTVERSION=	0.2.3
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Falling blocks game with 2-player hotseat mode

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
ALL_TARGET=	${PORTNAME}
USE_SDL=	sdl image mixer
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/${PORTNAME}

MAN6=		${PORTNAME}.6

PORTDATA=	*
PORTDOCS=	ChangeLog KNOWN_BUGS README TODO

SUB_FILES=	${PORTNAME}

.include <bsd.port.options.mk>

do-install:
# Scripts
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

# Executable
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${DATADIR}

post-install:
	${INSTALL_MAN} ${WRKSRC}/${MAN6} ${MAN6PREFIX}/man/man6

# Data
.  for d in data blockrage-fhs.rc blockrage.cfg blockrage.rc
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.  endfor

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
