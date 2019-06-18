#ifndef SPLAY_H
#define SPLAY_H 1

#include <cstring>
using namespace std;

struct Node {
	int siz, k;
	string val;
	Node *l, *r;
	Node() {
		k = siz = 0;
		val = "";
		l = r = NULL;
	}
	void Update() {
		siz = (l == NULL ? 0 : l->siz) + (r == NULL ? 0 : r->siz) + 1;
	}
};
struct Splay {
	private:
	Node *_root;
	void New(Node *&p, string val) {
		p = new Node;
		p->val = val;
		p->siz = 1;
	}
	void RotateL(Node *&p) {
		Node *q = p->r;
		p->r = q->l;
		q->l = p;
		p->Update();
		p = q;
		p->Update();
	}
	void RotateR(Node *&p) {
		Node *q = p->l;
		p->l = q->r;
		q->r = p;
		p->Update();
		p = q;
		p->Update();
	}
	void Splay_(Node *&p, string val) {
		if (p->val == val) {
			return;
		}
		if (p->val > val) {
			if (p->l->val == val) {
				RotateR(p);
			} else if (p->l->val > val) {
				Splay_(p->l->l, val);
				RotateR(p);
				RotateR(p);
			} else {
				Splay_(p->l->r, val);
				RotateL(p->l);
				RotateR(p);
			}
		} else {
			if (p->r->val == val) {
				RotateL(p);
			} else if (p->r->val < val) {
				Splay_(p->r->r, val);
				RotateL(p);
				RotateL(p);
			} else {
				Splay_(p->r->l, val);
				RotateR(p->r);
				RotateL(p);
			}
		}
	}
	void Update_(Node *&p, string s, int k) {
		if (p == NULL) {
			New(p, s);
			p->k = k;
			return;
		}
		if (p->val == s) {
			p->k = k;
		} else if (p->val > s) {
			Update_(p->l, s, k);
		} else {
			Update_(p->r, s, k);
		}
		p->Update();
	}
	int Query_(Node *p, string s) {
		if (p == NULL) {
			return 0;
		}
		if (p->val == s) {
			return p->k;
		} else if (p->val > s) {
			return Query_(p->l, s);
		} else {
			return Query_(p->r, s);
		}
	}
	public:
	Splay() {
		New(_root, "!");
		New(_root->r, "~");
	}
	void Update(string s, int k) {
		Update_(_root, s, k);
		Splay_(_root, s);
	}
	int Query(string s) {
		return Query_(_root, s);
	}
};

#endif
