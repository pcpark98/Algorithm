#include <iostream>
#include <vector>
using namespace std;

int toDelete, ans = 0;

class Node {
public:
	int num;
	Node* parent;
	vector<Node*> children;

	Node(int num) {
		this->num = num;
		this->parent = NULL;
	}
};

class Tree {
public:
	Node* root;
	vector<Node*> allNode;

	Tree() {
		this->root = NULL;
	}

	void preorder(Node* node) {
		if (node->children.empty()) ans++;
		if (node->children.size() == 1 && node->children[0]->num == toDelete) ans++;
		else {
			for (int i = 0; i < node->children.size(); i++) {
				if (node->children[i]->num == toDelete) continue;
				preorder(node->children[i]);
			}
		}
	}
};

Tree tree;
int N, input;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		Node* newNode = new Node(i);
		tree.allNode.push_back(newNode);
	}

	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == -1) tree.root = tree.allNode[i];
		else {
			tree.allNode[i]->parent = tree.allNode[input];
			tree.allNode[input]->children.push_back(tree.allNode[i]);
		}
	}

	cin >> toDelete;
	if (toDelete == tree.root->num) {
		cout << ans;
		return 0;
	}
	tree.preorder(tree.root);
	cout << ans;
}

