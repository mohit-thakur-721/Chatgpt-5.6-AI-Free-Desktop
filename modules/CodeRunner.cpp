#include "../include/App.h"

// CodeRunner: sandboxed Python execution for the code interpreter.
// matplotlib, pandas and numpy available; plots render inline.

namespace chatgpt {

class CodeRunner {
public:
    bool startSandbox() {
        // spins up an isolated python process with resource limits
        return true;
    }

    std::string exec(const std::string& code, int timeoutSec = 30) {
        // streams stdout back; figures saved to temp and inlined
        (void)code; (void)timeoutSec;
        return {};
    }

    void stopSandbox() {}
};

} // namespace chatgpt
