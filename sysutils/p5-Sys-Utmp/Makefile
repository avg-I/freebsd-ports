# New ports collection makefile for:	p5-Sys-Utmp
# Date created:				Fri Aug 20 13:33:55 MSD 2004
# Whom:					Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	Sys-Utmp
PORTVERSION=	1.6
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	zaa@ulstu.ru
COMMENT=	Perl5 module which provides Object(ish) Interface to UTMP files

PERL_CONFIGURE=	yes

MAN3=		Sys::Utmp.3 Sys::Utmp::Utent.3

post-patch:
	@${REINPLACE_CMD} -e '254 s,strcpy,strncpy,' ${WRKSRC}/Utmp.xs

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

.include <bsd.port.post.mk>
