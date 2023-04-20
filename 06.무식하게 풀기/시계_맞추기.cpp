#include <iostream>
#include <vector>
using namespace std; 

int clockTime[16]; 
vector<int> toggle[10];

void initialize() {
	// 스위치 0번.
	toggle[0].push_back(0); toggle[0].push_back(1); toggle[0].push_back(2); 

	// 스위치 1번.
	toggle[1].push_back(3); toggle[1].push_back(7); 
	toggle[1].push_back(7); toggle[1].push_back(9);

	// 스위치 2번. 
	toggle[2].push_back(4); toggle[2].push_back(10);
	toggle[2].push_back(14); toggle[2].push_back(15);

	// 스위치 3번. 
	toggle[3].push_back(0); toggle[3].push_back(4);
	toggle[3].push_back(5); toggle[3].push_back(6);
	toggle[3].push_back(7);

	// 스위치 4번.
	toggle[4].push_back(6); toggle[4].push_back(7);
	toggle[4].push_back(8); toggle[4].push_back(10);
	toggle[4].push_back(12);

	// 스위치 5번. 
	toggle[5].push_back(0); toggle[5].push_back(2);
	toggle[5].push_back(14); toggle[5].push_back(15);

	// 스위치 6번. 
	toggle[6].push_back(3); toggle[6].push_back(14);
	toggle[6].push_back(15);

	// 스위치 7번. 
	toggle[7].push_back(4); toggle[7].push_back(5);
	toggle[7].push_back(7); toggle[7].push_back(14);
	toggle[7].push_back(15);

	// 스위치 8번. 
	toggle[8].push_back(1); toggle[8].push_back(2);
	toggle[8].push_back(3); toggle[8].push_back(4);
	toggle[8].push_back(5);

	// 스위치 9번. 
	toggle[9].push_back(3); toggle[9].push_back(4);
	toggle[9].push_back(5); toggle[9].push_back(9);
	toggle[9].push_back(13);
} 

int countTime() {
	// 기저 사례. 모든 시계 값이 0 이라면, 값 반환.
	int time = -1;
	for (int i = 0; i < 16; i++) {
		if (clockTime[i] != 0) {
			time = i; 
			break;
		}
		if (time != -1) break;
	}

	int ret = 0; 

	if (time == -1) return ret + 1;

	// 재귀호출. 

	for (int i = 0; i < toggle[time].size(); i++) {
		countTime
	}
	
}

int main()
{
	int C; 
	cin >> C; 

	int num; 

	initialize(); 

	for (int turn = 0; turn < C; turn++) {
		for (int i = 0; i < 16; i++) {
			cin >> num; 
			switch (num) {
			case 3:
				clockTime[i] = 1; 
				break;
			case 6:
				clockTime[i] = 2; 
				break;
			case 9: 
				clockTime[i] = 3; 
				break;
			case 12: 
				clockTime[i] = 0; 
				break;
			}
		}
		cout << countTime(0, 0); 
	}

}