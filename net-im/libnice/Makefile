# New ports collection makefile for:	libnice
# Date created:				27 February 2009
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libnice
PORTVERSION=	0.0.13
PORTREVISION=	3
CATEGORIES=	net-im devel
MASTER_SITES=	http://nice.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library and transmitter that implements ICE-19

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack pkgconfig glib20 ltverhack
USE_GSTREAMER=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_GETIFADDRS
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|__BYTE_ORDER|_BYTE_ORDER|g ; \
	    	s|__BIG_ENDIAN|_BIG_ENDIAN|g' \
		${WRKSRC}/stun/md5.c \
		${WRKSRC}/stun/sha1.c
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
	    	's|-Wno-missing-field-initializers|#|g'
	@${REINPLACE_CMD} -e 's|-Wno-missing-field-initializers|#|g' \
	    	${WRKSRC}/common.mk

post-configure:
	@${TOUCH} -f ${WRKSRC}/config.h ${WRKSRC}/aclocal.m4 \
	    	${WRKSRC}/configure ${WRKSRC}/Makefile.in \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
