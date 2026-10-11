#include <iostream>
#include "List.h"
#include "Player.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene goes below ----

    std::cout << "== !!!LETS PLAY UNO!!! ==" << std::endl;
    std::unique_ptr<List<Player>> tableOne = makeList<Player>();
    std::unique_ptr<List<Player>> tableTwo = makeList<Player>();

    tableOne->addFront(new Player(1,"Emily"));
    tableOne->addFront(new Player(2, "Michael"));
    tableOne->addFront(new Player(3, "Christopher"));
    tableOne->addFront(new Player(4, "Jackie"));
    tableTwo->addFront(new Player(5,"Eric"));
    tableTwo->addFront(new Player(6, "Michelle"));
    tableTwo->addFront(new Player(7, "Caity"));

    std::cout << "Table 1 players in order are: " << std::endl;
    tableOne->print();

    std::cout << std::endl << "Emily plays a reverse card!" << std::endl;
    tableOne->reverse();
    std::cout << "New order: ";
    tableOne->print();

    std::cout << std::endl << "Looks like Emily got UNO first and ran out of cards, everyone else battles for 2nd place." << std::endl;
    tableOne->deleteAnywhere(0);
    tableOne->print();

    std::cout << std::endl << "Looks like another table is trying to join." << std::endl;

    std::cout << std::endl << "Table 2 players in order are: " << std::endl;
    tableTwo->print();

    tableOne->concat(tableTwo.get());
    std::cout << std::endl << "Now that Table 2 has joined Table 1 lets see the lineup: " << std::endl;
    tableOne->print();

    std::cout << std::endl << "Michael plays a reverse card!" << std::endl;
    tableOne->reverse();
    std::cout << "New order: ";
    tableOne->print();

    std::cout << std::endl << "Looks like another player wants to join the game, Maya pulls up a chair." << std::endl;
    tableOne->addAnywhere(4, new Player (8, "Maya"));
    tableOne->print();

    return 0;
}