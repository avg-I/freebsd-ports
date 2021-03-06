# New ports collection makefile for:	gnash
# Date created:				12 Jan 2006
# Whom:					Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	gnash
PORTVERSION=	0.8.10
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	GNU/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNU Flash movie player

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		curl.6:${PORTSDIR}/ftp/curl \
		gif.5:${PORTSDIR}/graphics/giflib \
		speex.1:${PORTSDIR}/audio/speex \
		nspr4:${PORTSDIR}/devel/nspr

CONFLICTS=	gnash-devel-[0-9]*

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libltdl
GNU_CONFIGURE=	yes
WANT_SDL=	yes
WANT_GNOME=	yes
USE_GCC=	4.2+	# triggers compiler error on gcc 3.4
WANT_GSTREAMER=	yes
USE_GNOME=	pkgconfig libxml2
USE_XORG=	x11 xau xdmcp xext xi xinerama ice sm xv
USE_AUTOTOOLS=	libltdl
MAKE_JOBS_SAFE=	yes
INSTALLS_ICONS=	yes

# jemalloc leads to infinite recursion on FreeBSD
CONFIGURE_ARGS=	--with-boost-incl="${LOCALBASE}/include" \
		--with-boost-lib="${LOCALBASE}/lib" \
		--disable-testsuite \
		--with-plugins-install=prefix \
		--sysconfdir="${WRKDIR}/etc" \
		--disable-jemalloc \
		--disable-silent-rules

GNASHVER=	${PORTVERSION}
CONFIG_FILES=	gnashpluginrc gnashrc

WRKSRC=		${WRKDIR}/${PORTNAME}-${GNASHVER}
PLIST_SUB+=	GNASHVER="${GNASHVER}"

USE_LDCONFIG=	${PREFIX}/lib/gnash

MAN1=		cygnal.1 findmicrophones.1 findwebcams.1 \
		flvdumper.1 gnash.1 gprocessor.1 \
		rtmpget.1 soldumper.1

OPTIONS_DEFINE=	PLUGIN CYGNAL VAAPI FFMPEG GSTREAMER
OPTIONS_SINGLE=	GUI RENDERER
OPTIONS_SINGLE_GUI=	GTK2 KDE3 KDE4
OPTIONS_SINGLE_RENDERER=AGG OPENGL CAIRO
#OPTIONS_SINGLE_MEDIA=	FFMPEG GSTREAMER
OPTIONS_DEFAULT=GTK2 PLUGIN AGG FFMPEG VAAPI

NO_OPTIONS_SORT=yes
PLUGIN_DESC=	browser plugin
CYGNAL_DESC=	Cygnal media server
AGG_DESC=	AGG renderer
OPENGL_DESC=	OpenGL renderer (broken)
CAIRO_DESC=	Cairo renderer (experimental)
FFMPEG_DESC=	ffmpeg media handler
GSTREAMER_DESC=	GStreamer media handler
VAAPI_DESC=	VAAPI support (requires FFMPEG)

.include <bsd.port.options.mk>

# Cygnal option processing
.if ${PORT_OPTIONS:MCYGNAL}
PLIST_SUB+=	CYGNAL=""
CONFIGURE_ARGS+=	--enable-cygnal
CONFIG_FILES+=	cygnalrc
.else
PLIST_SUB+=	CYGNAL="@comment "
CONFIGURE_ARGS+=	--disable-cygnal
.endif

# NLS option processing (not sure if --disable-nls actually has any effect)
.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

#
# Plugin configuration
#
.if ${PORT_OPTIONS:MGTK2} && ${PORT_OPTIONS:MPLUGIN}
USE_WEBPLUGINS=		native
WEBPLUGINS_FILES=	libgnashplugin.so
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"
PLIST_SUB+=	NPAPI=""
CONFIGURE_ARGS+=--with-npapi-plugindir="${WEBPLUGINS_DIR}"
BUILD_DEPENDS+=	${LOCALBASE}/lib/libxul/xpidl:${PORTSDIR}/www/libxul
RUN_DEPENDS+=	${LOCALBASE}/lib/libxul/xpidl:${PORTSDIR}/www/libxul
.else
PLIST_SUB+=	NPAPI="@comment "
CONFIGURE_ARGS+=	--disable-npapi
.endif

