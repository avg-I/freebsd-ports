# New ports collection makefile for:   hiawatha
# Date created:        24 november 2006
# Whom:                Hugo Leisink <hugo@leisink.net>
#
# $FreeBSD$
#

PORTNAME=	hiawatha
PORTVERSION=	8.4
CATEGORIES=	www
MASTER_SITES=	http://www.hiawatha-webserver.org/files/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	An advanced and secure webserver for Unix

LICENSE=	GPLv2

PORTDOCS=	AUTHORS ChangeLog INSTALL
CONFIG_FILES=	hiawatha.conf mimetype.conf cgi-wrapper.conf php-fcgi.conf \
		toolkit.conf index.xslt

MAN1=		cgi-wrapper.1 hiawatha.1 php-fcgi.1 ssi-cgi.1 wigwam.1

MAKE_JOBS_SAFE=	yes
SUB_FILES=	pkg-message
USE_CMAKE=	yes
USE_LDCONFIG=	yes
USE_RC_SUBR=	hiawatha php-fcgi
WANT_GNOME=	yes

CMAKE_ARGS+=	-DCMAKE_INSTALL_BINDIR=${PREFIX}/bin \
		-DCMAKE_INSTALL_SBINDIR=${PREFIX}/sbin \
		-DCMAKE_INSTALL_SYSCONFDIR=${ETCDIR} \
		-DCMAKE_INSTALL_LIBDIR=${PREFIX}/lib \
		-DCONFIG_DIR=${ETCDIR} \
		-DWEBROOT_DIR=${WWWDIR} \
		-DCMAKE_INSTALL_MANDIR=${PREFIX}/man \
		-DLOG_DIR=/var/log/hiawatha \
		-DPID_DIR=/var/run

OPTIONS_DEFINE=	CACHE \
		CHROOT \
		COMMAND \
		DEBUG \
		DOCS \
		IPV6 \
		MONITOR \
		RPROXY \
		SSL \
		TOOLKIT \
		XSLT

OPTIONS_DEFAULT=CACHE IPV6 RPROXY SSL TOOLKIT XSLT DOCS

CACHE_DESC=	Enable cache support
CHROOT_DESC=	Enable chroot support
COMMAND_DESC=	Enable Hiawatha command channel
MONITOR_DESC=	Enable Hiawatha Monitor
RPROXY_DESC=	Enable reverse proxy
TOOLKIT_DESC=	Enable URL toolkit
XSLT_DESC=	Enable XSLT support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCACHE}
CMAKE_ARGS+=	-DENABLE_CACHE=on
.else
CMAKE_ARGS+=	-DENABLE_CACHE=off
.endif

.if ${PORT_OPTIONS:MCHROOT}
CMAKE_ARGS+=	-DENABLE_CHROOT=on
.else
CMAKE_ARGS+=	-DENABLE_CHROOT=off
.endif

.if ${PORT_OPTIONS:MCOMMAND}
CMAKE_ARGS+=	-DENABLE_COMMAND=on
.else
CMAKE_ARGS+=	-DENABLE_COMMAND=off
.endif

.if ${PORT_OPTIONS:MDEBUG}
CMAKE_ARGS+=	-DENABLE_DEBUG=on
.else
CMAKE_ARGS+=	-DENABLE_DEBUG=off
.endif

.if ${PORT_OPTIONS:MIPV6}
CMAKE_ARGS+=	-DENABLE_IPV6=on
.else
CMAKE_ARGS+=	-DENABLE_IPV6=off
.endif

.if ${PORT_OPTIONS:MMONITOR}
CMAKE_ARGS+=	-DENABLE_MONITOR=on
.else
CMAKE_ARGS+=	-DENABLE_MONITOR=off
.endif

.if ${PORT_OPTIONS:MRPROXY}
CMAKE_ARGS+=	-DENABLE_RPROXY=on
.else
CMAKE_ARGS+=	-DENABLE_RPROXY=off
.endif

.if ${PORT_OPTIONS:MSSL}
CMAKE_ARGS+=	-DENABLE_SSL=on
.else
CMAKE_ARGS+=	-DENABLE_SSL=off
.endif

.if ${PORT_OPTIONS:MTOOLKIT}
CMAKE_ARGS+=	-DENABLE_TOOLKIT=on
.else
CMAKE_ARGS+=	-DENABLE_TOOLKIT=off
.endif

.if ${PORT_OPTIONS:MXSLT}
USE_GNOME+=	libxslt
CMAKE_ARGS+=	-DENABLE_XSLT=on
.else
CMAKE_ARGS+=	-DENABLE_XSLT=off
.endif

PLIST_SUB+=	ECHO_MSG=${ECHO_MSG}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
	${WRKSRC}/man/hiawatha.1.in ${WRKSRC}/man/cgi-wrapper.1.in \
	${WRKSRC}/man/php-fcgi.1.in ${WRKSRC}/config/cgi-wrapper.conf \
	${WRKSRC}/config/hiawatha.conf.in ${WRKSRC}/config/php-fcgi.conf.in

	@${REINPLACE_CMD} -e 's|/etc/hiawatha|${ETCDIR}|g' \
	${WRKSRC}/man/hiawatha.1.in ${WRKSRC}/man/cgi-wrapper.1.in \
	${WRKSRC}/man/php-fcgi.1.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.for FILE in ${CONFIG_FILES}
	@${INSTALL_DATA} ${WRKSRC}/config/${FILE} ${PREFIX}/etc/hiawatha/${FILE}.sample
	@if [ ! -f ${PREFIX}/etc/hiawatha/${FILE} ]; then \
		${CP} -p ${WRKSRC}/config/${FILE} ${PREFIX}/etc/hiawatha/${FILE} ; \
	fi
.endfor

	@if [ ! -d ${WWWDIR} ]; then \
		@${MKDIR} ${WWWDIR} ; \
	fi
	@${CP} ${WRKSRC}/extra/index.html ${WWWDIR}/index.hiawatha.html
	@if [ ! -f ${WWWDIR}/index.html ] ; then \
		${CP} ${WRKSRC}/extra/index.html ${WWWDIR}/ ; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
