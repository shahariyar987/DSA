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

    bool deleteHelper(TrieNode* node,
                      const string& word,
                      int depth) {
        if (node == nullptr)
            return false;

        if (depth == (int)word.length()) {
            if (!node->isEnd)
                return false;

            node->isEnd = false;

            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr)
                    return false;
            }

            return true;
        }

        int index = word[depth] - 'a';

        if (node->children[index] == nullptr)
            return false;

        bool shouldDelete =
            deleteHelper(node->children[index],
                         word, depth + 1);

        if (shouldDelete) {
            delete node->children[index];
            node->children[index] = nullptr;

            if (!node->isEnd) {
                for (int i = 0; i < 26; i++) {
                    if (node->children[i] != nullptr)
                        return false;
                }
                return true;
            }
        }

        return false;
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

    void remove(const string& word) {
        deleteHelper(root, word, 0);
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

    string word;
    cout << "Enter word to delete: ";
    cin >> word;

    if (!trie.search(word)) {
        cout << "Word does not exist.\n";
    } else {
        trie.remove(word);

        if (!trie.search(word))
            cout << "Word deleted successfully.\n";
    }

    return 0;
}
