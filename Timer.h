#ifndef TIMER_H
#define TIMER_H

#include <cmath>
#include <random>

#include <chrono>
#include <cstdlib>
#include <iostream>

template<typename Clock = std::chrono::system_clock>
class Timer{

private:
    typedef std::chrono::time_point<Clock> time_point;
    time_point _start;
    time_point _finish;
public:
    void start(){
        _start = Clock::now();
    }
    void finish(){
        _finish = Clock::now();
    }
    template<typename rtype>
    rtype count(){
        std::chrono::duration<rtype> elapsed = _finish - _start;
        return elapsed.count();
    }
};
#endif // TIMER_H
