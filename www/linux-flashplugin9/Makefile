# New ports collection makefile for:	linux-flashplugin9
# Date created:				28 May 2004
# Whom:					Jamie Jones <jamie@bishopston.net>
#
# $FreeBSD$
#

PORTNAME=	flashplugin
PORTVERSION=	9.0r289
PORTREVISION?=	1
CATEGORIES=	www multimedia linux
MASTER_SITES=	http://download.macromedia.com/pub/flashplayer/installers/current/9/:plugin \
		http://tijl.ulyssis.fm/mirror/:suplib \
		LOCAL/pav:suplib
PKGNAMEPREFIX=	linux-
DISTFILES=	install_flash_player_9.tar.gz:plugin \
		libflashsupport.so:suplib
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=	install_flash_player_9.tar.gz

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Adobe Flash Player NPAPI Plugin

BROKEN=		unfetchable

ONLY_FOR_ARCHS=	amd64 i386
USE_LINUX=	yes
USE_LINUX_APPS=	openssl gtk2

RESTRICTED=	Redistribution not allowed
RESTRICTED_FILES=	${DISTFILES:Nlibflashsupport*:C/:[^:]+$//}

NO_BUILD=	yes
WRKSRC=		${WRKDIR}
LATEST_LINK=	flash9

USE_NPAPI=	linux-*
NPAPI_FILES=	libflashplayer.so

CONFLICTS=	linux-flashplugin-7* linux-f8-flashplugin-10* linux-f10-flashplugin-10*

post-install:
	@${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/libflashsupport.so ${LINUXBASE}/usr/lib

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/linux-mplayer-plugin/Makefile.npapi"
.include <bsd.port.post.mk>
