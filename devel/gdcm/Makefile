# New ports collection Makefile for:	gdcm
# Date created:				24 February 2010
# Whom:					gahr
#
# $FreeBSD$

PORTNAME=	gdcm
PORTVERSION=	${GDCM_MAJ}.${GDCM_MIN}
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF/gdcm/gdcm%202.x/GDCM%20${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Grassroots DICOM library

LIB_DEPENDS=	openjpeg.2:${PORTSDIR}/graphics/openjpeg \
   		expat.6:${PORTSDIR}/textproc/expat2

OPTIONS=	VTK "Build the VTK bindings" off

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	${PREFIX}/lib \
		${PREFIX}/lib/gdcm-${GDCM_MAJ}
CFLAGS+=	-I${LOCALBASE}/include
CMAKE_OUTSOURCE=yes
CMAKE_ARGS+=	-DGDCM_PDF_DOCUMENTATION:BOOL=NO \
   		-DGDCM_USE_SYSTEM_OPENSSL:BOOL=YES \
		-DGDCM_USE_SYSTEM_EXPAT:BOOL=YES \
		-DGDCM_USE_SYSTEM_OPENJPEG:BOOL=YES \
		-DGDCM_USE_SYSTEM_ZLIB:BOOL=YES \
		-DGDCM_BUILD_APPLICATIONS:BOOL=YES \
    		-DGDCM_BUILD_SHARED_LIBS:BOOL=YES \
		-DGDCM_BUILD_EXAMPLES:BOOL=NO \
		-DGDCM_INSTALL_DATA_DIR:STRING=${DATADIR}

.include <bsd.port.options.mk>

.if defined(WITH_VTK)
LIB_DEPENDS+=	vtkHybrid.5:${PORTSDIR}/math/vtk5
CMAKE_ARGS+=	-DGDCM_USE_VTK:BOOL=YES
PLIST_SUB+=	VTK=""
.else
PLIST_SUB+=	VTK="@comment "
.endif

GDCM_SO=	2
GDCM_MAJ=	2.2
GDCM_MIN=	0

PLIST_SUB+=	GDCM_MAJ="${GDCM_MAJ}" \
		GDCM_MIN="${GDCM_MIN}" \
		GDCM_SO="${GDCM_SO}"

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen \
   		pdflatex:${PORTSDIR}/print/teTeX-base
CMAKE_ARGS+=	-DGDCM_DOCUMENTATION:BOOL=YES \
		-DGDCM_INSTALL_MAN_DIR:STRING=${MAN1PREFIX}/man
MAN1=		gdcm2vtk.1 gdcmconv.1 gdcmanon.1 gdcmgendir.1 \
		gdcmdump.1 gdcmimg.1 gdcminfo.1 gdcmpdf.1 \
		gdcmraw.1 gdcmscanner.1 gdcmtar.1 gdcmviewer.1 \
		gdcm2pnm.1 gdcmdiff.1 gdcmscu.1
PORTDOCS=	*
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${INSTALL_WRKSRC}/Utilities/doxygen/html && ${COPYTREE_SHARE} \* ${DOCSDIR}
.else
CMAKE_ARGS+=	-DGDCM_DOCUMENTATION:BOOL=NO
.endif

post-patch:
	${REINPLACE_CMD} -e 's| NAMELINK_SKIP||; s| NAMELINK_ONLY||' ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|share/man|man|g;' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
