# New ports collection makefile for:	s10sh
# Date created:				Tue Feb 27 00:16:34 MST 2001
# Whom:					John Reynolds <johnjen@reynoldsnet.org>
#
# $FreeBSD$
#

PORTNAME=	s10sh
PORTVERSION=	0.2.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.reynoldsnet.org/s10sh/ \
		http://www.edwinh.org/s10sh/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	USB/serial userspace driver for the Canon PowerShot digital cameras

# Don't extract the libusb bundled with s10sh:
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude '*/libusb*'

MAKEFILE=	${FILESDIR}/Makefile.bsd

.include <bsd.port.pre.mk>

.if defined(NOUSB) || defined(WITHOUT_USB)
MAKE_ENV+=	WITHOUT_USB=YES
.else
. if ${OSVERSION} < 800069
LIB_DEPENDS=	usb-0.1.8:${PORTSDIR}/devel/libusb
. endif
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
