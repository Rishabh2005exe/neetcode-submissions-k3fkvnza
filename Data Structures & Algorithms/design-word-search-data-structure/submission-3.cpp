class WordDictionary {
    WordDictionary* children[26];
    bool isLeaf;
public:
    WordDictionary() {
        isLeaf = false;
        for(int i=0;i<26;i++)
            children[i] = nullptr;
    }
    void addWord(string word) {
        WordDictionary* curr = this;
        for(char c:word)
        {
            int idx = c -'a';
            if(curr->children[idx] == nullptr)
            {
                WordDictionary* newNode = new WordDictionary();
                curr->children[c-'a'] = newNode;
            }
            curr = curr->children[c-'a'];
        }
        curr->isLeaf = true;
    }
    bool dfs(string word, int pos,WordDictionary* node)
    {
        if(pos == word.size())
            return node->isLeaf;
        char c = word[pos];
        if(c == '.')
        {
            for(int i=0;i<26;i++){
                if(node->children[i] && dfs(word,pos+1 ,node->children[i]))
                    return true;
            }
            return false;
        }
        int idx = c - 'a';
        if(node->children[idx] == nullptr)
            return false;
        return dfs(word , pos+1 , node->children[idx]);
    }
    
    bool search(string word) {
        return dfs(word ,0,this);
    }
};
