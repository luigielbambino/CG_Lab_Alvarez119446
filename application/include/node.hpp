// Node Header, Functions declarations
#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

#include "application.hpp"
#include "model.hpp"
#include "structs.hpp"
#include <list>


class Node : public Application {
public:
	// Default Constructor
	Node();

	// Constructor for root node
	Node(std::list<Node> children, string name, string path, int depth);

	// Constructor for children nodes
	Node(Node* parent, std::list<Node> children, string name, string path, int depth);

	// Destructor
	~Node();

	// getters and setters functions
	Node* getParent() const;
		// Return parent node
	void setParent(Node* parent);
		// Set parent node

	string getChildren() const;
		// Return children name

	std::list<Node> getChildrenList() const;
		// Return children list

	string getName() const;
		// Return name of the parent node

	string getPath() const;
		// Return path

	int getDepth() const;
		// Return depth

	glm::fmat4 getLocalTransform() const;
		// Return local transforma

	void setLocalTransform(glm::fmat4 localTransform);
		// Set local transform

	glm::fmat4 getWorldTransform() const;
		// Return world transform

	void setWorldTransform(glm::fmat4 worldTransform);
		// Set world transform

	void addChildren(Node*);
		// add new child

	Node* removeChildren(string);
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