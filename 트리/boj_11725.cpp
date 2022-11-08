#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
	int value;
	Node* parent;
	vector<Node*> children;

	Node(int value) {
		this->value = value;
		this->parent = NULL;
	}

	void getChild(Node* child) {
		children.push_back(child);
	}

	void setParent(Node* parent) {
		this->parent = parent;
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

	void insertNode(Node* node) {
		allNodes.push_back(node);
	}
};

Tree tree;
vector<vector<int>> graph;
vector<bool> visited;
int N, a, b;

void bfs(int start) {
	queue<int> q;
	visited[start] = true;
	q.push(start);
	while (!q.empty()) {
		int current = q.front();
		q.pop();

		Node* parent = tree.allNodes[current-1];
		for (int i = 0; i < graph[current].size(); i++) {
			int childIdx = graph[current][i];
			if (!visited[childIdx]) {
				visited[childIdx] = true;

				Node* child = tree.allNodes[childIdx-1];
				child->setParent(parent);
				parent->getChild(child);
				q.push(childIdx);
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N+1; i++) {
		graph.push_back({});
		visited.push_back(false);
		if (i > 0) {
			Node* newNode = new Node(i);
			tree.insertNode(newNode);
			if (i == 1) tree.setRoot(newNode);
		}
	}

	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	bfs(1);


	for (int i = 1; i < N; i++) {
		Node* current = tree.allNodes[i];
		cout << current->parent->value << "\n";
	}
}