#ifndef DECK_HPP
#define DECK_HPP
#include "card.hpp"
#include <vector>
class Deck {
    private:
        std::vector<Card> _cards;
    public:
        Deck();
        unsigned int getSize();
        Card draw();
        void populate();
        void shuffle();
        void reset();
};
#endif
