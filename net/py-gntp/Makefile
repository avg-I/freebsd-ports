# $FreeBSD$

PORTNAME=	gntp
PORTVERSION=	0.7
#PORTREVISION=	0
CATEGORIES=	net
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Growl Notification Transport Protocol for Python

LICENSE=	MIT

GH_ACCOUNT=	kfdm
GH_COMMIT=	e177c37
GH_TAGNAME=	master

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=	DOCS

USE_GITHUB=	yes
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PYDISTUTILS_BUILD_TARGET+=	build_sphinx

post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/build/sphinx/html && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
