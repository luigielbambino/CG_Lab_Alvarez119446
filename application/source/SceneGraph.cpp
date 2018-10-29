// function definitions
#include "SceneGraph.hpp"

#include <iostream>

//Member attributes
SceneGraph::SceneGraph(){
	name = "name";
	root = root;
}

// SceneGraph Constructor
SceneGraph::SceneGraph(string newname, node mewroot){
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