#ifndef PROIECTTOYSOCIALNETWORK_MESSAGE_H
#define PROIECTTOYSOCIALNETWORK_MESSAGE_H

#include <string>
#include "ValidatorException.h"
#include <ostream>
#include "../DataStructures/List.h"

class Message {
private:
    unsigned int id;
    unsigned int idUser1;
    unsigned int idUser2;
    std::string text;

public:
    /**
     * Constructor
     */
    Message();

    /**
     * Constructor
     * @param id - unsigned int id
     * @param idUser1 - unsigned int id
     * @param idUser2 - unsigned int id
     * @param text - std::string, the actual message
     */
    Message(unsigned int id, unsigned int idUser1, unsigned int idUser2, std::string text);

    /**
     * Copy constructor
     * @param rhs - Message entity
     */
    Message(const Message &rhs);

    /**
     * String constructor
     * @param stringMessage - string to convert
     * @param separator - separator between entity's elements
     */
    Message(const std::string &stringMessage, char separator);

    //Setters & getters

    unsigned int getId() const;

    void setId(unsigned int id);

    unsigned int getIdUser1() const;

    void setIdUser1(unsigned int idUser1);

    unsigned int getIdUser2() const;

    void setIdUser2(unsigned int idUser2);

    const std::string &getText() const;

    void setText(const std::string &text);

    /*
     * @return - a list containing entity's elements
     */
    List<std::string> split();

    //Operators

    bool operator==(const Message &rhs) const;

    bool operator!=(const Message &rhs) const;

    bool operator<(const Message &rhs) const;

    bool operator>(const Message &rhs) const;

    bool operator<=(const Message &rhs) const;

    bool operator>=(const Message &rhs) const;

    Message &operator=(const Message &rhs);

};

class MessageValidator {
public:
    static void validateId(int id);

    static void validateIdUser1(int idUser1);

    static void validateIdUser2(int idUser2);

    static void validateText(std::string message);
};

#endif //PROIECTTOYSOCIALNETWORK_MESSAGE_H
