class PrefixTree {

public:
    PrefixTree* children[26];
    bool isLeaf;
    PrefixTree() {
        isLeaf = false;
        for(int i=0; i<26;i++)
            children[i] = nullptr;
    }
    
    void insert(string word) {
        PrefixTree* curr = this;
        for(char c:word)
        {
            if(curr->children[c -'a'] == nullptr)
            {
                PrefixTree* newNode = new PrefixTree();
                curr->children [c- 'a'] = newNode;
            }
            curr = curr->children[c -'a'];
        }
        curr->isLeaf =true;
    }
    
    bool search(string word) {
        PrefixTree * current = this;
        for(char c: word)
        {
            int index = c-'a';
            if(current->children[index] == nullptr)
                return false;
            current = current->children[index];
        }
        return current->isLeaf;  
    }
    
    bool startsWith(string prefix) {
        PrefixTree * current = this;
        for(char c: prefix)
        {
            int index = c-'a';
            if(current->children[index] == nullptr)
                return false;
            current = current->children[index];
        }
        return true;  
    }
};
