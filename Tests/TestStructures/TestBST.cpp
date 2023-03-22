#include "TestBST.h"

void TestBST::testBST() {
    User user(6, "Ion", "ion", "0");

    ABCNode<User> node(user);
    ABC<User> us;

    User user1(5, "Gigi", "gg2", "0");
    User user2(3, "Marcela", "mrc", "0");
    User user3(7, "Ela", "ilm", "0");
    User user4(1, "Ina", "inna", "0");
    User user5(4, "Mihai", "mike", "0");

    us.add(user1);
    us.add(user2);
    us.add(user3);
    us.add(user4);
    us.add(user5);


    assert(us.lSize() == 5);

    us.remove(user3);

    assert(us.lSize() == 4);

    us.remove(user2);

    assert(us.lSize() == 3);

    assert(us.search(user1));
    assert(!us.search(user2));
    assert(!us.search(user3));


}
