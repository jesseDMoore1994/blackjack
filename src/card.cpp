#include "Card.hpp"

std::vector<Card::Face> Card::all_faces{
      Ace,
      Two,
      Three,
      Four,
      Five,
      Six,
      Seven,
      Eight,
      Nine,
      Ten,
      Jack,
      Queen,
      King,
};

std::vector<Card::Suit> Card::all_suits{
      Club,
      Diamond,
      Heart,
      Spade
};

Card::Card(Card::Face face, Card::Suit suit) {
    this->face = face;
    this->suit = suit;    
}

Card::Face Card::getFace() {
    return this->face;
}

Card::Suit Card::getSuit() {
    return this->suit;
}

bool Card::operator==(const Card& c) {
    return (
        this->face == c.face && this->suit == c.suit
    );
}

bool Card::operator!=(const Card& c) {
    return !(*this == c);
}
