/**
 * Based on DEM_SCHEMA_VELASSCO_V5 of 2105-06-17, JH updated with Alvaro.
 *
 * Thrift structs does not support subclassing/inheritence. 
 * When the EDM data model use subclasses this is modeled using struct with attributes 
 * that reflects the union of the attributes in the subclasses and an enum that tells
 * which subclass the actual struct representes. Attributes that not belongs to all subclasses
 * are declaerd as optional.
 */

namespace cpp DEM_Inject


struct Timestep {
   1: double                     time_value
   2: list<Particle>             consists_of     
   3: optional list<FEM_mesh>    boundary
   4: optional list<Contact>     has_contact
}

enum Particle_type {
  Template_nn_Particle = 1,
  Sphere_Particle = 2
}
struct Particle {
   1: i64                                 id
   2: i64                                 group
   3: Particle_type                       type
   4: optional double                     radius
}

struct Vertex {
   1: list<double>                        vetex_position
}

struct FEM_mesh {
   1: string                              name
   2: list<list<Vertex>>                  facets
}

enum Contact_type {
  Geometry_Contact = 1,
  Particle_Contact = 2
}
struct Contact {
   1: list<double>                        contact_location
   2: Contact_type                        type
   3: Particle                            P1
   4: optional Particle                   P2
   5: optional FEM_mesh                   geometry
}

enum Particle_result_property_type {
   Velocity = 1,
   Mass = 2,
   Volume = 3,
   Custom_property_vector = 4,
   Custom_property_scalar = 5
}
struct Particle_result_property {
   1: Particle_result_property_type       type
   2: optional list<double>               x_y_z
   3: optional double                     scalar
   4: optional string                     name
}

struct Particle_result {
   1: Particle                            valid_for
   2: Timestep                            calculated_for
   3: list<Particle_result_property>      result_properties
}



struct Simulation {
   1: string                              name
   2: list<Timestep>                      consists_of
}  


service DEM_Injector {

/**
   returns a session if if the user exists with the specified password and the specified role or an empty role.
 */
   string UserLogin (
      1: string                           user_name,
      2: string                           role,
      3: string                           password)



/**
   Stop access to the system by a given session id and release all resources held by that session
 */
   string UserLogout (
      1: string                           sessionID)


/**
   Stores a DEM_simulation with all timesteps, meshes, particles, results etc. in one operation in EDM
   If the model exists, the Simulation is added to the model. If the model does not exist, it is created. 
 */
   string StoreDEM_Simulation (
      1: string                           sessionID,
      2: string                           model_name,
      3: Simulation                       theSimulation)



/**
   Stores a DEM_simulation with all timesteps, meshes, particles, results etc. in one operation in EDM
   If the model exists, the Simulation is added to the model. If the model does not exist, it is created. 
 */
   string DeleteModelContent (
      1: string                           sessionID,
      2: string                           model_name)

}


service FEM_Injector {

   string StoreFEM_Simulation (
      1: string                           model_name
      2: Simulation                       theSimulation)

}

