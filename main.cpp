/* 
 * File:   main.cpp
 * Author: morgan
 *
 * Created on July 30, 2013, 8:34 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <ogli/time.h>

#include <mo/Renderer.h>
#include <mo/Model.h>
#include <mo/Vertex.h>

float resolution_x = 1280.0f;
float resolution_y = 800.0f;

auto projection = glm::perspective(45.0f, resolution_x / resolution_y, 1.0f, 1000.f);
auto view = glm::lookAt(glm::vec3(0.0f, -10.0f, 10.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

void error_callback(int error, const char* description) {
    fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    if (key == GLFW_KEY_A && action == GLFW_PRESS) {
        
    };
    if (key == GLFW_KEY_A && action == GLFW_RELEASE) {
       
    };
    if (key == GLFW_KEY_D) {
        
    };
    if (key == GLFW_KEY_D && action == GLFW_RELEASE) {
        
    };
    if (key == GLFW_KEY_W){
       
    };
    if (key == GLFW_KEY_W && action == GLFW_RELEASE){
        
    }
    if (key == GLFW_KEY_S){
        
    };
    if (key == GLFW_KEY_S && action == GLFW_RELEASE){
        
    }
    if (key == GLFW_KEY_SPACE ){
    
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    //TODO: define vertex format in main 
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }
    glfwSetErrorCallback(error_callback);

    glfwWindowHint(GLFW_SAMPLES, 4);
    GLFWwindow* window = glfwCreateWindow(resolution_x, resolution_y, "Ludum", NULL, NULL);

    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    glfwSwapInterval(1);
    
    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    
    
    mo::Renderer renderer;

    
    glm::vec3 v1(0.0f, 0.0f, 0.0f);
    glm::vec3 v2(1.0f, 0.0f, 0.0f);
    glm::vec3 v3(1.0f, 1.0f, 0.0f);
    glm::vec3 v4(0.0f, 1.0f, 0.0f);
    glm::vec3 n(1.0f, 0.0f, 0.0f);
    glm::vec2 uv(0.0f, 0.0f);
    std::vector<mo::Vertex> vertices = {mo::Vertex(v1, n, uv), 
        mo::Vertex(v2, n, uv),mo::Vertex(v3, n, uv),mo::Vertex(v4, n, uv)};
    
    std::vector<int> elements = {0, 1, 2, 3};
    
    mo::Mesh mesh(vertices.begin(), vertices.end(), elements.begin(), elements.end());
    
    mo::Model model(&mesh, 0);
    
    double frame_time = 0.0;
    while (!glfwWindowShouldClose(window)) {
        double old_time = ogli::now_ms();      
       
        renderer.clear(glm::vec3(1.0f, 0.0f, 0.0f));
        //renderer.render(model, glm::mat4(1.0f), view, projection);
        glfwSwapBuffers(window);
        glfwPollEvents();        
        frame_time = ogli::now_ms() - old_time;
    }
    return 0;
}

