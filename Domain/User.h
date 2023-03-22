#ifndef PROIECTTOYSOCIALNETWORK_USER_H
#define PROIECTTOYSOCIALNETWORK_USER_H

#include <string>
#include <ostream>
#include "../DataStructures/List.h"
#include "ValidatorException.h"

class User {
private:
    unsigned int id{};
    std::string name;
    std::string username;
    std::string password;
public:
    /**
     * Constructor
     */
    User();

    /**
     * Constructor with parameters
     * @param id - unsigned int
     * @param name - std::string
     * @param username - std::string
     * @param password - std::string
     */
    User(unsigned int id, const std::string &name, const std::string &username, const std::string &password);

    /**
     * Copy constructor
     * @param rhs - User entity
     */
    User(const User &rhs);

    /**
     * String constructor
     * @param stringUser - string to converts
     * @param separator - separator between entity's elements
     */
    User(const std::string &stringUser, char separator);

    /**
     * Destructor
     */
    ~User() = default;

    //Setters & getters

    void setId(unsigned int id);

    const std::string &getPassword() const;

    void setPassword(const std::string &password);

    void setName(const std::string &name);

    void setUsername(const std::string &username);

    unsigned int getId() const;

    const std::string &getName() const;

    const std::string &getUsername() const;

    /**
     * @return - a list containg user's elements
     */

    List<std::string> split();

    //Operators

    bool operator==(const User &rhs) const;

    bool operator!=(const User &rhs) const;

    bool operator<(const User &rhs) const;

    bool operator>(const User &rhs) const;

    bool operator<=(const User &rhs) const;

    bool operator>=(const User &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const User &user);

    User &operator=(const User &rhs);

};

class UserValidator {
public:

    static void validateId(int id);

    static void validateName(std::string name);

    static void validateUsername(std::string username);

    static void validatePassword(std::string password);

};

#endif //PROIECTTOYSOCIALNETWORK_USER_H
