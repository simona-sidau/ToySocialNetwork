#ifndef MAIN_CPP_EVENT_H
#define MAIN_CPP_EVENT_H


#include <string>
#include <ostream>
#include "../DataStructures/List.h"
#include "ValidatorException.h"
#include "User.h"

class Event {
private:
    unsigned int id;
    std::string name;
    std::string location;
    std::string date;
public:
    List<std::string> participants;

    friend std::ostream &operator<<(std::ostream &os, Event &event);

/**
 * Constructor
 */
    Event();

    /**
     * Construnctor with parameters
     * @param id - unsigned int
     * @param name - std::string
     * @param location - std::string
     * @param date - std::string
     * @param participants - List<std::string>, a list containing the usernames of the participants
     */
    Event(unsigned int id, std::string name, std::string location, std::string date, List<std::string> participants);

    /**
     * Copy constructor
     * @param rhs - Event entity
     */
    Event(const Event &rhs);

    //Setters & getters
    const List<std::string> &getParticipants() const;

    void setParticipants(const List<std::string> &participants);

    unsigned int getId() const;

    void setId(unsigned int id);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getLocation() const;

    void setLocation(const std::string &location);

    const std::string &getDate() const;

    void setDate(const std::string &date);

    //Operators

    bool operator==(const Event &rhs) const;

    bool operator!=(const Event &rhs) const;

    bool operator<(const Event &rhs) const;

    bool operator>(const Event &rhs) const;

    bool operator<=(const Event &rhs) const;

    bool operator>=(const Event &rhs) const;
};

class EventValidator {
public:
    static void validateName(std::string name);

    static void validateLocation(std::string location);

    static void validateDate(std::string date);


};


#endif //MAIN_CPP_EVENT_H
