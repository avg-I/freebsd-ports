# ex:ts=8
# New ports collection makefile for:	t_coffee
# Date created:		27 June 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	t_coffee
PORTVERSION=	5.68
CATEGORIES=	biology
MASTER_SITES=	http://www.tcoffee.org/Packages/
DISTNAME=	T-COFFEE_distribution_Version_${PORTVERSION}

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	A multiple DNA or protein sequence alignment package

BUILD_DEPENDS=	clustalw:${PORTSDIR}/biology/clustalw
RUN_DEPENDS:=	${BUILD_DEPENDS}

BUILD_WRKSRC=	${WRKSRC}/t_coffee_source
MAKE_ENV=	MV=${MV} USER_BIN=${PREFIX}/bin \
		CLUSTALW_4_TCOFFEE=${LOCALBASE}/bin/clustalw

MAKEFILE=	makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/t_coffee ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/html/* ${DOCSDIR}/html
.endif
.if !defined(NOPORTEXAMPLES)
	@ ${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/example && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
