#include <iostream>
#include <map>
#include <string>
using namespace std;

// Node of the Suffix Trie
class TrieNode {
public:
    map<char, TrieNode*> children;
    bool isEnd;  // marks end of a suffix

    TrieNode() {
        isEnd = false;
    }
};

// Suffix Trie Class
class SuffixTrie {
private:
    TrieNode *root;

public:
    SuffixTrie() {
        root = new TrieNode();
    }

    // Insert a suffix into the trie
    void insertSuffix(const string &suffix) {
        TrieNode *node = root;
        for (char c : suffix) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEnd = true; // mark the end of this suffix
    }

    // Build the suffix trie from the entire text
    void buildSuffixTrie(const string &text) {
        for (size_t i = 0; i < text.length(); i++) {
            insertSuffix(text.substr(i));
        }
    }

    // Search for a pattern in the text using the suffix trie
    bool search(const string &pattern) {
        TrieNode *node = root;
        for (char c : pattern) {
            if (node->children.find(c) == node->children.end())
                return false;
            node = node->children[c];
        }
        return true; // pattern found as a prefix of some suffix
    }
};

// Driver Code
int main() {
    string text;
    cout << "Enter text: ";
    cin >> text;

    // Add a unique terminator to ensure all suffixes end distinctly
    if (text.back() != '$')
        text += '$';

    SuffixTrie trie;
    trie.buildSuffixTrie(text);

    string pattern;
    cout << "Enter pattern to search: ";
    cin >> pattern;

    if (trie.search(pattern))
        cout << "Pattern \"" << pattern << "\" found in text." << endl;
    else
        cout << "Pattern \"" << pattern << "\" NOT found in text." << endl;

    return 0;
}
