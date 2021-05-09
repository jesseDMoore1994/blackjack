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
    this->_face = face;
    this->_suit = suit;    
    this->_is_hidden = false;
}

Card::Face Card::getFace() const {
    return this->_face;
}

Card::Suit Card::getSuit() const {
    return this->_suit;
}

bool Card::isHidden() const {
    return this->_is_hidden;
}

std::string Card::faceToString() {
    switch(this->getFace()) {
        case Ace:
            return "Ace";
        case Two:
            return "Two";
        case Three:
            return "Three";
        case Four:
            return "Four";
        case Five:
            return "Five";
        case Six:
            return "Six";
        case Seven:
            return "Seven";
        case Eight:
            return "Eight";
        case Nine:
            return "Nine";
        case Ten:
            return "Ten";
        case Jack:
            return "Jack";
        case Queen:
            return "Queen";
        case King:
            return "King";
        default:
            return "???";
    };
}

std::string Card::suitToString() {
    switch(this->getSuit()) {
        case Club:
            return "Clubs";
        case Diamond:
            return "Diamonds";
        case Heart:
            return "Hearts";
        case Spade:
            return "Spades";
        default:
            return "???";
    };
}

void Card::reveal() {
    this->_is_hidden = false;
}

void Card::hide() {
    this->_is_hidden = true;
}

bool Card::operator==(const Card& c) {
    return (
        this->getFace() == c.getFace() && this->getSuit() == c.getSuit()
    );
}

bool Card::operator!=(const Card& c) {
    return !(*this == c);
}

std::ostream& operator<<(std::ostream& out, Card card) {
    if(card.isHidden()) {
        out << "<this card cannot be seen>";
    }
    else {
        out << card.faceToString() << " of " << card.suitToString();
    }
    return out;
}
