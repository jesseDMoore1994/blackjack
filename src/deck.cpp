#include "deck.hpp"
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>

Deck::Deck() {
    this->populate();
}

unsigned int Deck::getSize() {
    return this->_cards.size();
}

Card Deck::draw() {
    Card top_card = this->_cards.back();
    this->_cards.pop_back();
    return top_card;
}

void Deck::populate() {
    std::vector<Card::Face>::iterator face;
    std::vector<Card::Suit>::iterator suit;

    for(face = Card::all_faces.begin(); face < Card::all_faces.end(); face++) {
        for(suit = Card::all_suits.begin(); suit < Card::all_suits.end(); suit++) {
            this->_cards.push_back(Card(*face, *suit));
        }
    }
}

void Deck::shuffle() {
    std::random_device rd;
    auto rng = std::default_random_engine {rd()};
    std::shuffle(this->_cards.begin(), this->_cards.end(), rng);
}

void Deck::reset() {
    this->_cards.clear();
    this->populate();
}
