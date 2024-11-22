#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include <unordered_map>
#include <memory>

class SoundManager {
public:
    // Hàm khởi tạo và hủy
    SoundManager();
    ~SoundManager();

    // Thêm một âm thanh từ file
    bool addSound(const std::string& id, const std::string& filePath);

    // Phát âm thanh
    void playSound(const std::string& id, bool loop = false);

    // Dừng phát âm thanh
    void stopSound(const std::string& id);

    // Kiểm tra xem âm thanh đã được thêm chưa
    bool hasSound(const std::string& id) const;

    // Xóa một âm thanh
    void removeSound(const std::string& id);

private:
    // Lưu trữ các âm thanh
    std::unordered_map<std::string, std::shared_ptr<sf::SoundBuffer>> soundBuffers;
    std::unordered_map<std::string, sf::Sound> sounds;
};