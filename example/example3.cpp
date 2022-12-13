#include <iostream>
#include "../ecs.hpp"

using Scene = ecs::Scene<128>;  // this allows max of 128 components that can be registered by an entity

int main() {
    
    Scene scene;   

    ecs::EntityID ent = scene.createEntity();
    
    // you can also multiple assign/get components 
    auto [i, f] = scene.assign<int, float>(ent);  // here i and f are refrences to scene
    i = 7;
    f = 9.5;

    auto [ii, ff] = scene.get<int, float>(ent);  // note the order the values are returned is the same as the order the components are given in the template

    std::cout << ii << " " << ff << '\n';

    return 0;
}