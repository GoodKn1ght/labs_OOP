#include <iostream>
#include "Patient.h"
#include "Doctor.h"

using namespace std;

void createUser(People& user) {
    string username, password;
    cout << "Введіть ім'я користувача: ";
    cin >> username;
    cout << "Введіть пароль: ";
    cin >> password;
    user.addUser(username, password);
    cout << "Акаунт для користувача " << username << " створено.\n";
}

void makeAppointment(Doctor& doctor, Patient& patient) {
    if (!patient.isLoggedIn()) {
        cout << "Спочатку увійдіть у свій акаунт.\n";
        return;
    }

    vector<string> availableTimes = {"10:00", "11:00", "13:00", "14:00"};

    cout << "Доступні години для запису:\n";
    for (int i = 0; i < availableTimes.size(); ++i) {
        if (doctor.isTimeAvailable(availableTimes[i])) {
            cout << i + 1 << ". " << availableTimes[i] << "\n";
        }
    }

    int choice;
    cout << "Виберіть номер години зі списку: ";
    cin >> choice;

    if (choice >= 1 && choice <= availableTimes.size()) {
        string selectedTime = availableTimes[choice - 1];
        if (doctor.isTimeAvailable(selectedTime)) {
            doctor.addAppointment(patient.getCurrentUser(), selectedTime);
            cout << "Запис успішно зроблено на " << selectedTime << ".\n";
        } else {
            cout << "Цей час вже зайнятий. Спробуйте обрати інший час.\n";
        }
    } else {
        cout << "Невірний вибір години.\n";
    }
}

int main() {
    Patient patient;
    Doctor doctor;

    char choice;
    cout << "Вітаємо!\n";
    while (true) {
        cout << "Бажаєте увійти в існуючий акаунт (l) чи створити новий (c)? ";
        cin >> choice;

        if (choice == 'c') {
            createUser(patient);
            cout << "Бажаєте увійти в існуючий акаунт (l) чи створити новий (c)? ";
            cin >> choice;
            if (choice == 'l') {
                break;
            }
        } else if (choice == 'l') {
            break;
        } else {
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    }

    while (!patient.isLoggedIn()) {
        string username, password;
        cout << "Введіть ім'я користувача: ";
        cin >> username;
        cout << "Введіть пароль: ";
        cin >> password;
        patient.authenticate(username, password);
    }

    cout << "Ви увійшли в акаунт " << patient.getCurrentUser() << ".\n";

    while (true) {
        cout << "Оберіть дію:\n";
        cout << "1. Переглянути свої записи до лікаря\n";
        cout << "2. Зробити новий запис до лікаря\n";
        cout << "3. Вийти з програми\n";
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "Ваші записи до лікаря:\n";
            doctor.printSchedule();
        } else if (choice == 2) {
            makeAppointment(doctor, patient);
        } else if (choice == 3) {
            cout << "До зустрічі! Ви вийшли з програми.\n";
            break;
        } else {
            cout << "Невідома команда. Спробуйте ще раз.\n";
        }
    }
    return 0;
}
