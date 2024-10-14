#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
//#include <string>

using std::cout;
using std::flush;
using std::this_thread::sleep_for;
using std::chrono::seconds;

constexpr float MAX_TEMPERATURE = 102;
constexpr float MIN_TEMPERATURE = 95;
constexpr float MAX_PULSE_RATE = 100;
constexpr float MIN_PULSE_RATE = 60;
constexpr float MIN_SPO2 = 90;
constexpr float MAX_SPO2 = 100;

bool isParametersNormal( float value, float max, float min, const char* vitalName) {
    if (value < min || value > max) {
        printOutput(vitalName);
        return false;
    }
    return true;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {

    bool isTempNormal = isParametersNormal(temperature, MAX_TEMPERATURE, MIN_TEMPERATURE, "Temperature is critical!\n");
    bool isPulseNormal = isParametersNormal(pulseRate, MAX_PULSE_RATE, MIN_PULSE_RATE, "Pulse Rate is out of range!\n");
    bool isOxygenNormal = isParametersNormal(spo2, MAX_SPO2, MIN_SPO2, "Oxygen Saturation out of range!\n");

    return  isTempNormal && isPulseNormal && isOxygenNormal;
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
