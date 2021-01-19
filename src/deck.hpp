#ifndef DECK_HPP
#define DECK_HPP
#include "card.hpp"
#include <vector>
class Deck {
    private:
        std::vector<Card> cards; 
    public:
        Deck();
        int getSize();
        Card draw();
        void shuffle();
};
#endif
