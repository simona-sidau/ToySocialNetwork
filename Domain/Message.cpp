#include <sstream>
#include "Message.h"

Message::Message(unsigned int id, unsigned int idUser1, unsigned int idUser2, std::string text) {
    this->id = id;
    this->idUser1 = idUser1;
    this->idUser2 = idUser2;
    this->text = text;
}

Message::Message(const Message &rhs) {
    this->id = rhs.id;
    this->idUser1 = rhs.idUser1;
    this->idUser2 = rhs.idUser2;
    this->text = rhs.text;
}

unsigned int Message::getId() const {
    return id;
}

void Message::setId(unsigned int id) {
    Message::id = id;
}

unsigned int Message::getIdUser1() const {
    return idUser1;
}

void Message::setIdUser1(unsigned int idUser1) {
    Message::idUser1 = idUser1;
}

unsigned int Message::getIdUser2() const {
    return idUser2;
}

void Message::setIdUser2(unsigned int idUser2) {
    Message::idUser2 = idUser2;
}

const std::string &Message::getText() const {
    return text;
}

void Message::setText(const std::string &text) {
    Message::text = text;
}

bool Message::operator==(const Message &rhs) const {
    return id == rhs.id &&
           idUser1 == rhs.idUser1 &&
           idUser2 == rhs.idUser2 &&
           text == rhs.text;
}

bool Message::operator!=(const Message &rhs) const {
    return !(rhs == *this);
}

bool Message::operator<(const Message &rhs) const {
    if (id < rhs.id)
        return true;
    if (rhs.id < id)
        return false;
    if (idUser1 < rhs.idUser1)
        return true;
    if (rhs.idUser1 < idUser1)
        return false;
    if (idUser2 < rhs.idUser2)
        return true;
    if (rhs.idUser2 < idUser2)
        return false;
    return text < rhs.text;
}

bool Message::operator>(const Message &rhs) const {
    return rhs < *this;
}

bool Message::operator<=(const Message &rhs) const {
    return !(rhs < *this);
}

bool Message::operator>=(const Message &rhs) const {
    return !(*this < rhs);
}

Message &Message::operator=(const Message &rhs) {
    this->id = rhs.id;
    this->idUser1 = rhs.idUser1;
    this->idUser2 = rhs.idUser2;
    this->text = rhs.text;
}

Message::Message(const std::string &stringMessage, char separator) {
    List<std::string> entities;
    std::stringstream ss(stringMessage);
    std::string element;

    while (getline(ss, element, separator)) {
        entities.add(element);
    }

    if (entities.lSize() == 4) {
        std::stringstream i(entities[0]);
        i >> this->id;
        std::stringstream j(entities[1]);
        j >> this->idUser1;
        std::stringstream k(entities[2]);
        k >> this->idUser2;
        this->text = entities[3];
    }

}

List<std::string> Message::split() {
    List<std::string> elements;

    elements.add(std::to_string(this->id));
    elements.add(std::to_string(this->idUser1));
    elements.add(std::to_string(this->idUser2));
    elements.add(this->text);

    return elements;
}

Message::Message() {
    this->id = 0;
    this->idUser1 = 0;
    this->idUser2 = 0;
    this->text = "";
}

void MessageValidator::validateId(int id) {
    if (id < 0)
        throw ValidatorException("ValidatorErr: InvalidId!");

}

void MessageValidator::validateIdUser1(int idUser1) {
    if (idUser1 < 0)
        throw ValidatorException("ValidatorErr: InvalidIdUser1!");

}

void MessageValidator::validateIdUser2(int idUser2) {
    if (idUser2 < 0)
        throw ValidatorException("ValidatorErr: InvalidUser2!");
}

void MessageValidator::validateText(std::string message) {
    if (message.empty())
        throw ValidatorException("ValidatorErr: InvalidMessage!");


    int space = 0;

    for (const auto &c: message)
        if (isspace(c))
            space++;

    if (space == message.size())
        throw ValidatorException("ValidatorErr: InvalidMessage!");

    /*for (const auto &c: message)
        if (isdigit(c) || (!isalnum(c) && !isspace(c)))
            throw ValidatorException("ValidatorErr: InvalidMessage!");*/
}
