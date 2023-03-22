#include <cassert>
#include "TestRepoBST.h"

void TestRepoBST::testRepoBST() {

    RepositoryBST<User> repo;

    User user(0, "test", "test", "test");
    User user1(1, "Mirel", "test", "test");
    User user2(2, "Marcel", "test", "test");

    repo.add(user);

    ABC<User> users = repo.getAll();

    assert(users.lSize() == 1);

    repo.add(user1);
    users = repo.getAll();

    assert(users.lSize() == 2);

    repo.update(user1, user2);

    assert(!repo.exist(user1));
    assert(repo.exist(user2));
    assert(users.lSize() == 2);

    repo.remove(user2);
    users = repo.getAll();
    assert(!repo.exist(user2));
    assert(users.lSize() == 1);


}
