#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include "../interface/sSet.h"
 
template<typename T>
class RedBlackTree : public SSet<T> {
 
    const int RED   = 0;
    const int BLACK = 1;
 
    struct RBTreeNode {
        T data;
        int color;
        RBTreeNode *left, *right, *parent;
        RBTreeNode(T value)
            : data(value), color(0),
              left(nullptr), right(nullptr), parent(nullptr) {}
    };
 
    // mutable so that const methods can still modify the tree
    mutable RBTreeNode* root;
    mutable RBTreeNode* NIL;
    mutable int nodeCount;
 
    // core helpers 
    void swapColors(RBTreeNode* u, RBTreeNode* v) const {
        std::swap(u->color, v->color);
    }
 
    void flipLeft(RBTreeNode* u) const {
        swapColors(u, u->right);
        rotateLeft(u);
    }
 
    void flipRight(RBTreeNode* u) const {
        swapColors(u, u->left);
        rotateRight(u);
    }
 
    // pushBlack: split a 4-node 
    void pushBlack(RBTreeNode* u) const {
        u->color--;
        u->left->color++;
        u->right->color++;
    }
 
    // pullBlack: merge 
    void pullBlack(RBTreeNode* u) const {
        u->color++;
        u->left->color--;
        u->right->color--;
    }
 
    // Rotations 
    void rotateLeft(RBTreeNode* u) const {
        RBTreeNode* w = u->right;
        replaceNodeInParent(u, w);
        u->right = w->left;
        if (w->left != NIL) w->left->parent = u;
        w->left = u;
        u->parent = w;
    }
 
    void rotateRight(RBTreeNode* u) const {
        RBTreeNode* w = u->left;
        replaceNodeInParent(u, w);
        u->left = w->right;
        if (w->right != NIL) w->right->parent = u;
        w->right = u;
        u->parent = w;
    }
 
    void replaceNodeInParent(RBTreeNode* u, RBTreeNode* v) const {
        if (v != NIL) v->parent = u->parent;
        if (u->parent == NIL) {
            root = v;
        } else if (u->parent->left == u) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
    }
 
    // addFixup 
        void addFixup(RBTreeNode* u) const {
        while (u->color == RED) {
            if (u == root) {
                u->color = BLACK;
                return;
            }
            RBTreeNode* w = u->parent;
 
            if (w->left->color == BLACK) {
                flipLeft(w);
                u = w;
                w = u->parent;
            }
 
            if (w->color == BLACK) return;
 
            RBTreeNode* g = w->parent;
            if (g->right->color == BLACK) {
                flipRight(g);
                return;
            }
            pushBlack(g);
            u = g;
        }
    }
 
    // removeFixup cases 
 
    // Case 1: parent's left child is RED 
    RBTreeNode* removeFixupCase1(RBTreeNode* u) const {
        flipRight(u->parent);
        return u;
    }
 
    // Case 2: u is a LEFT child 
    RBTreeNode* removeFixupCase2(RBTreeNode* u) const {
        RBTreeNode* w = u->parent;
        RBTreeNode* v = w->right;
 
        pullBlack(w);
        flipLeft(w);
 
        RBTreeNode* q = w->right;
 
        if (q->color == RED) {
            rotateLeft(w);
            flipRight(v);
            pushBlack(q);
            if (v->right->color == RED) flipLeft(v);
            return q;
        } else {
            return v;
        }
    }
 
    // Case 3: u is a RIGHT child 
    RBTreeNode* removeFixupCase3(RBTreeNode* u) const {
        RBTreeNode* w = u->parent;
        RBTreeNode* v = w->left;
 
        pullBlack(w);
        flipRight(w);
 
        RBTreeNode* q = w->left;
 
        if (q->color == RED) {
            rotateRight(w);
            flipLeft(v);
            pushBlack(q);
            return q;
        } else {
            if (v->left->color == RED) {
                pushBlack(v);
                return v;
            } else {
                flipLeft(v);
                return w;
            }
        }
    }
 
