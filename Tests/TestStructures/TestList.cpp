#include <cassert>
#include "TestList.h"

void TestList::testAllList() {
    testCreate();
    testAdd();
    testRemove();

}

void TestList::testCreate() {
    List<User> users;

    assert(users.lSize()==0);


}

void TestList::testAdd() {

    List<User> users;
    User user(1, "i", "i", "1");
    users.add(user);

    assert(users.lSize() == 1);

    assert(users[0].getId() == 1);
    assert(users[0].getName() == "i");
    assert(users[0].getUsername() == "i");
    assert(users[0].getPassword() == "1");

}

void TestList::testRemove() {
    List<User> users;
    User user(1, "i", "i", "1");
    User user1(2, "e", "e", "1");

    assert(users.lSize() == 0);

    users.add(user);
    users.add(user1);

    assert(users.lSize() == 2);

    users.remove(user);

    assert(users.lSize() == 1);

    assert(users[0].getId() == 2);
    assert(users[0].getName() == "e");
    assert(users[0].getUsername() == "e");
    assert(users[0].getPassword() == "1");

}