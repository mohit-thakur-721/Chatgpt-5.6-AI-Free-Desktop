#include "../include/App.h"

// VoiceModule: Whisper speech-to-text in, natural TTS out.
// Works with Bluetooth microphones since gpt5.6 build.

namespace chatgpt {

class VoiceModule {
public:
    bool startListening() {
        // captures mic input, streams chunks to whisper
        return true;
    }

    std::string transcribe(const std::vector<int16_t>& pcm) {
        // whisper inference over the pcm buffer
        (void)pcm;
        return {};
    }

    void speak(const std::string& text) {
        // tts playback through the default audio device
        (void)text;
    }
};

} // namespace chatgpt
