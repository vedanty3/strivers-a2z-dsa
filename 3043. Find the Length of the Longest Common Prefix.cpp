struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char& ch) { return links[ch - '0'] != nullptr; }

    void put(char& ch, Node* node) { links[ch - '0'] = node; }

    Node* get(char& ch) { return links[ch - '0']; }

    void setEnd() { flag = true; }

    bool isEnd() { return flag; }
};

class Trie {
private:
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); ++i) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    int get_prefix_length(string &word) {
        int len = 0;
        Node* node = root;
        for (int i = 0; i < word.size(); ++i) {
            if (!node->containsKey(word[i])) {
                break;
            }
            node = node->get(word[i]);
            ++len;
        }
        return len;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size();
        int n = arr2.size();
        string s;

        Trie trie;

        for (int i = 0; i < m; ++i) {
            s = to_string(arr1[i]);
            trie.insert(s);
        }

        int max_pref_len = INT_MIN;

        for (int i = 0; i < n; ++i) {
            s = to_string(arr2[i]);
            max_pref_len = max(max_pref_len, trie.get_prefix_length(s));
        }

        return max_pref_len;
    }
};
