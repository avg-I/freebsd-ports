# New ports collection makefile for:	installwatch
# Date created:		03 March 2001
# Whom:			George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	installwatch
PORTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://asic-linux.com.mx/~izto/checkinstall/files/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A file creation/modification logger

PLIST_FILES=	bin/installwatch lib/installwatch.so

PORTDOCS=	BUGS CHANGELOG INSTALL README TODO

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
