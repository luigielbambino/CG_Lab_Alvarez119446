// Node Header, Functions declarations
#ifndef NODE_HPP
#define NODE_HPP

#include "application.hpp"
#include "model.hpp"
#include "structs.hpp"
#include <list>

using namespace std;

class node : public Application {
public:
	// Load constructor
	node(node, node[], string, string, int, glm::fmat4, glm::fmat4);

	// Destructor
	~node();

	// getters and setters functions
	node getParent() const;
		// Return parent node
	void setParent(node);
		// Set parent node

	string getChildren() const;
		// Return children name

	std::list<node> getChildrenList() const;
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

	void addChildren(node);
		// add new child

	node removeChildren(string);
		//remove child

	// Other functions


private:
	// Member attributes
	node parent;
	std::list<node> children;
	string name;
	string path;
	int depth;
	glm::fmat4 localTransform;
	glm::fmat4 worldTransform;
};

#endif