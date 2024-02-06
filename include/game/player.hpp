#ifndef PLAYER_H
#define PLAYER_H

#include "object.hpp"
#include <iostream>
#include <cmath>

class Player : public Object {
public:
    using Object::Object;
    std::string getType() {return "player";} 

    void create() {
        vsp = 0;
        hsp = 0;
    }

    void update(float& delta_time, std::unordered_map<int, bool>& keys) {

        hsp = 0;
        float speed = 250;

        if (keys[119] && tilePlace(x, y+1, "walls")) {
            vsp = -19;
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
        vsp += 1.5;
        if (tilePlace(x, y+vsp, "walls")) {
            int direction = signbit(vsp) ? (-1) : (1);
            while (!tilePlace(x, y+direction, "walls")) {
                move(0, direction);
            }
            vsp = 0;
        }
        if (tilePlace(x+hsp, y, "walls")) {
            int direction = signbit(hsp) ? (-1) : (1);
            while (!tilePlace(x+direction, y, "walls")) {
                move(direction, 0);
            }
            hsp = 0;
        }
        
 
        move(0, vsp);
        move(hsp, 0);

    };

    ~Player() {};

private:
    float vsp;
    int hsp;
};

#endif