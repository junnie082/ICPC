// 나의 도전.
#include <iostream>
#include <vector>
using namespace std; 

vector<int> friends[11]; 
int paired[11]; 
int n, m; 

int result; 

void pairedToZero() {
	for (int i = 0; i <= 10; paired[i++] = 0); 
}

void howManyPairs(int start, int pairs) {

	// 기저 사례1. 만들어질 수 있는 짝이 모두 만들어졌을 때. 
	if (pairs == n/2) {
		cout << "n: " << n << "\n"; 
		cout << "pairs: " << pairs << "n/2: " << n/2 << "\n"; 
		result++;
		return; 
	}

	// 기저 사례2. 이미 방문한 원소일 때.  
	// if (paired[start] == 1) return; 

	paired[start] = 1; 

	for (int i = 0; i < friends[start].size(); i++) {
		if (paired[friends[start][i]] == 1) continue;
		cout << "start: " << start << "friend: " << friends[start][i] << "\n"; 
		paired[friends[start][i]] = 1;
		if (i+1 < friends[start].size()) 
			howManyPairs(friends[start][i+1], pairs+1);
		else {
			for (int j = 0; j < friends[start].size(); j++) {
				if (paired[friends[start][j]] == 0) {
					howManyPairs(friends[start][j], pairs+1); 
					break;
				}
			}
		}
		paired[friends[start][i]] = 0; 
	}

	paired[start] = 0; 

	return;
}

int main()
{
	int C; 
	cin >> C; 

	int from, to; 

	int count = 0; 
	for (int i = 0; i < C; i++) {
		result = 1; 
		pairedToZero(); 
		cin >> n >> m; 
		for (int j = 0; j < m; j++) {
			cin >> from >> to; 
			friends[from].push_back(to); 
			friends[to].push_back(from); 
		}

		howManyPairs(0, 0);
		cout << result << "\n"; 
	}
}