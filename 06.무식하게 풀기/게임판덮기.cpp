// 내풀이. 

#include <iostream>
#include <vector>
using namespace std; 

int H, W; 
vector<char> board[100]; 
int ret = 0; 

void initializeBoard() {
	for (int i = 0; i < 100; i++) {
		while (!board[i].empty()) board[i].pop_back(); 
	}
}

void gameStart() {

	int startRow = -1; 
	int startCol = -1; 

	int flag = 0; 
	// 기저 사례. 보드판의 모든 부분이 #이면 true.
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (board[i][j] == '.') {
				startRow = i; 
				startCol = j;
				flag = 1;  
				break;
			}
		}
		if (flag) break; 
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << board[i][j];
		}
		cout << "\n"; 
	}

	if (startRow == -1 && startCol == -1) {
		// 모든 보드판이 덮여짐. 
		ret++;
		return; 
	}

	// 첫번째 케이스. 오른쪽과 아래쪽.
	if ( (startCol + 1 < W && board[startRow][startCol + 1] == '.')
		&& (startRow + 1 < H && board[startRow + 1][startCol] == '.')) {
		board[startRow][startCol] = '#';
		board[startRow][startCol + 1] = '#'; 
		board[startRow + 1][startCol] = '#'; 
		gameStart(); 
		board[startRow][startCol] = '.';
		board[startRow][startCol + 1] = '.'; 
		board[startRow + 1][startCol] = '.';
	}


	// 두번째 케이스. 위쪽과 오른쪽.
	if ( (startRow - 1 >= 0 && board[startRow - 1][startCol] == '.')
		&& (startCol + 1 < W && board[startRow][startCol + 1] == '.') ) {
		board[startRow][startCol] = '#';
		board[startRow - 1][startCol] = '#'; 
		board[startRow][startCol + 1] = '#'; 
		gameStart(); 
		board[startRow][startCol] = '.';
		board[startRow - 1][startCol] = '.'; 
		board[startRow][startCol + 1] = '.';
	} 

	// 세번째 케이스. 왼쪽과 아래쪽. 
	if ( (startCol - 1 >= 0 && board[startRow][startCol - 1] == '.')
		&& (startRow + 1 < H && board[startRow + 1][startCol] == '.')) {
		board[startRow][startCol] = '#';
		board[startRow][startCol - 1] = '#'; 
		board[startRow + 1][startCol] = '#'; 
		gameStart();
		board[startRow][startCol] = '.';
		board[startRow][startCol - 1] = '.'; 
		board[startRow + 1][startCol] = '.';	
	}

	// 네번째 케이스. 왼쪽과 위쪽.
	if ( (startCol - 1 >= 0 && board[startRow][startCol - 1] == '.')
		&& (startRow - 1 >= 0 && board[startRow - 1][startCol] == '.')) {
		board[startRow][startCol] = '#';
		board[startRow][startCol - 1] = '#'; 
		board[startRow - 1][startCol] = '#'; 
		gameStart(); 
		board[startRow][startCol] = '.';
		board[startRow][startCol - 1] = '.'; 
		board[startRow + 1][startCol] = '.';
	}

	// 다섯번째 케이스 아래와 아래 오른쪽.
	if ( (startRow + 1 < H && board[startRow + 1][startCol] == '.')
		&& (startCol + 1 < W && board[startRow + 1][startCol + 1] == '.')) {
		board[startRow][startCol] = '#';
		board[startRow + 1][startCol] = '#'; 
		board[startRow + 1][startCol + 1] = '#'; 
		gameStart(); 
		board[startRow][startCol] = '.';
		board[startRow + 1][startCol] = '.'; 
		board[startRow + 1][startCol + 1] = '.';
	}

	//	여섯번째 케이스 오른쪽과 오른쪽 아래.
	if ( (startCol + 1 < W && board[startRow][startCol + 1] == '.')
		&& (startRow + 1 < H && board[startRow + 1][startCol + 1] == '.')) {
		board[startRow][startCol] = '#';
		board[startRow][startCol + 1] = '#'; 
		board[startRow + 1][startCol + 1] = '#'; 
		gameStart(); 
		board[startRow][startCol] = '.';
		board[startRow][startCol + 1] = '.'; 
		board[startRow + 1][startCol + 1] = '.';
	}

	//	일곱번째 케이스 오른쪽과 오른쪽 위.
	if ( (startCol + 1 < W && board[startRow][startCol + 1] == '.')
		&& (startRow - 1 >= 0 && board[startRow - 1][startCol + 1] == '.')) {
		board[startRow][startCol] = '#';
		board[startRow][startCol + 1] = '#'; 
		board[startRow - 1][startCol + 1] = '#'; 
		gameStart(); 
		board[startRow][startCol] = '.';
		board[startRow][startCol + 1] = '.'; 
		board[startRow - 1][startCol + 1] = '.';
	}

	//	여덟번째 케이스 위쪽과 오른쪽 위.
	if ( (startRow - 1 >= 0 && board[startRow - 1][startCol] == '.')
		&& (startCol + 1< W && board[startRow - 1][startCol + 1] == '.')) {
		board[startRow][startCol] = '#';
		board[startRow - 1][startCol] = '#'; 
		board[startRow - 1][startCol + 1] = '#'; 
		gameStart(); 
		board[startRow][startCol] = '.';
		board[startRow - 1][startCol] = '.'; 
		board[startRow - 1][startCol + 1] = '.';
	}

	// 아홉번째 케이스 아래와 아래 왼쪽
	if ( (startRow + 1 < H && board[startRow + 1][startCol] == '.')
		&& (startCol - 1 >= 0 && board[startRow + 1][startCol - 1] == '.')) {
		board[startRow][startCol] = '#';
		board[startRow + 1][startCol] = '#'; 
		board[startRow + 1][startCol - 1] = '#'; 
		gameStart(); 
		board[startRow][startCol] = '.';
		board[startRow + 1][startCol] = '.'; 
		board[startRow + 1][startCol - 1] = '.';
	}

}

int main()
{
	int C;
	cin >> C; 
	string s; 

	char blackOrWhite;
	for (int T = 0; T < C; T++) {
		cin >> H >> W; 
		initializeBoard(); 
		ret = 0; 
		for (int row = 0; row < H; row++) {
			cin >> s; 
			for (int i = 0; i < s.length(); i++) {
				board[row].push_back(s[i]); 
			}
		}

		gameStart(); 
		cout << ret << "\n"; 
	}


}