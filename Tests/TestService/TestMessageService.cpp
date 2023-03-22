#include "TestMessageService.h"

void TestMessageService::testMessageService() {

    RepositoryCSV<User> userRepo("testRepoUser.csv");
    RepositoryCSV<Friendship> friendshipRepo("testFriendship.csv");
    RepositoryCSV<Message> msgRepo("testMessageRepo.csv");

    UserService userService(userRepo);
    FriendshipService friendshipService(userRepo, friendshipRepo);
    MessageService messageService(userRepo, friendshipRepo, msgRepo);

    userService.add("Mihai", "mike", "m1");
    userService.add("Maria", "mimi", "m2");

    friendshipService.add(0, 1);

    assert(friendshipService.read().lSize() == 1);

    messageService.add(0, 1, "Salut!");

    assert(messageService.read().lSize() == 1);

    messageService.remove(Message(0, 0, 1, "Salut!"));

    assert(messageService.read().lSize() == 0);

    friendshipService.remove(userService.getUserById(0), userService.getUserById(1));

    userService.remove(0);
    userService.remove(1);

    //assert(friendshipService.read().lSize() == 7);

}
