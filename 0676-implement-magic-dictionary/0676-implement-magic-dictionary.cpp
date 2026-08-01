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

bool searchWordcall(TrieNode*root,string word,bool mismatch){
    if(word.size()==0){
       return mismatch && root->isTerminal;
    }

    char ch=word[0];
    if(root->children.find(ch)!=root->children.end()){
        //match till u can
        if(searchWordcall(root->children[ch],word.substr(1),mismatch)){
            return true;
        }
    }

    //1 char mismatch
    if(mismatch==false){
        for(auto&[childChar,childNode]:root->children){
            if(ch==childChar)continue;
            if(searchWordcall(childNode,word.substr(1),true)){
                return true;
            }
        }
    }
    return false;
}

class MagicDictionary {
public:
    TrieNode*root;
    MagicDictionary() {
       root=new TrieNode('-'); 
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto&word:dictionary){
            insertWord(root,word);
        }
    }
    
    bool search(string searchWord) {
        return searchWordcall(root,searchWord,false);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */