#ifndef WALL_H 
#define WALL_H 

#include "object.hpp"
#include <iostream>

class Wall : public Object {
public:
    using Object::Object;
    std::string getType() { return "wall"; } 

    void create() {};
    void update(float& delta_time, std::unordered_map<int, bool>& keys) {};

    ~Wall() {};
};

#endif