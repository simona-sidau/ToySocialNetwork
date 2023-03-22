#include <cassert>
#include "TestEvent.h"

void TestEvent::testEvent() {

    List<std::string> participants;
    participants.add("1");
    participants.add("2");

    Event event(1, "Party", "Cluj", "12.02.2020", participants);

    assert(event.getId() == 1);
    assert(event.getName() == "Party");
    assert(event.getLocation() == "Cluj");
    assert(event.getDate() == "12.02.2020");

    Event event0(3, "K", "Bucuresti", "13.04.2022", participants);
    Event event1(2, "Sport", "Oradea", "15.07.2020", participants);
    Event event2(4, "Dansuri", "Sibiu", "10.02.2020", participants);


    assert(event < event0);
    assert(event < event1);
    assert(event > event2);

}
