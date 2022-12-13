#include <iostream>
#include "../ecs.hpp"

using Scene = ecs::Scene<128>;  // this allows max of 128 components that can be registered by an entity

int main() {
    
    Scene scene;   


    for (int i = 0; i < 5; i++) {
        auto ent = scene.createEntity();
        scene.assign<float>(ent);
    }

    for (int i = 0; i < 5; i++) {
        auto ent = scene.createEntity();
        scene.assign<int>(ent);
    }

    for (int i = 0; i < 5; i++) {
        auto ent = scene.createEntity();
        scene.assign<int, float>(ent);
    }

    // you can loop thru all entity with
    for (auto ent : scene.group()) {
        // processing on all entities
        std::cout << ent << '\n';
    }
    std::cout << "-------------------------------------\n";

    // you can loop thru all entities with specific components with
    for (auto [ent, i] : scene.group<int>()) {
        // processing on all entities with int component
        std::cout << ent << '\n';
    }
    std::cout << "-------------------------------------\n";

    // you can loop thru all entities with specific components with
    for (auto [ent, i, f] : scene.group<int, float>()) {
        // processing on all entities with int and float component
        std::cout << ent << '\n';
    }
    std::cout << "-------------------------------------\n";

    return 0;
}