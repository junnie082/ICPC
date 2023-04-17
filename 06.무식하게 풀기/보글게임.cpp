// 내 풀이.

#include <iostream>
using namespace std; 

void boggle(char board[][10], int n, string s, int turn, int row, int col) {
	// base case
	if (n == turn) {
		cout << "exist\n";
		exit(0);
	}
	//if (row <= 0 || row > 5 || col <= 0 || col > 5) return; 
	// recursion
	for (int i = row - 1; i <= row + 1; i++) {
		for (int j = col - 1; j <= col + 1; j++) {
			if (!(row == i && col == j) && board[i][j] == s[turn+1]) {
				boggle(board, n, s, turn+1, i, j); 
			}
		}
	}

	return;
}

int main()
{
	char board[5][10] = {"URLPM", "XPRET", "GIAET", "XTNZY", "XOQRS"};

	string s;
	cin >> s;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			//cout << "board: " << board[i][j] << "\n"; 
			if (s[0] == board[i][j]) {
				boggle(board, s.length() - 1, s, 0, i, j);
			}
			
		}
	}

	cout << "doesn't exist\n";

}