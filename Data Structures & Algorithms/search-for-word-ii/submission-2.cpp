class TrieNode{
public:
    TrieNode* children[26];
    string word;

    TrieNode(){
        word = "";
        for(int i=0;i<26;i++)
            children[i] = nullptr;
    }
};

class Solution {
public:
    vector<string> ans;
    int rows, cols;

    void insert(TrieNode* root, string word){
        TrieNode* curr = root;

        for(char c: word){
            int idx = c - 'a';

            if(curr->children[idx] == nullptr)
                curr->children[idx] = new TrieNode();

            curr = curr->children[idx];
        }

        curr->word = word;
    }
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node){

        if(r<0 || c<0 || r>=rows || c>=cols || board[r][c]=='#')
            return;

        char ch = board[r][c];

        if(node->children[ch-'a'] == nullptr)
            return;

        node = node->children[ch-'a'];

        if(node->word != ""){
            ans.push_back(node->word);
            node->word = ""; // avoid duplicates
        }

        board[r][c] = '#';

        dfs(board,r+1,c,node);
        dfs(board,r-1,c,node);
        dfs(board,r,c+1,node);
        dfs(board,r,c-1,node);

        board[r][c] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        rows = board.size();
        cols = board[0].size();

        TrieNode* root = new TrieNode();

        for(string word: words)
            insert(root, word);

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                dfs(board,i,j,root);
            }
        }

        return ans;
    }
};
