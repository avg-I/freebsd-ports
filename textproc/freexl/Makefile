# New ports collection makefile for:	freexl
# Date created:				19 May 2012
# Whom:					lbartoletti <coder@tuxfamily.org>
#
# $FreeBSD$
#

PORTNAME=	freexl
DISTVERSION=	1.0.0d
CATEGORIES=	textproc
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/freexl-sources/

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Library to extract valid data from within an Excel (.xls) spreadsheet

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_ICONV=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -liconv
CONFIGURE_ARGS+=CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in
.include <bsd.port.mk>
