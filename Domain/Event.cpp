#include <sstream>
#include <cstring>
#include "Event.h"

Event::Event() {
    this->id = 0;
    this->name = "";
    this->location = "";
    this->date = "";
}

Event::Event(unsigned int id, std::string name, std::string location, std::string date,
             List<std::string> participants) {
    this->id = id;
    this->name = name;
    this->location = location;
    this->date = date;
    this->participants = participants;
}

Event::Event(const Event &rhs) {
    this->id = rhs.id;
    this->name = rhs.name;
    this->location = rhs.location;
    this->date = rhs.date;
    this->participants = rhs.participants;

}

unsigned int Event::getId() const {
    return id;
}

void Event::setId(unsigned int id) {
    Event::id = id;
}

const std::string &Event::getName() const {
    return name;
}

void Event::setName(const std::string &name) {
    Event::name = name;
}

const std::string &Event::getLocation() const {
    return location;
}

void Event::setLocation(const std::string &location) {
    Event::location = location;
}

const std::string &Event::getDate() const {
    return date;
}

void Event::setDate(const std::string &date) {
    Event::date = date;
}

bool Event::operator<(const Event &rhs) const {

    //return date < rhs.date;

    std::string dateToSplit = date;
    List<std::string> dateElements;
    std::stringstream ss(dateToSplit);
    std::string element;

    while (getline(ss, element, '.')) {
        dateElements.add(element);
    }

    std::string dateToSplitRhs = rhs.date;
    List<std::string> dateElementsRhs;
    std::stringstream ss1(dateToSplitRhs);

    while (getline(ss1, element, '.')) {
        dateElementsRhs.add(element);
    }

    if (dateElements[2] != dateElementsRhs[2])
        return dateElements[2] < dateElementsRhs[2];
    else if (dateElements[1] != dateElementsRhs[1])
        return dateElements[1] < dateElementsRhs[1];
    else
        return dateElements[0] < dateElementsRhs[0];

}

bool Event::operator>(const Event &rhs) const {
    return rhs < *this;
}

bool Event::operator<=(const Event &rhs) const {
    return !(rhs < *this);
}

bool Event::operator>=(const Event &rhs) const {
    return !(*this < rhs);
}

bool Event::operator==(const Event &rhs) const {
    return id == rhs.id &&
           name == rhs.name &&
           location == rhs.location &&
           date == rhs.date;
    //participants == rhs.participants;
}

bool Event::operator!=(const Event &rhs) const {
    return !(rhs == *this);
}

const List<std::string> &Event::getParticipants() const {
    return participants;
}

void Event::setParticipants(const List<std::string> &participants) {
    Event::participants = participants;
}

std::ostream &operator<<(std::ostream &os, Event &event) {
    os << "Id: " << event.id << ", Name: " << event.name << ", Location: " << event.location << ", Date: " << event.date
       << '\n';
    os << "Participants: ";
    int number = event.participants.lSize();
    if (number == 0)
        os << "no participants";
    for (int i = 0; i < number; i++)
        os << event.participants[i] << ", ";
    return os;
}

void EventValidator::validateName(std::string name) {
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

void EventValidator::validateLocation(std::string location) {
    if (location.empty())
        throw ValidatorException("ValidatorErr: InvalidName!");

    int space = 0;

    for (const auto &c: location)
        if (isspace(c))
            space++;
    if (space == location.size())
        throw ValidatorException("ValidatorErr: InvalidName!");
    for (const auto &c: location)
        if (isdigit(c) || (!isalnum(c) && !isspace(c)))
            throw ValidatorException("ValidatorErr: InvalidName!");

}

void EventValidator::validateDate(std::string date) {

    if (date.size() != 10)
        throw ValidatorException("ValidatorErr: InvalidDate!");

    char dateToValidate[12];

    strcpy(dateToValidate, date.c_str());


    for (int i = 0; i < 10; i++)
        if (i == 2 || i == 5) {
            if (dateToValidate[i] != '.')
                throw ValidatorException("ValidatorErr: InvalidDate!");
        } else if (!std::isalnum(dateToValidate[i]))
            throw ValidatorException("ValidatorErr: InvalidDate!");


}
