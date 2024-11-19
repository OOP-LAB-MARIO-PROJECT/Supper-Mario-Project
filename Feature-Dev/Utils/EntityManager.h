#pragma once
#include "../Entities/Entity.h"
#include <iostream>
#include <map>
#include <vector>

class EntityManager {
private:
    std::vector <std::unique_ptr<Entity>> entities;  // Container to store entities
    int curEntity = 0;

public:
    // Add an entity to the manager
    void addEntity(std::unique_ptr<Entity> entity) {
        entities.push_back(std::move(entity));
    }

    // Render all entities

    void updateAll(float deltaTime) {
       // std::cout << "huhu\n" << std::endl;
        for (const auto& entity : entities) {
            entity->update(deltaTime);
        }
    }

    void renderAll(sf::RenderWindow& window) {
        for (const auto& entity : entities) {
            entity->render(window);
        }
    }
};