class Solution {
public:
    int findComplement(int n) {
    vector<int> vec;
    while(n!= 0)
    {
        vec.push_back(n%2);
        n=n/2;
    }
    reverse(vec.begin(),vec.end());
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i]==0){
            vec[i]=1;
        }
        else{
            vec[i]=0;
        }
    }
    long int two=1;
    for (int i=vec.size()-1;i>=0;i--) {
        n=n+vec[i]*two;
        two=two*2;
    }
    return n;
    }
};