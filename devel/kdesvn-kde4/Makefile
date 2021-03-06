# New ports collection makefile for:	kdesvn
# Date created:				08 April 2006
# Whom:					Yuan Jue <yuanjue@yuanjue.net>
#
# $FreeBSD$

PORTNAME=	kdesvn
DISTVERSION=	1.6.0
CATEGORIES=	devel kde
MASTER_SITES=	http://kdesvn.alwins-world.de/downloads/

MAINTAINER=	naylor.b.david@gmail.com
COMMENT=	KDE frontend for Subversion

LIB_DEPENDS=	svn_client-1:${PORTSDIR}/devel/subversion

LICENSE=	GPLv2

CONFLICTS=	qsvn-[0-9]*

USE_BZIP2=	yes
USE_CMAKE=	yes
CMAKE_ARGS+=	-DSUBVERSION_INCLUDE_DIR=${LOCALBASE}/include/subversion-1
USE_KDE4=	kdelibs kdeprefix automoc4
USE_LDCONFIG=	yes
USE_QT4=	corelib gui xml network dbus svg qt3support sql \
		qmake_build moc_build rcc_build uic_build linguist_build
MAKE_JOBS_SAFE=	yes

MAN1=		kdesvn.1 kdesvnaskpass.1

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	${RM} ${WRKSRC}/src/kiosvn/svn*.protocol
.if empty(PORT_OPTIONS:MDOCS)
	${ECHO} "ADD_SUBDIRECTORY(man)" > ${WRKSRC}/doc/CMakeLists.txt
.endif
.if empty(PORT_OPTIONS:MNLS)
	${REINPLACE_CMD} -e 's,ADD_SUBDIRECTORY(po), ,g' \
		${WRKSRC}/CMakeLists.txt
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
