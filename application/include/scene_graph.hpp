// SceneGraph Header, Functions declarations
#ifndef SCENE_GRAPH_HPP
#define SCENE_GRAPH_HPP

#include <iostream>
using namespace std;

#include "application.hpp"
#include "model.hpp"
#include "structs.hpp"
#include "node.hpp"

class SceneGraph : public Application {
public:
	// Default constructor
	SceneGraph();

	// Destructor
	~SceneGraph();

	// getter functions
	string getName();
		// Return the name of the Scene

	Node* getNode();
		// Return the root node of the scene

	// Other functions
	string printGraph();

private:
	// Member attributes
	string name;
	Node* root;

	// Setter functions
	void setName(string name);
		// Set the name of the node

	void setRoot(Node* root);
		// Set the root node
};

#endif