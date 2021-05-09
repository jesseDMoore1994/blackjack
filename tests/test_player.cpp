#include <catch2/catch_all.hpp>
#include <memory>
#include "deck.hpp"
#include "player.hpp"
#include <sstream>

SCENARIO( "Player Operations.", "[player]" ) {

    GIVEN( "Two players with One deck." ) {
        std::shared_ptr<Deck> deck = std::shared_ptr<Deck>(new Deck());
        AiPlayer p1 = AiPlayer("player1", deck);
        AiPlayer p2 = AiPlayer("player2", deck);

        WHEN( "Each player draws a card." ) {
			p1.hit();
			p2.hit();

            THEN( "Each player has one card in hand." ) {
				CHECK(p1.getHandSize() == 1);
				CHECK(p2.getHandSize() == 1);
            }

            AND_THEN( "The deck has 50 cards left" ) {
                CHECK(deck->getSize() == 50);
            }
        }
    }

    GIVEN( "A player with a deck." ) {
        std::shared_ptr<Deck> deck = std::shared_ptr<Deck>(new Deck());
        AiPlayer p1 = AiPlayer("player1", deck);

        WHEN( "the player has two cards." ) {
			p1.hit();
			p1.hit();

            THEN( "We can see the hand." ) {
                std::stringstream actual;
                actual << p1;
                std::stringstream expected;
                expected << "Player Name: player1\n";
                expected << "Player Status: Active\n";
                expected << "Hand:\n";
                expected << "\t<this card cannot be seen>\n";
                expected << "\tKing of Hearts\n";
				CHECK(actual.str() == expected.str());
            }
        }
    }

    GIVEN( "An AI player with a deck." ) {
        std::shared_ptr<Deck> deck = std::shared_ptr<Deck>(new Deck());
        AiPlayer p1 = AiPlayer("player1", deck);

        WHEN( "the player has one card." ) {
            p1.hit();

            THEN( "The player holds after passing 16." ) {
                while(p1.getHandValue() < 16) {
                    CHECK("Active" == p1.getPlayerStatus());
                    p1.takeTurn();
                }
                CHECK("Active" == p1.getPlayerStatus());
                p1.takeTurn();
                CHECK("Hold" == p1.getPlayerStatus());
            }
        }
    }
}
