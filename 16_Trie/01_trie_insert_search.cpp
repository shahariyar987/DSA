#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* current = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (current->children[index] == nullptr)
                current->children[index] = new TrieNode();

            current = current->children[index];
        }

        current->isEnd = true;
    }

    bool search(const string& word) {
        TrieNode* current = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (current->children[index] == nullptr)
                return false;

            current = current->children[index];
        }

        return current->isEnd;
    }
};

int main() {
    Trie trie;
    int n;

    cout << "Enter number of words: ";
    cin >> n;

    cout << "Enter lowercase words:\n";

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        trie.insert(word);
    }

    int queries;
    cout << "Enter number of search queries: ";
    cin >> queries;

    while (queries--) {
        string word;
        cout << "Search word: ";
        cin >> word;

        if (trie.search(word))
            cout << "Found\n";
        else
            cout << "Not found\n";
    }

    return 0;
}
