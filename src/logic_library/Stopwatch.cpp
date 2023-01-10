//
// Created by student on 1/12/22.
//

#include "Stopwatch.h"
#include "CONSTANTS.h"
#include <thread>

logic::Stopwatch& logic::Stopwatch::getInstance() {
    static Stopwatch instance;
    return instance;
}

logic::Stopwatch::Stopwatch() { resetStart(); }

void logic::Stopwatch::resetStart() { start = std::chrono::steady_clock::now(); }

void logic::Stopwatch::timeit() { dt = std::chrono::steady_clock::now() - start; }

std::chrono::duration<double, std::milli>& logic::Stopwatch::getElapsed() { return getInstance().dt; }

void logic::Stopwatch::sleep() { getInstance().m_sleep(); }

void logic::Stopwatch::m_sleep() {
    timeit();
    if (dt.count() < 1000.0 / logic::constants::FRAME_RATE) {
        std::chrono::duration<double, std::milli> delta_ms(1000.0 / logic::constants::FRAME_RATE - dt.count());
        auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
        std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
    }
    timeit();
    resetStart();
}
