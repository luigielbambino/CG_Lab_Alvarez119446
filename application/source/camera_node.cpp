// Camera Node function definitions
#include "node.hpp"
#include "window_handler.hpp"
#include "utils.hpp"

#include <glbinding/gl/gl.h>
// use gl definitions from glbinding 
using namespace gl;

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <iostream>

//Geometry Node constructor
CameraNode::CameraNode(){
    isPerspective = false;
    isEnabled = false;
    projectionMatrix = -1;
}

// function definitios
bool CameraNode::getPerspective(){
    // Return state of perspective
    return isPerspective;
}

bool CameraNode::getEnabled(){
    // Return state of ableness
    return isEnabled;
}

void CameraNode::setEnabled(bool newEnabled){
    // set state of enable
    isEnabled = newEnabled;
}

glm::fmat4 CameraNode::getProjectionMatrix(){
    // Return projection matrix
    return projectionMatrix
}

void CameraNode::setProjectionMatrix(glm::fmat4 newProjectionMatrix){
    // Set projection matrix
    projectionMatrix = newProjectionMatrix
}