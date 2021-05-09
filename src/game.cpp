#include "game.hpp"

Game::Game(std::vector<std::shared_ptr<Player>> players) {
    this->_players = players;
}

unsigned int Game::getPlayerCount() {
    return this->_players.size();
}

void Game::run() {
    auto _initialize = [&]() {
        for(auto player = this->_players.begin(); player < this->_players.end(); player++) {
            (*player)->hit();
            (*player)->hit();
        }
    };

    auto _play_round = [&]() {
        std::cout << "Current round status:\n";
        for(auto player = this->_players.begin(); player < this->_players.end(); player++) {
            std::cout << **player;
        }
        for(auto player = this->_players.begin(); player < this->_players.end(); player++) {
            if((*player)->getHandSize() == 5) {
                (*player)->hold();
            }
            if((*player)->getPlayerStatus() == "Active") {
                (*player)->takeTurn();
            }
        }
    };

    auto _is_game_over = [&]() {
        bool at_least_one_active = false;
        for(auto player = this->_players.begin(); player < this->_players.end(); player++) {
            if((*player)->getPlayerStatus() == "Active") {
                at_least_one_active = true;
            }
        }
        return !at_least_one_active;
    };

    auto _print_winner = [&]() {
        unsigned int max_hand_value = 0;
        for(auto player = this->_players.begin(); player < this->_players.end(); player++) {
            if((*player)->getPlayerStatus() != "Bust") {
                max_hand_value = (*player)->getHandValue() > max_hand_value ? (*player) ->getHandValue() : max_hand_value;
            }
        }
        std::cout << "\nWinners:\n";
        for(auto player = this->_players.begin(); player < this->_players.end(); player++) {
            if((*player)->getHandValue() == max_hand_value) {
                std::cout << (*player)->getName() << " wins with a hand value of " << max_hand_value << "\n";
                (*player)->peekHand();
                std::cout << "\n";
            }
            if((*player)->getHandSize() == 5 && (*player)->getPlayerStatus() != "Bust") {
                std::cout << (*player)->getName() << " wins with a hand size of 5\n";
                (*player)->peekHand();
                std::cout << "\n";
            }
        }
    };

    _initialize();
    std::cout << "\nBlackjack game has started!\n\n";

    while(!_is_game_over()) {
        _play_round();
    }

    std::cout << "\nThe game is over!\n";
    _print_winner();
}
