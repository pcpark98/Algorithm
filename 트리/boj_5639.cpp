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
	vector<Node*> allNodes;

	Tree() {
		this->root = NULL;
	}

	void setRoot(Node* root) {
		this->root = root;
	}

	void insertNode(Node* newNode) {
		allNodes.push_back(newNode);
		if (this->root != newNode) {
			Node* current = root;
			while (current != NULL) {
				if (newNode->value < current->value) {
					if (current->left == NULL) {
						current->setLeft(newNode);
						newNode->setParent(current);
						return;
					}
					current = current->left;
				}

				else {
					if (current->right == NULL) {
						current->setRight(newNode);
						newNode->setParent(current);
						return;
					}
					current = current->right;
				}
			}
		}
	}

	bool empty() {
		if (allNodes.empty()) return true;
		else return false;
	}

	void postorder(Node* current) {
		if (current->left != NULL) postorder(current->left);
		if (current->right != NULL) postorder(current->right);
		cout << current->value << "\n";
	}
};

Tree tree;
int input;

int main() {
	while (cin >> input) {
		Node* newNode = new Node(input);
		if (tree.empty()) {
			tree.setRoot(newNode);
			tree.insertNode(newNode);
			continue;
		}
		tree.insertNode(newNode);
	}
	tree.postorder(tree.root);
}