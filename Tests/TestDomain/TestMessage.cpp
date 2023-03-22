#include <cassert>
#include "TestMessage.h"

void TestMessage::testMessage() {

    Message message(1, 5, 6, "Salut");

    assert(message.getId() == 1);
    assert(message.getIdUser1() == 5);
    assert(message.getIdUser2() == 6);
    assert(message.getText() == "Salut");

    Message message1(message);

    assert(message1.getId() == 1);
    assert(message1.getIdUser1() == 5);
    assert(message1.getIdUser2() == 6);
    assert(message1.getText() == "Salut");

    Message message2(0, 1, 2, "Alo");

    message2.setId(10);
    message2.setIdUser1(3);
    message2.setIdUser2(17);
    message2.setText("Hi!");

    assert(message2.getId() == 10);
    assert(message2.getIdUser1() == 3);
    assert(message2.getIdUser2() == 17);
    assert(message2.getText() == "Hi!");

    assert(message == message1);
    assert(message != message2);
    assert(message1 != message2);



}
