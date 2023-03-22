#include <sstream>
#include "User.h"
#include "../DataStructures/List.h"

User::User() {
    this->id = 0;
    this->name = "";
    this->username = "";
    this->password = "";
}

User::User(unsigned int id, const std::string &name, const std::string &username, const std::string &password) {
    this->id = id;
    this->name = name;
    this->username = username;
    this->password = password;
}

User::User(const User &rhs) {
    this->id = rhs.id;
    this->name = rhs.name;
    this->username = rhs.username;
    this->password = rhs.password;

}

User::User(const std::string &stringUser, char separator) {
    List<std::string> entities;
    std::stringstream ss(stringUser);
    std::string element;

    while (getline(ss, element, separator)) {
        entities.add(element);
    }

    if (entities.lSize() == 4) {
        std::stringstream i(entities[0]);
        i >> this->id;
        this->name = entities[1];
        this->username = entities[2];
        this->password = entities[3];
    }

}


void User::setId(unsigned int id) {
    User::id = id;
}

void User::setName(const std::string &name) {
    User::name = name;
}

void User::setUsername(const std::string &username) {
    User::username = username;
}

unsigned int User::getId() const {
    return this->id;
}

const std::string &User::getName() const {
    return name;
}

const std::string &User::getUsername() const {
    return username;
}

const std::string &User::getPassword() const {
    return password;
}

void User::setPassword(const std::string &password) {
    User::password = password;
}

List<std::string> User::split() {
    List<std::string> elements;

    elements.add(std::to_string(this->id));
    elements.add(this->name);
    elements.add(this->username);
    elements.add(this->password);

    return elements;
}


bool User::operator==(const User &rhs) const {
    return id == rhs.id &&
           name == rhs.name &&
           username == rhs.username;
}

bool User::operator!=(const User &rhs) const {
    return !(rhs == *this);
}

bool User::operator<(const User &rhs) const {
    if (id < rhs.id)
        return true;
    if (rhs.id < id)
        return false;
    if (name < rhs.name)
        return true;
    if (rhs.name < name)
        return false;
    return username < rhs.username;
}

bool User::operator>(const User &rhs) const {
    return rhs < *this;
}

bool User::operator<=(const User &rhs) const {
    return !(rhs < *this);
}

bool User::operator>=(const User &rhs) const {
    return !(*this < rhs);
}

std::ostream &operator<<(std::ostream &os, const User &user) {
    os << "User {" << '\n' << "id: " << user.id << '\n' << "password: " << user.name << '\n'
       << "username: " << user.username << '\n' << "}" << '\n';
    return os;
}

User &User::operator=(const User &rhs) {
    this->id = rhs.id;
    this->name = rhs.name;
    this->username = rhs.username;
    this->password = rhs.password;
}

void UserValidator::validateId(int id) {
    if (id < 0)
        throw ValidatorException("ValidatorErr: InvalidId!");
}

void UserValidator::validateName(std::string name) {
    if (name.empty())
        throw ValidatorException("ValidatorErr: InvalidName!");

    int space = 0;

    for (const auto &c: name)
        if (isspace(c))
            space++;
    if (space == name.size())
        throw ValidatorException("ValidatorErr: InvalidName!");
    for (const auto &c: name)
        if (isdigit(c) || (!isalnum(c) && !isspace(c)))
            throw ValidatorException("ValidatorErr: InvalidName!");
}

void UserValidator::validateUsername(std::string username) {
    if (username.empty())
        throw ValidatorException("ValidatorErr: InvalidUsername!");

    int space = 0;

    for (const auto &c: username)
        if (isspace(c))
            space++;
    if (space == username.size())
        throw ValidatorException("ValidatorErr: InvalidUsername!");

    for (const auto &c: username)
        if (isdigit(c) || (!isalnum(c) && !isspace(c)))
            throw ValidatorException("ValidatorErr: InvalidUserame!");

}

void UserValidator::validatePassword(std::string password) {
    if (password.empty())
        throw ValidatorException("ValidatorErr: InvalidPassword!");


    int space = 0;

    for (const auto &c: password)
        if (isspace(c))
            space++;
    if (space == password.size())
        throw ValidatorException("ValidatorErr: InvalidPassword!");
    /* for (const auto &c: password)
         if (isdigit(c) || (!isalnum(c) && !isspace(c)))
             throw ValidatorException("ValidatorErr: InvalidPassword!");*/
}
