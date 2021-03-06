// pic10chw1application.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Cards.h"

using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)


// Non member functions implementations (if any)


// Stub for main
int main() {
	Player p;

	Player dealer;
	dealer.set_money(900);
	int round = 0;
	string response;
	while ((p.get_money() > 0) && (dealer.get_money() > 0)) {

		cout << "your current money: " << p.get_money()<<endl;
		int bet;
		round = round + 1;
		cout << "game " << round << endl;
		cout << "Enter a number as bet: " << endl;
		cin >> bet;
		p.reset_myhand();
		dealer.reset_myhand();
		while (((p.get_hand()).get_sum_of_value() < 7.5) && ((dealer.get_hand()).get_sum_of_value() < 7.5)) {
			
			cout << "Do you want a new card? y or n." << endl;
			cin >> response;
			if (response == "y")
			{
				Card player_new_card;
				p.update_myhand(player_new_card.get_rank());
				(p.get_hand()).print_ranks_of_cards();
				//cout << (p.get_hand()).get_sum_of_value() << endl;
				
			}
			if (response == "n") {
				while (((dealer.get_hand()).get_sum_of_value()) < 5.5) {
					Card dealer_new_card;
					dealer.update_myhand(dealer_new_card.get_rank());
				}
				(dealer.get_hand()).print_ranks_of_cards();
				break;
			}
		}
		if (((p.get_hand()).get_sum_of_value()) > 7.5)
		{
			cout << "You lose " << bet << endl;
			cout << "Your ranks:";
			(p.get_hand()).print_ranks_of_cards();
			cout << "dealer's ranks: ";
			(dealer.get_hand()).print_ranks_of_cards();
			p.update_money(-1 * bet);
			dealer.update_money(bet);
			//cout << "your current money: " << p.get_money() << endl;
			//cout << (p.get_hand()).get_sum_of_value() << endl;
		}
		if ((((p.get_hand()).get_sum_of_value()) <= 7.5) && (((dealer.get_hand()).get_sum_of_value()) <= 7.5)) {
			if ((p.get_hand()).get_sum_of_value() < (dealer.get_hand()).get_sum_of_value()) {
				cout << "You lose " << bet << endl;
				cout << "Your ranks: ";
				(p.get_hand()).print_ranks_of_cards();
				cout << "dealer's ranks: ";
				(dealer.get_hand()).print_ranks_of_cards();
				p.update_money(-1 * bet);
				dealer.update_money(bet);
				//cout<< "your current money: " << p.get_money() << endl;
			}
		}
		if ((((p.get_hand()).get_sum_of_value()) <= 7.5) && (((dealer.get_hand()).get_sum_of_value()) <= 7.5)) {
			if ((p.get_hand()).get_sum_of_value() > (dealer.get_hand()).get_sum_of_value()) {
				cout << "You win " << bet << endl;
				cout << "Your ranks: ";
				(p.get_hand()).print_ranks_of_cards();
				cout << "dealer's ranks: ";
				(dealer.get_hand()).print_ranks_of_cards();
				p.update_money(bet);
				dealer.update_money(-1 * bet);
				//cout << "your current money: " << p.get_money() << endl;
			}
		}
		if ((((p.get_hand()).get_sum_of_value()) <= 7.5) && (((dealer.get_hand()).get_sum_of_value()) <= 7.5)) {
			if ((p.get_hand()).get_sum_of_value() == (dealer.get_hand()).get_sum_of_value()) {
				cout << "tie " << endl;
				cout << "Your ranks: ";
				(p.get_hand()).print_ranks_of_cards();
				cout << "dealer's ranks: ";
				(dealer.get_hand()).print_ranks_of_cards();
				//cout << "your current money: " << p.get_money() << endl;
			}
		}
		if ((((p.get_hand()).get_sum_of_value()) <= 7.5) && (((dealer.get_hand()).get_sum_of_value()) > 7.5)) {
			cout << "You win " << bet << endl;
			cout << "Your ranks: ";
			(p.get_hand()).print_ranks_of_cards();
			cout << "dealer's ranks: ";
			(dealer.get_hand()).print_ranks_of_cards();
			p.update_money(bet);
			dealer.update_money(-1 * bet);
			//cout << "your current money: " << p.get_money() << endl;
		}



	}
	if (p.get_money() <= 0) {
		cout << "Come back when you have more money." << endl;
	}
	if (dealer.get_money() <= 0) {
		cout << "You have won 900." << endl;
	}
	/* --STATEMENTS-- */
	return 0;
}




