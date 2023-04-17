// 모범 답안.

#include <iostream>
using namespace std; 

bool hasWord(int y, int x, const string &word) {
	// 기저 사례1: 시작 위치가 범위 밖이면 무조건 실패	
	if (!inRange(y, x)) return false; 
	// 기저 사례2: 첫 글자가 일치 하지 않으면 실패	
	if (board[y][x] != word[0]) return false; 
	// 기저 사례3: 단어 길이가 1이면 성공	
	if (word.size() == 1) return true; 


	// 인접한 여덟칸을 검사한다. 
	for (int direction = 0; direction < 8; ++direction) {
		int nextY = y + dy[direction], nextX = x + dx[direction]; 

		if (hasWord(nextY, nextX, word.substr(1))) return true;
	}

	return false;
}

int main()
{
	const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0}; 
	const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

	...

}