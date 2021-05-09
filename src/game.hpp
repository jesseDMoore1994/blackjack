#ifndef GAME_HPP
#define GAME_HPP
#include "deck.hpp"
#include "player.hpp"
#include <vector>
#include <memory>
class Game {
    private:
        std::vector<std::shared_ptr<Player>> _players;
    public:
        Game(std::vector<std::shared_ptr<Player>>);
        unsigned int getPlayerCount();
        void run();
};
#endif
