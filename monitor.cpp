#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>

using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

constexpr float MAX_TEMP = 102;
constexpr float MIN_TEMP = 95;
constexpr float MAX_PULSE = 100;
constexpr float MIN_PULSE = 60;
constexpr float MIN_SPO2 = 90;
constexpr float MAX_SPO2 = 100;
const char* tempWarning = "Temperature is critical!\n";
const char* pulseWarning = "Pulse Rate is out of range!\n";
const char* oxygenWarning = "Oxygen Saturation out of range!\n";

bool isVitalNormal(float value, float max, float min, const char* vitalWarning) {
    if (value < min || value > max) {
        printOutput(vitalWarning);
        return false;
    }
    return true;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
    bool isTempNormal = isVitalNormal(temperature, MAX_TEMP, MIN_TEMP, tempWarning);
    bool isPulseNormal = isVitalNormal(pulseRate, MAX_PULSE, MIN_PULSE, pulseWarning);
    bool isOxygenNormal = isVitalNormal(spo2, MAX_SPO2, MIN_SPO2, oxygenWarning);

    return  isTempNormal && isPulseNormal && isOxygenNormal;
}

void printOutput(std::string message) {
    cout << message;
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
}
