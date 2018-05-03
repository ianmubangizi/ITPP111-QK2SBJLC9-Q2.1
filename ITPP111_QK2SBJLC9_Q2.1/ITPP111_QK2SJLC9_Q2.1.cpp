/************************************************************
main.cpp
ITPP111_QK2SBJLC9_Q2.1

This Program Ask the User to enter the section they wish to
buy a ticket in and the amount of tickets they require and
then returns the cost for that section and the amount due
from the third-party user as currency.

Created by Ian Mubangizi on 2018/03/16.
Copyright © 2018 Evlutio (Pty) Ltd. All rights reserved.
*************************************************************/

#include <iostream>
#include <string>
#include <locale>
using namespace std;

// Main variables
bool    _sale = false;
int     _cost, _items, _section, _section_cost, _tickets, _retn, _section_tickets[3];
double  _sales;
string  input, _sections[3] = { "Student","Vistor","Employee" };

/* String Validate Function
* 
* Takes a String and Bool 
* Returns a Bool
*/
int _strValidate(string a, bool b) {
	int e; bool d = true;
	string c;
	string _options[6] = { "S", "V", "E", "s", "v", "e" };
	string _noInput[5] = { "NO","No","no", "N", "n" };
	while (d == true) {
		for (e = 0; e < 6; e++) {
			if (a == _noInput[e]) {
				b = false; d = false;
				e = 6;
			}
			else if (a == _options[e]) {
				b = true; d = false;
				_retn = e; e = 6;
			}
			else if ((e == 5) && (a != _noInput[e] && a != _options[e])) {
				cout << "Invaild Input!\nPlease Try Again\n\n[INPUT CODE] : ";
				cin >> c; input = c;
				a = c;
			}
		}
	}
	return b;
}
//End

/* Input Validate Function
* Takes a int
* Check if 0 and is a digit
* Returns a value to item
*/
void inputVal(int a) {
	bool b = true;
	while (b) {
		if (cin.fail() || a == 0) {
			if (cin.fail()) {
				cout << "Invaild Input! Can't input a Letter\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else if (a == 0) {
				cout << "Invaild Input! Can't input 0\n";
			}
			cout << "Please Try Again\n\n[Input] : ";
			cin >> a;
		}
		else {
			b = false;
		}
	}
	_items = a;
}


// Main Function
int main() {
	int _strValidate(string a, bool b);
	// Main Do While Loop
	do {
		cout << "================================================\n";
		cout << "Which Section do you want?\n";
		cout << "Sections:\n\nS) For the Student Section\nV) For the Vistor Section\nE) For the Employee Section\n\nEnter (No or N) to Exit\n[INPUT CODE] : ";
		cin >> input;
		cout << "\n";
		if (_strValidate(input, _sale)) {
			cout << "================================================\n";
			cout << "How Many tickets do you want? : ";cin >> _items;
			inputVal(_items);
			_section = _retn;
			_sale = true;
		}
		else {
			cout << "================================================\n";
			cout << "================================================\n";
			for (int a = 0; a < 3; a++) {
				cout << "Tickets Sold for " << _sections[a] << " Section : " << _section_tickets[a]; cout << "\n";
				_tickets = _tickets + _section_tickets[a];}
			cout << "\n";cout << "Total Tickets Sold : " << _tickets << "\n";
			cout << "Total Sales : R" << _sales << "\n";
			cout << "================================================\n";
			_sale = false;
		}
		// If Statement For Bool _sale
		if (_sale == true) {
			// Switch Statement to Select the section Cost
			switch (_section) {
			case 0:case 3:
				_section_cost = 10;
				cout << _sections[0] << " Section Costs R" << _section_cost << "\n";
				_section_tickets[0] = _section_tickets[0] + _items;
				break;
			case 1:case 4:
				_section_cost = 15;
				cout << _sections[1] << " Section Costs R" << _section_cost << "\n";
				_section_tickets[1] = _section_tickets[1] + _items;
				break;
			case 2:case 5:
				_section_cost = 20;
				cout << _sections[2] << " Section Costs R" << _section_cost << "\n";
				_section_tickets[2] = _section_tickets[2] + _items;
				break;
			default:
				break;
			}
			_cost = _section_cost * _items;
			_sales = _sales + _cost;
			cout << "Amount Due R" << _cost;
			cout << "\n\n================================================\n";
		}
	} while (_sale == true);
	cout << "\n";
	system("PAUSE");
	return(0);
}
