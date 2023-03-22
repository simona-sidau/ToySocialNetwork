#include "Network.h"

Network::Network(UserService &userService, FriendshipService &friendshipService, MessageService &messageService,
                 EventService &eventService) :
        userService(userService), friendshipService(friendshipService), messageService(messageService),
        eventService(eventService) {}

void Network::addFriend(unsigned int idUser1, std::string usernameUser2) {

    unsigned int idUser2 = userService.getUserByUsername(usernameUser2).getId();
    UserValidator::validateId(idUser2);
    friendshipService.add(idUser1, idUser2);

}

void Network::removeFriend(unsigned int idUser1, std::string usernameUser2) {
    unsigned int idUser2 = userService.getUserByUsername(usernameUser2).getId();
    UserValidator::validateId(idUser2);
    User user1 = userService.getUserById(idUser1);
    User user2 = userService.getUserById(idUser2);
    friendshipService.remove(user1, user2);

}

void Network::getMessages(unsigned int idUser1, std::string usernameUser2) {
    if (this->checkFriendship(idUser1, usernameUser2)) {
        unsigned int idUser2 = userService.getUserByUsername(usernameUser2).getId();
        UserValidator::validateId(idUser2);
        List<Message> msg = messageService.read();

        for (int i = 0; i < msg.lSize(); i++) {
            if (idUser1 == msg[i].getIdUser1() && idUser2 == msg[i].getIdUser2() ||
                idUser1 == msg[i].getIdUser2() && idUser2 == msg[i].getIdUser1())
                std::cout << "Id: " << msg[i].getId() << ", From: "
                          << userService.getUserById(msg[i].getIdUser1()).getUsername()
                          << ", To: " <<
                          userService.getUserById(msg[i].getIdUser2()).getUsername() << ", Message: " <<
                          msg[i].getText() << '\n';
        }
    } else
        throw ServiceException("You are not friend with this user! ");
}

void Network::sendMessage(unsigned int idUser1, std::string usernameUser2, std::string text) {
    unsigned int idUser2 = userService.getUserByUsername(usernameUser2).getId();
    UserValidator::validateId(idUser2);
    MessageValidator::validateText(text);

    messageService.add(idUser1, idUser2, text);

}

bool Network::checkFriendship(unsigned int idUser1, std::string usernameUser2) {
    unsigned int idUser2 = userService.getUserByUsername(usernameUser2).getId();
    UserValidator::validateId(idUser2);

    return friendshipService.checkFriendship(idUser1, idUser2);
}

void Network::deleteMessage(unsigned int idMessage, unsigned int idUser) {

    MessageValidator::validateId(idMessage);

    if (!messageService.exist(idMessage))
        throw ServiceException("The message does not exist!");

    Message msg = messageService.getMessage(idMessage);

    if (msg.getIdUser1() != idUser)
        throw ServiceException("You can delete only your message!");

    messageService.remove(msg);

}
