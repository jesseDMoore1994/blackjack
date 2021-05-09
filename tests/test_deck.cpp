#include <catch2/catch_all.hpp>
#include "card.hpp"
#include "deck.hpp"
#include <algorithm>
#include <iterator>
#include <vector>

SCENARIO( "Deck Operations.", "[deck]" ) {

    GIVEN( "a Deck of cards." ) {
		Deck deck = Deck();

        WHEN( "I count them." ) {
			unsigned int num_cards = deck.getSize();

            THEN( "I have 52." ) {
				CHECK(num_cards == 52);
            }
        }
    }

    GIVEN( "a Deck of cards." ) {
		Deck deck = Deck();
        std::vector<Card> drawn_cards{};
        std::vector<Card>::iterator drawn_card;

        WHEN( "I search them for duplicates." ) {
            bool match_found = false;
            unsigned int size = deck.getSize();
            for(unsigned int i = 0; i < size; i++) {
                auto card = deck.draw();
                drawn_card = std::find(drawn_cards.begin(), drawn_cards.end(), card);
                if(drawn_card != drawn_cards.end())
                    match_found = true;
                drawn_cards.push_back(card);
            }

            THEN( "I have no duplicates." ) {
				REQUIRE(!match_found);
            }
        }
    }

    GIVEN( "two decks of the same size." ) {
		Deck deck1 = Deck();
		Deck deck2 = Deck();
        REQUIRE(deck1.getSize() == deck2.getSize());

        WHEN( "I shuffle them both." ) {
            deck1.shuffle();
            deck2.shuffle();

            THEN( "I have different ordering." ) {
                bool identical = true;
                unsigned int size = deck1.getSize();
                for(unsigned int i = 0; i < size; i++) {
                    auto card1 = deck1.draw();
                    auto card2 = deck2.draw();
                    if(card1 != card2) {
                        identical = false;
                        break;
                    }
                }
                REQUIRE(!identical);
            }
        }
    }

    GIVEN( "two decks of the same size." ) {
		Deck deck1 = Deck();
		Deck deck2 = Deck();
        REQUIRE(deck1.getSize() == deck2.getSize());

        WHEN( "I do nothing to them." ) {
            THEN( "they have the same ordering." ) {
                bool identical = true;
                unsigned int size = deck1.getSize();
                for(unsigned int i = 0; i < size; i++) {
                    auto card1 = deck1.draw();
                    auto card2 = deck2.draw();
                    if(card1 != card2) {
                        identical = false;
                        break;
                    }
                }
                REQUIRE(identical);
            }
        }
    }
}
