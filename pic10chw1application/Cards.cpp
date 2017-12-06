#include "stdafx.h"
#include "Cards.h"
#include <cstdlib>
#include <iostream>

/*
You might or might not need these two extra libraries
#include <iomanip>
#include <algorithm>
*/


/* *************************************************
Card class
************************************************* */

/*
Default constructor for the Card class.
It could give repeated cards. This is OK.
Most variations of Blackjack are played with
several decks of cards at the same time.
*/
Card::Card() {
	int r = 1 + rand() % 4;
	switch (r) {
	case 1: suit = OROS; break;
	case 2: suit = COPAS; break;
	case 3: suit = ESPADAS; break;
	case 4: suit = BASTOS; break;
	default: break;
	}

	r = 1 + rand() % 10;
	switch (r) {
	case  1: rank = AS; break;
	case  2: rank = DOS; break;
	case  3: rank = TRES; break;
	case  4: rank = CUATRO; break;
	case  5: rank = CINCO; break;
	case  6: rank = SEIS; break;
	case  7: rank = SIETE; break;
	case  8: rank = SOTA; break;
	case  9: rank = CABALLO; break;
	case 10: rank = REY; break;
	default: break;
	}
}

// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "oros";
		break;
	case COPAS:
		suitName = "copas";
		break;
	case ESPADAS:
		suitName = "espadas";
		break;
	case BASTOS:
		suitName = "bastos";
		break;
	default: break;
	}
	return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "As";
		break;
	case DOS:
		rankName = "Dos";
		break;
	case TRES:
		rankName = "Tres";
		break;
	case CUATRO:
		rankName = "Cuatro";
		break;
	case CINCO:
		rankName = "Cinco";
		break;
	case SEIS:
		rankName = "Seis";
		break;
	case SIETE:
		rankName = "Siete";
		break;
	case SOTA:
		rankName = "Sota";
		break;
	case CABALLO:
		rankName = "Caballo";
		break;
	case REY:
		rankName = "Rey";
		break;
	default: break;
	}
	return rankName;
}



// Accessor: returns a string with the suit of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "suit_A";
		break;
	case COPAS:
		suitName = "suit_B";
		break;
	case ESPADAS:
		suitName = "suit_C";
		break;
	case BASTOS:
		suitName = "suit_D";
		break;
	default: break;
	}
	return suitName;

}

// Accessor: returns a string with the rank of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "ACE";
		break;
	case DOS:
		rankName = "TWO";
		break;
	case TRES:
		rankName = "THREE";
		break;
	case CUATRO:
		rankName = "FOUR";
		break;
	case CINCO:
		rankName = "FIVE";
		break;
	case SEIS:
		rankName = "SIX";
		break;
	case SIETE:
		rankName = "SEVEN";
		break;
	case SOTA:
		rankName = "TEN";
		break;
	case CABALLO:
		rankName = "ELEVEN";
		break;
	case REY:
		rankName = "TWELVE";
		break;
	default: break;
	}
	return rankName;

}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
	return static_cast<int>(rank) + 1;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
	return rank < card2.rank;
}



/* *************************************************
Hand class
************************************************* */
// Implement the member functions of the Hand class here.
Hand::Hand() {
	vector<int> a(0);
	rank_of_cards = a;
}

//i is the rank of the updated card.
void Hand::update_hand(int i) {
	rank_of_cards.push_back(i);
}

double Hand::get_sum_of_value() const {
	int i;
	double sum = 0;
	for (i = 1; i < rank_of_cards.size(); i++)
	{
		if (this->rank_of_cards[i] >= 10)
			sum = sum + 0.5;
		else
			sum = sum + rank_of_cards[i];
	}
	return sum;
}

void Hand::print_ranks_of_cards() const {
	for (int i = 0; i++; i<rank_of_cards.size())
		cout << rank_of_cards[i];
	cout << endl;
}

/* *************************************************
Player class
************************************************* */
// Implemente the member functions of the Player class here.
Player::Player() {
	money = 100;
	myhand = Hand();
}

int Player::get_money() const {
	return money;
}

void Player::set_money(int i) {
	money = i;
}

void Player::update_money(int i) {
	money = money + i;
}

Hand Player::get_hand() {
	return myhand;
}

void Player::update_myhand(int i) {
	myhand.update_hand(i);
}

void Player::reset_myhand() {
	myhand = Hand();
}
