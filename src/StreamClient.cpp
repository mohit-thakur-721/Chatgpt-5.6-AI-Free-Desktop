#include "../include/App.h"

// StreamClient: SSE streaming for the GPT-5.6 responses.
// Renders tokens live, supports conversation branching.

namespace chatgpt {

void App::sendMessage(const std::string& text, TokenCallback cb) {
    session_.addUser(text);
    client_.streamCompletion(session_.messages(),
        [&](const std::string& token) {
            cb(token);
            ui_.appendToken(token);
        });
}

void App::branchFrom(int messageIndex) {
    // fork the conversation tree at any message
    session_.forkAt(messageIndex);
}

} // namespace chatgpt
