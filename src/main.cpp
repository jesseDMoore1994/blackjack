#include <iostream>
#include <algorithm>
#include <memory>
#include <sstream>
#include <string>
#include <game.hpp>

std::vector<std::shared_ptr<Player>> create_players(std::shared_ptr<Deck> deck) {
    std::vector<std::shared_ptr<Player>> players = std::vector<std::shared_ptr<Player>>();
    std::string user_input;

    unsigned int num_players;
    std::cout << "Enter the number of players in the game:\n> ";
    getline(std::cin, user_input);
    std::istringstream(user_input) >> num_players;

    unsigned int num_humans;
    std::cout << "Enter the number of human players in the game:\n> ";
    getline(std::cin, user_input);
    std::istringstream(user_input) >> num_humans;

    unsigned int num_ai = num_players - num_humans;

    auto get_player_name = [&](){
        std::string name;
        std::cout << "Enter a player name:\n> ";
        getline(std::cin, name);
        return std::string(name);
    };

    for(unsigned int i = 0; i < num_humans; i++){
        players.push_back(
            std::make_shared<HumanPlayer>(get_player_name(), deck, 1)
        );
    }
    for(unsigned int i = 0; i < num_ai; i++){
        auto ai_name = std::string("AI_") + std::to_string(i);
        players.push_back(
            std::make_shared<AiPlayer>(ai_name, deck, 1)
        );
    }
    return players;
}

int main() {
    std::shared_ptr<Deck> deck = std::shared_ptr<Deck>(new Deck());
    deck->shuffle();
    auto players = create_players(deck);

    bool continue_game = true;
    while(continue_game) {
        Game blackjack = Game(players);
        blackjack.run();

        bool valid_input = false;
        while(!valid_input) {
            std::string user_input;
            std::string restart;
            std::cout << "Would you like to play again? (Y/N)\n> ";
            getline(std::cin, user_input);
            std::istringstream(user_input) >> restart;
            transform(restart.begin(), restart.end(), restart.begin(), toupper);

            if (restart.compare("Y") == 0 || restart.compare("YES") == 0) {
                continue_game = true;
                valid_input = true;
            } else if (restart.compare("N") == 0 || restart.compare("NO") == 0) {
                continue_game = false;
                valid_input = true;
            } else {
                std::cout << "Invalid input use one of the following: (Y/N/YES/NO)\n";
                valid_input = false;
            }
        }
        if(continue_game) {
            deck->reset();
            deck->shuffle();
            for(auto player = players.begin(); player < players.end(); player++) {
                (*player)->reset();
            }
        }
    }
    return 0;
}
