// Node function definitions
#include "node.hpp"
#include "window_handler.hpp"
#include "utils.hpp"

#include <glbinding/gl/gl.h>
// use gl definitions from glbinding 
using namespace gl;

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <iostream>

//Node constructors
Node::Node(){
}

Node::Node(std::list<Node> newChildren, string newName, string newPath, int newDepth){
	name = newName;
	children = newchildren;
	path = newpath;
	depth = newdepth;
}

Node::Node(Node* newParent, std::list<Node> newChildren, string newName, string newPath, int newDepth){
	parent = newParent
	name = newName;
	children = newchildren;
	path = newpath;
	depth = newdepth;
}