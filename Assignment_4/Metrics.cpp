//
// Created by Glados on 9/10/2016.
//
#include <windows.h>
#include <stdlib.h>
#include "Metrics.h"

Metric_Check::Metric_Check() {
    QueryPerformanceFrequency(&frequency);
    startCount.QuadPart = 0;
    endCount.QuadPart = 0;

    stopped = 0;
    startTimeInMicroSec = 0;
    endTimeInMicroSec = 0;
}

Metric_Check::~Metric_Check() {

}

void Metric_Check::ResetTimer() {
    startCount.QuadPart = 0;
    endCount.QuadPart = 0;

    stopped = 0;
    startTimeInMicroSec = 0;
    endTimeInMicroSec = 0;
}

void Metric_Check::StartTimer() {
    stopped = 0; // reset stop flag
    QueryPerformanceCounter(&startCount);
}

void Metric_Check::StopTimer() {
    stopped = 1; // set timer stopped flag
    QueryPerformanceCounter(&endCount);

}

double Metric_Check::ReturnTime() {
    if(!stopped)
        QueryPerformanceCounter(&endCount);

    startTimeInMicroSec = startCount.QuadPart * (1000000.0 / frequency.QuadPart);
    endTimeInMicroSec = endCount.QuadPart * (1000000.0 / frequency.QuadPart);

    return endTimeInMicroSec - startTimeInMicroSec;
}