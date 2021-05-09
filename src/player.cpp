#include "player.hpp"

Player::Player(std::string name, std::shared_ptr<Deck> game_deck, unsigned int hidden_cards) {
    this->_name = name;
    this->_deck = game_deck;
    this->_hand = std::vector<Card>();
    this->_hidden_cards = hidden_cards;
    this->_status = "Active";
}

void Player::reset() {
    this->_hand.clear();
    this->_status = "Active";
}

void Player::hit() {
    auto new_card = this->_deck->draw();
    if(this->_hand.size() < this->_hidden_cards) {
        new_card.hide();
    }
    this->_hand.push_back(new_card);
    if(this->getHandValue() > 21) {
        std::cout << this->_name << " has busted!\n";
        this->_status = "Bust";
    }
}

void Player::hold() {
    std::cout << this->_name << " is holding!\n";
    this->_status = "Hold";
}

void Player::peekHand() {
    std::cout << "Player Name: " << this->_name << "\n";
    std::cout << "Player Status: " << this->_status << "\n";
    std::cout << "hand:\n";
    std::vector<Card>::iterator card = this->_hand.begin();
    for(card = this->_hand.begin(); card < this->_hand.end(); card++) {
        if(card->isHidden()) {
            card->reveal();
            std::cout << "\t(Hidden) " << *card << "\n";
            card->hide();
        }
        else {
            std::cout << "\t" << *card << "\n";
        }
    }
    std::cout << "\n";
}

unsigned int Player::getHandSize() {
    return this->_hand.size();
}

unsigned int Player::getHandValue() {
    std::vector<Card>::iterator card = this->_hand.begin();
    unsigned int sum = 0;
    unsigned int aces_in_hand = 0;
    for(card = this->_hand.begin(); card < this->_hand.end(); card++) {
        switch(card->getFace()) {
            case Card::Two:
                sum = sum + 2;
                break;
            case Card::Three:
                sum = sum + 3;
                break;
            case Card::Four:
                sum = sum + 4;
                break;
            case Card::Five:
                sum = sum + 5;
                break;
            case Card::Six:
                sum = sum + 6;
                break;
            case Card::Seven:
                sum = sum + 7;
                break;
            case Card::Eight:
                sum = sum + 8;
                break;
            case Card::Nine:
                sum = sum + 9;
                break;
            case Card::Ten:
            case Card::Jack:
            case Card::Queen:
            case Card::King:
                sum = sum + 10;
                break;
            case Card::Ace:
                aces_in_hand++;
                sum = sum + 11;
                break;
            default:
                break;
        }
    }
    if(sum > 21 && aces_in_hand > 0) {
        unsigned int x = aces_in_hand;
        while(x > 0 && sum > 21) {
            sum -= 10;
            x--;
        }
    }
    return sum;
}

std::string Player::getName() {
    return this->_name;
}

std::string Player::getPlayerStatus() {
    return this->_status;
}

std::ostream& operator<<(std::ostream &out, Player &player) {
    out << "Player Name: " << player._name << "\n";
    out << "Player Status: " << player._status << "\n";
    out << "Hand:\n";
    std::vector<Card>::iterator card = player._hand.begin();
    for(card = player._hand.begin(); card < player._hand.end(); card++) {
        out << "\t" << *card << "\n";
    }
    std::cout << "\n";
    return out;
}

void AiPlayer::takeTurn() {
    std::cout << this->_name << "'s turn: action taken is ";
    if(this->getHandValue() < 16) {
        std::cout << "hit.\n";
        this->hit();
    }
    else {
        std::cout << "hold.\n";
        this->hold();
    }
}

void HumanPlayer::takeTurn() {
    bool turn_taken = false;
    while(!turn_taken)
    {
        std::cout << "It is " << this->_name << "'s turn, what would you like to do?\n";
        std::cout << "1) see hand\n";
        std::cout << "2) hit\n";
        std::cout << "3) stay\n";
        std::cout << "> ";

        std::string user_input;
        int choice;
        getline(std::cin, user_input);
        std::istringstream(user_input) >> choice;
        switch(choice) {
            case 1:
                this->peekHand();
                break;
            case 2:
                this->hit();
                turn_taken = true;
                break;
            case 3:
                this->hold();
                turn_taken = true;
                break;
            default:
                std::cout << "Invalid Entry, try again.\n";
                break;
        }
    }
}
