#pragma once
#include <ostream>
#include <string>

class Deck {
public:
    Deck() {}

    bool operator==(const Card& other) const {
        return color_ == other.color_ && rank_ == other.rank_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Card& c) {
        return out << c.color_ << " " << c.rank_;
    }

private:
};