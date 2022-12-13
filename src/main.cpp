#include <iostream>
#include "../ecs.h"

using Scene = ecs::Scene<128>;

int main() {
    
    Scene scene;   

    auto ent = scene.createEntity();
    scene.assign<int>(ent);

    std::cout << scene.has<int>(ent) << '\n';

    return 0;
}