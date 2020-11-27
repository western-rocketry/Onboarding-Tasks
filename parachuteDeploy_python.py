import random
from time import sleep

iterationFactor: int = 1
simpleCounter: int = 0
noisyCounter: int = 0
pdTrigger = False


def simpleSensor_Function():
    global iterationFactor
    global simpleCounter
    dataValue = round(random.uniform(0, 9), 2) + iterationFactor

    if simpleCounter < 150:
        iterationFactor += 70
    else:
        iterationFactor -= 70

    simpleCounter += 1
    
    if simpleCounter >= 302:
        raise Exception("It appears we've turned this rocket into a lawn dart! MISSION FAILED")
    
    sleep(0.1)
    return dataValue


def noisySensor_Function():
    global noisyCounter
    global iterationFactor
    dataSet = []

    for i in range(3):
        dataSet.append(round(random.uniform(4, 7), 2) + iterationFactor)
        if noisyCounter <= 150:
            iterationFactor += 10
        else:
            iterationFactor -= 10

    noisyCounter += 1
    
    if noisyCounter >= 302:
        raise Exception("It appears we've turned this rocket into a lawn dart! MISSION FAILED")
        
    sleep(0.1)
    return dataSet


def user_Function():
    # display max altitude, height at which parachute is deployed, flight time (opt.)
    while not pdTrigger:
        # Write code here
        
        print(simpleSensor_Function(), "   Counter: ", simpleCounter)
        print(noisySensor_Function(), "    Counter: ", noisyCounter, "\n")
        


user_Function()

