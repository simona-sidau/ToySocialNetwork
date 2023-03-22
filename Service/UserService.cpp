#include "UserService.h"

UserService::UserService(RepositoryCSV<User> &repositoryCsv) : userRepository(repositoryCsv) {}


List<User> UserService::read() {
    return userRepository.getAll();
}

void UserService::add(std::string name, std::string username, std::string password) {

    if (userRepository.noEntities() != 0)
        this->id = userRepository.getEntityByIndex(userRepository.noEntities() - 1).getId() + 1;
    else
        this->id = 0;

    UserValidator::validateId(this->id);
    UserValidator::validateName(name);
    UserValidator::validateUsername(username);
    UserValidator::validatePassword(password);
    this->checkUsername(username);
    User user(this->id, name, username, password);

    userRepository.add(user);


}

void UserService::update(unsigned int id, std::string name, std::string username, std::string password) {

    UserValidator::validateName(name);
    UserValidator::validateUsername(username);
    UserValidator::validatePassword(password);

    if (username != this->getUserById(id).getUsername())
        this->checkUsername(username);

    User user(id, name, username, password);

    userRepository.update(user);

}

void UserService::remove(unsigned int id) {

    userRepository.remove(this->getUserById(id));

}

User UserService::getUserById(unsigned int id) {
    return userRepository.getEntity(id);
}

void UserService::checkUsername(std::string username) {
    List<User> users = this->read();

    for (int i = 0; i < users.lSize(); i++) {
        if (users[i].getUsername() == username) {
            throw ServiceException("ServiceERR: This username already exist!");
        }
    }
}

User UserService::getUserByUsername(std::string username) {
    List<User> users = this->read();

    for (int i = 0; i < users.lSize(); i++) {
        if (users[i].getUsername() == username) {
            return users[i];
        }
    }
    throw ServiceException("ServiceERR: This user does not exist!");
}

bool UserService::logIn(std::string username, std::string password) {

    List<User> users = this->read();

    for (int i = 0; i < users.lSize(); i++) {
        if (users[i].getUsername() == username) {
            if (users[i].getPassword() == password)
                return true;
            else
                return false;
        }
    }
    return false;
}







