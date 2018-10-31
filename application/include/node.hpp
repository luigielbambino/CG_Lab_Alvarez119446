// Node Header, Functions declarations
#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

#include "application.hpp"
#include "model.hpp"
#include "structs.hpp"
#include <list>
#include <string>


class Node{
public:
	// Default Constructor
	Node(std::string name);

	// Constructor for root node
	Node(std::list<Node> newchildren, string newname, string newpath, int newdepth);

	// Constructor for children nodes
	Node(Node* newparent, std::list<Node> newchildren, string newname, string newpath, int newdepth);

	// Destructor
	~Node();

	// getters and setters functions
	Node* getParent();
		// Return parent node
	void setParent(Node* newparent);
		// Set parent node

	string getChildren();
		// Return children name

	std::list<Node> getChildrenList();
		// Return children list

	string getName();
		// Return name of the parent node

	string getPath();
		// Return path

	int getDepth();
		// Return depth

	glm::fmat4 getLocalTransform();
		// Return local transforma

	void setLocalTransform(glm::fmat4 newlocalTransform);
		// Set local transform

	glm::fmat4 getWorldTransform();
		// Return world transform

	void setWorldTransform(glm::fmat4 newworldTransform);
		// Set world transform

	void addChildren(Node* newnode);
		// add new child

	Node* removeChildren(string newname);
		//remove child
	
private:
	// Member attributes
	Node* parent;
	std::list<Node> children;
	string name;
	string path;
	int depth;
	glm::fmat4 localTransform;
	glm::fmat4 worldTransform;
};

#endif