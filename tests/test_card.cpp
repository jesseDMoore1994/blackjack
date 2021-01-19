#include <catch2/catch_all.hpp>
#include "card.hpp"

SCENARIO( "Card Operations.", "[card]" ) {

    GIVEN( "a face and suit." ) {
		Card::Face face = Card::Face::Ace;
		Card::Suit suit = Card::Suit::Spade;

        WHEN( "a card is constructed with those values." ) {
			Card card = Card(face, suit);

            THEN( "those values can be read from the card." ) {
				CHECK(card.getFace() == Card::Face::Ace);
				CHECK(card.getSuit() == Card::Suit::Spade);
            }
        }
    }

    GIVEN( "Two cards with the same face and suit." ) {
	    Card card1 = Card(Card::Face::Ace, Card::Suit::Spade);
	    Card card2 = Card(Card::Face::Ace, Card::Suit::Spade);

        WHEN( "I compare the two of them." ) {
			bool res = (card1 == card2);

            THEN( "they are identical." ) {
				REQUIRE(res);
            }
        }
    }

    GIVEN( "Two cards with the same face and different suit." ) {
	    Card card1 = Card(Card::Face::Ace, Card::Suit::Spade);
	    Card card2 = Card(Card::Face::Ace, Card::Suit::Club);

        WHEN( "I compare the two of them." ) {
			bool res = (card1 == card2);

            THEN( "they are not identical." ) {
				REQUIRE(!res);
            }
        }
    }

    GIVEN( "Two cards with a different face and the same suit." ) {
	    Card card1 = Card(Card::Face::Ace, Card::Suit::Spade);
	    Card card2 = Card(Card::Face::King, Card::Suit::Spade);

        WHEN( "I compare the two of them." ) {
			bool res = (card1 == card2);

            THEN( "they are not identical." ) {
				REQUIRE(!res);
            }
        }
    }

    GIVEN( "Two cards with different face and suit." ) {
	    Card card1 = Card(Card::Face::Ace, Card::Suit::Spade);
	    Card card2 = Card(Card::Face::King, Card::Suit::Club);

        WHEN( "I compare the two of them." ) {
			bool res = (card1 == card2);

            THEN( "they are not identical." ) {
				REQUIRE(!res);
            }
        }
    }
}
