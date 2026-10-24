class TrieNode{
    public:
    char data;
    TrieNode*child[26];
    bool isEnd;

    TrieNode(char ch){
        this->data = ch;
        for(int i = 0; i<26; i++){
            child[i] = nullptr;
        }
        this->isEnd = false;
    }
};

class Trie {
public:
    TrieNode*root;
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) {
        TrieNode*temp = root;
        for(int i = 0; i<word.size(); i++){
            char ch = word[i];
            if(temp->child[ch-'a'] == NULL){
                temp->child[ch - 'a'] = new TrieNode(ch);
            }
            temp = temp->child[ch - 'a'];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode*temp = root;
        for(char ch:word){
            if(temp->child[ch-'a'] == NULL){
                return false;
            }
            temp = temp->child[ch - 'a'];
        }
        if(temp->isEnd){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode*temp = root;
        for(char ch:prefix){
             if(temp->child[ch-'a'] == NULL){
                return false;
            }
            temp = temp->child[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */