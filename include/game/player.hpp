#ifndef PLAYER_H
#define PLAYER_H

#include "object.hpp"
#include <iostream>

class Player : public Object {
public:
    using Object::Object;
    std::string getType() {return "player";} 

    void update(float& delta_time, std::unordered_map<int, bool>& keys) {

        float speed = 250;
        float vsp = 0;
        float hsp = 0;

        if (keys[119]) {
            // Jump
            //vsp += -speed*delta_time;
            vsp = -25;
        } 
        if (keys[97]) {
            hsp += -speed*delta_time;
        } 
        if (keys[115]) {
            vsp += speed*delta_time;
        } 
        if (keys[100]) {
            hsp += speed*delta_time;
        } 
        vsp += 5;

        if (instancePlace(x+hsp, y, "wall")) {
            float direction = signbit(hsp) ? (-1) : (1);
            while (!instancePlace(x+direction, y, "wall")) {
                move(direction, 0);
            }
            hsp = 0;
        }
        if (instancePlace(x, y+vsp, "wall")) {
            float direction = signbit(vsp) ? (-1) : (1);
            while (!instancePlace(x, y+direction, "wall")) {
                move(0, direction);
            }
            vsp = 0;
        }
        move(0, vsp);
        move(hsp, 0);

    };

    ~Player() {};
};

#endif