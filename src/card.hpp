#ifndef CARD_HPP
#define CARD_HPP
#include <vector>

class Card {
    public:
        enum Face {
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
            King
        };
        static std::vector<Face> all_faces;
        enum Suit {
            Club,
            Diamond,
            Heart,
            Spade
        };
        static std::vector<Suit> all_suits;

    private:
        Card::Face face;
        Card::Suit suit;


    public:
        Card(Card::Face, Card::Suit);
        Card::Face getFace();
        Card::Suit getSuit();
        bool operator==(const Card& c);
        bool operator!=(const Card& c);
};
#endif
