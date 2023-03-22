#ifndef MAIN_CPP_MESSAGESERVICE_H
#define MAIN_CPP_MESSAGESERVICE_H

#include "../DataStructures/List.h"
#include "../Domain/Friendship.h"
#include "../Domain/Message.h"
#include "../Repository/RepositoryCSV.h"
#include "ServiceException.h"
#include "UserService.h"

class MessageService {
private:
    RepositoryCSV<Friendship> &friendshipRepository;
    RepositoryCSV<User> &userRepository;
    RepositoryCSV<Message> &messageRepository;
    unsigned int id = 0;
public:
    /**
     * Constructor
     * @param userRepositoryCsv
     * @param friendshipRepositoryCsv
     * @param messageRepositoryCsv
     */
    explicit MessageService(RepositoryCSV<User> &userRepositoryCsv, RepositoryCSV<Friendship> &friendshipRepositoryCsv,
                            RepositoryCSV<Message> &messageRepositoryCsv);

    /**
     * Get all messages
     * @return
     */
    List<Message> read();

    /**
     * Add a message
     * @param idUser1
     * @param idUser2
     * @param text
     */
    void add(unsigned int idUser1, unsigned int idUser2, std::string text);

    /**
     * Remove a message
     * @param msg
     */
    void remove(Message msg);

    /**
     * Verify if a message exist
     * @param id
     * @return
     */
    bool exist(unsigned int id);

    /**
     * Get a message with a given id
     * @param id
     * @return
     */
    Message getMessage(unsigned int id);
};


#endif //MAIN_CPP_MESSAGESERVICE_H
