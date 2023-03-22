#ifndef PROIECTTOYSOCIALNETWORK_USERSERVICE_H
#define PROIECTTOYSOCIALNETWORK_USERSERVICE_H

#include "../DataStructures/List.h"
#include "../Domain/User.h"
#include "../Repository/RepositoryCSV.h"
#include "ServiceException.h"

class UserService {
private:
    RepositoryCSV<User> &userRepository;

    friend class FriendshipService;

    unsigned int id;

public:
    /**
     * Constructtor
     * @param repositoryCsv
     */
    explicit UserService(RepositoryCSV<User> &repositoryCsv);

    /**
     * Destructor
     */
    ~UserService() = default;

    /**
     * Get all users
     * @return
     */
    List<User> read();

    /**
     * Add an user
     * @param name
     * @param username
     * @param password
     */
    void add(std::string name, std::string username, std::string password);

    /**
     * Update an user
     * @param id
     * @param name
     * @param username
     * @param password
     */
    void update(unsigned int id, std::string name, std::string username, std::string password);

    /**
     * Remove a user
     * @param id
     */
    void remove(unsigned int id);

    /**
     * Get an user with a given id
     * @param id
     * @return
     */
    User getUserById(unsigned int id);

    /**
     * Get an user with a given username
     * @param username
     * @return
     */
    User getUserByUsername(std::string username);

    /**
     * Check if a username already exist
     * @param username
     */
    void checkUsername(std::string username);

    /**
     * Verify username and password
     * @param username
     * @param password
     * @return
     */
    bool logIn(std::string username, std::string password);


};


#endif //PROIECTTOYSOCIALNETWORK_USERSERVICE_H
