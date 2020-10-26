#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define null 0

using namespace std;

template <typename T>
class Tree;

template <typename T>
class TreeNode {
	friend class Tree<T>;
private:
	T x;
	T y;
	T value;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode(T x = 0, T y = 0, T value = 0, TreeNode* left = null, TreeNode* right = null) {
		this->x = x;
		this->y = y;
		this->value = value;
		this->left = left;
		this->right = right;
	}
};

template <typename T>
class Tree {
private:
	TreeNode<T>* root;
public:
	Tree(T x = 0, T y = 0, T value = 0) {
		root = new TreeNode<T>(x, y, value);
	}

	void buildTree(T x, T y, T value) {
		TreeNode<T>* new_node;
		new_node = new TreeNode<T>(x, y, value);
		TreeNode<T>* cur = root;
		TreeNode<T>* prev = NULL;


		while (cur != NULL && cur->y > new_node->y) {
			prev = cur;
			if (prev->x > new_node->x)cur = cur->left;
			else cur = cur->right;
		}

		if (cur == NULL) {
			if (prev->x > new_node->x)prev->left = new_node;
			else prev->right = new_node;


		}
	}

	TreeNode<T>* getRoot() {
		return root;
	}

	T visit(TreeNode<T>* current) {
		return current->value;
	}

	// 전위 순회 Current - Left - Right
	void preorder(TreeNode<T>* current, vector<int> &a) {
		if (current != null) {
			a.push_back(visit(current));
			preorder(current->left, a);
			preorder(current->right, a);
		}
	}

	// 후위 순회 Left - Right - Current
	void postorder(TreeNode<T>* current, vector<int>& a) {
		if (current != null) {
			postorder(current->left, a);
			postorder(current->right, a);
			a.push_back(visit(current));
		}
	}
};

bool cmp(vector<int> a, vector<int> b) {
	if (a[1] > b[1]) {
		return true;
	}
	else if (a[1] == b[1]) {
		if (a[0] < b[0]) { return true; }
		else return false;
	}
	return false;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;
	for (int i = 1; i <= nodeinfo.size(); i++) {
		nodeinfo[i-1].push_back(i);
	}
	sort(nodeinfo.begin(), nodeinfo.end(), cmp);
	Tree<int> tree(nodeinfo[0][0], nodeinfo[0][1], nodeinfo[0][2]);
	for (int i = 1; i < nodeinfo.size(); i++) {
		tree.buildTree(nodeinfo[i][0], nodeinfo[i][1], nodeinfo[i][2]);
	}

	vector<int> a;
	tree.preorder(tree.getRoot(),a);

	vector<int> b;
	tree.postorder(tree.getRoot(),b);
	answer.push_back(a); answer.push_back(b);


	return answer;
}

int main() {
	vector<vector<int>> answer = solution({ {5, 3},{11, 5},{13, 3},{3, 5},{6, 1},{1, 3},{8, 6},{7, 2},{2, 2} });
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < answer[i].size(); j++) {
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
