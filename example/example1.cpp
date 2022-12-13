#include <iostream>
#include "../ecs.hpp"

using Scene = ecs::Scene<128>;  // this allows max of 128 components that can be registered by an entity

struct SomeComponentStruct {
    // SomeComponentStruct(int i, float j) : i(i), j(j) {}
    int i;
    float j;
};

int main() {
    
    Scene scene;   

    // you need to create a entity before you can use it
    ecs::EntityID ent1 = scene.createEntity();
    // or
    auto ent2 = scene.createEntity();

    // to add components to an entity you use the assign keyword
    scene.assign<SomeComponentStruct>(ent1);

    // you can also pass in arguments to construct the component
    scene.assign<SomeComponentStruct>(ent2, 5, 6.0f);

    // assign also returns a refrence to the component
    scene.assign<int>(ent1) = 5;

    auto& i = scene.assign<int>(ent2);
    i = 7;

    // you can delete entity
    scene.destroyEntity(ent1);  // after deleting/destroying an entity, you cannot assign/get/has/remove components from it, the program will crash with a warning in debug but cause undefined behaviour in release

    return 0;
}