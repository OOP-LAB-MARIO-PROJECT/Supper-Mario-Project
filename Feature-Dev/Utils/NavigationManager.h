#pragma once
#include <string>
//#include "MainMenu.h"
#include "../Game/GameController.h"
class MainMenu;
using namespace std;
class NavigationManager
{
public:
    enum class Screen
    {
        Start,
        Exit,
        Game,
        MainMenu,
    };
    static NavigationManager& getInstance();
    Screen getCurrentScreen() const;
    //const string& getCurrentParam() const;
    void navigate(Screen screen);
private:
    NavigationManager() {}
    Screen currentScreen = Screen::MainMenu; // Default screen
   // string currentParam;

    // Prevent copying and assignment
    NavigationManager(const NavigationManager&) = delete;
    NavigationManager& operator=(const NavigationManager&) = delete;
};
