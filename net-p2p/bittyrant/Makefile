# New ports collection makefile for:	bittyrant
# Date created:				2007-04-19
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	bittyrant
PORTVERSION=	1.1
PORTREVISION=	6
CATEGORIES=	net-p2p java
MASTER_SITES=	http://bittyrant.cs.washington.edu/dist_010807/
DISTNAME=	BitTyrant-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java BitTorrent client optimized for fast download performance

BUILD_DEPENDS=	${JAVALIBDIR}/log4j.jar:${PORTSDIR}/devel/log4j \
		${JAVALIBDIR}/commons-cli.jar:${PORTSDIR}/java/jakarta-commons-cli \
		${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit \
		${JAVALIBDIR}/${SWT}.jar:${PORTSDIR}/x11-toolkits/${SWT}
RUN_DEPENDS=	${JAVALIBDIR}/${SWT}.jar:${PORTSDIR}/x11-toolkits/${SWT}

USE_ZIP=	yes
USE_DOS2UNIX=	build.xml \
		org/gudy/azureus2/ui/swt/test/PrintTransferTypes.java \
		org/gudy/azureus2/platform/macosx/access/jnilib/OSXAccess.java
USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_OS=	native
USE_ANT=	yes
WRKSRC=		${WRKDIR}/BitTyrant

OPTIONS_DEFINE=	SWTDEVEL
OPTIONS_DEFAULT=	SWTDEVEL
SWTDEVEL_DESC=	Use SWT Development port

# build classpath from BUILD_DEPENDS
MAKE_ENV=	LANG=C
CLASSPATH_JARS=	${BUILD_DEPENDS:C/:.+$//:M*.jar}

PLIST_FILES=	bin/${PORTNAME} \
		%%JAVAJARDIR%%/${PORTNAME}.jar

SUB_FILES=	${PORTNAME}
SUB_LIST=	JARFILE="${PORTNAME}.jar" \
		JAVA="${LOCALBASE}/bin/java" \
		LIBDIR="${LOCALBASE}/lib" \
		SWTJAR="${JAVAJARDIR}/${SWT}.jar"

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
BROKEN=		Does not build
.endif

.if ${PORT_OPTIONS:MSWTDEVEL}
SWT=		swt-devel
.else
SWT=		swt
.endif

CLASSPATH=.
.for jar in ${CLASSPATH_JARS}
CLASSPATH:=${CLASSPATH}:${jar}
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|refid="libs.classpath"|path="${CLASSPATH}"|' \
		${WRKSRC}/build.xml

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dist/Azureus2.jar \
		${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
