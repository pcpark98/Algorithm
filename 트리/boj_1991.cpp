#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int value;
	Node* parent, *left, *right;

	Node(int value) {
		this->value = value;
		this->parent = NULL;
		this->left = NULL;
		this->right = NULL;
	}

	void setParent(Node* parent) {
		this->parent = parent;
	}

	void setLeft(Node* left) {
		this->left = left;
	}

	void setRight(Node* right) {
		this->right = right;
	}
};

class Tree {
public:
	Node* root;
	vector<Node*> allNode;

	Tree() {
		root = NULL;
	}

	void setRoot(Node* root) {
		this->root = root;
	}

	void insertNode(Node* node) {
		allNode.push_back(node);
	}

	void preorder(Node* current) {
		cout << char(current->value + 65);
		if (current->left != NULL) preorder(current->left);
		if (current->right != NULL) preorder(current->right);
	}

	void inorder(Node* current) {
		if (current->left != NULL) inorder(current->left);
		cout << char(current->value + 65);
		if (current->right != NULL) inorder(current->right);
	}

	void postorder(Node* current) {
		if (current->left != NULL) postorder(current->left);
		if (current->right != NULL) postorder(current->right);
		cout << char(current->value + 65);
	}
};

Tree tree;
int N;
char input;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		Node* newNode = new Node(i);
		tree.insertNode(newNode);
		if (i == 0) tree.setRoot(newNode);
	}

	for (int i = 0; i < N; i++) {
		vector<char> inputs;
		for (int j = 0; j < 3; j++) {
			cin >> input;
			inputs.push_back(input);
		}
		
		Node* parent = tree.allNode[int(inputs[0]) - 65];
		if (inputs[1] != '.') {
			Node* left = tree.allNode[int(inputs[1]) - 65];
			parent->setLeft(left);
			left->setParent(parent);
		}

		if (inputs[2] != '.') {
			Node* right = tree.allNode[int(inputs[2]) - 65];
			parent->setRight(right);
			right->setParent(parent);
		}
	}

	tree.preorder(tree.root);
	cout << "\n";
	tree.inorder(tree.root);
	cout << "\n";
	tree.postorder(tree.root);
}