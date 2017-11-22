/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */

class TrieNode {
public:
    // Initialize your data structure here.
    #define MAX 256
    int count;
    class TrieNode *symbol[MAX];
    TrieNode() {
        this->count = 0;
        for(int i=0; i<MAX; i++)
            this->symbol[i] = NULL;
    }
};

class Trie {
public:
    class TrieNode *root;
    Trie() {
        // do intialization if necessary
        root = new TrieNode();
    }

    /*
     * @param word: a word
     * @return: nothing
     */
    void insert(string &word) {
        // write your code here
        if(word.size() == 0)
            return;
        class TrieNode *p = root;
        for(int i=0; i<word.size(); i++)
        {
            int idx = word[i];
            if(p->symbol[idx] == NULL)
                p->symbol[idx] = new TrieNode();
            p = p->symbol[idx];
        }
        p->count++;
    }

    /*
     * @param word: A string
     * @return: if the word is in the trie.
     */
    bool search(string &word) {
        // write your code here
        if(word.size() == 0)
            return true;
        class TrieNode *p = root;
        for(int i=0; i<word.size(); i++)
        {
            int idx = word[i];
            if(p->symbol[idx] == NULL)
                return false;
            p = p->symbol[idx];
        }
        if(p->count > 0)
            return true;
        return false;
    }

    /*
     * @param prefix: A string
     * @return: if there is any word in the trie that starts with the given prefix.
     */
    bool startsWith(string &prefix) {
        // write your code here
        if(prefix.size() == 0)
            return true;
        class TrieNode *p = root;
        for(int i=0; i<prefix.size(); i++)
        {
            int idx = prefix[i];
            if(p->symbol[idx] == NULL)
                return false;
            p = p->symbol[idx];
        }
        return true;
    }
};