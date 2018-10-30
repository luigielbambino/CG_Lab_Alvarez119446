// SceneGraph Header, Functions declarations
#ifndef SCENE_GRAPH_HPP
#define SCENE_GRAPH_HPP

#include "application.hpp"
#include "model.hpp"
#include "structs.hpp"
#include "node.hpp"

class SceneGraph : public Application {
public:
	// Load constructor
	SceneGraph(string, node);

	// Destructor
	~SceneGraph();

	// getter functions
	string getName() const;
		// Return the name of the Scene

	node getNode() const;
		// Return the root node of the scene

	// Other functions
	string printGraph();


private:
	// Member attributes
	string name;
	node root;

	// Setter functions
	void setName(string);
		// Set the name of the node

	void setRoot(node);
		// Set the root node
};

#endif