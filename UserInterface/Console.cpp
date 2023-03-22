#include <iostream>
#include "Console.h"
#include "UserPanel.h"
#include "Admin.h"


Console::Console(Network &network) : network(network) {}

void Console::showStartMenu() {
    std::cout << "1. Admin" << '\n';
    std::cout << "2. User" << '\n';
    std::cout << "3. Exit" << '\n';
    std::cout << "Option: ";
}

void Console::startAplication() {
    char option;
    bool shouldRun = true;

    while (shouldRun) {
        this->showStartMenu();
        std::cin >> option;
        switch (option) {
            case '1': {
                Admin admin(network);
                admin.runAdminMenu();
                break;
            }
            case '2': {
                UserPanel userI(network);
                userI.runUserMenu();
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