# New ports collection makefile for:   dvdauthor
# Date created:        20 April 2003
# Whom:                pb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	dvdauthor
PORTVERSION=	0.7.0
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Makes a DVD file structure from one or more MPEG2 streams

LIB_DEPENDS=	dvdread.4:${PORTSDIR}/multimedia/libdvdread \
		fribidi.3:${PORTSDIR}/converters/fribidi \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		freetype.9:${PORTSDIR}/print/freetype2

USE_BISON=	build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
WRKSRC=		${WRKDIR}/dvdauthor
MAN1=	dvdauthor.1 dvddirdel.1 dvdunauthor.1 mpeg2desc.1 spumux.1 spuunmux.1

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libfreetype.so.9)
WITH_FREETYPE=		yes
.endif
.if exists(${LOCALBASE}/lib/libiconv.so)
WITH_ICONV=		yes
.endif
.if exists(${LOCALBASE}/lib/libMagickWand.so.5)
WITH_IMAGEMAGICK=	yes
.endif

.if defined(WITH_ICONV)
USE_ICONV=	yes
CFLAGS+=	-DICONV_CONV=yes
.endif
.if defined(WITH_IMAGEMAGICK)
LIB_DEPENDS+=	MagickWand.5:${PORTSDIR}/graphics/ImageMagick
.else
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
.endif

pre-everything::
.if !defined(WITH_ICONV)
	@${ECHO_MSG} "You can enable Iconv support by defining WITH_ICONV."
	@${ECHO_MSG}
.endif
.if !defined(WITH_IMAGEMAGICK)
	@${ECHO_MSG} "You can enable ImageMagick support by defining WITH_IMAGEMAGICK."
	@${ECHO_MSG}
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/dvdauthor
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dvdauthor
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${PREFIX}/share/doc/dvdauthor
.endif

.include <bsd.port.post.mk>