.if ${PORT_OPTIONS:MKDE3} && ${PORT_OPTIONS:MPLUGIN}
PLIST_SUB+=	KPARTS3=""
USE_LDCONFIG+=	${PREFIX}/lib/kde3
.else
PLIST_SUB+=	KPARTS3="@comment "
CONFIGURE_ARGS+=	--disable-kparts3
.endif

.if ${PORT_OPTIONS:MKDE4} && ${PORT_OPTIONS:MPLUGIN}
PLIST_SUB+=	KPARTS4=""
USE_LDCONFIG+=	${KDE4_PREFIX}/lib/kde4
CONFIGURE_ARGS+=	--with-kde4_prefix=${PREFIX}/kde4
.else
PLIST_SUB+=	KPARTS4="@comment "
CONFIGURE_ARGS+=	--disable-kparts4
.endif

#
# GUI options processing
#
GNASH_GUIS=

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME=	gtk20 atk gconf2
GNASH_GUIS+=	gtk
PLIST_SUB+=	GTK=""
MAN1+=		gnash-gtk-launcher.1 gtk-gnash.1
.else
PLIST_SUB+=	GTK="@comment "
.endif

.if ${PORT_OPTIONS:MKDE3} 
GNASH_GUIS+=	kde3
PLIST_SUB+=	KDE=""
USE_KDELIBS_VER=3
.else
PLIST_SUB+=	KDE="@comment "
.endif

.if ${PORT_OPTIONS:MKDE4}
GNASH_GUIS+=	kde4
PLIST_SUB+=	KDE4=""
USE_QT4=	moc_build
QT_NONSTANDARD=	yes
USE_KDE4=	kdehier kdelibs
CONFIGURE_ENV+=	KDE4_CONFIG="${KDE4_PREFIX}/bin/kde4-config"
.if exists(${LOCALBASE}/lib/libkdeui.so)
IGNORE=		KDE4 GUI can't be built when KDE3 is installed. Please rerun 'make config' and disable KDE4 GUI or deinstall kdelibs-3
.endif
MAN1+=		gnash-qt-launcher.1 kde4-gnash.1
.else
PLIST_SUB+=	KDE4="@comment "
.endif

.if ${PORT_OPTIONS:MKDE3} && ${PORT_OPTIONS:MKDE4}
IGNORE=		KDE3 and KDE4 GUIs are mutually exclusive. Please rerun 'make config' and disable one of these
.endif

.if ${GNASH_GUIS} == ""
IGNORE=		needs at least one GUI enabled. Please rerun 'make config' and enable GTK, KDE or KDE4
.endif

CONFIGURE_ARGS+=--enable-gui=`${ECHO} ${GNASH_GUIS} | ${TR} ' ' ,`

#
# Renderer options processing
#
GNASH_RENDERERS=

.if ${PORT_OPTIONS:MAGG} 
LIB_DEPENDS+=		agg.2:${PORTSDIR}/graphics/agg
GNASH_RENDERERS+=	agg
.endif

.if ${PORT_OPTIONS:MOPENGL} 
USE_GL=			yes
GNASH_RENDERERS+=	ogl
.if ${PORT_OPTIONS:MGTK2}
LIB_DEPENDS+=		gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext
.endif
.endif

.if ${PORT_OPTIONS:MCAIRO}
.if ${PORT_OPTIONS:MKDE3} || ${PORT_OPTIONS:MKDE4}
IGNORE=			doesn't support Cairo renderer with KDE/KDE4 gui. Please rerun 'make config' and select different renderer or disable KDE/KDE4 GUIs
.endif
LIB_DEPENDS+=		cairo.2:${PORTSDIR}/graphics/cairo
GNASH_RENDERERS+=	cairo
.endif

