# New ports collection makefile for:	wordpress
# Date created:		2011-12-27
# Whom:			Mihail Timofeev <9267096@gmail.com>
#			(based on wordpress by Elvis Chiang)
#
# $FreeBSD$
#

PORTNAME=	wordpress
PORTVERSION=	3.4.1
CATEGORIES=	russian www
MASTER_SITES=	http://ru.wordpress.org/
DISTNAME=	${PORTNAME}-${PORTVERSION}-ru_RU

MAINTAINER=	9267096@gmail.com
COMMENT=	A state-of-the-art semantic personal publishing platform

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

CONFLICTS_INSTALL=	wordpress-3.* de-wordpress-3.* ja-wordpress-3.*

NO_BUILD=	yes
USE_ZIP=	yes
USE_PHP=	curl gd mysql pcre tokenizer xml zip
WANT_PHP_WEB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST=		${WRKDIR}/pkg-plist
PORTDOCS=	license.txt readme.html
SUB_FILES=	pkg-message

pre-everything::
	@${ECHO_CMD} "If you want to upgrade, you must read upgrade document."
	@${ECHO_CMD} ""
	@sleep 1

pre-install:
	cd ${WRKSRC}/ && \
		(${FIND} -s * -type f | ${SED} -e 's|^|%%WWWDIR%%/|'; \
		${FIND} -d . -type d | ${SED} -e 's|^\.|@dirrm %%WWWDIR%%|') > ${PLIST}
	if [ ! -f ${WRKSRC}/wp-config-sample.php ]; then ${CP} \
		${WRKSRC}/wp-config.php.sample ${WRKSRC}/wp-config.php; fi

do-install:
	${INSTALL} -d -g ${WWWGRP} -m 755 -o ${WWWOWN} ${WWWDIR}/
	${CP} -R ${WRKSRC}/ ${WWWDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
