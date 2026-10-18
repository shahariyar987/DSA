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

    void collectWords(TrieNode* node, string current) {
        if (node->isEnd)
            cout << current << "\n";

        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr)
                collectWords(node->children[i],
                             current + char('a' + i));
        }
    }

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

    void searchPrefix(const string& prefix) {
        TrieNode* current = root;

        for (char ch : prefix) {
            int index = ch - 'a';

            if (current->children[index] == nullptr) {
                cout << "No words found with this prefix.\n";
                return;
            }

            current = current->children[index];
        }

        cout << "Words with prefix \"" << prefix << "\":\n";
        collectWords(current, prefix);
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

    string prefix;
    cout << "Enter prefix: ";
    cin >> prefix;

    trie.searchPrefix(prefix);

    return 0;
}
