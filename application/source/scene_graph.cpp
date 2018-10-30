// SceneGraph function definitions
#include "scene_graph.hpp"
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
scene_graph::scene_graph(){
	name = "name";
	root = root;
}

// SceneGraph Constructor
SceneGraph::SceneGraph(string newname, node newroot){
	name = newname;
	root = newroot;
}

// Deconstructor
SceneGraph:::~SceneGraph(){}


//Setters
string SceneGraph:::getName() const {
	return name;
}

node SceneGraph:::getRoot() const {
	return root;
}

//Getters
void SceneGraph::setName(string newname){
	name = newname;
}

void SceneGraph::setRoot(node newroot){
	root = newroot;
}

// Other functions
string SceneGraph::printGraph(){
	return " "
}