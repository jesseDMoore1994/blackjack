#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "deck.hpp"
#include "card.hpp"
#include <vector>
#include <iterator>
#include <memory>
#include <string>
#include <sstream>
#include <iostream>

class Player {
    protected:
        std::string _name;
        std::shared_ptr<Deck> _deck;
        std::vector<Card> _hand;
        unsigned int _hidden_cards;
        std::string _status;
    public:
        Player(std::string, std::shared_ptr<Deck>, unsigned int hidden_cards = 1);
        virtual ~Player() = default;
        void reset();
        void hit();
        void hold();
        void peekHand();
        unsigned int getHandSize();
        unsigned int getHandValue();
        std::string getName();
        std::string getPlayerStatus();
        friend std::ostream& operator<<(std::ostream&, Player&);
        virtual void takeTurn() = 0;
};

class AiPlayer : public Player {
    public:
        AiPlayer(std::string s, std::shared_ptr<Deck> d, unsigned int hidden_cards = 1) :
            Player(s, d, hidden_cards) {};
        void takeTurn();
};

class HumanPlayer : public Player {
    public:
        HumanPlayer(std::string s, std::shared_ptr<Deck> d, unsigned int hidden_cards = 1) :
            Player(s, d, hidden_cards) {};
        void takeTurn();
};
#endif
