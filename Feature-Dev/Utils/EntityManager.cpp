#include "EntityManager.h"
void EntityManager::addEntity(std::unique_ptr<Entity> entity) {
    entities.push_back(std::move(entity));
}

void EntityManager::updateAll(float deltaTime) {
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

void EntityManager::renderAll(sf::RenderWindow& window) {
    for (const auto& entity : entities) {
        entity->render(window);
    }
}