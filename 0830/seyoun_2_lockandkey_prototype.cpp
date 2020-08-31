#include <string>
#include <vector>

using namespace std;
bool check(int x, int y, vector<vector<int>> key, vector<vector<int>> lock) {
	int key_size = key.size(), lock_size = lock.size();//이동 거리, 돌려진 벡터
	for (int i = 0; i < lock_size; i++) {
		for (int j = 0; j < lock_size; j++) {
			if (lock[i][j] == 0) {
				if ((i - y) < 0 || (i - y) >= key_size) { return false; }
				if ((j - x) < 0 || (j - x) >= key_size) { return false; }
				if (key[i - y][j - x] == 0) {
					return false;
				}
			}
			if (lock[i][j] == 1) {
				if ((i - y) < 0 || (i - y) >= key_size) { continue; }
				if ((j - x) < 0 || (j - x) >= key_size) { continue; }
				if (key[i - y][j - x] == 1) {
					return false;
				}
			}
		}
	}
	return true;
}

vector<vector<int>> rotation(vector<vector<int>> key) {
	int key_size = key.size();
	vector<vector<int>> res(key_size, vector<int>(key_size));
	for (int i = 0; i < key_size; i++) {
		for (int j = key_size - 1; j >= 0; j--) {
			res[i][key_size - (j + 1)] = key[j][i];
			;
		}
	}

	return res;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int key_size = key.size(), lock_size = lock.size();
	for (int i = 0; i < lock_size; i++) {
		for (int j = 0; j < lock_size; j++) {
			for (int k = 0; k < key_size; k++) {
				for (int e = 0; e < key_size; e++) {
					int move_x = j - e;
					int move_y = i - k;
					if (check(move_x, move_y, key, lock) == true) { return true; }//원형
					vector<vector<int >> tmp = rotation(key);//90도
					if (check(move_x, move_y, tmp, lock) == true) { return true; }
					tmp = rotation(tmp);//180도
					if (check(move_x, move_y, tmp, lock) == true) { return true; }
					tmp = rotation(tmp);//270도
					if (check(move_x, move_y, tmp, lock) == true) { return true; }
				}
			}
		}
	}
	return false;
}


