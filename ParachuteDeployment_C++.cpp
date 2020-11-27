#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int iterationFactor = 0;
int counter = 0;
int upperLimit = rand() % 60 + 490;

bool pdTrigger;

float simpleSensor_Function(){

    float dataValue;

    try{
        dataValue = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX/9.0)) + iterationFactor;

        if(counter < upperLimit){
            iterationFactor += 20;
        }
        else{
            iterationFactor -= 20;
        }

        counter++;

        if (counter > (upperLimit*2 + 10)){
            throw "crashDetection";
        }
    }

    catch(...){
        cout << "It appears we've turned this rocket into a lawn dart! MISSION FAILED";
        exit(0);
    }

    return dataValue;
}

float * noisySensor_Function(){

    float dataValue;
    float static dataSet[3];

    try {
        for(int i = 0; i < 3; i++){
            dataSet[i] = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX/9.0)) + iterationFactor;
        }

        if (counter <= upperLimit){
            iterationFactor += 20;
        }
        else {
            iterationFactor -= 20;
        }

        counter++;

        if (counter > (upperLimit*2 + 10)){
            throw "crashDetection";
        }
    }

    catch(...){
        cout << "It appears we've turned this rocket into a lawn dart! MISSION FAILED";
        exit(0);
    }

    return dataSet;
}

int main()
{
    // display max altitude, height at which parachute is deployed, flight time

    float *data; //https://www.tutorialspoint.com/cplusplus/cpp_return_arrays_from_functions.htm?fbclid=IwAR1NiTClRMcOKfu7gH_n3psQv2Q527U8YTKE5f6XmKHymrzQQiIe2qoWybs

    while(pdTrigger == false){ //trigger paracute deployment
        // Write code here
        // Implement either the simple sensor or noisy sensor function when completing the program

        //Example output
        cout << simpleSensor_Function() << " " << " Iteration step: " << counter << "\n";

        //data = noisySensor_Function();
        //cout << *(data+0) << " " << *(data+1) << " " << *(data+2) << " Iteration step: " << counter << "\n";

    }

    return 0;
}
