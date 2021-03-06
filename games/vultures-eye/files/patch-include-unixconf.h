--- include/unixconf.h.orig	Thu Apr  6 02:59:04 2006
+++ include/unixconf.h	Thu May 25 00:15:21 2006
@@ -19,13 +19,13 @@
  */
 
 /* define exactly one of the following four choices */
-/* #define BSD 1 */	/* define for 4.n/Free/Open/Net BSD  */
+#define BSD 1		/* define for 4.n/Free/Open/Net BSD  */
 			/* also for relatives like SunOS 4.x, DG/UX, and */
 			/* older versions of Linux */
 /* #define ULTRIX */	/* define for Ultrix v3.0 or higher (but not lower) */
 			/* Use BSD for < v3.0 */
 			/* "ULTRIX" not to be confused with "ultrix" */
-#define SYSV		/* define for System V, Solaris 2.x, newer versions */
+/* #define SYSV	*/	/* define for System V, Solaris 2.x, newer versions */
 			/* of Linux */
 /* #define HPUX */	/* Hewlett-Packard's Unix, version 6.5 or higher */
 			/* use SYSV for < v6.5 */
