#ifndef PROIECTTOYSOCIALNETWORK_CONSOLE_H
#define PROIECTTOYSOCIALNETWORK_CONSOLE_H

#include "../Service/Network.h"


class Console {
protected:
    Network network;
public:
    /**
     * Constructor
     * @param network
     */
    Console(Network &network);
    /**
     * Destructor
     */
    ~Console() = default;
    /**
     * Show start menu
     */
    void showStartMenu();
    /**
     * Start the aplication
     */
    void startAplication();
};



#endif //PROIECTTOYSOCIALNETWORK_CONSOLE_H
