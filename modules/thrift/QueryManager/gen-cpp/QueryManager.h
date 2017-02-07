/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef QueryManager_H
#define QueryManager_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "QueryManager_types.h"

namespace VELaSSCo {

#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class QueryManagerIf {
 public:
  virtual ~QueryManagerIf() {}

  /**
   * User login
   * 
   * @param url
   * @param name
   * @param password
   */
  virtual void UserLogin(UserLogin_Result& _return, const std::string& url, const std::string& name, const std::string& password) = 0;

  /**
   * User logout
   * 
   * @param sessionID
   */
  virtual void UserLogout(UserLogout_Result& _return, const SessionID sessionID) = 0;

  /**
   * Query
   * 
   * @param sessionID
   * @param query
   */
  virtual void Query(Query_Result& _return, const SessionID sessionID, const std::string& query) = 0;

  /**
   * StatusDB: status of the HBase system or the EDM system
   * 
   * @param sessionID
   */
  virtual void GetStatusDB(StatusDB_Result& _return, const SessionID sessionID) = 0;

  /**
   * StatusDB: status of the HBase system or the EDM system
   * 
   * @param sessionID
   */
  virtual void StopVELaSSCo(StopVELaSSCo_Result& _return, const SessionID sessionID) = 0;
};

class QueryManagerIfFactory {
 public:
  typedef QueryManagerIf Handler;

  virtual ~QueryManagerIfFactory() {}

  virtual QueryManagerIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(QueryManagerIf* /* handler */) = 0;
};

class QueryManagerIfSingletonFactory : virtual public QueryManagerIfFactory {
 public:
  QueryManagerIfSingletonFactory(const boost::shared_ptr<QueryManagerIf>& iface) : iface_(iface) {}
  virtual ~QueryManagerIfSingletonFactory() {}

  virtual QueryManagerIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(QueryManagerIf* /* handler */) {}

 protected:
  boost::shared_ptr<QueryManagerIf> iface_;
};

class QueryManagerNull : virtual public QueryManagerIf {
 public:
  virtual ~QueryManagerNull() {}
  void UserLogin(UserLogin_Result& /* _return */, const std::string& /* url */, const std::string& /* name */, const std::string& /* password */) {
    return;
  }
  void UserLogout(UserLogout_Result& /* _return */, const SessionID /* sessionID */) {
    return;
  }
  void Query(Query_Result& /* _return */, const SessionID /* sessionID */, const std::string& /* query */) {
    return;
  }
  void GetStatusDB(StatusDB_Result& /* _return */, const SessionID /* sessionID */) {
    return;
  }
  void StopVELaSSCo(StopVELaSSCo_Result& /* _return */, const SessionID /* sessionID */) {
    return;
  }
};

typedef struct _QueryManager_UserLogin_args__isset {
  _QueryManager_UserLogin_args__isset() : url(false), name(false), password(false) {}
  bool url :1;
  bool name :1;
  bool password :1;
} _QueryManager_UserLogin_args__isset;

class QueryManager_UserLogin_args {
 public:

  QueryManager_UserLogin_args(const QueryManager_UserLogin_args&);
  QueryManager_UserLogin_args& operator=(const QueryManager_UserLogin_args&);
  QueryManager_UserLogin_args() : url(), name(), password() {
  }

  virtual ~QueryManager_UserLogin_args() throw();
  std::string url;
  std::string name;
  std::string password;

  _QueryManager_UserLogin_args__isset __isset;

  void __set_url(const std::string& val);

  void __set_name(const std::string& val);

  void __set_password(const std::string& val);

