#pragma once
#include "../Entities/Entity.h"
#include <iostream>
#include <map>


class EntityManager {
private:
    std::map<int, std::unique_ptr<Entity>> entities;  // Container to store entities
    int curEntity = 0;

public:
    // Add an entity to the manager
    void addEntity(std::unique_ptr<Entity> entity) {
        entities[curEntity ++] = std::move(entity);
    }

    // Render all entities
    void renderAll(sf::RenderWindow& window) {
        for (const auto& entity : entities) {
            entity.second->render(window);
        }
    }
};