# New ports collection makefile for:	transmission-daemon
# Date created:				08 February 2008
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
PKGNAMESUFFIX=	-daemon

MAINTAINER=	crees@FreeBSD.org
COMMENT=	A fast and lightweight daemon BitTorrent client

RUN_DEPENDS=	${GEN_RUN_DEPENDS}

DESCR=		${.CURDIR}/pkg-descr
MASTERDIR=	${.CURDIR}/../transmission25-cli
PLIST=		${.CURDIR}/pkg-plist
PKGINSTALL=	${.CURDIR}/pkg-install
SLAVEPORT=	daemon

USE_RC_SUBR=	transmission

EXTRA_CONF_ARGS=--disable-cli \
		--enable-daemon \
		--without-gtk \
		--disable-mac \
		--disable-nls

MAN1=		transmission-daemon.1 transmission-remote.1

post-install: general-install
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include "${MASTERDIR}/Makefile"
