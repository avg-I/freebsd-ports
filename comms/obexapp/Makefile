# New ports collection makefile for:	obexapp
# Date created:				22 March 2004
# Whom:					Guido Falsi <mad@madpilot.net>
#
# $FreeBSD$
#

PORTNAME=	obexapp
PORTVERSION=	1.4.15
PORTREVISION=	1
CATEGORIES=	comms net
MASTER_SITES=	http://people.freebsd.org/~emax/obexapp/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Obex application to transfer objects to mobile equipment

LIB_DEPENDS=	openobex:${PORTSDIR}/comms/openobex \
		expat:${PORTSDIR}/textproc/expat2

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_ICONV=	yes
PLIST_FILES=	bin/obexapp
MAKE_JOBS_SAFE=	yes

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		obexapp.1
MANCOMPRESSED=	yes
.else
MAKE_ENV+=	NO_MAN=yes
.endif

MAKE_ENV+=	NO_WERROR=yes

.include <bsd.port.mk>
