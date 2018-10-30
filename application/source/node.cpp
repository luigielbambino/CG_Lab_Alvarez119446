// Node function definitions
#include "node.hpp"
#include "window_handler.hpp"
#include "utils.hpp"

#include <glbinding/gl/gl.h>
// use gl definitions from glbinding 
using namespace gl;

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <string>
#include <iostream>

//Member attributes
node::node(node parent, std::list<node> children, string name, string path, int depth, glm::fmat4 localTransform, glm::fmat4 worldTransform){
	node parent;
	std::list<node> children;
	string name;
	string path;
	int depth;
	glm::fmat4 localTransform;
	glm::fmat4 worldTransform;
}