#include "application_solar.hpp"
#include "window_handler.hpp"

#include "utils.hpp"
#include "shader_loader.hpp"
#include "model_loader.hpp"
#include "scene_graph.hpp"
#include "node.hpp"
#include "geometry_node.hpp"
#include "camera_node.hpp"

#include <glbinding/gl/gl.h>
// use gl definitions from glbinding 
using namespace gl;
using namespace std;

//dont load gl bindings from glfw
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

ApplicationSolar::ApplicationSolar(std::string const& resource_path)
 :Application{resource_path}
 ,planet_object{}
 ,m_view_transform{translate(glm::fmat4{}, glm::fvec3{0.0f, 4.0f, 30.0f})}
 ,m_view_projection{utils::calculate_projection_matrix(initial_aspect_ratio)}
{

  //Node* planet_node = new Node("SolarSystem");
  // Defining transformations for each element in the solar system
  init_node({0.0f, 1.0f, 0.1f}, {0.0f, 0.0f, 0.0f}, {2.0f, 2.0f, 2.0f}, "sun");
  init_node({0.0f, 1.0f, 0.1f}, {1.0f, 0.0f, 5.0f}, {0.1f, 0.1f, 0.1f}, "mercury");
  init_node({0.0f, 1.0f, 0.1f}, {2.0f, 0.0f, -7.0f}, {0.2f, 0.2f, 0.2f}, "venus");
  init_node({0.0f, 1.0f, 0.1f}, {10.0f, 0.0f, 2.0f}, {0.3f, 0.3f, 0.3f}, "earth");
  init_node({0.0f, 1.0f, 0.1f}, {2.0f, 0.0f, -14.0f}, {0.4f, 0.4f, 0.4f}, "mars");
  init_node({0.0f, 1.0f, 0.1f}, {-16.0f, 0.0f, 0.0f}, {0.8f, 0.8f, 0.8f}, "jupiter");
  init_node({0.0f, 1.0f, 0.1f}, {-5.0f, 0.0f, 18.0f}, {0.5f, 0.5f, 0.5f}, "saturn");
  init_node({0.0f, 1.0f, 0.1f}, {5.0f, 0.0f, -20.0f}, {0.6f, 0.6f, 0.6f}, "uranus");
  init_node({0.0f, 1.0f, 0.1f}, {22.0f, 0.0f, -22.0f}, {0.7f, 0.7f, 0.7f}, "neptune");
  init_node({0.0f, 1.0f, 0.1f}, {30.0f, 0.0f, -20.0f}, {0.1f, 0.1f, 0.1f}, "pluto");

  // Initialiye geomtry and shaders program
  initializeGeometry();
  initializeShaderPrograms();
}

// Define node initializer with transformation vectors and name of the element
void ApplicationSolar::init_node(glm::fvec3 rotation, glm::fvec3 translation, glm::fvec3 scale, std::string nodeName){
  // Initialize node
  node new_node;
  // set rotation for new node
  new_node.rotation = rotation;
  // set translation for new node
  new_node.translation = translation;
  // set scale for new node
  new_node.scale = scale;
  // set name of the node
  new_node.nodeName = nodeName;

  //push new node to the back of the vector list
  node_list.push_back(new_node);
}

ApplicationSolar::~ApplicationSolar() {
  glDeleteBuffers(1, &planet_object.vertex_BO);
  glDeleteBuffers(1, &planet_object.element_BO);
  glDeleteVertexArrays(1, &planet_object.vertex_AO);
}

void ApplicationSolar::render() const {
  // bind shader to upload uniforms

  // loop to draw all the elements of the node list
  for(int i = 0; i < node_list.size(); i++){
    //set node list to a variable which can be manipulated to retrieve data of each element of the solar system
    node currentNode = node_list[i];
    glUseProgram(m_shaders.at("planet").handle);
    // Aply transformations to the elements to be drawn
    glm::fmat4 model_matrix = rotate(glm::fmat4{}, float(glfwGetTime()), currentNode.rotation);
    model_matrix = translate(model_matrix, currentNode.translation);
    model_matrix = scale(model_matrix, currentNode.scale);
    glUniformMatrix4fv(m_shaders.at("planet").u_locs.at("ModelMatrix"),
                       1, GL_FALSE, glm::value_ptr(model_matrix));

    // extra matrix for normal transformation to keep them orthogonal to surface
    glm::fmat4 normal_matrix = glm::inverseTranspose(glm::inverse(m_view_transform) * model_matrix);
    glUniformMatrix4fv(m_shaders.at("planet").u_locs.at("NormalMatrix"),
                       1, GL_FALSE, glm::value_ptr(normal_matrix));

    // bind the VAO to draw
    glBindVertexArray(planet_object.vertex_AO);

    // draw bound vertex array using bound shader
    glDrawElements(planet_object.draw_mode, planet_object.num_elements, model::INDEX.type, NULL);
  }

}

