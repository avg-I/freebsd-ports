# New ports collection makefile for:	wmshuffle
# Date created:			15 May 2002
# Whom:				Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmshuffle
PORTVERSION=	0.6
PORTREVISION=	3
CATEGORIES=	games windowmaker afterstep
MASTER_SITES=	http://www.linuks.mine.nu/dockapp/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockable Shuffle game for WindowMaker and AfterStep

USE_GMAKE=	yes
USE_XORG=	xpm

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/skin-*.xpm ${DATADIR}
	@${ECHO_MSG} "===>   Run 'wmshuffle --help' for the available options"

.include <bsd.port.mk>
