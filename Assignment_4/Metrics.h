/////////////////////////////////////////////////////////////////////////
// Title: Assignment 4 - Fractions and Efficiency Metrics
// Author: Zachary Carofanello
// CPET-321 Computational Problem Solving II Fall 2016
// Platform: CLion 2016.2.1
// Description: Working with fractions held as integers
//
// Revisions:
// Revision 1.0 10/09/2016
//
/////////////////////////////////////////////////////////////////////////

#ifndef ASSIGNMENT_4_METRICS_H
#define ASSIGNMENT_4_METRICS_H

#include <ctime>
#include <windows.h>

class Metric_Check{
public:
    Metric_Check();
    ~Metric_Check();

    void ResetTimer (void);

    void StartTimer(void);
    void StopTimer(void);

    double ReturnTime (void);


private:
    double startTime_us; // start time in us
    double endTime_us;   // end time in us
    int    stop;         // stop flag

    LARGE_INTEGER frequency;
    LARGE_INTEGER startCount;
    LARGE_INTEGER endCount;
};

#endif //ASSIGNMENT_4_METRICS_H
