#ifndef MAIN_CPP_EVENTSERVICE_H
#define MAIN_CPP_EVENTSERVICE_H

#include "../Domain/Event.h"
#include "../DataStructures/BST.h"
#include "../Repository/RepositoryBST.h"
#include "ServiceException.h"

class EventService {
    RepositoryBST<Event> &repository;
    unsigned int id = 0;
public:
    /**
     * Constructor
     * @param repository - BST repo
     */
    explicit EventService(RepositoryBST<Event> &repository);

    /**
     * @return - all the events
     */
    ABC<Event> read();

    /**
     * add an event
     * @param name - std::string
     * @param location - std::string
     * @param date - std::string
     */
    void add(std::string name, std::string location, std::string date);

    /**
     * Remove an event
     * @param id - unsigned int
     * @param name - std::string
     * @param location - std::string
     * @param date - std::string
     */
    void remove(unsigned int id, std::string name, std::string location, std::string date);

    /**
     * verify if an event exist
     * @param event - Event entity
     * @return true, if it exist, false, if not
     */
    bool exist(Event event);

    /**
     * Show events
     */
    void show();

    /**
     * Add a user to a event
     * @param id - unsigned in
     * @param name - std::string
     * @param location - std::string
     * @param date - std::string
     * @param username - std::string, the user added to the event
     */
    void addEvent(unsigned int id, std::string name, std::string location, std::string date, std::string username);

    /**
    * Remove a user from a event
     * @param id - unsigned in
     * @param name - std::string
     * @param location - std::string
     * @param date - std::string
     * @param username - std::string, the user removed from the event
     */
    void
    removeUserEvent(unsigned int id, std::string name, std::string location, std::string date, std::string username);

};


#endif //MAIN_CPP_EVENTSERVICE_H
