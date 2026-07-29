class TrieNode{
    public:
           char data;
           unordered_map<char,TrieNode*>children;
           bool isTerminal;

           TrieNode(char val){
              data=val;
              isTerminal=false;
           }
};

void insertWord(TrieNode*root,string word){
    if(word.size()==0){
        root->isTerminal=true;
        return;
    }

    char ch=word[0];
    TrieNode*child;
    if(root->children.find(ch)!=root->children.end()){
        child=root->children[ch];
    }
    else{
        child=new TrieNode(ch);
        root->children[ch]=child;
    }
    insertWord(child,word.substr(1));
}

bool searchWord(TrieNode*root,string word){
    if(word.size()==0){
        return root->isTerminal;
    }

    char ch=word[0];
    bool matched=false;
    if(ch!='.'){
        if(root->children.find(ch)!=root->children.end()){
            matched=searchWord(root->children[ch],word.substr(1));
        }
    }
    else{
        for(auto it:root->children){
            matched=matched||searchWord(root->children[it.first],word.substr(1));
        }
    }
    return matched;
}

class WordDictionary {
public:
    TrieNode*root;
    WordDictionary() {
        root= new TrieNode('-');
    }
    
    void addWord(string word) {
        insertWord(root,word);
    }
    
    bool search(string word) {
        return searchWord(root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */