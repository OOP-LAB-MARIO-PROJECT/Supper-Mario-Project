#include <SFML/Audio.hpp>
#include <map>
#include <string>

class SoundController {
private:
    std::map<std::string, sf::SoundBuffer> soundBuffers;
    std::map<std::string, sf::Sound> sounds;

    void loadSound(const std::string& key, const std::string& filePath);

public:
    SoundController();
    ~SoundController();

    void playSound(const std::string& key);
    void stopSound(const std::string& key);
    void stopAllSounds();
};