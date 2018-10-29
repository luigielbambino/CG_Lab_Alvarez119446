// Header, Functions declarations
#ifndef SCENEGRAPH_HPP
#define SCENEGRAPH_HPP

#include <iostream>
#include <string>

using namespace std;

class SceneGraph{
public:
	// Default constructor
	SceneGraph();

	// Load constructor
	SceneGraph(string, node);

	// Destructor
	~ApplicationSolar();

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