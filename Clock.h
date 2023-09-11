#pragma once
#include <chrono>
#include <thread>

class Clock
{
public:
	Clock(float fps);
	void Tick();
	float ElapsedTime();

private:
	typedef std::chrono::time_point<std::chrono::high_resolution_clock> time_point;

	int ComputeDuration_(const time_point& lhv, const time_point& rhv);

	float fps_;
	int interval_;
	time_point start_;
	time_point last_request_;

	const int time_ratio_ = 1'000'000;
};


