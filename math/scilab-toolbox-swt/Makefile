## New ports collection makefile for:	swt
# Date created:				2006-03-28
# Whom:					Max Brazhnikov makc@issp.ac.ru
#
# $FreeBSD$
#

PORTNAME=	swt
PORTVERSION=	0.1.11
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://atoms.scilab.org/toolboxes/swt/${PORTVERSION}/files/
PKGNAMEPREFIX=	scilab-toolbox-
DISTFILES=	${DISTNAME}-1-src${EXTRACT_SUFX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Scilab 1-D and 2-D Wavelet Toolbox

BUILD_DEPENDS=	${SCILAB_CMD}:${PORTSDIR}/math/scilab
RUN_DEPENDS:=	${BUILD_DEPENDS}

SCILAB_CMD=	${LOCALBASE}/bin/scilab
CONTRIBDIR?=	share/scilab/contrib
TOOLBOXDIR_REL?=	${CONTRIBDIR}/${PORTNAME}
TOOLBOXDIR=	${PREFIX}/${TOOLBOXDIR_REL}
PLIST_SUB=	TOOLBOXDIR=${TOOLBOXDIR_REL}
TOOLBOX_SUBDIRS=	demos etc macros

OPTIONS_DEFINE=	HELP SIVP
OPTIONS_DEFAULT=	HELP

HELP_DESC=	Build help files (requires scilab with gui support)
SIVP_DESC=	Enable Image and Video support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSIVP}
RUN_DEPENDS+=	${LOCALBASE}/${CONTRIBDIR}/sivp/loader.sce:${PORTSDIR}/math/scilab-toolbox-sivp
.endif

.if !${PORT_OPTIONS:MHELP}
SCILAB_ARGS=	-nogui
PLIST_SUB+=	HELP="@comment "
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-etc__swt.start
.else
USE_DISPLAY=	yes
MAKE_ENV=	LC_ALL="C"
PLIST_SUB+=	HELP=""
TOOLBOX_SUBDIRS+=	jar
.endif

post-patch:
.if !${PORT_OPTIONS:MHELP}
	${REINPLACE_CMD} -e '/tbx_builder_help/d' ${WRKSRC}/builder.sce
.endif
	${REINPLACE_CMD} -e "s,SWTDIR+','${TOOLBOXDIR}/demos," \
		${WRKSRC}/demos/image.sce
	${ECHO_CMD} quit >> ${WRKSRC}/builder.sce

pre-build:
	${FIND} -d ${WRKSRC} \( -name '*.orig' -or -name '*.bak' \) -delete
.if ${PORT_OPTIONS:MHELP} && !defined(DISPLAY)
	@if [ -f ${WRKDIR}/.Xvfb.pid ]; then \
		${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill || ${TRUE} ; \
		${RM} -f ${WRKDIR}/.Xvfb.pid ; \
	fi
	${LOCALBASE}/bin/Xvfb :1001 -screen 0 800x600x24 -fp ${LOCALBASE}/lib/X11/fonts/misc > /dev/null 2>&1 & ${ECHO} $$! > ${WRKDIR}/.Xvfb.pid
	@sleep 5
.endif

do-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${SCILAB_CMD} ${SCILAB_ARGS} -f builder.sce

post-build:
.if ${PORT_OPTIONS:MHELP} && !defined(DISPLAY)
	@if [ -f ${WRKDIR}/.Xvfb.pid ]; then \
		${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill || ${TRUE} ; \
		${RM} -f ${WRKDIR}/.Xvfb.pid ; \
	fi
.endif

do-install:
	${MKDIR} ${TOOLBOXDIR}/sci_gateway/c
	${INSTALL_DATA} ${WRKSRC}/loader.sce ${TOOLBOXDIR}
	${INSTALL_DATA} ${WRKSRC}/sci_gateway/loader_gateway.sce \
		${TOOLBOXDIR}/sci_gateway
	cd ${WRKSRC}/sci_gateway/c && \
	${INSTALL_DATA} loader.sce ${TOOLBOXDIR}/sci_gateway/c && \
	${INSTALL_PROGRAM} libswt_c.so ${TOOLBOXDIR}/sci_gateway/c
.for d in ${TOOLBOX_SUBDIRS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${TOOLBOXDIR}
.endfor

.include <bsd.port.mk>
