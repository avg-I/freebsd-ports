--- cpp.orig/src/Ice/ConnectionI.cpp	2011-06-15 21:43:58.000000000 +0200
+++ cpp/src/Ice/ConnectionI.cpp	2012-03-04 20:14:52.000000000 +0100
@@ -31,7 +31,7 @@
 using namespace Ice;
 using namespace IceInternal;
 
-Ice::LocalObject* IceInternal::upCast(ConnectionI* p) { return p; }
+Ice::LocalObject* Ice::upCast(ConnectionI* p) { return p; }
 
 namespace
 {
@@ -600,6 +600,7 @@
     }
     catch(const LocalException& ex)
     {
+        status = IceInternal::AsyncStatusQueued; // this is only to apeace the compiler
         setState(StateClosed, ex);
         assert(_exception.get());
         _exception->ice_throw();
@@ -971,6 +972,7 @@
     }
     catch(const Ice::LocalException& ex)
     {
+        status = IceInternal::AsyncStatusQueued; // this is only to apeace the compiler
         setState(StateClosed, ex);
         assert(_exception.get());
         _exception->ice_throw();
