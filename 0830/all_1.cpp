#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool check(int x, int y, vector<vector<int>> key, vector<vector<int>> lock) {
	int key_size = key.size(), lock_size = lock.size();//이동 거리, 돌려진 벡터
	for (int i = 0; i < lock_size; i++) {
		for (int j = 0; j < lock_size; j++) {
			if (lock[i][j] == 0) {
				if ((i - x) < 0 || (i - x) >= key_size) { return false; }
				if ((j - y) < 0 || (j - y) >= key_size) { return false; }
				if (key[i - x][j - y] != 1) {
					return false;
				}
			}
            if (lock[i][j] == 1) {
				if ((i - x) < 0 || (i - x) >= key_size) { continue; }
				if ((j - y) < 0 || (j - y) >= key_size) { continue; }
				if (key[i - x][j - y] == 1) {
					return false;
				}
			}
            
		}
	}
	return true;
}
vector<vector<int>> rotation(vector<vector<int>> key) {
	int key_size = key.size();
	vector<vector<int>> res;
	for (int i = 0; i < key_size; i++) {
        vector<int> r;
		for (int j = key_size - 1; j >= 0; j--) {
			r.push_back(key[j][i]);
		}
        res.push_back(r);
	}
	return res;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int key_size = key.size(), lock_size = lock.size();
    for (int move_x = 0-lock_size; move_x < lock_size; move_x++) {
        for (int move_y = 0-lock_size; move_y < lock_size; move_y++) { 
			if (check(move_x, move_y, key, lock) == true) { return true; }//원형
			vector<vector<int >> tmp = rotation(key);//90도
			if (check(move_x, move_y, tmp, lock) == true) { return true; }
			tmp = rotation(tmp);//180도
            if (check(move_x, move_y, tmp, lock) == true) { return true; }
			tmp = rotation(tmp);//270도
			if (check(move_x, move_y, tmp, lock) == true) { return true; }
        }
    }
	return false;
} 
