# New ports collection makefile for:	sysutils/p5-Sys-Syslog
# Date created:				27 May 2008
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Sys-Syslog
PORTVERSION=	0.31
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Perl interface to the UNIX syslog(3) calls

PERL_CONFIGURE=	yes

MAN3=	Sys::Syslog.3

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} test

.include <bsd.port.mk>
