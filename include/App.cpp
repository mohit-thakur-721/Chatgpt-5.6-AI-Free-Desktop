#include "App.h"
#include <fstream>

// App shell: config load and the desktop loop.

namespace chatgpt {

bool App::init(const std::string& configPath) {
    std::ifstream f(configPath);
    if (!f) return false;
    // api key, persona default, theme, plugin toggles
    return true;
}

void App::setContextWindow(size_t tokens) { (void)tokens; }

int App::runDesktop() {
    // native window: chat list, persona switcher, export buttons
    return 0;
}

int accentFor(Persona p) {
    switch (p) {
        case Persona::Luna:  return 0x6C8CFF;
        case Persona::Terra: return 0x58B368;
        case Persona::Cyber: return 0xFF5964;
        default:             return 0xFFB347; // sol
    }
}

} // namespace chatgpt
