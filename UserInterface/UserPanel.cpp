
#include <iostream>
#include "UserPanel.h"

UserPanel::UserPanel(Network &network) : network(network) {}

void UserPanel::showUserMenu() {
    std::cout << "1. Create an acount" << '\n';
    std::cout << "2. Log in" << '\n';
    std::cout << "x. Exit" << '\n';
    std::cout << "Option: ";

}

void UserPanel::runUserMenu() {
    char option;
    bool shouldRun = true;

    while (shouldRun) {
        showUserMenu();
        std::cin >> option;
        switch (option) {
            case '1': {
                try {
                    std::string name, username, password;
                    std::cout << "Name: ";
                    std::cin >> name;
                    std::cout << "Username: ";
                    std::cin >> username;
                    std::cout << "Password: ";
                    std::cin >> password;
                    network.userService.add(name, username, password);
                    std::cout << "Successfully created!" << '\n';
                }
                catch (RepositoryException &err) {
                    std::cout << err << '\n';
                }
                catch (ValidatorException &err) {
                    std::cout << err << '\n';
                }
                catch (ServiceException &err) {
                    std::cout << err << '\n';
                }
                break;

            }
            case '2': {
                std::string username, password;
                std::cout << "Username: ";
                std::cin >> username;
                std::cout << "Password: ";
                std::cin >> password;
                if (network.userService.logIn(username, password)) {
                    int id = network.userService.getUserByUsername(username).getId();
                    this->runLoggedUserMenu(id);
                } else {
                    std::cout << "Invalid username or password!" << '\n';
                }
                break;

            }
            case 'x': {
                shouldRun = false;
                break;
            }
            default: {
                std::cout << "Invalid option! Try again" << '\n';
                break;
            }
        }
    }

}

void UserPanel::showLoggedUserMenu() {
    std::cout << "1. View friends" << '\n';
    std::cout << "2. Add a friend" << '\n';
    std::cout << "3. Remove a friend" << '\n';
    std::cout << "4. Send a message" << '\n';
    std::cout << "5. Get conversation with an user" << '\n';
    std::cout << "6. Delete a message" << '\n';
    std::cout << "7. Show all events" << '\n';
    std::cout << "8. Add an event" << '\n';
    std::cout << "9. Remove an event" << '\n';
    std::cout << "x. Log out" << '\n';
    std::cout << "Option: ";
}

void UserPanel::runLoggedUserMenu(unsigned int idUser) {
    char option;
    bool run = true;
    while (run) {
        this->showLoggedUserMenu();
        std::cin >> option;
        switch (option) {
            case '1': {
                List<std::string> friends = network.friendshipService.getFriends(idUser);
                std::cout << "Friends:" << '\n';
                for (int i = 0; i < friends.lSize(); i++)
                    std::cout << friends[i] << '\n';
                break;
            }
            case '2': {
                std::string newFriendUsername;
                std::cout << "Give username: ";
                std::cin >> newFriendUsername;
                try {
                    network.addFriend(idUser, newFriendUsername);
                    std::cout << "Now you are friends!" << '\n';
                }
                catch (RepositoryException &err) {
                    std::cout << err << '\n';
                }
                catch (ValidatorException &err) {
                    std::cout << err << '\n';
                }
                catch (ServiceException &err) {
                    std::cout << err << '\n';
                }
                break;
            }
            case '3': {
                std::string username;
                std::cout << "Username: ";
                std::cin >> username;
                try {
                    network.removeFriend(idUser, username);
                    std::cout << "You are no longer friends!" << '\n';
                }
                catch (RepositoryException &err) {
                    std::cout << err << '\n';
                }
                catch (ValidatorException &err) {
                    std::cout << err << '\n';
                }
                catch (ServiceException &err) {
                    std::cout << err << '\n';
                }
                break;
            }
            case '4': {
                std::string username;
                // std::string message;
                std::cout << "Message to: ";
                std::cin >> username;
                try {
                    network.getMessages(idUser, username);
                    std::cout << "Type a message: ";
                    char message[100];
                    cin.get();
                    std::cin.getline(message, 90);
                    network.sendMessage(idUser, username, message);
                } catch (RepositoryException &err) {
                    std::cout << err << '\n';
                }
                catch (ValidatorException &err) {
                    std::cout << err << '\n';
                }
                catch (ServiceException &err) {
                    std::cout << err << '\n';
                }
                break;
            }
            case '5': {
                std::string username;
                std::cout << "Get conversation with: ";
                std::cin >> username;
                try {
                    network.getMessages(idUser, username);
                } catch (RepositoryException &err) {
                    std::cout << err << '\n';
                }
                catch (ValidatorException &err) {
                    std::cout << err << '\n';
                }
                catch (ServiceException &err) {
                    std::cout << err << '\n';
                }
                break;
            }
            case '6': {
                unsigned int idMessage;
                std::cout << "Id: ";
                std::cin >> idMessage;
                if(cin.fail()){
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout<< "Invalid id!" << '\n';
                    break;
                }
                if(idMessage < 0){
                    std::cout << "Invalid id!" << '\n';
                    break;
                }
                try {
                    network.deleteMessage(idMessage, idUser);
                }
                catch (RepositoryException &err) {
                    std::cout << err << '\n';
                }
                catch (ValidatorException &err) {
                    std::cout << err << '\n';
                }
                catch (ServiceException &err) {
                    std::cout << err << '\n';
                }
                break;
            }
            case '7': {
                network.eventService.show();
                break;
            }
            case '8': {
                unsigned int id;
                std::string name, location, date, username;
                std::cout << "Id: ";
                std::cin >> id;
                if(cin.fail()){
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout<< "Invalid id!" << '\n';
                    break;
                }
                if(id < 0){
                    std::cout << "Invalid id!" << '\n';
                    break;
                }
                std::cout << "Name: ";
                std::cin >> name;
                std::cout << "Location: ";
                std::cin >> location;
                std::cout << "Date: ";
                std::cin >> date;
                username = network.userService.getUserById(idUser).getUsername();
                try {

                    network.eventService.addEvent(id, name, location, date, username);
                    std::cout << "Successfully added!" << '\n';
                }
                catch (ValidatorException &err) {
                    std::cout << err << '\n';
                }
                catch (RepositoryException &err) {
                    std::cout << err << '\n';
                }
                catch (ServiceException &err) {
                    std::cout << err << '\n';
                }
                break;
            }
            case '9': {
                int id;
                std::string name, location, date, username;
                std::cout << "Id: ";
                std::cin >> id;
                if(cin.fail()){
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout<< "Invalid id!" << '\n';
                    break;
                }
                if(id < 0){
                    std::cout << "Invalid id!" << '\n';
                    break;
                }
                std::cout << "Name: ";
                std::cin >> name;
                std::cout << "Location: ";
                std::cin >> location;
                std::cout << "Date: ";
                std::cin >> date;
                username = network.userService.getUserById(idUser).getUsername();
                try {

                    network.eventService.removeUserEvent(id, name, location, date, username);
                    std::cout << "Successfully deleted!" << '\n';
                }
                catch (ValidatorException &err) {
                    std::cout << err << '\n';
                }
                catch (RepositoryException &err) {
                    std::cout << err << '\n';
                }
                catch (ServiceException &err) {
                    std::cout << err << '\n';
                }
                break;
            }
            case 'x': {
                run = false;
                break;
            }
            default: {
                std::cout << "Invalid option! Try again!" << '\n';
            }
        }
    }

}
