#ifndef PROIECTTOYSOCIALNETWORK_ADMIN_H
#define PROIECTTOYSOCIALNETWORK_ADMIN_H


#include "Console.h"

class Admin {
private:
    Network network;
public:
    /**
     * Constructor
     * @param network
     */
    Admin(Network &network);

    /**
     * Destructor
     */
    ~Admin() = default;

    /**
     * Show menu for the admin
     */
    void showAdminMenu();

    /**
     * Run menu for the admin
     */
    void runAdminMenu();

};


#endif //PROIECTTOYSOCIALNETWORK_ADMIN_H
