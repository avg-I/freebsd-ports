--- cpp.orig/demo/IceGrid/secure/makecerts.py	2011-06-15 21:43:58.000000000 +0200
+++ cpp/demo/IceGrid/secure/makecerts.py	2012-03-04 19:55:44.000000000 +0100
@@ -44,8 +44,9 @@
 print
 print
 
-createCertificate("registry", "IceGrid Registry")
-createCertificate("node", "IceGrid Node")
+createCertificate("master", "Master")
+createCertificate("slave", "Slave")
+createCertificate("node", "Node")
 createCertificate("glacier2", "Glacier2")
 createCertificate("server", "Server")
 
