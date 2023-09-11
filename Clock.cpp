#include <iostream>
#include "Clock.h"

Clock::Clock(float fps)
{
    fps_ = fps;
    interval_ = time_ratio_ / fps;
    start_ = std::chrono::high_resolution_clock::now();
    last_request_ = start_;
}

void Clock::Tick()
{
    time_point now = std::chrono::high_resolution_clock::now();

    while (ComputeDuration_(now, start_) < interval_) {
        now = std::chrono::high_resolution_clock::now();
    }

    start_ = now;
}

float Clock::ElapsedTime() {
    time_point now = std::chrono::high_resolution_clock::now();
    float elapsedTime = static_cast<float>(ComputeDuration_(now, last_request_)) / static_cast<float>(time_ratio_);
    last_request_ = now;
    return elapsedTime;
}

int Clock::ComputeDuration_(const time_point& lhv, const time_point& rhv)
{
    return std::chrono::duration_cast<std::chrono::microseconds>(lhv - rhv).count();
}
