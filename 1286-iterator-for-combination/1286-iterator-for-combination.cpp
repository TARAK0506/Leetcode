class CombinationIterator {
    string s;
    int targetLen;
    vector<string> curr;
    vector<string>::iterator itr;

    function<void(int, int, string, string)> dfs = [&](int idx, int targetLen, string path, string s) {
        if(path.length() == targetLen){
            curr.emplace_back(path);
            return ;
        }
        for(int i = idx; i < s.length(); i++){
            dfs(i + 1, targetLen, path + s[i], s);
        }
    };

public : CombinationIterator(string characters, int combinationLength) {
        this->s = characters;
        this->targetLen = combinationLength;
        dfs(0, targetLen, "", s);
        itr = curr.begin();
    }
    string next() {
        return *itr++;
    }
    bool hasNext() {
        return itr != curr.end();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters,
 * combinationLength); string param_1 = obj->next(); bool param_2 =
 * obj->hasNext();
 */