# New ports collection makefile for:	phalcon
# Date created:		6 May 2012
# Whom:			Jin-Sih Lin <linpct@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	phalcon
PORTVERSION=	0.4.5
CATEGORIES=	www
MASTER_SITES=	https://github.com/${PORTNAME}/c${PORTNAME}/tarball/${GITVERSION}/
DISTNAME=	${PORTNAME}-c${PORTNAME}-${GITVERSION}

MAINTAINER=	linpct@gmail.com
COMMENT=	Phalcon PHP Framework written in C-language

GITVERSION=	97d8732
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/${PORTNAME}-c${PORTNAME}-${GITVERSION}/release/

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--enable-phalcon --prefix=${PREFIX} --with-php-config=${LOCALBASE}/bin/php-config

USE_PHP=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes

.include <bsd.port.mk>
