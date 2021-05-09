#ifndef CARD_HPP
#define CARD_HPP
#include <vector>
#include <iostream>

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
        Card::Face _face;
        Card::Suit _suit;
        bool _is_hidden;

    public:
        Card(Card::Face, Card::Suit);
        Card::Face getFace() const;
        Card::Suit getSuit() const;
        bool isHidden() const;
        std::string faceToString();
        std::string suitToString();
        void reveal();
        void hide();
        bool operator==(const Card& c);
        bool operator!=(const Card& c);
        friend std::ostream& operator<<(std::ostream&, Card);
};
#endif
