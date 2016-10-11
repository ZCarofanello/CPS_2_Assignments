#include <iostream>
#include "LCG.h"

struct Data {
    int min;
    int max;
    float mean;
    float median;
    int mode;
} ;

void BubbleSort (int List[], int size);
float CalcMedian(const int values[],int num);
float CalcMean(const int values[] , int num);
int CalcMode(const int values[],int num);

int main() {
    const int TRIALS = 50;
    const int SAMPLE_SIZE = 1000;

    int Random_Array [TRIALS][SAMPLE_SIZE];
    Data Aggregate_Data [TRIALS];
    LCG Testing;

    for(int i = 0; i < TRIALS; i++) {
        Testing.SetValues(i,9,3,100);
        for (int j = 0; j < SAMPLE_SIZE; j++) {
            int k = Testing.RandomNumber();
            Random_Array[i][j] = k;
        }
        BubbleSort(Random_Array[i],SAMPLE_SIZE);
    }

    for(int i = 0; i < TRIALS; i++) {
        Aggregate_Data[i].min = Random_Array[i][0];
        Aggregate_Data[i].max = Random_Array[i][SAMPLE_SIZE-1];
        Aggregate_Data[i].median = CalcMedian(Random_Array[i], SAMPLE_SIZE);
        Aggregate_Data[i].mean = CalcMean(Random_Array[i], SAMPLE_SIZE);
        Aggregate_Data[i].mode = CalcMode(Random_Array[i], SAMPLE_SIZE);
    }
    int TotalMin = 0, TotalMax = 0, TotalMode = 0;
    float TotalMedian = 0, TotalMean = 0;
    for(int i = 0; i < TRIALS; i++) {
        TotalMin    += Aggregate_Data[i].min;
        TotalMax    += Aggregate_Data[i].max;
        TotalMedian += Aggregate_Data[i].median;
        TotalMean   += Aggregate_Data[i].mean;
        TotalMode   += Aggregate_Data[i].mode;
    }

    TotalMin = TotalMin / TRIALS;
    TotalMax = TotalMax / TRIALS;
    TotalMean = TotalMean / TRIALS;
    TotalMedian = TotalMedian / TRIALS;
    TotalMode = TotalMode / TRIALS;

    std::cout << "This is the avg minimum number for all trials " << TotalMin    << std::endl;
    std::cout << "This is the avg maximum number for all trials " << TotalMax    << std::endl;
    std::cout << "This is the avg mode number for all trials "    << TotalMode   << std::endl;
    std::cout << "This is the avg median number for all trials "  << TotalMedian << std::endl;
    std::cout << "This is the avg mean number for all trials "    << TotalMean   << std::endl;

    Testing.~LCG();

    system("pause");
    return 0;
}

void BubbleSort (int List[], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (List[j] < List[i]) {
                int buff;
                buff = List[i];
                List[i] = List[j];
                List[j] = buff;
            }
        }
    }
}

int AvgofList (int List[], int size){
    int sum = 0;
    for(int i = 0; i < size; i++)
        sum += List[i];
    return sum / size;
}

float CalcMean(const int values[] , int num){
    if (num<=0) return 0;
    int count=0;
    for (int i=0;i<num;i++) count += values[i];
    return (float)count / num;
}

float CalcMedian(const int values[],int num){
    if(num<=0) return 0;
    if(num%2) return (float)values[(num+1)/2];
    else{
        int pos = num/2;
        return (float)(values[pos] + values[pos+1]) / 2;
    }
}

int CalcMode(const int values[],int num){
    if(num<=0)return 0;
    int max_count=0 , pos=0, max_nums=0;
    int count=1;
    for(int i=1;i<num;i++){
        if(values[i] != values[pos]){
            if(count > max_count){
                max_count=count;
                max_nums=0;
            }else if (count == max_count) max_nums++;
            pos= i;
            count=0;
        }else count++;
    }
    if(max_nums) return 0;
    else return values[pos];
}