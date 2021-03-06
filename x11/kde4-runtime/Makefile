# -*-mode: makefile-*-
# New ports collection makefile for:	kdebase-runtime
# Date created:				22 Januar 2008
# Whom:					kde@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	kde-runtime
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic applications for the KDE system

LIB_DEPENDS=	IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		exiv2.12:${PORTSDIR}/graphics/exiv2 \
		xine.2:${PORTSDIR}/multimedia/libxine \
		slp.1:${PORTSDIR}/net/openslp \
		smbclient.0:${PORTSDIR}/net/samba-libsmbclient \
		ssh.4:${PORTSDIR}/security/libssh \
		qzeitgeist.1:${PORTSDIR}/sysutils/qzeitgeist

# Explicitly depend on libssh to avoid interference with ssh.4 from
# compat7x.
BUILD_DEPENDS=	${LOCALBASE}/lib/libssh.so:${PORTSDIR}/security/libssh

RUN_DEPENDS=	cagibid:${PORTSDIR}/net/cagibi

CONFLICTS=	kdebase-runtime-4.[0-6].* kdebase-workspace-4.5.[0-5] nepomukcontroller-0.2

USE_XZ=	yes
USE_GETTEXT=	yes
USE_KDE4=	kdehier kdelibs kdeprefix \
		attica automoc4 ontologies sharedmime soprano strigi
KDE4_BUILDENV=	yes
USE_QT4=	dbus declarative designer gui phonon qt3support \
		script svg webkit xml \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	x11 xcursor
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		kdesu.1
MAN8=		nepomukserver.8 nepomukservicestub.8

SUB_FILES=	nepomuk-env.sh

OPTIONS=	NEPOMUK "Nepomuk semantic desktop (installs Virtuoso)" off \
		SPEAKER "Speaker setup GUI (requires PulseAudio)" off \
		ZEITGEIST "Event logging via Zeitgeist" off

# Explicitly disable ALSA, see for details:
# http://mail.kde.org/pipermail/kde-freebsd/2010-March/008015.html
CMAKE_ARGS+=	-DWITH_ALSA:BOOL=OFF

.include <bsd.port.options.mk>

.if defined(WITH_NEPOMUK)
RUN_DEPENDS+=	virtuoso-t:${PORTSDIR}/databases/virtuoso
.endif

.if defined(WITH_SPEAKER)
CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=ON
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio \
		canberra.0:${PORTSDIR}/audio/libcanberra
USE_GNOME=	glib20
.else
CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=OFF
.endif

.if defined(WITH_ZEITGEIST)
RUN_DEPENDS+=	zeitgeist-daemon:${PORTSDIR}/sysutils/zeitgeist
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800505 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900012)
LIB_DEPENDS+=	lzma.5:${PORTSDIR}/archivers/xz
.endif

.if ${KDE4_PREFIX} != ${LOCALBASE}
PLIST_SUB+=	HACK=""
.else
PLIST_SUB+=	HACK="@comment "
post-extract:
	${REINPLACE_CMD} -e '/add_subdirectory.*hicolor/d' \
		${PATCH_WRKSRC}/pics/CMakeLists.txt
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		${PATCH_WRKSRC}/khelpcenter/infotree.cpp \
		${PATCH_WRKSRC}/kioslave/info/kde-info2html.conf \
		${PATCH_WRKSRC}/kioslave/man/kio_man.cpp \
		${PATCH_WRKSRC}/kioslave/man/man2html.cpp \
		${PATCH_WRKSRC}/cmake/modules/FindCLucene.cmake

post-install:
	${MKDIR} ${PREFIX}/env
	${INSTALL_SCRIPT} ${WRKDIR}/nepomuk-env.sh ${PREFIX}/env

.include <bsd.port.post.mk>
