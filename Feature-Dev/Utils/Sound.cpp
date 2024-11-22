#include "Sound.h"
#include <iostream>

// Constructor: Load all sound effects
SoundController::SoundController() {
    try {
        loadSound("jump", "Assets/sounds/jump.wav");
        loadSound("collect", "Assets/sounds/collect.wav");
        loadSound("defeat", "Assets/sounds/defeat.wav");
        loadSound("hit", "Assets/sounds/hit.wav");
    }
    catch (const std::exception& e) {
        std::cerr << "Error loading sounds: " << e.what() << std::endl;
    }
}

// Destructor
SoundController::~SoundController() {
    stopAllSounds();
}

// Load a sound file into buffer and map
void SoundController::loadSound(const std::string& key, const std::string& filePath) {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(filePath)) {
        throw std::runtime_error("Failed to load sound file: " + filePath);
    }

    soundBuffers[key] = buffer;
    sounds[key].setBuffer(soundBuffers[key]);
}

// Play a specific sound
void SoundController::playSound(const std::string& key) {
    if (sounds.find(key) != sounds.end()) {
        sounds[key].play();
    }
    else {
        std::cerr << "Sound key not found: " << key << std::endl;
    }
}

// Stop a specific sound
void SoundController::stopSound(const std::string& key) {
    if (sounds.find(key) != sounds.end()) {
        sounds[key].stop();
    }
    else {
        std::cerr << "Sound key not found: " << key << std::endl;
    }
}

// Stop all sounds
void SoundController::stopAllSounds() {
    for (auto& pair : sounds) {
        pair.second.stop();
    }
}