#include <sstream>
#include "Friendship.h"

//Friendship::Friendship = default();

Friendship::Friendship(unsigned int id, unsigned int id1, unsigned int id2) {
    this->id = id;
    this->idUser1 = id1;
    this->idUser2 = id2;
}

Friendship::Friendship(const Friendship &rhs) {
    this->id = rhs.id;
    this->idUser1 = rhs.idUser1;
    this->idUser2 = rhs.idUser2;
}

unsigned int Friendship::getId() const {
    return this->id;
}

void Friendship::setId(unsigned int id) {
    Friendship::id = id;
}

unsigned int Friendship::getIdUser1() const {
    return idUser1;
}

void Friendship::setIdUser1(unsigned int idUser1) {
    Friendship::idUser1 = idUser1;
}

unsigned int Friendship::getIdUser2() const {
    return idUser2;
}

void Friendship::setIdUser2(unsigned int idUser2) {
    Friendship::idUser2 = idUser2;
}

bool Friendship::operator==(const Friendship &rhs) const {
    return id == rhs.id &&
           idUser1 == rhs.idUser1 &&
           idUser2 == rhs.idUser2;
}

bool Friendship::operator!=(const Friendship &rhs) const {
    return !(rhs == *this);
}

bool Friendship::operator<(const Friendship &rhs) const {
    if (id < rhs.id)
        return true;
    if (rhs.id < id)
        return false;
    if (idUser1 < rhs.idUser1)
        return true;
    if (rhs.idUser1 < idUser1)
        return false;
    return idUser2 < rhs.idUser2;
}

bool Friendship::operator>(const Friendship &rhs) const {
    return rhs < *this;
}

bool Friendship::operator<=(const Friendship &rhs) const {
    return !(rhs < *this);
}

bool Friendship::operator>=(const Friendship &rhs) const {
    return !(*this < rhs);
}

Friendship &Friendship::operator=(const Friendship &rhs) {
    this->id = rhs.id;
    this->idUser1 = rhs.idUser1;
    this->idUser2 = rhs.idUser2;
}

Friendship::Friendship() {
    this->id = 0;
    this->idUser1 = 0;
    this->idUser2 = 0;
}

List<std::string> Friendship::split() {
    List<std::string> elements;

    elements.add(std::to_string(this->id));
    elements.add(std::to_string(this->idUser1));
    elements.add(std::to_string(this->idUser2));

    return elements;
}

Friendship::Friendship(const std::string &stringFriendship, char separator) {
    List<std::string> entities;
    std::stringstream ss(stringFriendship);
    std::string element;

    while (getline(ss, element, separator)) {
        entities.add(element);
    }

    if (entities.lSize() == 3) {
        std::stringstream i(entities[0]);
        i >> this->id;
        std::stringstream j(entities[1]);
        j >> this->idUser1;
        std::stringstream k(entities[2]);
        k >> this->idUser2;


    }
}

void FriendshipValidator::validateId(int id) {
    if (id < 0)
        throw ValidatorException("ValidatorErr: InvalidId!");
}

void FriendshipValidator::validateIdUser1(int idUser1) {
    if (idUser1 < 0)
        throw ValidatorException("ValidatorErr: InvalidIdUser1!");
}

void FriendshipValidator::validateIdUser2(int idUser2) {
    if (idUser2 < 0)
        throw ValidatorException("ValidatorErr: InvalidUser2!");
}
