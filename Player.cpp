/* 
 * File:   Player.cpp
 * Author: morgan
 * 
 * Created on April 26, 2014, 1:49 PM
 */

#include "Player.h"

#include <glm/gtx/transform.hpp>
#include <iostream>

Player::Player() : world_xy_(b2Vec2(0.0f, 0.0f)), world_xz_(b2Vec2(0.0f, 0.0f)) {
    b2BodyDef body_def;
    body_def.type = b2_dynamicBody;
    body_def.position.Set(0.0f, 1.0f);
    body_xy_ = world_xy_.CreateBody(&body_def);
       
    b2PolygonShape dynamic_box;
    dynamic_box.SetAsBox(1.0f, 1.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamic_box;

    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f; 

    body_xy_->CreateFixture(&fixtureDef);
    body_xy_->SetLinearDamping(0.5f);
    body_xy_->SetAngularDamping(0.5f);

   
    body_xz_ = world_xz_.CreateBody(&body_def);
    
    body_xz_->CreateFixture(&fixtureDef);
    body_xz_->SetLinearDamping(0.5f);
    body_xz_->SetAngularDamping(0.5f);
}


Player::~Player() {
}

glm::mat4 Player::transform(){
    b2Vec2 pos_xy = body_xy_->GetPosition();
    b2Vec2 pos_xz = body_xz_->GetPosition();
    float angle = glm::degrees(body_xz_->GetAngle());
    return glm::rotate(angle, 0.0f , 1.0f, 0.0f) * glm::translate(pos_xz.x, pos_xy.y, pos_xz.y);
}

glm::vec3 Player::position(){
    b2Vec2 pos_xy = body_xy_->GetPosition();
    b2Vec2 pos_xz = body_xz_->GetPosition();
    return glm::vec3(pos_xz.x, pos_xy.y, pos_xz.y);
}

void Player::update(float dt){
    world_xy_.Step(1.0f / 60.0f, 6, 2);
    world_xz_.Step(1.0f / 60.0f, 6, 2);
      
    if (up){        
        if (body_xy_->GetPosition().y > max_){
             body_xy_->ApplyForceToCenter(b2Vec2(0.0f, -speed_));
        }
        else{
             body_xy_->ApplyForceToCenter(b2Vec2(0.0f, speed_));
        }
    }
    if(down){        
        if (body_xy_->GetPosition().y < min_){
            body_xy_->ApplyForceToCenter(b2Vec2(0.0f, speed_));
        }
        else{
            body_xy_->ApplyForceToCenter(b2Vec2(0.0f, -speed_));        
        }
    }
    if(left){      
        body_xz_->ApplyTorque(-speed_*0.1f);
    }
    if(right){            
        body_xz_->ApplyTorque(speed_*0.1f);
    }
    if (forward){
        b2Vec2 direction = body_xz_->GetWorldVector(b2Vec2(0.0f,1.0f));
        direction *= speed_;
        body_xz_->ApplyForceToCenter(-direction);        
    }
    if(back){  
        b2Vec2 direction = body_xz_->GetWorldVector(b2Vec2(0.0f,1.0f));
        direction *= speed_;
        body_xz_->ApplyForceToCenter(direction);
         
    }
}

