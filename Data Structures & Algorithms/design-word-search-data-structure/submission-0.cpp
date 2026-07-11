class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {

        for (int i = 0; i < 26; i++)
            children[i] = nullptr;

        isEnd = false;
    }
};

class WordDictionary {
public:

    TrieNode* root;

    WordDictionary() {

        root = new TrieNode();
    }

    void addWord(string word) {

        TrieNode* curr = root;

        for (char ch : word) {

            int index = ch - 'a';

            if (curr->children[index] == nullptr)
                curr->children[index] = new TrieNode();

            curr = curr->children[index];
        }

        curr->isEnd = true;
    }

    bool dfs(string &word, int pos, TrieNode* node) {

        if (node == nullptr)
            return false;

        if (pos == word.size())
            return node->isEnd;

        char ch = word[pos];

        if (ch == '.') {

            for (int i = 0; i < 26; i++) {

                if (dfs(word, pos + 1, node->children[i]))
                    return true;
            }

            return false;
        }

        return dfs(word, pos + 1, node->children[ch - 'a']);
    }

    bool search(string word) {

        return dfs(word, 0, root);
    }
};