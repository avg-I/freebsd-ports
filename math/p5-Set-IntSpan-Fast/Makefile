# New ports collection makefile for:	math/p5-Set-IntSpan-Fast
# Date created:				15 February 2007
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Set-IntSpan-Fast
PORTVERSION=	1.15
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Fast handling of sets containing integer spans

BUILD_DEPENDS=	p5-Data-Types>=0:${PORTSDIR}/devel/p5-Data-Types
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Set::IntSpan::Fast.3 Set::IntSpan::Fast::PP.3

.include <bsd.port.mk>
