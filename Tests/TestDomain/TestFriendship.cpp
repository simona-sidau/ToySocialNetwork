#include <cassert>
#include "TestFriendship.h"


void TestFriendship::testFriendship() {

    Friendship friendship(0, 12, 35);

    assert(friendship.getId() == 0);
    assert(friendship.getIdUser1() == 12);
    assert(friendship.getIdUser2() == 35);

    Friendship friendship2(friendship);

    assert(friendship2.getId() == 0);
    assert(friendship2.getIdUser1() == 12);
    assert(friendship2.getIdUser2() == 35);

    friendship.setId(18);
    friendship.setIdUser1(32);
    friendship.setIdUser2(9);

    assert(friendship.getId() == 18);
    assert(friendship.getIdUser1() == 32);
    assert(friendship.getIdUser2() == 9);

    Friendship friendship1(friendship2);

    assert(friendship!=friendship1);
    assert(friendship1 == friendship2);
    assert(friendship2 != friendship);

}

