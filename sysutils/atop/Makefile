# New ports collection makefile for:	atop
# Date created:		2011-06-30
# Whom:			Alex Samorukov <samm@os2.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	atop
PORTVERSION=	1.26.b8
CATEGORIES=	sysutils
MASTER_SITES=	BERLIOS
MASTER_SITE_SUBDIR=atop-freebsd
DISTNAME=	${PORTNAME}-${PORTVERSION:C|b|fbsd.beta|}

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	ASCII Monitor for system resources and process activity

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_NCURSES=	yes
MAKEFILE=	Makefile.fbsd
MAN1=		atop.1 atopsar.1
MAN5=		atoprc.5
LOGDIR?=	/var/log/atop

USE_RC_SUBR=	atop
PLIST_SUB+=	LOGDIR="${LOGDIR}"
SUB_FILES=	pkg-message
SUB_LIST=	LOGDIR="${LOGDIR}"

PORTDOCS=	AUTHOR \
		ChangeLog \
		ChangeLog.FreeBSD \
		README \
		README.FreeBSD

do-install:
		@${INSTALL_PROGRAM} ${WRKSRC}/atop ${PREFIX}/bin
		@${LN} -sf ${PREFIX}/bin/atop ${PREFIX}/bin/atopsar
.for manpage in ${MAN1}
		@${INSTALL_MAN} ${WRKSRC}/man/${manpage} ${MAN1PREFIX}/man/man1/
.endfor
		@${INSTALL_MAN} ${WRKSRC}/man/${MAN5} ${MAN5PREFIX}/man/man5/
		@${MKDIR} ${LOGDIR}
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
