#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout;
using std::flush;
using std::this_thread::sleep_for;
using std::chrono::seconds;

int vitalsOk(float temperature, float pulseRate, float spo2) {
    if (temperature > 102 || temperature < 95) { return printOutput("Temperature is critical!\n");}
    else if (pulseRate < 60 || pulseRate > 100) {return printOutput("Pulse Rate is out of range!\n");}
    else if (spo2 < 90) {return printOutput("Oxygen Saturation out of range!\n");}
    return 1;
}

int printOutput(std::string message)
{
    cout << message;

    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
    return 0;
}
