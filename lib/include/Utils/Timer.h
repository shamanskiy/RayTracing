#pragma once

#include <chrono>
#include <sstream>

namespace 
{
    using timeStamp = std::chrono::steady_clock::time_point;
    const auto now = std::chrono::high_resolution_clock::now;
}

class Timer
{
    timeStamp m_start;
    
public:
    Timer() : m_start(now()) {}

    void start() {
        m_start = now();
    }

    std::string reportElapsedTime() {
        timeStamp end = now();
        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - m_start);
        std::ostringstream oss;
        oss.precision(3);
        oss << "Complete in " << elapsed.count() * 1e-9 << " seconds";
        return oss.str();
    }
};

