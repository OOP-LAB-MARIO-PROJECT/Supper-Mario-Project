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
        std::vector <std::unique_ptr<Entity>> aliveEntities;  // Container to store entities
        for (auto& entity : entities) if (!entity->isDead()) {
            entity->update(deltaTime);
            aliveEntities.push_back(std::move(entity));
        }

        entities.clear();
        for (auto& entity : aliveEntities)
            entities.push_back(std::move(entity));

    }

    void renderAll(sf::RenderWindow& window) {
        for (const auto& entity : entities) {
            entity->render(window);
        }
    }
};