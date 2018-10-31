#ifndef APPLICATION_SOLAR_HPP
#define APPLICATION_SOLAR_HPP

#include "application.hpp"
#include "model.hpp"
#include "structs.hpp"
#include "scene_graph.hpp"

using namespace std;
using namespace glm;

// gpu representation of model
class ApplicationSolar : public Application {
 public:
  // Struct with the data to render planets
  // http://www.cplusplus.com/doc/tutorial/structures/
  struct node
  {
    glm::fvec3 rotation;
    glm::fvec3 translation;
    glm::fvec3 scale;
    string nodeName;
  };

  // Declare list to store the planet nodes
  vector<node> node_list;

  // allocate and initialize objects
  ApplicationSolar(std::string const& resource_path);
  // free allocated objects
  ~ApplicationSolar();

  // react to key input
  void keyCallback(int key, int action, int mods);
  //handle delta mouse movement input
  void mouseCallback(double pos_x, double pos_y);
  //handle resizing
  void resizeCallback(unsigned width, unsigned height);

  // draw all objects
  void render() const;

  // Delaration of planet data
  void init_node(glm::fvec3 rotation, glm::fvec3 translation, glm::fvec3 scale, std::string nodeName);

 protected:
  void initializeShaderPrograms();
  void initializeGeometry();
  // update uniform values
  void uploadUniforms();
  // upload projection matrix
  void uploadProjection();
  // upload view matrix
  void uploadView();

  // cpu representation of model
  model_object planet_object;
  
  // camera transform matrix
  glm::fmat4 m_view_transform;
  // camera projection matrix
  glm::fmat4 m_view_projection;
};

#endif