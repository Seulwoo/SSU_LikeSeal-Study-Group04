#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct node {
    int x, y, num;
    struct node *left = 0;
    struct node *right = 0;
    struct node *parent = 0;
};

bool comp(struct node a, struct node b) {
    if (a.y == b.y)
        return a.x <= b.x;
    else
        return a.y >= b.y;
}

void preorder(vector<int> &prevector, node *parent) {
    prevector.push_back(parent->num);
    if (parent->left) {
        preorder(prevector, parent->left);
    }
    if (parent->right) {
        preorder(prevector, parent->right);
    }
}

void postorder(vector<int> &postvector, node *parent) {
    if (parent->left) {
        postorder(postvector, parent->left);
    }
    if (parent->right) {
        postorder(postvector, parent->right);
    }
    postvector.push_back(parent->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<node> input;
    vector<vector<int>> answer;
    struct node *head;
    
    for (int i = 0; i < nodeinfo.size(); i++) {
        struct node new_node;
        new_node.x = nodeinfo[i][0];
        new_node.y = nodeinfo[i][1];
        new_node.num = i+1;
        input.push_back(new_node);
    }
    sort(input.begin(), input.end(), comp);
    for (int j = 1; j < input.size(); j++) { // 아래 for문은 트리 만드는 코드로 이세연학우님이 도와주셨습니다
		struct node* cur = &input[0];
			while (cur != 0) {
				if (input[j].y < cur->y) {
					if (input[j].x < cur->x) {
						if (cur->left) { cur = cur->left; }
						else {
							cur->left = &input[j];
							input[j].parent = cur;
                            break;
						}
					}
					if (input[j].x > cur->x) {
						if (cur->right) { cur = cur->right; }
						else {
							cur->right = &input[j];
							input[j].parent = cur;
                            break;
						}
					}
				}
            }
    }
			
    vector<int> prevector, postvector;
    preorder(prevector, &input[0]);
    postorder(postvector, &input[0]);
    answer.push_back(prevector);
    answer.push_back(postvector);
    return answer;
}
