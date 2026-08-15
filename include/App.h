#pragma once
#include <functional>
#include <string>
#include <vector>

// ChatGPT 5.6 desktop client core types.
// Personas: sol, luna, terra, cyber. 200K context window.

namespace chatgpt {

enum class Persona { Sol, Luna, Terra, Cyber };
Persona personaFromName(const std::string& name);

struct Message {
    std::string role;
    std::string content;
};

class Session {
public:
    void setSystemPrompt(const std::string& p);
    void addUser(const std::string& text);
    void forkAt(int index);
    const std::vector<Message>& messages() const { return msgs_; }
private:
    std::vector<Message> msgs_;
};

class StreamClient {
public:
    void streamCompletion(const std::vector<Message>& msgs,
                          std::function<void(const std::string&)> cb);
};

struct Ui {
    void appendToken(const std::string& tok);
};

class App {
public:
    using TokenCallback = std::function<void(const std::string&)>;
    bool init(const std::string& configPath);
    void setPersona(Persona p);
    void setContextWindow(size_t tokens);
    void sendMessage(const std::string& text, TokenCallback cb);
    void branchFrom(int messageIndex);
    int runDesktop();

private:
    Persona persona_ = Persona::Sol;
    Session session_;
    StreamClient client_;
    Ui ui_;
    int accentColor_ = 0;
};

int accentFor(Persona p);

} // namespace chatgpt
