# New ports collection makefile for:	pypanda
# Date created:				3 September 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pypanda
PORTVERSION=	0.6
PORTREVISION=	6
CATEGORIES=	misc
MASTER_SITES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Viewer for San Diego Zoo Pandacam written in Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game

USE_PYTHON=	yes

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${DATADIR}
.for ext in py pyc pyo jpg png
	${INSTALL_DATA} ${WRKSRC}/*.${ext} ${DATADIR}
.endfor
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
	@printf "#!/bin/sh\ncd ${DATADIR} && \
		exec ${PYTHON_CMD} ${DATADIR}/pypanda.py\n" > ${WRKDIR}/pypanda.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/pypanda.sh ${PREFIX}/bin/pypanda

.include <bsd.port.mk>
