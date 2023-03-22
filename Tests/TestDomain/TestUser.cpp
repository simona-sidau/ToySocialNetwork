#include <cassert>
#include "TestUser.h"

void TestUser::testAllUser() {
    testCreate();
    testSettersGetters();
    testOperators();

}

void TestUser::testCreate() {
    User user;
    assert(user.getName() == "");
    assert(user.getId() == 0);
    assert(user.getUsername() == "");

    User user1(1, "Ana", "anna", "123");
    assert(user1.getName() == "Ana");
    assert(user1.getId() == 1);
    assert(user1.getUsername() == "anna");
    assert(user1.getPassword() == "123");

    User user2(user1);
    assert(user2.getName() == "Ana");
    assert(user2.getId() == 1);
    assert(user2.getUsername() == "anna");
    assert(user2.getPassword() == "123");


}

void TestUser::testSettersGetters() {
    User user;

    assert(user.getName() == "");
    assert(user.getId() == 0);
    assert(user.getUsername() == "");
    assert(user.getPassword() == "");

    user.setId(1);
    assert(user.getId() == 1);

    user.setName("Emil");
    assert(user.getName() == "Emil");

    user.setUsername("emi12");
    assert(user.getUsername() == "emi12");

    user.setPassword("123");
    assert(user.getPassword() == "123");

}

void TestUser::testOperators() {

    User user(1, "Maria", "eu", "1");
    User user1(10, "Ion", "eu", "1");
    User user2(1, "Maria", "eu", "1");

    assert(user == user2);
    assert(user != user1);
    assert(user1 != user2);

}


