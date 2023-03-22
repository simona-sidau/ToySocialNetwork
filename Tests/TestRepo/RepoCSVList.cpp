#include <cassert>
#include "RepoCSVList.h"

void RepoCSVList::testAllRepoUser() {
    testAdd();
    testRemove();
    testUpdate();
    testGetUser();

}


void RepoCSVList::testAdd() {
    RepositoryCSV<User> repo("testRepoUser.csv");
    User user(0, "0", "0", "0");
    repo.add(user);
    List<User> users;
    users = repo.getAll();

    assert(users.lSize() == 1);
    assert(users[0].getId() == 0);
    assert(users[0].getName() == "0");
    assert(users[0].getUsername() == "0");
    assert(users[0].getPassword() == "0");

    repo.remove(user);

}

void RepoCSVList::testRemove() {
    RepositoryCSV<User> repo("testRepoUser.csv");
    User user(1, "1", "1", "1");
    repo.add(user);
    User user1(2, "2", "2", "2");
    repo.add(user1);
    User user2(3, "3", "3", "3");
    repo.add(user2);
    List<User> users;

    users = repo.getAll();
    assert(users.lSize() == 3);

    repo.remove(user);
    users = repo.getAll();
    assert(users.lSize() == 2);

    repo.remove(user1);
    users = repo.getAll();
    assert(users.lSize() == 1);

    repo.remove(user2);
    users = repo.getAll();
    assert(users.lSize() == 0);


}

void RepoCSVList::testUpdate() {
    RepositoryCSV<User> repo("testRepoUser.csv");
    User user(0, "0", "0", "0");
    repo.add(user);
    List<User> users;
    users = repo.getAll();

    assert(users.lSize() == 1);
    assert(users[0].getId() == 0);
    assert(users[0].getName() == "0");
    assert(users[0].getUsername() == "0");
    assert(users[0].getPassword() == "0");

    User user1(0, "1", "1", "1");

    repo.update(user1);
    users = repo.getAll();

    assert(users.lSize() == 1);
    assert(users[0].getId() == 0);
    assert(users[0].getName() == "1");
    assert(users[0].getUsername() == "1");
    assert(users[0].getPassword() == "1");

    repo.remove(user1);


}

void RepoCSVList::testGetUser() {
    RepositoryCSV<User> repo("testRepoUser.csv");
    User user(0, "0", "0", "0");
    repo.add(user);

    User test = repo.getEntity(0);

    assert(test.getName() == "0");
    assert(test.getUsername() == "0");
    assert(test.getPassword() == "0");

    repo.remove(user);


}

