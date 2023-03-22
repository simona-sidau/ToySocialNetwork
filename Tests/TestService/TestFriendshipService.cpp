#include "TestFriendshipService.h"

void TestFriendshipService::testFriendship() {
    RepositoryCSV<User> userRepo("testRepoUser.csv");
    RepositoryCSV<Friendship> friendshipRepo("testFriendship.csv");

    UserService userService(userRepo);
    FriendshipService friendshipService(userRepo, friendshipRepo);

    userService.add("Mihai", "mike", "m1");
    userService.add("Maria", "mimi", "m2");

    friendshipService.add(0, 1);

    assert(friendshipService.read().lSize() == 1);

    friendshipService.remove(userService.getUserById(0), userService.getUserById(1));

    assert(friendshipService.read().lSize() == 0);

    userService.remove(0);
    userService.remove(1);

}
