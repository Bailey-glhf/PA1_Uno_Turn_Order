/*******************************************************************************
* CS210-16 – Fall 2026
* Project name: PA1_Uno_Turn_Order
* Developer: Emily Bailey
* 10/11/26
* Description: Data structures project using ArrayList and LinkedList implemen-
* tations to utilize addAnywhere, deleteAnywhere, reverse, and concat functions
* with in place memory management. Main class tests functions with hard coded Uno
* simulation.
******************************************************************************/
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
    //creation of 2 seperate lists of Player objects
    std::unique_ptr<List<Player>> tableOne = makeList<Player>();

    //creates players
    Player* p1 = new Player (1,"Emily");
    Player* p2 = new Player (2, "Michael");
    Player* p3 = new Player (3, "Christopher");
    Player* p4 = new Player (4, "Jackie");

    //adds players to list
    //List1
    tableOne->addFront(p1);
    tableOne->addFront(p2);
    tableOne->addFront(p3);
    tableOne->addFront(p4);



    //prints table 1 players
    std::cout << "Table 1 players in order are: " << std::endl;
    tableOne->print();

    //completes addAnywhere function and prints
    std::cout << std::endl << "Looks like another player wants to join the game, Maya pulls up a chair." << std::endl;
    tableOne->addAnywhere(2, new Player (5, "Maya"));
    tableOne->print();

    //completes reverse function and prints
    std::cout << std::endl << "Emily plays a reverse card!" << std::endl;
    tableOne->reverse();
    std::cout << "New order: ";
    tableOne->print();

    //completes deleteAnywhere function and prints
    std::cout << std::endl << "Looks like Emily got UNO first and ran out of cards, everyone else battles for 2nd place." << std::endl;
    tableOne->deleteAnywhere(0);
    std::cout << "New order: ";
    tableOne->print();

    std::unique_ptr<List<Player>> tableTwo = makeList<Player>();
    //adds players to list
    //List2
    tableTwo->addFront(new Player(6,"Eric"));
    tableTwo->addFront(new Player(7, "Michelle"));
    tableTwo->addFront(new Player(8, "Caity"));

    std::cout << std::endl << "Looks like another table is trying to join." << std::endl;
    std::cout << std::endl << "Table 2 players in order are: " << std::endl;
    tableTwo->print();

    //completes concat function and prints
    tableOne->concat(tableTwo.get());
    std::cout << std::endl << "Now that Table 2 has joined Table 1 lets see the lineup." << std::endl;
    std::cout << "New order: ";
    tableOne->print();

    //completes another reverse function and prints
    std::cout << std::endl << "Michael plays a reverse card!" << std::endl;
    tableOne->reverse();
    std::cout << "New order: ";
    tableOne->print();

    return 0;
} //end of main