#include <iostream>
#include "../ecs.hpp"

using Scene = ecs::Scene<128>;  // this allows max of 128 components that can be registered by an entity

int main() {
    
    Scene scene;   

    ecs::EntityID ent = scene.createEntity();
    
    scene.assign<int>(ent);

    // you can query if an entity has a particular component using has
    std::cout << scene.has<int>(ent) << '\n';

    // you can remove component from entity by calling remove
    scene.remove<int>(ent);
    std::cout << scene.has<int>(ent) << '\n';

    return 0;
}