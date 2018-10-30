// SceneGraph function definitions
#include "scene_graph.hpp"
#include "window_handler.hpp"
#include "utils.hpp"

#include <glbinding/gl/gl.h>
// use gl definitions from glbinding 
using namespace gl;

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <iostream>

// SceneGraph Constructor
SceneGraph::SceneGraph(){
	name = "solar system";
	root = new Node();
}

// Deconstructor
SceneGraph:::~SceneGraph(){}


//Setters
string SceneGraph:::getName() const {
	return name;
}

Node SceneGraph:::getRoot() const {
	return root;
}

//Getters
void SceneGraph::setName(string newname){
	name = newname;
}

void SceneGraph::setRoot(Node newroot){
	root = newroot;
}

// Other functions
string SceneGraph::printGraph(){
	return " "
}