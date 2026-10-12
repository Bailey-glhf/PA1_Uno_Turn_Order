//Deck Class is unfinished and not connected to main. If fully implemented
//Deck would generate a basic UNO deck, shuffle and deal accordingly into
//player's hands

#pragma once
#include <ostream>
#include <string>

#include "Card.h"

class Deck {
public:
    Deck() {
        //rough outline of loops to create modified UNO deck
        //outer loop iterates from 0 to 3 for all 4 colors and pushes specialty cards reverse
        //and 0 that do not get as many duplicates as other cards
        //inner loop iterates from 1-9 since UNO has 2 of each of these numbers in each suit
        for (c = 0; c <= 3; ++c) {
            deck_.push(new Card("Color", "Reverse"));
            deck_.push(new Card("Color", "Reverse"));
            deck_.push(new Card("Color", "0"));
            for ( r = 1; r <= 9; ++r) {
                deck_.push(new Card("Color", "Number"));
                deck_.push(new Card("Color", "Number"));
            }
        }
    }

private:
    Stack<Card> deck_;
};