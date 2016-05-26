// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "QueryManager.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::VELaSSCo;

class QueryManagerHandler : virtual public QueryManagerIf {
 public:
  QueryManagerHandler() {
    // Your initialization goes here
  }

  /**
   * User login
   * 
   * @param url
   * @param name
   * @param password
   */
  void UserLogin(UserLogin_Result& _return, const std::string& url, const std::string& name, const std::string& password) {
    // Your implementation goes here
    printf("UserLogin\n");
  }

  /**
   * User logout
   * 
   * @param sessionID
   */
  void UserLogout(UserLogout_Result& _return, const SessionID sessionID) {
    // Your implementation goes here
    printf("UserLogout\n");
  }

  /**
   * Query
   * 
   * @param sessionID
   * @param query
   */
  void Query(Query_Result& _return, const SessionID sessionID, const std::string& query) {
    // Your implementation goes here
    printf("Query\n");
  }

  /**
   * StatusDB: status of the HBase system or the EDM system
   * 
   * @param sessionID
   */
  void GetStatusDB(StatusDB_Result& _return, const SessionID sessionID) {
    // Your implementation goes here
    printf("GetStatusDB\n");
  }

  /**
   * StatusDB: status of the HBase system or the EDM system
   * 
   * @param sessionID
   */
  void StopVELaSSCo(StopVELaSSCo_Result& _return, const SessionID sessionID) {
    // Your implementation goes here
    printf("StopVELaSSCo\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<QueryManagerHandler> handler(new QueryManagerHandler());
  shared_ptr<TProcessor> processor(new QueryManagerProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}
