/* 
 * File:   Player.cpp
 * Author: morgan
 * 
 * Created on April 26, 2014, 1:49 PM
 */

#include "Player.h"

#include <glm/gtx/transform.hpp>

Player::Player() {
}

Player::Player(const Player& orig) {
}

Player::~Player() {
}

glm::mat4 Player::transform(){
    return glm::translate(position);
}

void Player::update(float dt){
    float acceleration = dt * speed;    
    if (up){
        position.y -= acceleration;
    }
    if(down){
        position.y += acceleration;
    }
    if(left){
        position.x -= acceleration;
    }
    if(right){
        position.x += acceleration;        
    }
    if (forward){
        position.z -= acceleration;        
    }
    if(back){
        position.z += acceleration;
    }
}

