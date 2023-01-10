//
// Created by student on 1/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_STOPWATCH_H
#define INC_2022_PROJECT_BWC00_STOPWATCH_H

#include <chrono>

namespace logic {
class Stopwatch {
public:
    // getters
    static Stopwatch& getInstance();
    static std::chrono::duration<double, std::milli>& getElapsed();

    void timeit();
    static void sleep();

    Stopwatch(const Stopwatch&) = delete;

private:
    Stopwatch();
    void resetStart();
    void m_sleep();

    std::chrono::steady_clock::time_point start;
    std::chrono::duration<double, std::milli> dt;
};
} // namespace logic

#endif // INC_2022_PROJECT_BWC00_STOPWATCH_H
