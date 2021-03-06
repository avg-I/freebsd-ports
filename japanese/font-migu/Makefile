# New ports collection makefile for:	font-migu
# Date created:		22 June 2011
# Whom:			hrs
#
# $FreeBSD$
#

PORTNAME=	font-migu
PORTVERSION=	1.0.20120411
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	mix-mplus-ipa/56156
DISTFILES=	migu-1p-20120411-2${EXTRACT_SUFX} \
		migu-1c-20120411-2${EXTRACT_SUFX} \
		migu-1m-20120411-2${EXTRACT_SUFX} \
		migu-2m-20120411-2${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Another Japanese font set based on MigMix

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_ZIP=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
SUB_LIST=	X_FONTSDIR=${PREFIX}/${X_FONTSDIR}
PLIST_SUB=	X_FONTSDIR=${X_FONTSDIR} \
		LOCAL_FONTSDIR=${LOCAL_FONTSDIR}
PORTDOCS=	IPA_Font_License_Agreement_v1.0.txt Readme_ipag00303.txt \
		README_E README_J migu-README.txt

LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts

do-install:
	cd ${WRKDIR}/migu-1p-20120411-2/ && \
		${INSTALL_DATA} ipag00303/*.txt \
			mplus-TESTFLIGHT-048/* \
			migu-README.txt \
			${WRKDIR}
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} \
		${WRKDIR}/migu-1p-20120411-2/*.ttf \
		${WRKDIR}/migu-1c-20120411-2/*.ttf \
		${WRKDIR}/migu-1m-20120411-2/*.ttf \
		${WRKDIR}/migu-2m-20120411-2/*.ttf \
		${DATADIR}
	${MKDIR} ${PREFIX}/${LOCAL_FONTSDIR}/TTF
	${LN} -s -f ${DATADIR}/migu*.ttf \
		${PREFIX}/${LOCAL_FONTSDIR}/TTF/
	${MKDIR} ${PREFIX}/${X_FONTSDIR}/TTF
	${LN} -s -f ${DATADIR}/migu*.ttf \
		${PREFIX}/${X_FONTSDIR}/TTF/
	${INSTALL_DATA} ${FILESDIR}/20-unhint-migu.conf \
		${FILESDIR}/62-fonts-migu.conf \
		${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-migu.conf \
		${PREFIX}/etc/fonts/conf.d/20-unhint-migu.conf
	${LN} -s -f ../conf.avail/62-fonts-migu.conf \
		${PREFIX}/etc/fonts/conf.d/62-fonts-migu.conf
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKDIR} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	${LOCALBASE}/bin/fc-cache -s -f -v ${PREFIX}/${X_FONTSDIR}/TTF
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
