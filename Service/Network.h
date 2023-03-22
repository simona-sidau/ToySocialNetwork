#ifndef MAIN_CPP_NETWORK_H
#define MAIN_CPP_NETWORK_H

#include "UserService.h"
#include "MessageService.h"
#include "FriendshipService.h"
#include "EventService.h"


class Network {
protected:
    UserService &userService;
    FriendshipService &friendshipService;
    MessageService &messageService;
    EventService &eventService;

    friend class Console;

    friend class Admin;

    friend class UserPanel;

public:
    /**
     * Constructor
     * @param userService
     * @param friendshipService
     * @param messageService
     * @param eventService
     */
    Network(UserService &userService, FriendshipService &friendshipService, MessageService &messageService,
            EventService &eventService);

    ~Network() = default;

    /**
     * Create a Friendship between two users
     * @param idUser1
     * @param usernameUser2
     */
    void addFriend(unsigned int idUser1, std::string usernameUser2);

    /**
     * Delete a Friendship from two users
     * @param idUser1
     * @param usernameUser2
     */
    void removeFriend(unsigned int idUser1, std::string usernameUser2);

    /**
     * Check if two users are friends
     * @param idUser1
     * @param usernameUser2
     * @return
     */
    bool checkFriendship(unsigned int idUser1, std::string usernameUser2);

    /**
     * Get a message
     * @param idUser1
     * @param usernameUser2
     */
    void getMessages(unsigned int idUser1, std::string usernameUser2);

    /**
     * Send a message from user1 to user2
     * @param idUser1
     * @param usernameUser2
     * @param text
     */
    void sendMessage(unsigned int idUser1, std::string usernameUser2, std::string text);

    /**
     * Delete a message
     * @param idMessage
     * @param idUser
     */
    void deleteMessage(unsigned int idMessage, unsigned int idUser);


};


#endif //MAIN_CPP_NETWORK_H
