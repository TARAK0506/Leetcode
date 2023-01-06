class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
       //sort(arr.rbegin(),arr.rend());
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr.size();j++)
            {
                if(i!=j && arr[i]==2*arr[j])
                {
                    return true;
                }
            }
        }
        return false;
    }
};