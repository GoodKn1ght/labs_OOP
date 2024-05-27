#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>
#include <unordered_map>

class People {
protected:
    std::unordered_map<unsigned int, std::string> userDatabase;
    std::string currentUser;
    bool loggedIn;

public:
    People();
    void addUser(const std::string& username, const std::string& password);
    bool authenticate(const std::string& username, const std::string& password);
    bool isLoggedIn() const;
    const std::string& getCurrentUser() const;
    void logout();
};

#endif // PEOPLE_H
