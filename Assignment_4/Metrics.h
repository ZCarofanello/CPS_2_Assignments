//
// Created by Glados on 9/10/2016.
//

#ifndef ASSIGNMENT_4_METRICS_H
#define ASSIGNMENT_4_METRICS_H

#include <ctime>

class Metric_Check{
public:
    Metric_Check();
    ~Metric_Check();

    void StartTimer(void);
    void StopTimer(void);

    int ReturnTime (void);


private:
    double startTimeInMicroSec;                 // starting time in micro-second
    double endTimeInMicroSec;                   // ending time in micro-second
    //int    stopped;                             // stop flag

    LARGE_INTEGER frequency;                    // ticks per second
    LARGE_INTEGER startCount;                   //
    LARGE_INTEGER endCount;                     //
};

#endif //ASSIGNMENT_4_METRICS_H
