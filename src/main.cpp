#include "../include/App.h"
#include <iostream>

// ChatGPT 5.6 Sol Luna Terra Free Desktop - entry point.
// Native client with persona modes: sol, luna, terra, cyber.

int main(int argc, char** argv) {
    chatgpt::App app;

    if (!app.init("config/settings.json")) {
        std::cerr << "[gpt-5.6] init failed - check config\n";
        return 1;
    }

    app.setPersona(chatgpt::Persona::Sol); // default creative mode
    app.setContextWindow(200000);

    if (argc > 2 && std::string(argv[1]) == "--persona") {
        app.setPersona(chatgpt::personaFromName(argv[2])); // sol|luna|terra|cyber
    }

    return app.runDesktop(); // native window, streaming chat
}
