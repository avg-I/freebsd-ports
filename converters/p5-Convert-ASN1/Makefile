# New ports collection makefile for:	p5-Convert-ASN1
# Date created:				October 27, 2000
# Whom:	      				Marc Fournier <scrappy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Convert-ASN1
PORTVERSION=	0.26
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module to encode and decode ASN.1 data structures

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Math-BigInt>=1.997:${PORTSDIR}/math/p5-Math-BigInt
RUN_DEPENDS=	p5-Math-BigInt>=1.997:${PORTSDIR}/math/p5-Math-BigInt

PERL_CONFIGURE=	yes

MAN3=		Convert::ASN1.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.90:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
