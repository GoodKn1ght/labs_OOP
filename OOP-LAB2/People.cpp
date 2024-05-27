#include "People.h"
#include "Utils.h"
#include <iostream>

using namespace std;

People::People() : loggedIn(false) {}

void People::addUser(const string& username, const string& password) {
    unsigned int hashedPassword = customHash(password);
    userDatabase[hashedPassword] = username;
}

bool People::authenticate(const string& username, const string& password) {
    unsigned int hashedPassword = customHash(password);
    auto it = userDatabase.find(hashedPassword);
    if (it != userDatabase.end() && it->second == username) {
        cout << "Користувач " << username << " успішно авторизований.\n";
        currentUser = username;
        loggedIn = true;
        return true;
    } else {
        cout << "Помилка авторизації: невірне ім'я користувача або пароль.\n";
        loggedIn = false;
        return false;
    }
}

bool People::isLoggedIn() const {
    return loggedIn;
}

const string& People::getCurrentUser() const {
    return currentUser;
}

void People::logout() {
    loggedIn = false;
    cout << "Ви вийшли з акаунту.\n";
}
