// Node Header, Functions declarations
#ifndef NODE_HPP
#define NODE_HPP

#include "application.hpp"
#include "model.hpp"
#include "structs.hpp"

class Node : public Application {
public:
	// Load constructor
	Node(Node, std::list<Node>, string, string, int, glm::fmat4, glm::fmat4);

	// Destructor
	~Node();

	// getters and setters functions
	Node getParent() const;
		// Return parent node
	void setParent(Node);
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

	void setLocalTransform(glm::fmat4);
		// Set local transform

	glm::fmat4 getWorldTransform() const;
		// Return world transform

	void setWorldTransform(glm::fmat4);
		// Set world transform

	void addChildren(Node);
		// add new child

	Node removeChildren(string);
		//remove child

	// Other functions


private:
	// Member attributes
	Node parent;
	std::list<Node> children;
	string name;
	string path;
	int depth;
	glm::fmat4 localTransform;
	glm::fmat4 worldTransform;
};

#endif