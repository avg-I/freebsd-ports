# New ports collection makefile for:	devel/p5-Parse-CPAN-Meta
# Date created:				26 February 2009
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Parse-CPAN-Meta
PORTVERSION=	1.44.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Parse META.yml and other similar CPAN metadata files

BUILD_DEPENDS=	p5-CPAN-Meta-YAML>=0.008:${PORTSDIR}/devel/p5-CPAN-Meta-YAML \
		p5-JSON-PP>=2.27200:${PORTSDIR}/converters/p5-JSON-PP
RUN_DEPENDS=	p5-CPAN-Meta-YAML>=0.008:${PORTSDIR}/devel/p5-CPAN-Meta-YAML \
		p5-JSON-PP>=2.27200:${PORTSDIR}/converters/p5-JSON-PP

PERL_CONFIGURE=	yes

MAN3=		Parse::CPAN::Meta.3

.include <bsd.port.mk>
