#include "Doctor.h"
#include <iostream>

using namespace std;

void Doctor::addAppointment(const string& patient, const string& time) {
    schedule[patient].push_back(time);
}

bool Doctor::isTimeAvailable(const string& time) const {
    for (const auto& entry : schedule) {
        for (const string& t : entry.second) {
            if (t == time) {
                return false;
            }
        }
    }
    return true;
}

void Doctor::removeAppointment(const string& patient, const string& time) {
    auto it = schedule.find(patient);
    if (it != schedule.end()) {
        auto& appointments = it->second;
        for (auto iter = appointments.begin(); iter != appointments.end(); ++iter) {
            if (*iter == time) {
                appointments.erase(iter);
                break;
            }
        }
    }
}

void Doctor::printSchedule() const {
    for (const auto& entry : schedule) {
        cout << "Patient: " << entry.first << "\n";
        for (const string& time : entry.second) {
            cout << " - " << time << "\n";
        }
    }
}
