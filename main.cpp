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
#include <glm/gtc/random.hpp>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <ogli/time.h>

#include <mo/Renderer.h>
#include <mo/Model.h>
#include <mo/Vertex.h>

#include "Assets.h"
#include "Player.h"
#include "Sound.h"

float resolution_x = 1280.0f;
float resolution_y = 800.0f;

auto projection = glm::perspective(45.0f, resolution_x / resolution_y, 1.0f, 1000.f);
auto view = glm::lookAt(glm::vec3(0.0f, 5.0f, -10.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

Player player;

void error_callback(int error, const char* description) {
    fputs(description, stderr);
}



static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    if (key == GLFW_KEY_A && action == GLFW_PRESS) {
        player.left = true;
    };
    if (key == GLFW_KEY_A && action == GLFW_RELEASE) {
        player.left = false;
    };
    if (key == GLFW_KEY_D) {
        player.right = true;
    };
    if (key == GLFW_KEY_D && action == GLFW_RELEASE) {
        player.right = false;
    };
    if (key == GLFW_KEY_W){
        player.forward = true;
    };
    if (key == GLFW_KEY_W && action == GLFW_RELEASE){
        player.forward = false;
    }
    if (key == GLFW_KEY_S){
        player.back = true;
    };
    if (key == GLFW_KEY_S && action == GLFW_RELEASE){
        player.back = false;
    }
    if (key == GLFW_KEY_SPACE ){
        player.up = true;
    }
    if(key == GLFW_KEY_SPACE && action == GLFW_RELEASE){
        player.up = false;
    }
    if (key == GLFW_KEY_LEFT_SHIFT){
        player.down = true;
    }
    if (key == GLFW_KEY_LEFT_SHIFT && action == GLFW_RELEASE){
        player.down = false;
    }
}
enum State{
    STAGE1,
    STAGE2,
    STAGE3,
    STAGE4,
    STAGE5,
    GAMEOVER,
    WIN
};
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
    renderer.addProgram("hud");
    Assets assets;    
    
    auto ortho_proj = glm::ortho(-0.5f, 0.5f, -0.5f, 0.5f, 1.0f, 1000.0f);
    auto straight_view = glm::lookAt(glm::vec3(0.0f, 0.0f, -10.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    
    mo::Model model(assets.loadMesh("data/Level.obj"), assets.loadTexture("data/Level.png"));
    mo::Model quad(assets.loadMesh("data/Quad.obj"), assets.loadTexture("data/Block.png"));    
    double frame_time = 0.0;
    
    Sound sound;
    sound.playMusic();  
    sound.playNoise();
    
    bool out_played = false;
    bool wasd_played = false;
    bool oxygen_played = false;
    
       
    double heart_interval = 3000;
    double heart_wait = 0;
    double time = 0;
    
    State state = State::STAGE1;
    sound.playOxygen();
    
    while (!glfwWindowShouldClose(window)) {
        
        time += frame_time;
        heart_wait += frame_time;
        if (heart_wait > heart_interval){
            sound.playHeartbeat();            
            heart_wait = 0;
        }
        
        if (time > 20000 && time < 40000){
            state = State::STAGE2;            
        }
        else if (time > 40000 && time < 80000){
            state = State::STAGE3;
        }
        else if (time > 80000 && time < 120000){
            state = State::STAGE4;
        }        
        else if (time > 120000 && time < 200000){        
            state = State::STAGE5;
        }
        else if (time > 200000){
            state = State::GAMEOVER;
        }
        
        if (state == State::STAGE1){
            heart_interval = 3000;            
        }
        
        if (state == State::STAGE2){
            heart_interval = 2000;
            if (!wasd_played){
                sound.playWasd();
                wasd_played = true;
            }
        }
        else if (state == State::STAGE3){
            heart_interval = 1000;
            if (!out_played){
                sound.playOut();
                out_played = true;
            }
        }
        else if (state == State::STAGE4){
            heart_interval = 500;
        }
        else if (state == State::STAGE5){
            heart_interval = glm::linearRand(100.0, 300.0);
        }
        else if (state == State::GAMEOVER){
            renderer.clear(glm::vec3(0.0f, 0.0f, 0.5f));
            continue;
        }
        else if (state == State::WIN){
            renderer.clear(glm::vec3(1.0f, 1.0f, 1.0f));
            continue;
        }
        
        sound.setHeartbeatPosition(player.position());
        sound.setNoisePosition(player.position());
        sound.setOutPosition(player.position());
        sound.setWasdPosition(player.position());
        
        sound.setListenerPosition(player.position());
        
        view = glm::lookAt(glm::vec3(0.0f, 5.0f, -10.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)) * player.transform();
        
        std::cout << player.position().y << std::endl;
        
        double old_time = ogli::now_ms();      
        player.update(frame_time);
        renderer.clear(glm::vec3(0.0f, 0.1f, 0.2f));
        renderer.render(model, glm::mat4(1.0f), view, projection);
        renderer.render(quad, glm::mat4(1.0f), straight_view, ortho_proj, "hud");
        glfwSwapBuffers(window);
        glfwPollEvents();        
        frame_time = ogli::now_ms() - old_time;
    }
    return 0;
}