.if ${GNASH_RENDERERS} == ""
IGNORE=			needs at least one renderer enabled. Please rerun 'make config' and enable AGG, OPENGL or CAIRO
.endif

CONFIGURE_ARGS+=	--enable-renderer=`${ECHO} ${GNASH_RENDERERS} | ${TR} ' ' ,`

#
# Hardware acceleration options processing
#
.if ${PORT_OPTIONS:MVAAPI}
.if empty(PORT_OPTIONS:MFFMPEG)
IGNORE=			VAAPI currently works only with FFMPEG. Please rerun 'make config' and enable FFMPEG.
.endif
LIB_DEPENDS+=		va.1:${PORTSDIR}/multimedia/libva
PLIST_SUB+=		VAAPI=""
.else
CONFIGURE_ARGS+=	--enable-hwaccel=none # XVideo
PLIST_SUB+=		VAAPI="@comment "
.endif

#
# Media handler options processing
#
.if ${PORT_OPTIONS:MFFMPEG} && empty(PORT_OPTIONS:MGSTREAMER) 
LIB_DEPENDS+=		avcodec.1:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=	--enable-media=ffmpeg
USE_SDL+=		sdl
.elif empty(PORT_OPTIONS:MFFMPEG) && ${PORT_OPTIONS:MGSTREAMER}
USE_GSTREAMER=		yes
CONFIGURE_ARGS+=	--enable-media=gst
USE_SDL+=		sdl
.elif empty(PORT_OPTIONS:MFFMPEG) && empty(PORT_OPTIONS:MGSTREAMER)
CONFIGURE_ARGS+=	--enable-media=none
IGNORE=			can't be built with multiple media handlers enabled. Please rerun 'make config' and leave one or none of them (ffmpeg|gstreamer)
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
PLIST_SUB+=		GSTREAMER=""
.else
PLIST_SUB+=		GSTREAMER="@comment "
.endif

.include <bsd.port.pre.mk>

pre-everything::
.if ${PORT_OPTIONS:MOPENGL}
	@${ECHO_CMD} "OpenGL support is currently broken (Gnash hangs using 100% CPU). Use at your own risk"
	@sleep 3
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^PTHREAD_[LC][IF]*=/ d; s|-lpthread|${PTHREAD_LIBS}|' \
		-e '/KDE4_APPSDATADIR=/ s|share/kde4|share|' \
		-e 's|/usr/local|${LOCALBASE}|g; \
		s|/lib64|/lib|g; \
		s|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/configure \
		${WRKSRC}/macros/libslist ${WRKSRC}/macros/incllist
	@${REINPLACE_CMD} -e '/^pkgconfigdir =/ s|libdir)|exec_prefix)/libdata|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^man1dir =/ s|=.*|= ${MAN1PREFIX}/man/man1|' \
		${WRKSRC}/doc/C/Makefile.in

post-install:
.for conf in ${CONFIG_FILES}
	@${INSTALL_DATA} ${WRKDIR}/etc/${conf} ${PREFIX}/etc/${conf}.dist
	if [ ! -f ${PREFIX}/etc/${conf} ]; then \
		${INSTALL_DATA} ${PREFIX}/etc/${conf}.dist \
			${PREFIX}/etc/${conf}; \
	fi
.endfor
.if ${PORT_OPTIONS:MPLUGIN}
.if ${PORT_OPTIONS:MGTK2}
	${MKDIR} ${WEBPLUGINS_DIR}
	@cd ${INSTALL_WRKSRC}/plugin && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install-plugin
.endif
.if ${PORT_OPTIONS:MKDE3}
	@cd ${INSTALL_WRKSRC}/plugin/klash && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install-plugin
.endif
.if ${PORT_OPTIONS:MKDE4}
	@cd ${INSTALL_WRKSRC}/plugin/klash4 && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install-plugin
.endif
.endif

.include <bsd.port.post.mk>
