#include <vector>

using namespace std;
int color(vector<vector<int>> &picture, int x, int y) {
    int area = 1;
    int cur = picture[x][y]; // 0으로 색칠하기 전에 색을 저장하기 위해 (다른 방법을 써도 좋았을 것 가틈)
    picture[x][y] = 0; // 0으로 색칠
    
    if (x > 0) { // 위도 같은 색이면 색칠
        if (picture[x-1][y] == cur)
            area += color(picture, x-1, y); 
    }
    if (x < picture.size()-1) { // 아래도 같은 색이면 색칠
        if (picture[x+1][y] == cur)
            area+= color(picture, x+1, y);
    }
    if (y > 0) { // 왼쪽도 같은 색이면 색칠
        if (picture[x][y-1] == cur)
            area += color(picture, x, y-1);
    }
    if (y < picture[0].size()-1) { // 오른쪽도 같은 색이면 색칠
        if (picture[x][y+1] == cur)
            area += color(picture, x, y+1);
    }
    return area; // 같은 색이었던 영역의 개수
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0) {
                number_of_area++; // 영역 개수 증가
                max_size_of_one_area = max(max_size_of_one_area, color(picture, i, j)); // 최대값
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
