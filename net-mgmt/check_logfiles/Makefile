# New ports collection makefile for:    check_logfile
# Date created:         11 Mar 2011
# Whom:                 flo@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	check_logfiles
PORTVERSION=	3.4.3.1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://labs.consol.de/wp-content/uploads/2011/03/

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Nagios plugin which scans log files for specific patterns

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=	--with-trusted-path=/bin:/sbin:/usr/bin:/usr/sbin:${LOCALBASE}/bin:${LOCALBASE}/sbin \
			--libexecdir=${PREFIX}/libexec/nagios \

.include <bsd.port.mk>
