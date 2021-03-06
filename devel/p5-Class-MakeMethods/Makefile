# New ports collection makefile for:	Class::MakeMethods
# Date created:				24 Jan 2002
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Class-MakeMethods
PORTVERSION=	1.010
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generate common types of methods

PERL_CONFIGURE=	yes

MAN3=		Class::MakeMethods.3 \
		Class::MakeMethods::Attribute.3 \
		Class::MakeMethods::Autoload.3 \
		Class::MakeMethods::Basic.3 \
		Class::MakeMethods::Basic::Array.3 \
		Class::MakeMethods::Basic::Global.3 \
		Class::MakeMethods::Basic::Hash.3 \
		Class::MakeMethods::Composite.3 \
		Class::MakeMethods::Composite::Array.3 \
		Class::MakeMethods::Composite::Global.3 \
		Class::MakeMethods::Composite::Hash.3 \
		Class::MakeMethods::Composite::Inheritable.3 \
		Class::MakeMethods::Composite::Universal.3 \
		Class::MakeMethods::Docs::Catalog.3 \
		Class::MakeMethods::Docs::Changes.3 \
		Class::MakeMethods::Docs::Examples.3 \
		Class::MakeMethods::Docs::ReadMe.3 \
		Class::MakeMethods::Docs::RelatedModules.3 \
		Class::MakeMethods::Docs::ToDo.3 \
		Class::MakeMethods::Emulator.3 \
		Class::MakeMethods::Emulator::AccessorFast.3 \
		Class::MakeMethods::Emulator::Inheritable.3 \
		Class::MakeMethods::Emulator::MethodMaker.3 \
		Class::MakeMethods::Emulator::Singleton.3 \
		Class::MakeMethods::Emulator::Struct.3 \
		Class::MakeMethods::Emulator::accessors.3 \
		Class::MakeMethods::Emulator::mcoder.3 \
		Class::MakeMethods::Evaled.3 \
		Class::MakeMethods::Evaled::Hash.3 \
		Class::MakeMethods::Standard.3 \
		Class::MakeMethods::Standard::Array.3 \
		Class::MakeMethods::Standard::Global.3 \
		Class::MakeMethods::Standard::Hash.3 \
		Class::MakeMethods::Standard::Inheritable.3 \
		Class::MakeMethods::Standard::Universal.3 \
		Class::MakeMethods::Template.3 \
		Class::MakeMethods::Template::Array.3 \
		Class::MakeMethods::Template::Class.3 \
		Class::MakeMethods::Template::ClassInherit.3 \
		Class::MakeMethods::Template::ClassName.3 \
		Class::MakeMethods::Template::ClassVar.3 \
		Class::MakeMethods::Template::Flyweight.3 \
		Class::MakeMethods::Template::Generic.3 \
		Class::MakeMethods::Template::Global.3 \
		Class::MakeMethods::Template::Hash.3 \
		Class::MakeMethods::Template::InsideOut.3 \
		Class::MakeMethods::Template::Inheritable.3 \
		Class::MakeMethods::Template::PackageVar.3 \
		Class::MakeMethods::Template::Ref.3 \
		Class::MakeMethods::Template::Scalar.3 \
		Class::MakeMethods::Template::Static.3 \
		Class::MakeMethods::Template::Struct.3 \
		Class::MakeMethods::Template::StructBuiltin.3 \
		Class::MakeMethods::Template::Universal.3 \
		Class::MakeMethods::Utility::ArraySplicer.3 \
		Class::MakeMethods::Utility::DiskCache.3 \
		Class::MakeMethods::Utility::Inheritable.3 \
		Class::MakeMethods::Utility::Ref.3 \
		Class::MakeMethods::Utility::TextBuilder.3

post-extract:
		@${RM} ${WRKSRC}/benchmark.pl
		@${PERL} -pi -e '$$_="" if m|benchmark.pl|' ${WRKSRC}/MANIFEST

.include <bsd.port.mk>
