#include <iostream>
#include "Admin.h"
#include "Console.h"

Admin::Admin(Network &network) : network(network) {}

void Admin::showAdminMenu() {
    std::cout << "1. Show all users" << '\n';
    std::cout << "2. Add an user" << '\n';
    std::cout << "3. Remove an user" << '\n';
    std::cout << "4. Update an user" << '\n';
    std::cout << "5. Create an event" << '\n';
    std::cout << "6. Delete an event" << '\n';
    std::cout << "7.Show all events" << '\n';
    std::cout << "x.Exit" << '\n';
    std::cout << "Option: ";

}

void Admin::runAdminMenu() {
    char option;
    bool shouldRun = true;

    while (shouldRun) {
        showAdminMenu();
        std::cin >> option;
        switch (option) {
            case '1': {
                List<User> users = network.userService.read();
                for (int i = 0; i < users.lSize(); i++) {
                    std::cout << users[i] << '\n';
                }
                break;
            }
            case '2': {
                try {
                    std::string name, username, password;
                    std::cout << "Name: ";
                    std::cin >> name;
                    std::cout << "Username: ";
                    std::cin >> username;
                    std::cout << "Password: ";
                    std::cin >> password;

                    network.userService.add(name, username, password);

                    std::cout << "Successfully added!" << '\n';
                }
                catch (RepositoryException &err) {
                    std::cout << err << '\n';
                }
                catch (ValidatorException &err) {
                    std::cout << err << '\n';
                }
                break;

            }
            case '3': {
                try {
                    int id;
                    std::cout << "Give the id of the acount to be removed: ";
                    std::cin >> id;
                    if (cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout << "Invalid id!" << '\n';
                        break;
                    }
                    if(id < 0){
                        std::cout << "Invalid id!" << '\n';
                        break;
                    }
                    network.userService.remove(id);
                    network.friendshipService.multiRemove(id);
                    std::cout << "Successfully deleted!" << '\n';
                }
                catch (RepositoryException &err) {
                    std::cout << err << '\n';
                }
                break;
            }
            case '4': {
                try {
                    int id;
                    std::string name, username, password;
                    std::cout << "Give the id of the account to be modified: ";
                    std::cin >> id;
                    if (cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout << "Invalid id!" << '\n';
                        break;
                    }
                    if(id < 0){
                        std::cout << "Invalid id!" << '\n';
                        break;
                    }
                    std::cout << "New name: ";
                    std::cin >> name;
                    std::cout << "New username: ";
                    std::cin >> username;
                    std::cout << "New password: ";
                    std::cin >> password;
                    network.userService.update(id, name, username, password);

                    std::cout << "Successfully updated!" << '\n';
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
            case '5': {
                std::string name, location, date;
                std::cout << "Name: ";
                std::cin >> name;
                std::cout << "Location: ";
                std::cin >> location;
                std::cout << "Date: ";
                std::cin >> date;
                try {

                    network.eventService.add(name, location, date);
                    std::cout << "Successfully added!" << '\n';
                }
                catch (ValidatorException &err) {
                    std::cout << err << '\n';
                }
                catch (ServiceException &err) {
                    std::cout << err << '\n';
                }
                catch (RepositoryException &err) {
                    std::cout << err << '\n';
                }
                break;
            }
            case '6': {
                int id;
                std::string name, location, date;
                std::cout << "Id: ";
                std::cin >> id;
                if (cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "Invalid id!" << '\n';
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
                try {

                    network.eventService.remove(id, name, location, date);
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
            case '7': {
                network.eventService.show();
                break;
            }
            case 'x': {
                shouldRun = false;
                break;
            }
            default: {
                std::cout << "Invalid option! Try again!" << '\n';
                break;
            }

        }
    }

}
