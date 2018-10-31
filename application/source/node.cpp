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
#include <string>

//Node constructors
Node::Node(std::string newname){
	name = newname;
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

// Destructor
Node::~Node(){}

// getters and setters functions
Node* Node::getParent(){
	// Return parent node
	return parent;
}

void Node::setParent(Node* newparent){
	// Set parent node
	parent = newparent;
}

string Node::getChildren(){
	// Return children name
	return name;
}

std::list<Node> Node::getChildrenList(){
	// Return children list
	return children;
}

string Node::getName(){
	// Return name of the parent node
	return name;
}

string Node::getPath(){
	// Return path
	return path;
}

int Node::getDepth(){
	// Return depth
	return depth;
}

glm::fmat4 Node::getLocalTransform(){
	// Return local transforma
	return localTransform;
}

void Node::setLocalTransform(glm::fmat4 newlocalTransform){
	// Set local transform
	localTransform = newlocalTransform;
}

glm::fmat4 Node::getWorldTransform(){
	// Return world transform
	return worldTransform;
}

void Node::setWorldTransform(glm::fmat4 newworldTransform){
	// Set world transform
	worldTransform = newworldTransform;
}

void Node::addChildren(Node* newnode){
	// add new child
	children += newnode;
}

Node* Node::removeChildren(string newname){
}