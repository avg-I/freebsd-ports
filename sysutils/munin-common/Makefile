# New ports collection makefile for:	munin-common
# Date created:                         10 February 2010
# Whom:                                 Sean Rees <sean@rees.us>
#
# $FreeBSD$
#

PORTNAME=	munin
PORTVERSION=	1.4.7
CATEGORIES=	sysutils perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20stable/${PORTVERSION}
PKGNAMESUFFIX=	-common

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Common components between a munin node and server

BUILD_DEPENDS=	p5-Module-Build>=0:${PORTSDIR}/devel/p5-Module-Build \
		p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay
RUN_DEPENDS=	p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay

USE_PERL5=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.r/rc/}

.include "${.CURDIR}/../munin-common/munin.mk"

ALL_TARGET=	build-common-prime
INSTALL_TARGET=	install-common

MAN3=		Munin::Common::Config.3 \
		Munin::Common::Defaults.3 \
		Munin::Common::TLS.3 \
		Munin::Common::TLSClient.3 \
		Munin::Common::TLSServer.3 \
		Munin::Common::Timeout.3

post-install:
	@${MKDIR} ${LOGDIR}
	@${CHOWN} ${USERS}:${GROUPS} ${LOGDIR}
	@(cd ${WRKSRC}/common/blib/libdoc && for man in ${MAN3} ; do \
		${INSTALL_MAN} -C $$man ${PREFIX}/man/man3; \
	done)

.include <bsd.port.mk>
