class WordDictionary {
public:
    /*
     * @param word: Adds a word into the data structure.
     * @return: nothing
     */
    class TrieNode{
    public:
        #define MAX 256
        int count;
        class TrieNode *symbol[MAX];
        TrieNode(){
            this->count = 0;
            for(int i=0; i<MAX; i++)
                symbol[i] = NULL;
        }
    };
    class TrieNode *root;
    WordDictionary(){
        root = new TrieNode();
    }
    
    void addWord(string &word) {
        // write your code here
        if(word.size()==0)
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
    
    bool search_dfs(string word, class TrieNode *root)
    {
        if(word.size()==0 && root->count>0)
            return true;
        for(int i=0; i<word.size(); i++)
        {
            if(word[i] == '.')
            {
                for(int j=0; j<MAX; j++)
                {
                    if(root->symbol[j] != NULL && search_dfs(word.substr(i+1), root->symbol[j]))
                        return true;
                }
                return false;
            }
            else
            {
                int idx = word[i];
                if(root->symbol[idx] == NULL)
                    return false;
                root = root->symbol[idx];
            }
        }
        if(root->count > 0)
            return true;
        return false;
    }


    /*
     * @param word: A word could contain the dot character '.' to represent any one letter.
     * @return: if the word is in the data structure.
     */
    bool search(string &word) {
        // write your code here
        return search_dfs(word, root);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");