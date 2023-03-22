#include "MessageService.h"

MessageService::MessageService(RepositoryCSV<User> &userRepositoryCsv,
                               RepositoryCSV<Friendship> &friendshipRepositoryCsv,
                               RepositoryCSV<Message> &messageRepositoryCsv) :
        userRepository(userRepositoryCsv),
        friendshipRepository(friendshipRepositoryCsv),
        messageRepository(messageRepositoryCsv) {}

List<Message> MessageService::read() {
    return messageRepository.getAll();
}

void MessageService::add(unsigned int idUser1, unsigned int idUser2, std::string text) {

    if (messageRepository.noEntities() != 0)
        this->id = messageRepository.getEntityByIndex(messageRepository.noEntities() - 1).getId() + 1;
    else
        this->id = 0;

    MessageValidator::validateId(this->id);
    MessageValidator::validateIdUser1(idUser1);
    MessageValidator::validateIdUser2(idUser2);
    MessageValidator::validateText(text);

    Message msg(this->id, idUser1, idUser2, text);
    messageRepository.add(msg);
    this->id++;

}

void MessageService::remove(Message msg) {
    messageRepository.remove(msg);
}

bool MessageService::exist(unsigned int id) {
    List<Message> msg = this->read();
    for (int i = 0; i < msg.lSize(); i++)
        if (msg[i].getId() == id)
            return true;
    return false;
}

Message MessageService::getMessage(unsigned int id) {
    List<Message> msg = this->read();

    for (int i = 0; i < msg.lSize(); i++)
        if (msg[i].getId() == id)
            return msg[i];
}

