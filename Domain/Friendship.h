
#ifndef PROIECTTOYSOCIALNETWORK_FRIENDSHIP_H
#define PROIECTTOYSOCIALNETWORK_FRIENDSHIP_H

#include <string>
#include <ostream>
#include "ValidatorException.h"
#include"../DataStructures/List.h"


class Friendship {
private:
    unsigned int id;
    unsigned int idUser1;
    unsigned int idUser2;
public:
    /**
     * Constructor
     */
    Friendship();

    /**
     * Constructor with parameters
     * @param id - unsigned int
     * @param idUser1 - unsigned int
     * @param idUser2 - unsigned int
     */
    Friendship(unsigned int id, unsigned int idUser1, unsigned int idUser2);

    /**
     * Copy constructor
     * @param rhs - Friendship entity
     */
    Friendship(const Friendship &rhs);

/**
 * String constructor
 * @param stringFriendship - string to convert
 * @param separator - separator between Friendship elements
 */
    Friendship(const std::string &stringFriendship, char separator);

/**
 * Destructor
 */
    ~Friendship() = default;

    //Setters & getters

    unsigned int getId() const;

    void setId(unsigned int id);

    unsigned int getIdUser1() const;

    void setIdUser1(unsigned int idUser1);

    unsigned int getIdUser2() const;

    void setIdUser2(unsigned int idUser2);

    //Operators

    bool operator==(const Friendship &rhs) const;

    bool operator!=(const Friendship &rhs) const;

    bool operator<(const Friendship &rhs) const;

    bool operator>(const Friendship &rhs) const;

    bool operator<=(const Friendship &rhs) const;

    bool operator>=(const Friendship &rhs) const;

    Friendship &operator=(const Friendship &rhs);

    /**
     * @return a list containg the elements of entity
     */
    List<std::string> split();

};

class FriendshipValidator {
public:
    static void validateId(int id);

    static void validateIdUser1(int idUser1);

    static void validateIdUser2(int idUser2);
};

#endif //PROIECTTOYSOCIALNETWORK_FRIENDSHIP_H
