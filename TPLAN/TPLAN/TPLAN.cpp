// TPLAN.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>

#define N 100005
#define M 100005
#define SPACE 11184602

#define MOD 1000000007



using namespace std;

class Node {
	int from, to;
	Node *left, *right;

	void ensureExistanceRigth() {
		if (right == nullptr)
			right = newNode((from + to) / 2 + 1, to);
	}

	void ensureExistanceLeft() {
		if (left == nullptr)
			left = newNode(from, (from + to) / 2);
	}

	void ensureExistance() {
		ensureExistanceLeft();
		ensureExistanceRigth();
	}
public:
	static Node* newNode(int from, int to);

	long value, lazy;
	Node() {}
	Node(int _from, int _to) :from(_from), to(_to) {}

	long add(int afrom, int ato, int avalue) {
		if (afrom > to || ato < from)
			return 0;

		if (from == to) {
			value = (value + avalue) % MOD;
			return avalue;
		}

		if (afrom <= from && ato >= to) {
			lazy = (lazy + avalue) % MOD;
			value += (to - from + 1)*avalue%MOD;
			return (to - from + 1)*avalue%MOD;
		}

		ensureExistance();

		long a = left->add(afrom, ato, avalue) + right->add(afrom, ato, avalue);
		value = (value + a) % MOD;
		return a;
	}

	long get(int gfrom, int gto) {
		if (gfrom > to || gto < from)
			return 0;
		if (gfrom <= from && gto >= to) {
			return value;
		}

		ensureExistance();
		left->add(from, to, lazy);
		right->add(from, to, lazy);
		lazy = 0;

		return (left->get(gfrom, gto) + right->get(gfrom, gto)) % MOD;
	}

	void plot(int indentation = 0) {
		if (left != nullptr)
			left->plot(indentation + 1);
		for (int i = 0; i < indentation; i++)
			cout << "\t\t";
		cout << from << " - " << to << " --> " << value << " (" << lazy << ")" << endl;
		if (right != nullptr)
			right->plot(indentation + 1);
	}
};

Node nodes[SPACE];
int nextFreeNode = 0;

Node* Node::newNode(int from, int to) {
	Node& node = nodes[nextFreeNode++];
	node.from = from;
	node.to = to;
	return &node;
}

class SegmentTree {
public:
	Node* root;
	SegmentTree() : root(Node::newNode(0, N)) {
	}

	void add(int from, int to, int value) {
		root->add(from, to, value);
	}

	void plot() {
		root->plot(0);
	}

	long get(int from, int to) {
		return root->get(from, to);
	}
};

struct Training {
	int type, left, right;
};

Training training[N];

int main() {
	int n, m;

	//freopen("../in.txt", "r", stdin);

	SegmentTree total, count;

	scanf("%d %d", &n, &m);


	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &training[i].type, &training[i].left, &training[i].right);
	}

	for (int i = m; i > 0; i--) {
		Training& t = training[i];
		if (t.type == 1) {
			int c = count.get(i, i)+1;
			total.add(t.left, t.right, c);
		} else {
			count.add(t.left, t.right, count.get(i,i)+1);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << total.get(i, i) << " ";
	}
	cout << endl;
}
