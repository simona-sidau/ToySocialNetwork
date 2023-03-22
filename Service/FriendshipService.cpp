#include "FriendshipService.h"

FriendshipService::FriendshipService(RepositoryCSV<User> &userRepositoryCsv,
                                     RepositoryCSV<Friendship> &friendshipRepositoryCsv) :
        userRepository(userRepositoryCsv), friendshipRepository(friendshipRepositoryCsv) {}

void FriendshipService::add(unsigned int idUser1, unsigned int idUser2) {

    if (friendshipRepository.noEntities() != 0)
        this->id = friendshipRepository.getEntityByIndex(friendshipRepository.noEntities() - 1).getId() + 1;
    else
        this->id = 0;

    FriendshipValidator::validateId(this->id);
    FriendshipValidator::validateIdUser1(idUser1);
    FriendshipValidator::validateIdUser2(idUser2);

    if (idUser1 == idUser2)
        throw ServiceException("ServiceErr: You cannot add yourself as a friend!");
    if (!userRepository.exist(userRepository.getEntity(idUser1)))
        throw ServiceException("First user does not exist!");
    if (!userRepository.exist(userRepository.getEntity(idUser2)))
        throw ServiceException("This user does not exist!");

    if (!this->checkFriendship(idUser1, idUser2)) {

        Friendship fr(this->id, idUser1, idUser2);

        friendshipRepository.add(fr);

        this->id++;
    } else
        throw ServiceException("ServiceErr: This friendship already exist!");

}

void FriendshipService::remove(User user1, User user2) {

    List<Friendship> friendships;
    friendships = read();


    for (int i = 0; i < friendships.lSize(); i++)
        if (userRepository.getEntity(friendships[i].getIdUser1()) == user1 ||
            userRepository.getEntity(friendships[i].getIdUser1()) == user2)
            if (userRepository.getEntity(friendships[i].getIdUser2()) == user2 ||
                userRepository.getEntity(friendships[i].getIdUser2()) == user1) {
                friendshipRepository.remove(friendships[i]);
                return;
            }
    throw RepositoryException("The friendship does not exist!");

}

Friendship FriendshipService::getFriendship(unsigned int id) {
    return friendshipRepository.getEntity(id);
}

List<Friendship> FriendshipService::read() {
    return friendshipRepository.getAll();
}

bool FriendshipService::checkFriendship(unsigned int user1, unsigned int user2) {
    List<Friendship> fr = this->read();

    for (int i = 0; i < fr.lSize(); i++) {
        if (fr[i].getIdUser1() == user1 and fr[i].getIdUser2() == user2)
            return true;
        if (fr[i].getIdUser1() == user2 and fr[i].getIdUser2() == user1)
            return true;
    }
    return false;
}

List<std::string> FriendshipService::getFriends(unsigned int id) {
    List<std::string> friends;
    List<Friendship> fr = this->read();

    for (int i = 0; i < fr.lSize(); i++) {
        if (fr[i].getIdUser1() == id)
            friends.add(userRepository.getEntity(fr[i].getIdUser2()).getUsername());
        if (fr[i].getIdUser2() == id)
            friends.add(userRepository.getEntity(fr[i].getIdUser1()).getUsername());
    }

    return friends;
}

void FriendshipService::multiRemove(unsigned int id) {
    //if(userRepository.exist(userRepository.getEntity(id))){
    List<Friendship> fr = this->read();
    for (int i = 0; i < fr.lSize(); i++)
        if (fr[i].getIdUser1() == id || fr[i].getIdUser2() == id) {
            friendshipRepository.remove(fr[i]);
            i--;
            fr = this->read();
        }

    //}
}

