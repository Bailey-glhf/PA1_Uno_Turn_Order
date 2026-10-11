#pragma once
#include <ostream>
#include <string>
#include "Card.h"
#include "Stack.h"

class Player {
public:
    Player(int id, const std::string& name)
        : id_(id), name_(name) {}

    bool operator==(const Player& other) const {
        return id_ == other.id_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Player& p) {
        return out << p.id_ << " " << p.name_;
    }

    void showHand() const {
        std::cout << name_ << "'s hand: ";
        hand_.print();
    }

    void addToHand(Card* card) {
        hand_.push(card);
    }

    //Not how Uno works but apparently out playable hand is now FILO
    void removeFromHand() {
        if (hand_.isEmpty()) {
            std::cout << name_ << " has no more cards to play!" << std::endl;
            return;
        }
        hand_.pop();
    }

private:
    int id_;
    std::string name_;
    Stack<Card> hand_;
};