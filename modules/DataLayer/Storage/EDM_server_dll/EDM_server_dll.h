
/*!
   namespace EDM VELaSSCo Data - EDMVD
*/
namespace EDMVD {

   typedef struct Vertex {
      EDMULONG                            id;
      double                              x;
      double                              y;
      double                              z;
   } Vertex;

   enum ModelType { mtFEM, mtDEM, mtAP209, mtUnknown };
}

struct rvGetListOfAnalyses : public CppParameterClass
{
   tRemoteParameter                    *attrPointerArr[3];
   tRemoteParameter                    *status;
   tRemoteParameter                    *report;
   tRemoteParameter                    *analysis_name_list;

   void* operator new(size_t sz, CMemoryAllocator *ma){ return ma->alloc(sz); }
   rvGetListOfAnalyses(CMemoryAllocator *_ma, tRemoteParameter *inAttrPointerArr)
      : CppParameterClass(attrPointerArr, sizeof(attrPointerArr), _ma, inAttrPointerArr) {
      addAddribute(&status, rptSTRING);
      addAddribute(&report, rptSTRING);
      addAddribute(&analysis_name_list, rptStringCollection);
   }
};

using namespace EDMVD;