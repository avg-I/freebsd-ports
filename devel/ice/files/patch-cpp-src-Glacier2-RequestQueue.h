--- cpp.orig/src/Glacier2/RequestQueue.h	2011-06-15 21:43:58.000000000 +0200
+++ cpp/src/Glacier2/RequestQueue.h	2012-03-04 19:39:27.000000000 +0100
@@ -65,8 +65,12 @@
     bool addRequest(const RequestPtr&);
     void flushRequests(std::set<Ice::ObjectPrx>&);
 
+    void destroy();
+
 private:
 
+    void destroyInternal();
+
     void flush();
     void flush(std::set<Ice::ObjectPrx>&);
 
@@ -83,6 +87,7 @@
     std::deque<RequestPtr> _requests;
     bool _pendingSend;
     RequestPtr _pendingSendRequest;
+    bool _destroyed;
 };
 typedef IceUtil::Handle<RequestQueue> RequestQueuePtr;
 
