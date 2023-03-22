#include "EventService.h"

EventService::EventService(RepositoryBST<Event> &repository) : repository(repository) {}

ABC<Event> EventService::read() {
    return repository.getAll();
}

void EventService::add(std::string name, std::string location, std::string date) {
    EventValidator::validateName(name);
    EventValidator::validateLocation(location);
    EventValidator::validateDate(date);
    List<std::string> participants;

    Event event(this->id, name, location, date, participants);

    EventValidator::validateName(name);
    EventValidator::validateLocation(location);
    EventValidator::validateDate(date);

    repository.add(event);

    this->id++;
}

void EventService::remove(unsigned int id, std::string name, std::string location, std::string date) {
    List<std::string> participants;
    Event event(id, name, location, date, participants);
    if (this->exist(event))
        repository.remove(event);
    else
        throw ServiceException("This event does not exist!");
}

bool EventService::exist(Event event) {
    return repository.exist(event);
}

void EventService::show() {

    ABC<Event> events = repository.getAll();

    events.show();
}

void EventService::addEvent(unsigned int id, std::string name, std::string location, std::string date,
                            std::string username) {
    EventValidator::validateName(name);
    EventValidator::validateLocation(location);
    EventValidator::validateDate(date);
    List<std::string> participants;

    Event event(id, name, location, date, participants);

    if (repository.exist(event)) {
        int number = repository.getEntity(event).participants.lSize();
        for (int i = 0; i < number; i++)
            if (repository.getEntity(event).participants[i] == username)
                throw ServiceException("You already participate at this event!");
        repository.getEntity(event).participants.add(username);
    } else
        throw ServiceException("The event does not exist!");
}

void EventService::removeUserEvent(unsigned int id, std::string name, std::string location, std::string date,
                                   std::string username) {
    EventValidator::validateName(name);
    EventValidator::validateLocation(location);
    EventValidator::validateDate(date);
    List<std::string> participants;

    Event event(id, name, location, date, participants);

    if (repository.exist(event)) {
        int number = repository.getEntity(event).participants.lSize();
        for (int i = 0; i < number; i++) {
            if (repository.getEntity(event).participants[i] == username) {
                repository.getEntity(event).participants.remove(username);
                return;
            }
        }
        throw ServiceException("You do not participate at this event!");

    } else
        throw ServiceException("The event does not exist!");


}
