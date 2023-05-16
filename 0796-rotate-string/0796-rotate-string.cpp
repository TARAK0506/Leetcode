class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i=0;i<s.size();i++){
            rotate(goal.begin(),goal.begin()+1,goal.end());
            if(s==goal){
                return true;
            }
        }
        return false;
    }
};