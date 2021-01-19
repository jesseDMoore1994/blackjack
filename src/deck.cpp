#include "deck.hpp"
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>

Deck::Deck() {
    std::vector<Card::Face>::iterator face;
    std::vector<Card::Suit>::iterator suit;

    for(face = Card::all_faces.begin(); face < Card::all_faces.end(); face++) {
        for(suit = Card::all_suits.begin(); suit < Card::all_suits.end(); suit++) {
            this->cards.push_back(Card(*face, *suit));
        } 
    }
}

int Deck::getSize() {
    return this->cards.size();
}

Card Deck::draw() {
    Card top_card = this->cards.back();
    this->cards.pop_back();
    return top_card;
}

void Deck::shuffle() {
    std::random_device rd;
    auto rng = std::default_random_engine {rd()};
    std::shuffle(this->cards.begin(), this->cards.end(), rng);
}
