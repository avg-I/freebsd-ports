# New ports collection makefile for:	toppler
# Date created:				18 Jan 2002
# Whom:					Dom Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	toppler
PORTVERSION=	1.1.5
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A game where you have to climb the tower and avoid the monsters

USE_SDL=	mixer sdl
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share

MAN6=		${PORTNAME}.6

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|DATA install-dist_pkgdocDATA|DATA|g' ${WRKSRC}/Makefile.in

post-install:
	@${CHMOD} 2755 ${PREFIX}/bin/${PORTNAME}
	@${CHOWN} root:games ${PREFIX}/bin/${PORTNAME}
	@${CHMOD} 0664 ${DATADIR}/${PORTNAME}.hsc
	@${CHOWN} root:games ${DATADIR}/${PORTNAME}.hsc
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
