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

//Node constructor
Node::Node(Node newparent, std::list<Node> newchildren, string newname, string newpath, int newdepth, glm::fmat4 newlocalTransform, glm::fmat4 newworldTransform){
	parent = newparent;
	children = newchildren;
	name = newname;
	path = newpath;
	depth = newdepth;
	localTransform = newlocaltransform;
	worldTransform = newworldtransform;
}