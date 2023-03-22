#ifndef PROIECTTOYSOCIALNETWORK_USERINTERFACE_H
#define PROIECTTOYSOCIALNETWORK_USERINTERFACE_H

#include "Console.h"
#include "../Service/Network.h"


class UserPanel {
private:
    Network network;
public:
    /**
     * Constructor
     * @param network
     */
    UserPanel(Network &network);

    /**
     * Destructor
     */
    ~UserPanel() = default;

    /**
     * Show the menu for an user
     */
    void showUserMenu();

    /**
     * Show menu for a logged user
     */
    void showLoggedUserMenu();

    /**
     * run menu for an user
     */
    void runUserMenu();

    /**
     * run menu for a logged user
     * @param id
     */
    void runLoggedUserMenu(unsigned int id);


};


#endif //PROIECTTOYSOCIALNETWORK_USERINTERFACE_H
