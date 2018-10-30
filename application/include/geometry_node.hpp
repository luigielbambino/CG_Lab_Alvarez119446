// Geomnetry Node Header, Functions declarations
#ifndef GEOMETRY_NODE_HPP
#define GEOMETRY_NODE_HPP

#include <iostream>
using namespace std;

#include "application.hpp"
#include "model.hpp"
#include "structs.hpp"
#include <list>
#include "node.hpp"

class GeometryNode : public Node{
public:
    // Default constructor
	GeometryNode();
    
    // Destructor
    ~GeometryNode();

    // getters and setters functions
    model getGeometry();
        // Return geometry model
    void setGeometry(model);
        // set geometry model

private:
    // Member attributes
    model geometry;
};

#endif