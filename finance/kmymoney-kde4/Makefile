# $FreeBSD$

PORTNAME=	kmymoney
PORTVERSION=	4.6.2
PORTREVISION=	3
CATEGORIES=	finance kde
MASTER_SITES=	SF/${PORTNAME}2/KMyMoney-KDE4/${PORTVERSION}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	KDE 4.x-based personal finance manager

LICENSE=	GPLv2

LIB_DEPENDS=	boost_graph:${PORTSDIR}/devel/boost-libs \
		alkimia:${PORTSDIR}/finance/libalkimia

OPTIONS_DEFINE=	CALENDAR KBANKING OFX QUOTES
OPTIONS_DEFAULT=CALENDAR

CALENDAR_DESC=	Enable Calendar plugin
KBANKING_DESC=	Enable KBanking plugin
OFX_DESC=	Enable OFX plugin
QUOTES_DESC=	Enable online price quotes

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_PKGCONFIG=	build
USE_QT4=	gui dbus network phonon sql svg xml \
		qmake_build moc_build rcc_build uic_build
USE_KDE4=	kdehier kdeprefix automoc4 kdelibs pimlibs sharedmime
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		kmymoney.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCALENDAR}
LIB_DEPENDS+=	ical:${PORTSDIR}/devel/libical
CMAKE_ARGS+=	-DENABLE_LIBICAL:BOOL=ON
PLIST_SUB+=	CALENDAR=""
.else
CMAKE_ARGS+=	-DENABLE_LIBICAL:BOOL=OFF
PLIST_SUB+=	CALENDAR="@comment "
.endif

.if ${PORT_OPTIONS:MKBANKING}
LIB_DEPENDS+=	gwengui-qt4:${PORTSDIR}/devel/gwenhywfar-qt4 \
		aqbanking:${PORTSDIR}/finance/aqbanking
CMAKE_ARGS+=	-DENABLE_KBANKING:BOOL=ON
PLIST_SUB+=	KBANKING=""
.else
CMAKE_ARGS+=	-DENABLE_KBANKING:BOOL=OFF
PLIST_SUB+=	KBANKING="@comment "
.endif

.if ${PORT_OPTIONS:MOFX}
LIB_DEPENDS+=	ofx:${PORTSDIR}/finance/libofx
CMAKE_ARGS+=	-DENABLE_LIBOFX:BOOL=ON
PLIST_SUB+=	OFX=""
.else
CMAKE_ARGS+=	-DENABLE_LIBOFX:BOOL=OFF
PLIST_SUB+=	OFX="@comment "
.endif

.if ${PORT_OPTIONS:MQUOTES}
USE_PERL5_RUN=	yes
RUN_DEPENDS+=	p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-Finance-Quote>=0:${PORTSDIR}/finance/p5-Finance-Quote \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-Writer>=0:${PORTSDIR}/textproc/p5-XML-Writer \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
.endif

.include <bsd.port.mk>
