#include "Tests/TestAll.h"
#include "Repository/RepositoryCSV.h"
#include "Repository/RepositoryBST.h"
#include "Service/Network.h"
#include "UserInterface/Console.h"

int main() {
    TestAll::test();

    RepositoryCSV<User> userRepo("users.csv");
    RepositoryCSV<Friendship> friendshipRepo("friendships.csv");
    RepositoryCSV<Message> messageRepo("messages.csv");
    RepositoryBST<Event> eventRepo;

    UserService userService(userRepo);
    FriendshipService friendshipService(userRepo, friendshipRepo);
    MessageService messageService(userRepo, friendshipRepo, messageRepo);
    EventService eventService(eventRepo);
    Network network(userService, friendshipService, messageService, eventService);

    Console console(network);

    console.startAplication();

    return 0;
}
