#include<iostream>

using namespace std;

char letter = 'A';
string s = "       ";
string clear = "\x1b[2J\x1b[3J\x1b[H";
string temp1 = "", temp2 = "";	

// Background Colors
string blackbg = "\x1b[40m";
string redbg = "\x1b[41m";
string greenbg = "\x1b[42m";
string yellowbg = "\x1b[43m";
string bluebg = "\x1b[44m";
string magentabg = "\x1b[45m";
string cyanbg = "\x1b[46m";
string whitebg = "\x1b[47m";

// Text Colors
string blacktx = "\x1b[30m";
string redtx = "\x1b[31m";
string greentx = "\x1b[32m";
string yellowtx = "\x1b[33m";
string bluetx = "\x1b[34m";
string magentatx = "\x1b[35m";
string cyantx = "\x1b[36m";
string whitetx = "\x1b[37m";

// White Chess Pieces
string player1 [16] = {"\u2656", "\u2658", "\u2657", "\u2654", "\u2655", "\u2657", "\u2658", "\u2656", "\u2659", "\u2659", "\u2659", "\u2659", "\u2659", "\u2659", "\u2659", "\u2659"};

// Black Chess Pieces
string player2 [16] = {"\u265f", "\u265f", "\u265f", "\u265f", "\u265f", "\u265f", "\u265f", "\u265f", "\u265c", "\u265e", "\u265d", "\u265a", "\u265b", "\u265d", "\u265e", "\u265c"};
string place [64];
string grid [64];
int count = 1;
bool change = false;


int size (string s[]) {

	while(!s[count].empty()) {

		count++;

	}
	return count;

}

void init() {

	char temp = 'A';
	int num = 1;

	for (int i = 0; i < 64; i++) {

		grid[i] = " ";

	}
	for(int i = 0; i < 16; i++) {

		grid[i] = player1[i];

	}

	for (int i = 0; i < 16; i++) {

		grid[i + 48] = player2[i];

	}

	for(int i = 0; i < 64; i++){

			place[i] = temp + to_string(num);
			num++;
			if (num == 9) {
				
				temp++;
				num = 1;
			}
	}

}

void paint() {

	letter = 'A';
	cout << clear << flush;

	cout << yellowbg << bluetx << "\n\t";
	cout << "      1   " << "   2   " << "   3   " << "   4   " << "   5   " << "   6   " << "   7   " << "   8      " << bluebg << greentx << size(grid) << "\x1b[0m";
	for (int i = 0; i < size(grid); i++) {
		
		cout << redtx;

		if(i % 8 == 0) {
			change = !change;
			if(change) {
		cout << "\n\t" << yellowbg << "   " << whitebg << s << blackbg << s << whitebg << s << blackbg << s << whitebg << s << blackbg << s << whitebg << s << blackbg << s << yellowbg << "   " << "\n\t" << bluetx << " " << letter << " ";
			}
			else {
		cout << "\n\t" << yellowbg << "   " << blackbg << s << whitebg << s << blackbg << s << whitebg << s << blackbg << s << whitebg << s << blackbg << s << whitebg << s << yellowbg << "   " << "\n\t" << bluetx << " " << letter << " ";
			}

		}

		if (change) {
		cout << redtx << whitebg << "   " << grid[i] << "   ";
			change = !change;
		}
		else {
		cout << redtx << blackbg << "   " << grid[i] << "   ";
			change = !change;
		}

		if((i + 1) % 8 == 0 && i != 0) {
			if(change) { 
		cout << yellowbg << bluetx << " " << letter << " " << "\n\t" << yellowbg << "   " << whitebg << s << blackbg << s << whitebg << s << blackbg << s << whitebg << s << blackbg << s << whitebg << s << blackbg << s << yellowbg << "   ";
			}
			else {
		cout << yellowbg << bluetx << " " << letter << " " << "\n\t" << yellowbg << "   " << blackbg << s << whitebg << s << blackbg << s << whitebg << s << blackbg << s << whitebg << s << blackbg << s << whitebg << s << yellowbg << "   ";
			}
			
			letter++;
		}


	}

	cout << yellowbg << bluetx << "\n\t";
	cout << "      1   " << "   2   " << "   3   " << "   4   " << "   5   " << "   6   " << "   7   " << "   8      " << bluebg << greentx << size(grid) << "\x1b[0m\n\n";

}

void move() {

	while(true) {
	cout << "Select Piece Location: ";
	cin >> temp1;
	cout << "Select Piece Move: ";
	cin >> temp2;

		for(int i = 0; i < 64; i++) {
			if(temp1 == place[i]){
				for(int j = 0; j < 64; j++) {
					if(temp2 == place[j]){
			
						grid[j] = grid[i];
						grid[i] = " ";
					}
				}

			}
		}
		paint();
	}
}

int main() {

	init();	
	paint();
	move();

}
