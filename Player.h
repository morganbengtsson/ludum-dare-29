/* 
 * File:   Player.h
 * Author: morgan
 *
 * Created on April 26, 2014, 1:49 PM
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include <glm/glm.hpp>
#include <Box2D/Box2D.h>

class Player {
public:
    Player();
    virtual ~Player();

    bool up;
    bool down;
    bool left;
    bool right;
    bool forward;
    bool back;
    
    glm::vec3 position;

    void update(float dt);
    glm::mat4 transform();
private:
    const float speed_ = 5.0f;
    b2World world_xy_;
    b2Body * body_xy_;
    b2World world_xz_;
    b2Body * body_xz_;
};

#endif	/* PLAYER_H */

