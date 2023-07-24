class Solution {
public:
    int isvowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
            return 1;
        }
        return 0;
}
    string sortVowels(string s) {
        vector<char>vowels;
        for(auto it:s){
            if(isvowel(it)){
                vowels.emplace_back(it);
            }
        }
        sort(vowels.begin(),vowels.end());
        string t=s;
        int n=vowels.size();
        int j=0;
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])){
                t[i]=vowels[j++];
            }
        }
        // for(auto it:vowels){
        //     cout<<it<<" ";
        // }
        return t;
    }
};