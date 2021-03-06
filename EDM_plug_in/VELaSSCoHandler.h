class VELaSSCoHandler : public StorageModuleIf, public EDM_interface
{
   char                                         errmsg[2048];
   EDMmodelCache                                *setCurrentModelCache(SdaiModel modelID);
   std::map<SdaiModel, EDMmodelCache*>          caches;
public:
   Repository                                   *cFEMrep;
   Repository                                   *cDEMrep;

   VELaSSCoHandler();
   char *getErrorMsg(CedmError *e);
   char *getErrorMsg(int rstat);

   /**
   * Return the status of the different services
   * which run on the Data Layer.
   * @return string - returns a structured list of avialbe vertices,
   * 	with the attached list of double
   * 	if errors occur the contect is also returned here?
   *
   * @param sessionID
   * @param modelID
   * @param analysisID
   * @param timeStep
   * @param resultID
   * @param listOfVertices
   */
   void GetResultFromVerticesID(rvGetResultFromVerticesID_B& _return, const std::string& sessionID, const std::string& modelID, const std::string& coordinatesSet, const std::vector<int64_t> & vertexIDs, const std::string& resultID, const double time_step, const std::string& analysisID);

   /**
   * returns a session if if the user exists with the specified password and the specified role or an empty role.
   *
   * @param user_name
   * @param role
   * @param password
   */
   void UserLogin(std::string& _return, const std::string& user_name, const std::string& role, const std::string& password);

   /**
   * Stop access to the system by a given session id and release all resources held by that session
   *
   * @param sessionID
   */
   void UserLogout(std::string& _return, const std::string& sessionID) ;

   /**
   * Returns a list of names of data sets that are available from the VELaSSCo platform
   * and - optionally - their properties.
   *
   * @param sessionID
   * @param groupQualifier
   * @param modelNamePattern
   * @param options
   */
   void GetListOfModels(rvGetListOfModels& _return, const std::string& sessionID, const std::string& groupQualifier, const std::string& modelNamePattern, const std::string& options);

   void OpenModel(rvOpenModel& _return, const std::string& sessionID, const std::string& modelName, const std::string& requestedAccess);

   /**
   * Description: Removes the possibility to access a model via a previously assigned
   * GUID (OpenModel). Corresponding housekeeping is wrapped up.
   *
   * @param sessionID
   * @param modelName
   */
   void CloseModel(std::string& _return, const std::string& sessionID, const std::string& modelName);

   /**
   * Description: Store a new thumbnail of a model
   *
   * @param sessionID
   * @param modelID
   * @param imageFile
   */
   void SetThumbnailOfAModel(std::string& _return, const std::string& sessionID, const std::string& modelID, const std::string& imageFile);

   /**
   * Description: Return thumbnail of a model.
   *
   * @param sessionID
   * @param modelID
   */
   void GetThumbnailOfAModel(rvGetThumbnailOfAModel& _return, const std::string& sessionID, const std::string& modelID);

   /**
   * For each point in the input parameter points, the method returns data about the element that contains the point.
   * The number of elements in the returned list of elements shall be the same as the number of points in the input parameter.
   * If the method does not find an element for a point it shall return a dummy element with id equal to -1.
   *
   * @param sessionID
   * @param modelName
   * @param points
   */
   void GetElementOfPointsInSpace(rvGetElementOfPointsInSpace& _return, const std::string& sessionID, const std::string& modelName, const std::vector<Point> & points);
   
   /**
   * GetBoundaryOfLocalMesh will get the partial tetrahedral elements, calculate and output the unique triangles,
   * i.e. triangles that are not shared between two or more elements.
   *
   * @param sessionID
   * @param modelName
   * @param meshID
   * @param analysisID
   * @param time_step
   */
   void GetBoundaryOfLocalMesh(rvGetBoundaryOfLocalMesh& _return, const std::string& sessionID, const std::string& modelName, const std::string& meshID, const std::string& analysisID, const double time_step);

   /**
   * Retrieves the list of time steps for a given model and analysis.
   *
   * @param sessionID
   * @param modelID
   */
   void GetListOfAnalyses(rvGetListOfAnalyses& _return, const std::string& sessionID, const std::string& modelID);

   /**
   * Retrieves the list of time steps for a given model and analysis.
   *
   * @param sessionID
   * @param modelID
   * @param analysisID
   */
   void GetListOfTimeSteps(rvGetListOfTimeSteps& _return, const std::string& sessionID, const std::string& modelID, const std::string& analysisID);

   /**
   * Returns a list of meshes present for the given time-step of that analysis.
   * If analysis == "" and step-value == -1 then the list will be of the 'static' meshes.
   * If analysis != "" and step-value != -1 then the list will be of the 'dynamic' meshes
   * that are present on that step-values of that analysis.
   *
   * @param sessionID
   * @param modelID
   * @param analysisID
   * @param timeStep
   */
   void GetListOfMeshes(rvGetListOfMeshes& _return, const std::string& sessionID, const std::string& modelID, const std::string& analysisID, const double timeStep);

   void CalculateBoundaryOfMesh(FEMmodelCache *fmc, std::vector<Triangle> &elements);
   void ReportError(char *f) { printf(f); }
   void InitQueryCaches();
   void GetFEMresultFromVerticesID(rvGetResultFromVerticesID_B& _return, bool allNodes, std::map<int, int> & nodesInParameter, const char *resultID, const double time_step, const char *analysisID, FEMmodelCache *fmc);
   void GetDEMresultFromVerticesID(rvGetResultFromVerticesID_B& _return, bool allNodes, std::map<int, int> & nodesInParameter, const char *resultID, const double time_step, const char *analysisID, DEMmodelCache *dmc);
};


typedef struct BoundingBox {
   double min_x, min_y, min_z, max_x, max_y, max_z;
} BoundingBox;