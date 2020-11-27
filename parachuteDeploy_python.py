import random
from time import sleep

iterationFactor = 1
counter = 0
upperLimit = round(random.uniform(300, 360), 0)
pdTrigger = False


# this function outputs a single value iterating over time simulating altitude outputs
def simpleSensor_Function():
    global iterationFactor
    global counter
    global upperLimit

    dataValue = round(random.uniform(0, 9), 2) + iterationFactor

    if counter < upperLimit:
        iterationFactor += 20
    else:
        iterationFactor -= 20

    counter += 1

    if counter >= upperLimit * 2:
        raise Exception("It appears we've turned this rocket into a lawn dart! MISSION FAILED")

    sleep(0.1)
    return dataValue


# this function outputs an array of 3 values iterating over time simulating altitude outputs with noise
def noisySensor_Function():
    global counter
    global iterationFactor
    global upperLimit
    dataSet = []

    for i in range(3):
        dataSet.append(round(random.uniform(4, 7), 2) + iterationFactor)
        if counter <= upperLimit:
            iterationFactor += 20
        else:
            iterationFactor -= 20

    counter += 1

    if counter >= upperLimit * 2:
        raise Exception("It appears we've turned this rocket into a lawn dart! MISSION FAILED")
    
    sleep(0.1)
    return dataSet


def user_Function():
    # display max altitude, height at which parachute is deployed, flight time.
    while not pdTrigger:
        # Write code here
        # Implement either the simple sensor or noisy sensor function when completing the program.

        # Example outputs:
        print(simpleSensor_Function(), "   Counter: ", counter)
        print(noisySensor_Function(), "    Counter: ", counter, "\n")
    

user_Function()

