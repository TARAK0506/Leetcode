class Solution {
public:
    int passwordStrength(string password) {
        int n = password.length(), strength = 0;
        set<char> s;
        for (int i = 0; i < n; i++) {
            if (s.find(password[i]) != s.end())
                continue;
            else {
                s.insert(password[i]);
                if (password[i] >= 'a' && password[i] <= 'z')
                    strength += 1;
                else if (password[i] >= 'A' && password[i] <= 'Z')
                    strength += 2;
                else if (password[i] >= '0' && password[i] <= '9')
                    strength += 3;
                else
                    strength += 5;
            }
        }
        return strength;
    }
};