  bool operator == (const QueryManager_UserLogin_args & rhs) const
  {
    if (!(url == rhs.url))
      return false;
    if (!(name == rhs.name))
      return false;
    if (!(password == rhs.password))
      return false;
    return true;
  }
  bool operator != (const QueryManager_UserLogin_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryManager_UserLogin_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QueryManager_UserLogin_pargs {
 public:


  virtual ~QueryManager_UserLogin_pargs() throw();
  const std::string* url;
  const std::string* name;
  const std::string* password;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryManager_UserLogin_result__isset {
  _QueryManager_UserLogin_result__isset() : success(false) {}
  bool success :1;
} _QueryManager_UserLogin_result__isset;

class QueryManager_UserLogin_result {
 public:

  QueryManager_UserLogin_result(const QueryManager_UserLogin_result&);
  QueryManager_UserLogin_result& operator=(const QueryManager_UserLogin_result&);
  QueryManager_UserLogin_result() {
  }

  virtual ~QueryManager_UserLogin_result() throw();
  UserLogin_Result success;

  _QueryManager_UserLogin_result__isset __isset;

  void __set_success(const UserLogin_Result& val);

  bool operator == (const QueryManager_UserLogin_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QueryManager_UserLogin_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryManager_UserLogin_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryManager_UserLogin_presult__isset {
  _QueryManager_UserLogin_presult__isset() : success(false) {}
  bool success :1;
} _QueryManager_UserLogin_presult__isset;

class QueryManager_UserLogin_presult {
 public:


  virtual ~QueryManager_UserLogin_presult() throw();
  UserLogin_Result* success;

  _QueryManager_UserLogin_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _QueryManager_UserLogout_args__isset {
  _QueryManager_UserLogout_args__isset() : sessionID(false) {}
  bool sessionID :1;
} _QueryManager_UserLogout_args__isset;

class QueryManager_UserLogout_args {
 public:

  QueryManager_UserLogout_args(const QueryManager_UserLogout_args&);
  QueryManager_UserLogout_args& operator=(const QueryManager_UserLogout_args&);
  QueryManager_UserLogout_args() : sessionID(0) {
  }

  virtual ~QueryManager_UserLogout_args() throw();
  SessionID sessionID;

  _QueryManager_UserLogout_args__isset __isset;

  void __set_sessionID(const SessionID val);

  bool operator == (const QueryManager_UserLogout_args & rhs) const
  {
    if (!(sessionID == rhs.sessionID))
      return false;
    return true;
  }
  bool operator != (const QueryManager_UserLogout_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryManager_UserLogout_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QueryManager_UserLogout_pargs {
 public:


  virtual ~QueryManager_UserLogout_pargs() throw();
  const SessionID* sessionID;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryManager_UserLogout_result__isset {
  _QueryManager_UserLogout_result__isset() : success(false) {}
  bool success :1;
} _QueryManager_UserLogout_result__isset;

class QueryManager_UserLogout_result {
 public:

  QueryManager_UserLogout_result(const QueryManager_UserLogout_result&);
  QueryManager_UserLogout_result& operator=(const QueryManager_UserLogout_result&);
  QueryManager_UserLogout_result() {
  }

  virtual ~QueryManager_UserLogout_result() throw();
  UserLogout_Result success;

  _QueryManager_UserLogout_result__isset __isset;

  void __set_success(const UserLogout_Result& val);

  bool operator == (const QueryManager_UserLogout_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QueryManager_UserLogout_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryManager_UserLogout_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryManager_UserLogout_presult__isset {
  _QueryManager_UserLogout_presult__isset() : success(false) {}
  bool success :1;
} _QueryManager_UserLogout_presult__isset;

class QueryManager_UserLogout_presult {
 public:


  virtual ~QueryManager_UserLogout_presult() throw();
  UserLogout_Result* success;

  _QueryManager_UserLogout_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _QueryManager_Query_args__isset {
  _QueryManager_Query_args__isset() : sessionID(false), query(false) {}
  bool sessionID :1;
  bool query :1;
} _QueryManager_Query_args__isset;

class QueryManager_Query_args {
 public:

  QueryManager_Query_args(const QueryManager_Query_args&);
  QueryManager_Query_args& operator=(const QueryManager_Query_args&);
  QueryManager_Query_args() : sessionID(0), query() {
  }

  virtual ~QueryManager_Query_args() throw();
  SessionID sessionID;
  std::string query;

  _QueryManager_Query_args__isset __isset;

  void __set_sessionID(const SessionID val);

  void __set_query(const std::string& val);

  bool operator == (const QueryManager_Query_args & rhs) const
  {
    if (!(sessionID == rhs.sessionID))
      return false;
    if (!(query == rhs.query))
      return false;
    return true;
  }
  bool operator != (const QueryManager_Query_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryManager_Query_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QueryManager_Query_pargs {
 public:


  virtual ~QueryManager_Query_pargs() throw();
  const SessionID* sessionID;
  const std::string* query;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryManager_Query_result__isset {
  _QueryManager_Query_result__isset() : success(false) {}
  bool success :1;
} _QueryManager_Query_result__isset;

class QueryManager_Query_result {
 public:

  QueryManager_Query_result(const QueryManager_Query_result&);
  QueryManager_Query_result& operator=(const QueryManager_Query_result&);
  QueryManager_Query_result() {
  }

  virtual ~QueryManager_Query_result() throw();
  Query_Result success;

  _QueryManager_Query_result__isset __isset;

  void __set_success(const Query_Result& val);

  bool operator == (const QueryManager_Query_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QueryManager_Query_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryManager_Query_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryManager_Query_presult__isset {
  _QueryManager_Query_presult__isset() : success(false) {}
  bool success :1;
} _QueryManager_Query_presult__isset;

class QueryManager_Query_presult {
 public:


  virtual ~QueryManager_Query_presult() throw();
  Query_Result* success;

  _QueryManager_Query_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _QueryManager_GetStatusDB_args__isset {
  _QueryManager_GetStatusDB_args__isset() : sessionID(false) {}
  bool sessionID :1;
} _QueryManager_GetStatusDB_args__isset;

class QueryManager_GetStatusDB_args {
 public:

  QueryManager_GetStatusDB_args(const QueryManager_GetStatusDB_args&);
  QueryManager_GetStatusDB_args& operator=(const QueryManager_GetStatusDB_args&);
  QueryManager_GetStatusDB_args() : sessionID(0) {
  }

  virtual ~QueryManager_GetStatusDB_args() throw();
  SessionID sessionID;

  _QueryManager_GetStatusDB_args__isset __isset;

  void __set_sessionID(const SessionID val);

  bool operator == (const QueryManager_GetStatusDB_args & rhs) const
  {
    if (!(sessionID == rhs.sessionID))
      return false;
    return true;
  }
  bool operator != (const QueryManager_GetStatusDB_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryManager_GetStatusDB_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QueryManager_GetStatusDB_pargs {
 public:


  virtual ~QueryManager_GetStatusDB_pargs() throw();
  const SessionID* sessionID;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryManager_GetStatusDB_result__isset {
  _QueryManager_GetStatusDB_result__isset() : success(false) {}
  bool success :1;
} _QueryManager_GetStatusDB_result__isset;

class QueryManager_GetStatusDB_result {
 public:

  QueryManager_GetStatusDB_result(const QueryManager_GetStatusDB_result&);
  QueryManager_GetStatusDB_result& operator=(const QueryManager_GetStatusDB_result&);
  QueryManager_GetStatusDB_result() {
  }

  virtual ~QueryManager_GetStatusDB_result() throw();
  StatusDB_Result success;

  _QueryManager_GetStatusDB_result__isset __isset;

  void __set_success(const StatusDB_Result& val);

  bool operator == (const QueryManager_GetStatusDB_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QueryManager_GetStatusDB_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryManager_GetStatusDB_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryManager_GetStatusDB_presult__isset {
  _QueryManager_GetStatusDB_presult__isset() : success(false) {}
  bool success :1;
} _QueryManager_GetStatusDB_presult__isset;

class QueryManager_GetStatusDB_presult {
 public:


  virtual ~QueryManager_GetStatusDB_presult() throw();
  StatusDB_Result* success;

  _QueryManager_GetStatusDB_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _QueryManager_StopVELaSSCo_args__isset {
  _QueryManager_StopVELaSSCo_args__isset() : sessionID(false) {}
  bool sessionID :1;
} _QueryManager_StopVELaSSCo_args__isset;

class QueryManager_StopVELaSSCo_args {
 public:

  QueryManager_StopVELaSSCo_args(const QueryManager_StopVELaSSCo_args&);
  QueryManager_StopVELaSSCo_args& operator=(const QueryManager_StopVELaSSCo_args&);
  QueryManager_StopVELaSSCo_args() : sessionID(0) {
  }

  virtual ~QueryManager_StopVELaSSCo_args() throw();
  SessionID sessionID;

  _QueryManager_StopVELaSSCo_args__isset __isset;

  void __set_sessionID(const SessionID val);

  bool operator == (const QueryManager_StopVELaSSCo_args & rhs) const
  {
    if (!(sessionID == rhs.sessionID))
      return false;
    return true;
  }
  bool operator != (const QueryManager_StopVELaSSCo_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryManager_StopVELaSSCo_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QueryManager_StopVELaSSCo_pargs {
 public:


  virtual ~QueryManager_StopVELaSSCo_pargs() throw();
  const SessionID* sessionID;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryManager_StopVELaSSCo_result__isset {
  _QueryManager_StopVELaSSCo_result__isset() : success(false) {}
  bool success :1;
} _QueryManager_StopVELaSSCo_result__isset;

class QueryManager_StopVELaSSCo_result {
 public:

  QueryManager_StopVELaSSCo_result(const QueryManager_StopVELaSSCo_result&);
  QueryManager_StopVELaSSCo_result& operator=(const QueryManager_StopVELaSSCo_result&);
  QueryManager_StopVELaSSCo_result() {
  }

  virtual ~QueryManager_StopVELaSSCo_result() throw();
  StopVELaSSCo_Result success;

  _QueryManager_StopVELaSSCo_result__isset __isset;

  void __set_success(const StopVELaSSCo_Result& val);

  bool operator == (const QueryManager_StopVELaSSCo_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QueryManager_StopVELaSSCo_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryManager_StopVELaSSCo_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryManager_StopVELaSSCo_presult__isset {
  _QueryManager_StopVELaSSCo_presult__isset() : success(false) {}
  bool success :1;
} _QueryManager_StopVELaSSCo_presult__isset;

class QueryManager_StopVELaSSCo_presult {
 public:


  virtual ~QueryManager_StopVELaSSCo_presult() throw();
  StopVELaSSCo_Result* success;

  _QueryManager_StopVELaSSCo_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class QueryManagerClient : virtual public QueryManagerIf {
 public:
  QueryManagerClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  QueryManagerClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void UserLogin(UserLogin_Result& _return, const std::string& url, const std::string& name, const std::string& password);
  void send_UserLogin(const std::string& url, const std::string& name, const std::string& password);
  void recv_UserLogin(UserLogin_Result& _return);
  void UserLogout(UserLogout_Result& _return, const SessionID sessionID);
  void send_UserLogout(const SessionID sessionID);
  void recv_UserLogout(UserLogout_Result& _return);
  void Query(Query_Result& _return, const SessionID sessionID, const std::string& query);
  void send_Query(const SessionID sessionID, const std::string& query);
  void recv_Query(Query_Result& _return);
  void GetStatusDB(StatusDB_Result& _return, const SessionID sessionID);
  void send_GetStatusDB(const SessionID sessionID);
  void recv_GetStatusDB(StatusDB_Result& _return);
  void StopVELaSSCo(StopVELaSSCo_Result& _return, const SessionID sessionID);
  void send_StopVELaSSCo(const SessionID sessionID);
  void recv_StopVELaSSCo(StopVELaSSCo_Result& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class QueryManagerProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<QueryManagerIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (QueryManagerProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_UserLogin(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_UserLogout(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Query(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_GetStatusDB(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_StopVELaSSCo(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  QueryManagerProcessor(boost::shared_ptr<QueryManagerIf> iface) :
    iface_(iface) {
    processMap_["UserLogin"] = &QueryManagerProcessor::process_UserLogin;
    processMap_["UserLogout"] = &QueryManagerProcessor::process_UserLogout;
    processMap_["Query"] = &QueryManagerProcessor::process_Query;
    processMap_["GetStatusDB"] = &QueryManagerProcessor::process_GetStatusDB;
    processMap_["StopVELaSSCo"] = &QueryManagerProcessor::process_StopVELaSSCo;
  }

  virtual ~QueryManagerProcessor() {}
};

class QueryManagerProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  QueryManagerProcessorFactory(const ::boost::shared_ptr< QueryManagerIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< QueryManagerIfFactory > handlerFactory_;
};

class QueryManagerMultiface : virtual public QueryManagerIf {
 public:
  QueryManagerMultiface(std::vector<boost::shared_ptr<QueryManagerIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~QueryManagerMultiface() {}
 protected:
  std::vector<boost::shared_ptr<QueryManagerIf> > ifaces_;
  QueryManagerMultiface() {}
  void add(boost::shared_ptr<QueryManagerIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void UserLogin(UserLogin_Result& _return, const std::string& url, const std::string& name, const std::string& password) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->UserLogin(_return, url, name, password);
    }
    ifaces_[i]->UserLogin(_return, url, name, password);
    return;
  }

  void UserLogout(UserLogout_Result& _return, const SessionID sessionID) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->UserLogout(_return, sessionID);
    }
    ifaces_[i]->UserLogout(_return, sessionID);
    return;
  }

  void Query(Query_Result& _return, const SessionID sessionID, const std::string& query) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Query(_return, sessionID, query);
    }
    ifaces_[i]->Query(_return, sessionID, query);
    return;
  }

  void GetStatusDB(StatusDB_Result& _return, const SessionID sessionID) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->GetStatusDB(_return, sessionID);
    }
    ifaces_[i]->GetStatusDB(_return, sessionID);
    return;
  }

  void StopVELaSSCo(StopVELaSSCo_Result& _return, const SessionID sessionID) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->StopVELaSSCo(_return, sessionID);
    }
    ifaces_[i]->StopVELaSSCo(_return, sessionID);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class QueryManagerConcurrentClient : virtual public QueryManagerIf {
 public:
  QueryManagerConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  QueryManagerConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void UserLogin(UserLogin_Result& _return, const std::string& url, const std::string& name, const std::string& password);
  int32_t send_UserLogin(const std::string& url, const std::string& name, const std::string& password);
  void recv_UserLogin(UserLogin_Result& _return, const int32_t seqid);
  void UserLogout(UserLogout_Result& _return, const SessionID sessionID);
  int32_t send_UserLogout(const SessionID sessionID);
  void recv_UserLogout(UserLogout_Result& _return, const int32_t seqid);
  void Query(Query_Result& _return, const SessionID sessionID, const std::string& query);
  int32_t send_Query(const SessionID sessionID, const std::string& query);
  void recv_Query(Query_Result& _return, const int32_t seqid);
  void GetStatusDB(StatusDB_Result& _return, const SessionID sessionID);
  int32_t send_GetStatusDB(const SessionID sessionID);
  void recv_GetStatusDB(StatusDB_Result& _return, const int32_t seqid);
  void StopVELaSSCo(StopVELaSSCo_Result& _return, const SessionID sessionID);
  int32_t send_StopVELaSSCo(const SessionID sessionID);
  void recv_StopVELaSSCo(StopVELaSSCo_Result& _return, const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif

} // namespace

#endif
