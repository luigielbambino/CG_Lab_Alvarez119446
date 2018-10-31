// Camera Node Header, Functions declarations
#ifndef CAMERA_NODE_HPP
#define CAMERA_NODE_HPP

#include <iostream>
using namespace std;

#include "application.hpp"
#include "model.hpp"
#include "structs.hpp"
#include <list>
#include "node.hpp"

class CameraNode : public Node{
public:
    // Default constructor
	CameraNode();
    
    // Destructor
    ~CameraNode();

    // getters and setters functions
    bool getPerspective();
        // Return state of perspective

    bool getEnabled();
        // Return state of ableness

    void setEnabled(bool);
        // set state of enable

    glm::fmat4 getProjectionMatrix();
        // Return projection matrix

    void setProjectionMatrix(glm::fmat4);
        // Set projection matrix

private:
    // Member attributes
    bool isPerspective;
    bool isEnabled;
    glm::fmat4 projectionMatrix;
};

#endif