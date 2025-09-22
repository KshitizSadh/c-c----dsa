#include <iostream>
using namespace std;


class BTreeNode {
public:
    int *keys;       
    int t;          
    BTreeNode **C;  
    int n;          
    bool leaf;       

    BTreeNode(int _t, bool _leaf);

    void traverse();                     // Traverse nodes
    BTreeNode *search(int k);            // Search key in subtree

    void insertNonFull(int k);           // Insert key in non-full node
    void splitChild(int i, BTreeNode *y); // Split child y at index i

    friend class BTree;
};

class BTree {
public:
    BTreeNode *root; 
    int t;           

    BTree(int _t) {
        root = NULL;
        t = _t;
    }

    void traverse() {
        if (root != NULL) root->traverse();
    }

    BTreeNode *search(int k) {
        return (root == NULL) ? NULL : root->search(k);
    }

    void insert(int k);
};

// Constructor for BTreeNode
BTreeNode::BTreeNode(int t1, bool leaf1) {
    t = t1;
    leaf = leaf1;

    keys = new int[2 * t - 1];
    C = new BTreeNode *[2 * t];
    n = 0;
}

// Traverse all nodes in subtree
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        // If not leaf, traverse child before key
        if (leaf == false)
            C[i]->traverse();
        cout << " " << keys[i];
    }

    // Print subtree after last key
    if (leaf == false)
        C[i]->traverse();
}

// Search key in subtree rooted with this node
BTreeNode *BTreeNode::search(int k) {
    int i = 0;
    while (i < n && k > keys[i])
        i++;

    if (i < n && keys[i] == k)
        return this;

    if (leaf == true)
        return NULL;

    return C[i]->search(k);
}

// Insert key in non-full node
void BTreeNode::insertNonFull(int k) {
    int i = n - 1;

    if (leaf == true) {
        // Insert key into this node
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
        n = n + 1;
    } else {
        // Find child to insert into
        while (i >= 0 && keys[i] > k)
            i--;

        if (C[i + 1]->n == 2 * t - 1) {
            splitChild(i + 1, C[i + 1]);

            if (keys[i + 1] < k)
                i++;
        }
        C[i + 1]->insertNonFull(k);
    }
}

// Split child y of this node at index i
void BTreeNode::splitChild(int i, BTreeNode *y) {
    BTreeNode *z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;

    // Copy last (t-1) keys of y to z
    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    // Copy children if not leaf
    if (y->leaf == false) {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    y->n = t - 1;

    // Shift children of this node
    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];

    C[i + 1] = z;

    // Shift keys of this node
    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[t - 1];

    n = n + 1;
}

// Insert key into BTree
void BTree::insert(int k) {
    if (root == NULL) {
        root = new BTreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    } else {
        if (root->n == 2 * t - 1) {
            BTreeNode *s = new BTreeNode(t, false);

            s->C[0] = root;

            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->C[i]->insertNonFull(k);

            root = s;
        } else
            root->insertNonFull(k);
    }
}

// Driver code
int main() {
    int t;
    cout << "Enter minimum degree (t) of B-Tree: ";
    cin >> t;

    BTree tree(t);

    int n;
    cout << "Enter number of keys to insert: ";
    cin >> n;

    cout << "Enter keys:\n";
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        tree.insert(k);
    }

    cout << "\nTraversal of the constructed B-Tree is:\n";
    tree.traverse();

    cout << "\nEnter key to search: ";
    int key;
    cin >> key;
    if (tree.search(key) != NULL)
        cout << "Key " << key << " is found.\n";
    else
        cout << "Key " << key << " is not found.\n";

    return 0;
}
