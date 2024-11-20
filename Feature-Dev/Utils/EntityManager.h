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
    void addEntity(std::unique_ptr<Entity> entity);

    // Render all entities
    void updateAll(float deltaTime);

    void renderAll(sf::RenderWindow& window);

    // vector <..> getEntityWithID();
    
};