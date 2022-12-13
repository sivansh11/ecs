#include <iostream>
#include "../ecs.hpp"

using Scene = ecs::Scene<128>;  // this allows max of 128 components that can be registered by an entity

int main() {
    
    Scene scene;   

    ecs::EntityID ent = scene.createEntity();
    scene.assign<int>(ent);

    // you can get back the component by using get, it returns a refrence to the component
    auto& i = scene.get<int>(ent);
    i = 7;
    std::cout << scene.get<int>(ent) << '\n';

    scene.get<int>(ent) = 8;
    std::cout << scene.get<int>(ent) << '\n';

    return 0;
}