void ApplicationSolar::uploadView() {
  // vertices are transformed in camera space, so camera transform must be inverted
  glm::fmat4 view_matrix = glm::inverse(m_view_transform);
  // upload matrix to gpu
  glUniformMatrix4fv(m_shaders.at("planet").u_locs.at("ViewMatrix"),
                     1, GL_FALSE, glm::value_ptr(view_matrix));
}

void ApplicationSolar::uploadProjection() {
  // upload sun matrix to gpu
  glUniformMatrix4fv(m_shaders.at("planet").u_locs.at("ProjectionMatrix"),
                     1, GL_FALSE, glm::value_ptr(m_view_projection));
}

// update uniform locations
void ApplicationSolar::uploadUniforms() { 
  // bind shader to which to upload unforms
  glUseProgram(m_shaders.at("planet").handle);
  // upload uniform values to new locations
  uploadView();
  uploadProjection();
}

///////////////////////////// intialisation functions /////////////////////////
// load shader sources
void ApplicationSolar::initializeShaderPrograms() {
  // store shader program objects for planet in container
  m_shaders.emplace("planet", shader_program{{{GL_VERTEX_SHADER,m_resource_path + "shaders/simple.vert"},
                                           {GL_FRAGMENT_SHADER, m_resource_path + "shaders/simple.frag"}}});
  
  // request uniform locations for shader program for planet
  m_shaders.at("planet").u_locs["NormalMatrix"] = -1;
  m_shaders.at("planet").u_locs["ModelMatrix"] = -1;
  m_shaders.at("planet").u_locs["ViewMatrix"] = -1;
  m_shaders.at("planet").u_locs["ProjectionMatrix"] = -1;

}

// load models
void ApplicationSolar::initializeGeometry() {
  model planet_model = model_loader::obj(m_resource_path + "models/sphere.obj", model::NORMAL);

  // generate vertex array object
  glGenVertexArrays(1, &planet_object.vertex_AO);
  // bind the array for attaching buffers
  glBindVertexArray(planet_object.vertex_AO);

  // generate generic buffer
  glGenBuffers(1, &planet_object.vertex_BO);
  // bind this as an vertex array buffer containing all attributes
  glBindBuffer(GL_ARRAY_BUFFER, planet_object.vertex_BO);
  // configure currently bound array buffer
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * planet_model.data.size(), planet_model.data.data(), GL_STATIC_DRAW);

  // activate first attribute on gpu
  glEnableVertexAttribArray(0);
  // first attribute is 3 floats with no offset & stride
  glVertexAttribPointer(0, model::POSITION.components, model::POSITION.type, GL_FALSE, planet_model.vertex_bytes, planet_model.offsets[model::POSITION]);
  // activate second attribute on gpu
  glEnableVertexAttribArray(1);
  // second attribute is 3 floats with no offset & stride
  glVertexAttribPointer(1, model::NORMAL.components, model::NORMAL.type, GL_FALSE, planet_model.vertex_bytes, planet_model.offsets[model::NORMAL]);

   // generate generic buffer
  glGenBuffers(1, &planet_object.element_BO);
  // bind this as an vertex array buffer containing all attributes
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, planet_object.element_BO);
  // configure currently bound array buffer
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, model::INDEX.size * planet_model.indices.size(), planet_model.indices.data(), GL_STATIC_DRAW);

  // store type of primitive to draw
  planet_object.draw_mode = GL_TRIANGLES;
  // transfer number of indices to model object 
  planet_object.num_elements = GLsizei(planet_model.indices.size());
}

///////////////////////////// callback functions for window events ////////////
// handle key input
void ApplicationSolar::keyCallback(int key, int action, int mods) {
  if (key == GLFW_KEY_W  && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
    m_view_transform = glm::translate(m_view_transform, glm::fvec3{0.0f, 0.0f, -0.1f});
    uploadView();
  }
  else if (key == GLFW_KEY_S  && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
    m_view_transform = glm::translate(m_view_transform, glm::fvec3{0.0f, 0.0f, 0.1f});
    uploadView();
  }
}

//handle delta mouse movement input
void ApplicationSolar::mouseCallback(double pos_x, double pos_y) {
  // mouse handling
}

//handle resizing
void ApplicationSolar::resizeCallback(unsigned width, unsigned height) {
  // recalculate projection matrix for new aspect ration
  m_view_projection = utils::calculate_projection_matrix(float(width) / float(height));
  // upload new projection matrix
  uploadProjection();
}

// exe entry point
int main(int argc, char* argv[]) {
  Application::run<ApplicationSolar>(argc, argv, 3, 2);
}