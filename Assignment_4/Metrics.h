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
    std::clock_t start, end;
    double cpu_time_used;
};

#endif //ASSIGNMENT_4_METRICS_H
