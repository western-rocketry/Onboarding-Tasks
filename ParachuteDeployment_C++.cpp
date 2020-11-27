#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int iterationFactor = 1;
int simpleCounter = 0;
int noisyCounter = 0;

bool pdTrigger;

float simpleSensor_Function(){

    float dataValue;

    dataValue = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX/9.0)) + iterationFactor;

    if(simpleCounter < 150){
        iterationFactor += 70;
    }
    else{
        iterationFactor -= 70;
    }

    simpleCounter++;

    return dataValue;
}

float * noisySensor_Function(){

    float dataValue;
    float dataSet[3];

    for(int i = 0; i < 3; i++){
        dataSet[i] = (4.0 + static_cast <float> (rand()) / static_cast <float> (RAND_MAX/3.0)) + iterationFactor;
    }

    if (noisyCounter <= 13){
        iterationFactor += 5;
    }
    else{
        iterationFactor -= 5;
    }

    noisyCounter++;

    return dataSet;
}

int main()
{
    // display max altitude, height at which parachute is deployed, flight time (opt.)

    while(pdTrigger == false){ //trigger paracute deployment
        // write code here

    }

    return 0;
}
