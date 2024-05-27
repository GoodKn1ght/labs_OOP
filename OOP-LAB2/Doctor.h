#ifndef DOCTOR_H
#define DOCTOR_H

#include "People.h"
#include <unordered_map>
#include <vector>
#include <string>

class Doctor : public People {
private:
    std::unordered_map<std::string, std::vector<std::string>> schedule;

public:
    Doctor() : People() {}
    void addAppointment(const std::string& patient, const std::string& time);
    bool isTimeAvailable(const std::string& time) const;
    void removeAppointment(const std::string& patient, const std::string& time);
    void printSchedule() const;
};

#endif // DOCTOR_H
