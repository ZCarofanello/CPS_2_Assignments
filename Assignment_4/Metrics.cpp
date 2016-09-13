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
#include <windows.h>
#include <stdlib.h>
#include "Metrics.h"

Metric_Check::Metric_Check() {
    QueryPerformanceFrequency(&frequency);
    startCount.QuadPart = 0;
    endCount.QuadPart = 0;

    stop = 0;
    startTime_us = 0;
    endTime_us = 0;
}

Metric_Check::~Metric_Check() {

}

void Metric_Check::ResetTimer() {
    startCount.QuadPart = 0;
    endCount.QuadPart = 0;

    stop = 0;
    startTime_us = 0;
    endTime_us = 0;
}

void Metric_Check::StartTimer() {
    stop = 0; // reset stop flag
    QueryPerformanceCounter(&startCount);
}

void Metric_Check::StopTimer() {
    stop = 1; // set timer stopped flag
    QueryPerformanceCounter(&endCount);

}

double Metric_Check::ReturnTime() {
    if(!stop)
        QueryPerformanceCounter(&endCount);

    startTime_us = startCount.QuadPart * (1000000.0 / frequency.QuadPart);
    endTime_us = endCount.QuadPart * (1000000.0 / frequency.QuadPart);

    return endTime_us - startTime_us;
}