#include <catch2/catch_all.hpp>
#include "game.hpp"

SCENARIO( "Game Operations.", "[game]" ) {

    GIVEN( "A game of blackjack with 1 player." ) {
        std::shared_ptr<Deck> deck = std::shared_ptr<Deck>(new Deck());
        std::vector<std::shared_ptr<Player>> players = std::vector<std::shared_ptr<Player>>();
        players.push_back(std::make_shared<AiPlayer>("AI", deck, 1));
		Game game = Game(players);

        WHEN( "I count the players." ) {
			int num_players = game.getPlayerCount();

            THEN( "I have 1." ) {
				CHECK(num_players == 1);
            }
        }
    }
}
