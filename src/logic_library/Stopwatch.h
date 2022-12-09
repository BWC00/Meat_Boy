//
// Created by student on 1/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_STOPWATCH_H
#define INC_2022_PROJECT_BWC00_STOPWATCH_H

#include <chrono>

namespace logic {
    class Stopwatch {
    public:
        Stopwatch(const Stopwatch&) = delete;
        static Stopwatch& getInstance();
        static std::chrono::duration<double, std::milli>& getElapsed();
        void timeit();
        static void sleep();
    private:
        Stopwatch();
        void resetStart();
        void m_sleep();
        std::chrono::steady_clock::time_point start;
        std::chrono::duration<double, std::milli> dt;
    };
}



#endif //INC_2022_PROJECT_BWC00_STOPWATCH_H
