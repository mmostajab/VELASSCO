
// STL
#include <iostream>

// VELaSSCo
#include "EDM.h"

#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include "EDM/StorageModule.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

// VELaSSCo
#include "cJSON.h"
#include "base64.h"
#include "Helpers.h"


using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace dli;

using namespace boost;



// TODO: reference additional headers your program requires here


StorageModuleClient *clp = NULL;

using namespace VELaSSCo;

bool EDM::startConnection( const char *DB_hostname, const int DB_port) {
  std::cout << FUNCTION_NAME << " not implemented yet" << std::endl;
  return true;
}

bool EDM::stopConnection() {
  std::cout << FUNCTION_NAME << " not implemented yet" << std::endl;
  return true;
}

std::string EDM::getStatusDB() {
  std::cout << FUNCTION_NAME << " not implemented yet" << std::endl;
  return "EDM::Status not implemented.";
}

std::string EDM::getListOfModelNames( std::string &report, std::vector< FullyQualifiedModelName> &listOfModelNames, 
				      const std::string &sessionID, const std::string &model_group_qualifier, 
				      const std::string &model_name_pattern) {
  std::cout << FUNCTION_NAME << " not implemented yet" << std::endl;
  report = "EDM::getListOfModelNames not implemented.";
  return "Error";
}

std::string EDM::findModel( std::string &report, std::string &modelID, 
			    const std::string &sessionID, const std::string &unique_model_name_pattern, const std::string &requested_access) {
  std::cout << FUNCTION_NAME << " not implemented yet" << std::endl;
  report = "EDM::findModel not implemented.";
  return "Error";
}

std::string EDM::getResultOnVertices( const std::string &sessionID,
                                      const std::string &modelID,
                                      const std::string &analysisID,
                                      const double       timeStep,
                                      const std::string &resultID,
                                      const std::string &listOfVertices )
{

#ifdef WIN32
   rvOpenModel rvOM;
   string modelID_of_VELaSSCo_HbaseBasicTest_part_1;
   dli::rvGetResultFromVerticesID_B results;
   vector<int64_t> vertexIDs;

   clp->OpenModel(rvOM, sessionID, "VELaSSCo_HbaseBasicTest_part_1", "read");
   modelID_of_VELaSSCo_HbaseBasicTest_part_1 = rvOM.modelID;
   clp->GetResultFromVerticesID(results, sessionID, modelID_of_VELaSSCo_HbaseBasicTest_part_1, "", vertexIDs, "Height", 1.0, "geometry");

   string resultString;
   for (vector<VertexResult>::iterator resIter = results.vertexResults.begin(); resIter != results.vertexResults.end(); resIter++) {
      char cb[2048], *np;
      int length = sprintf(cb, "%d ", resIter->vertexID); np = cb + length;
      for (vector<double>::iterator value = resIter->resuls.begin(); value != resIter->resuls.end(); value++) {
         length = sprintf(np, " %f", *value); np = np + length;
      }
      sprintf(np, "\n");
      resultString += cb;
   }
   return resultString;
 #endif

}

#ifdef WIN32

// #define EDM_TEST_SERVER
#ifdef EDM_TEST_SERVER

/*===============================================================================================*/
int main(int argc, char* argv[])
/*
Program to test VELaSSCo Data Layer thrift based server. The program has 3 command line parameters:
1. server address
2. server port number
3. Command

Command can eiter be "all" or any of the querynames.
=================================================================================================*/
{
   const char *command = "all";
   const char *server = "localhost";
   int port = 9090;

   if (argc > 1) server = argv[1];
   if (argc > 2) port = atoi(argv[2]);
   if (argc > 3) command = argv[3];

   boost::shared_ptr<TTransport> socket(new TSocket(server, port));
   boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
   boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
   StorageModuleClient client(protocol);
   clp = &client;

#ifdef WIN32
   WSADATA wsaData = {};
   WORD wVersionRequested = MAKEWORD(2, 2);
   int err = WSAStartup(wVersionRequested, &wsaData);
#endif

   try {
      transport->open();
      
      VELaSSCo::EDM myEDM;

      string sessionID = "";
      string vertices = myEDM.getResultOnVertices(sessionID, "0", "analysis", 00.1, "resultID", "LOV");
      printf("getResultOnVertices returns the following string\n");
      printf(vertices.data());

      transport->close();
   } catch (TException &tx) {
      printf("ERROR: %s\n", tx.what());
   }
   printf("\n\nEnter a character to stop the program.\n");
   getchar();
   return 0;
}

#endif

#endif
