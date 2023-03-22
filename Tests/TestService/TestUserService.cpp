#include <cassert>
#include "TestUserService.h"
#include "../../Repository/RepositoryCSV.h"
#include "../../Service/UserService.h"

void TestUserService::testAllUserService() {
    testAdd();
    testUpdate();
    testRemove();
    testGetUser();
    testLogIn();

}

void TestUserService::testAdd() {
    RepositoryCSV<User> repo("testRepoUser.csv");

    UserService service(repo);

    service.add("Mihai", "mike", "m1");

    List<User> users = service.read();

    assert(users.lSize() == 1);
    assert(users[0].getName() == "Mihai");
    assert(users[0].getUsername() == "mike");
    assert(users[0].getPassword() == "m1");

    service.remove(0);

}

void TestUserService::testUpdate() {
    RepositoryCSV<User> repo("testRepoUser.csv");

    UserService service(repo);

    service.add("Gigel", "geo", "g1");
    service.update(0, "Gigi", "geo", "g2");

    List<User> users = service.read();

    assert(users.lSize() == 1);
    assert(users[0].getId() == 0);
    assert(users[0].getName() == "Gigi");
    assert(users[0].getUsername() == "geo");
    assert(users[0].getPassword() == "g2");

    service.remove(0);

}

void TestUserService::testRemove() {
    RepositoryCSV<User> repo("testRepoUser.csv");

    UserService service(repo);

    service.add("Maria", "mimi", "m1");
    service.add("Elena", "eln", "a0");
    service.add("Mihaela", "mini", "m3");

    List<User> users = service.read();
    assert(users.lSize() == 3);

    service.remove(2);
    users = service.read();
    assert(users.lSize() == 2);

    service.remove(1);
    users = service.read();
    assert(users.lSize() == 1);

    service.remove(0);
    users = service.read();
    assert(users.lSize() == 0);

}

void TestUserService::testGetUser() {
    RepositoryCSV<User> repo("testRepoUser.csv");

    UserService service(repo);

    service.add("Ana", "nini", "1o");

    User test = service.getUserById(0);

    assert(test.getName() == "Ana");
    assert(test.getUsername() == "nini");
    assert(test.getPassword() == "1o");

    service.remove(0);

}

void TestUserService::testLogIn() {
    RepositoryCSV<User> repo("testRepoUser.csv");

    UserService service(repo);

    service.add("Mihai", "mike", "m1");

    assert(service.logIn("mike", "m1"));
    assert(!service.logIn("ionel", "inl"));

    service.remove(0);
}
