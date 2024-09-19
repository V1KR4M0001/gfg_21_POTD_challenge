// Given a String str, reverse the string without reversing its individual words. Words are separated by dots.
// Note: The last character has not been '.'. 


// Examples :
// Input: str = i.like.this.program.very.much
// Output: much.very.program.this.like.i
// Explanation: After reversing the whole string(not individual words), the input string becomes much.very.program.this.like.i

// Input: str = pqr.mno
// Output: mno.pqr
// Explanation: After reversing the whole string , the input string becomes mno.pqr


// Expected Time Complexity: O(|str|)
// Expected Auxiliary Space: O(|str|)


// Constraints:
// 1 <= |str| <= 105


//   Solution:=>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string reverseWords(string str) {
        vector<string> v;
        string word = "";
        for(int i = 0; i < str.size(); i++) {
            if(str[i] != '.') word += str[i];
            else {
                v.push_back(word);
                word = "";
            }
        }
        v.push_back(word);
        
        string ans = "";
        for(int i = v.size()-1; i >= 0; i--) {
            ans += v[i];
            if(i != 0) ans += ".";
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
