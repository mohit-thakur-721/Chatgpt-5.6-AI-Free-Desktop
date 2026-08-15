#include "../include/App.h"

// PersonaEngine: chatgpt 5.6 sol / luna / terra / cyber modes.
// Each persona swaps the system prompt and streaming style.

namespace chatgpt {

Persona personaFromName(const std::string& name) {
    if (name == "luna")  return Persona::Luna;
    if (name == "terra") return Persona::Terra;
    if (name == "cyber") return Persona::Cyber;
    return Persona::Sol;
}

static const char* promptFor(Persona p) {
    switch (p) {
        case Persona::Luna:  return "You are Luna: analytical, precise. Code, math, research.";
        case Persona::Terra: return "You are Terra: practical, concise. Quick answers, summaries.";
        case Persona::Cyber: return "You are Cyber: security-focused. Code audits, threat docs.";
        default:             return "You are Sol: creative, expressive. Writing and brainstorming.";
    }
}

void App::setPersona(Persona p) {
    persona_ = p;
    session_.setSystemPrompt(promptFor(p));
    accentColor_ = accentFor(p); // per-persona UI accent
}

} // namespace chatgpt