    // removeFixup
    void removeFixup(RBTreeNode* u) const {
        while (u->color > BLACK) {
            if (u == root) {
                u->color = BLACK;
                return;
            } else if (u->parent->left->color == RED) {
                u = removeFixupCase1(u);
            } else if (u->parent->left == u) {
                u = removeFixupCase2(u);
            } else {
                u = removeFixupCase3(u);
            }
        }
        // Fix left-leaning violation (slide 35 last lines)
        if (u != root) {
            RBTreeNode* w = u->parent;
            if (w->right->color == RED && w->left->color != RED) {
                flipLeft(w);
            }
        }
    }
 
    // splice: unlinks w (at most one real child)
    void splice(RBTreeNode* w) const {
        RBTreeNode* s = (w->left != NIL) ? w->left : w->right;
        RBTreeNode* p = w->parent;
 
        if (s != NIL) s->parent = p;
        if (p == NIL) {
            root = s;
        } else if (p->left == w) {
            p->left = s;
        } else {
            p->right = s;
        }
        s->color += w->color;
        s->parent = p;
    }
 
    // Internal helpers
    void destroy(RBTreeNode* n) const {
        if (n == NIL) return;
        destroy(n->left);
        destroy(n->right);
        delete n;
    }
 
    void printNode(RBTreeNode* n, const std::string& prefix, bool isLeft) const {
        if (n == NIL) return;
        std::cout << prefix;
        std::cout << (isLeft ? "|-- " : "+-- ");
        std::cout << (n->color == RED ? "[R] " : "[B] ") << n->data << "\n";
        std::string child = prefix + (isLeft ? "|   " : "    ");
        printNode(n->left,  child, true);
        printNode(n->right, child, false);
    }
 
public:
    // Constructor / Destructor
    RedBlackTree() {
        NIL        = new RBTreeNode(T());
        NIL->color = BLACK;
        NIL->left  = NIL->right = NIL->parent = NIL;
        root       = NIL;
        nodeCount  = 0;
    }
 
    ~RedBlackTree() {
        destroy(root);
        delete NIL;
    }
 
    // SSet interface — all const to match your sSet.h
    size_t size() const override { return nodeCount; }
 
    T find(const T& x) const override {
        RBTreeNode* curr = root;
        while (curr != NIL) {
            if      (x < curr->data) curr = curr->left;
            else if (x > curr->data) curr = curr->right;
            else return curr->data;
        }
        return T();
    }
 
    void add(const T& x) const override {
        RBTreeNode* u = new RBTreeNode(x);
        u->left = u->right = u->parent = NIL;
        u->color = RED;
 
        RBTreeNode* prev = NIL;
        RBTreeNode* curr = root;
        while (curr != NIL) {
            prev = curr;
            if      (x < curr->data) curr = curr->left;
            else if (x > curr->data) curr = curr->right;
            else { delete u; return; }  // duplicate
        }
 
        u->parent = prev;
        if      (prev == NIL)    root = u;
        else if (x < prev->data) prev->left  = u;
        else                     prev->right = u;
 
        addFixup(u);
        nodeCount++;
    }
 
    T remove(const T& x) const override {
        RBTreeNode* u = root;
        while (u != NIL) {
            if      (x < u->data) u = u->left;
            else if (x > u->data) u = u->right;
            else break;
        }
        if (u == NIL) return T();
 
        T removedValue = u->data;
 
        RBTreeNode* w;
 
        if (u->right == NIL) {
            w = u;
        } else {
            w = u->right;
            while (w->left != NIL) w = w->left;
            u->data = w->data;
        }
 
        splice(w);
 
        RBTreeNode* s = (w->left != NIL) ? w->left : w->right;
        removeFixup(s);
 
        delete w;
        nodeCount--;
        return removedValue;
    }
 
    // printTree, but sideways view with [R] = red /[B] = black labels
    void printTree() const {
        if (root == NIL) {
            std::cout << "(empty tree)" << std::endl;
            return;
        }
        printNode(root, "", false);
    }
};