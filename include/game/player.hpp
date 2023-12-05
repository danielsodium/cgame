#ifndef PLAYER_H
#define PLAYER_H

#include "object.hpp"
#include <iostream>

class Player : public Object {
public:
    using Object::Object;
    std::string getType() {return "player";} 

    void create() {
        jumped = false;
        vsp = 0;
        hsp = 0;
    }

    void update(float& delta_time, std::unordered_map<int, bool>& keys) {

        hsp = 0;
        float speed = 250;
        if (keys[119]) {
            // Jump
            //vsp += -speed*delta_time;
            if (!jumped && instancePlace(x, y+1, "wall")) {
                jumped = true;
                vsp = -25;
            }
       } 
        else {
            jumped = false;
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
        vsp += 2;

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

private:
    bool jumped;
    float vsp;
    float hsp;
};

#endif