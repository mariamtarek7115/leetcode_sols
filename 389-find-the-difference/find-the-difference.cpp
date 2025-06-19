
class Solution {
public:
    char findTheDifference(string s, string t) {
        int tLength = t.length();
        int sLnegth = s.length();
        char result='0';
        if (tLength == 1) {
            result = t[0];
        }
        for (int i = 0; i < tLength; i++) {
            bool found = false;
            for (int j = 0; j < sLnegth; j++) {
                if (t[i] == s[j]) {
                    s[j]='*';
                    found = true;
                    break;
                }
            }
            if (!found) {
                result = t[i];
                break;
            }
        }

        return result;
    }
};