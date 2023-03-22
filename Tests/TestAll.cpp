#include "TestAll.h"

void TestAll::test() {
    //test domain
    TestUser::testAllUser();
    TestFriendship::testFriendship();
    TestMessage::testMessage();
    TestEvent::testEvent();

    //test data structures
    TestList::testAllList();
    TestBST::testBST();

    // test repo
    RepoCSVList::testAllRepoUser();
    TestRepoBST::testRepoBST();

    //test service
    TestUserService::testAllUserService();
    TestFriendshipService::testFriendship();
    TestMessageService::testMessageService();

}
