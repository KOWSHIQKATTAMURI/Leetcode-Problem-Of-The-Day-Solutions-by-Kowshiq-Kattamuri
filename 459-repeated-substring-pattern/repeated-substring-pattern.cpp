class Solution {
public:
    bool repeatedSubstringPattern(string s){
        cout << s + s << endl;
        cout << (s + s).substr(1, 2*s.length() - 2) << endl; 
        return (s + s).substr(1, 2*s.length() - 2).find(s) != string :: npos;
    }
};
   