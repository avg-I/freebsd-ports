# New ports collection makefile for:    check_mysql_health
# Date created:         November 8, 2010
# Whom:                 pgollucci@p6m7g8.com
#
# $FreeBSD$
#

PORTNAME=	check_mysql_health
PORTVERSION=	2.1.5.1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://labs.consol.de/wp-content/uploads/2011/04/

MAINTAINER=	ssanders@taximagic.com
COMMENT=	Nagios plugin to check various parameters of a MySQL database

RUN_DEPENDS=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-statefiles-dir=${NAGIOSDIR} \
		--with-nagios-user=${NAGIOSUSER} \
		--with-nagios-group=${NAGIOSGROUP} \
		--with-mymodules-dir=${PREFIX}/libexec/nagios \
		--with-mymodules-dyn-dir=${PREFIX}/libexec/nagios \
		--libexecdir=${PREFIX}/libexec/nagios \
		--with-perl=${PERL}

USE_PERL5=	yes

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
NAGIOSDIR?=	/var/spool/nagios

PLIST_FILES=	libexec/nagios/check_mysql_health
PLIST_DIRS=	libexec/nagios

.include <bsd.port.mk>
