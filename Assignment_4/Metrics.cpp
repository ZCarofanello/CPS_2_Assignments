//
// Created by Glados on 9/10/2016.
//
#include <windows.h>
#include <stdlib.h>
#include "Metrics.h"

Metric_Check::Metric_Check() {

}

Metric_Check::~Metric_Check() {

}

void Metric_Check::StartTimer() {
    QueryPerformanceFrequency(&frequency);
    startCount.QuadPart = 0;
    endCount.QuadPart = 0;
}

void Metric_Check::StopTimer() {

}

int Metric_Check::ReturnTime() {

}