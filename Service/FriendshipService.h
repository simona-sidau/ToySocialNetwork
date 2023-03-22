#ifndef MAIN_CPP_FRIENDSHIPSERVICE_H
#define MAIN_CPP_FRIENDSHIPSERVICE_H

#include "../DataStructures/List.h"
#include "../Domain/Friendship.h"
#include "../Repository/RepositoryCSV.h"
#include "ServiceException.h"
#include "UserService.h"


class FriendshipService {
private:
    RepositoryCSV<User> &userRepository;
    RepositoryCSV<Friendship> &friendshipRepository;
    unsigned int id = 0;
public:
    /**
     * Constructor
     * @param userRepositoryCsv
     * @param friendshipRepositoryCsv
     */
    explicit FriendshipService(RepositoryCSV<User> &userRepositoryCsv,
                               RepositoryCSV<Friendship> &friendshipRepositoryCsv);

    /**
     * @return all friendships
     */
    List<Friendship> read();

    /**
     * Add a friendship
     * @param idUser1
     * @param idUser2
     */
    void add(unsigned int idUser1, unsigned int idUser2);

    /**
     * Remove a friendship
     * @param user1
     * @param user2
     */
    void remove(User user1, User user2);

    /**
     * Get a friendship with a given id
     * @param id
     * @return
     */
    Friendship getFriendship(unsigned int id);

    /**
     * Check if two users are friends
     * @param user1
     * @param user2
     * @return
     */
    bool checkFriendship(unsigned int user1, unsigned int user2);

    /**
     * Get all friends for an user
     * @param id
     * @return
     */
    List<std::string> getFriends(unsigned int id);

    /**
     * Remove all friends for a user
     * @param id
     */
    void multiRemove(unsigned int id);

    // List<User> getFriends(User user1);


};

#endif //MAIN_CPP_FRIENDSHIPSERVICE_H
