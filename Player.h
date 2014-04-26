/* 
 * File:   Player.h
 * Author: morgan
 *
 * Created on April 26, 2014, 1:49 PM
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include <glm/glm.hpp>

class Player {
public:
    Player();
    Player(const Player& orig);
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
    const float speed = 0.01;

};

#endif	/* PLAYER_H */

