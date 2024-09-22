// Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.
// NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.


// Examples :
// Input: str = "abab"
// Output: 2
// Explanation: "ab" is the longest proper prefix and suffix. 

// Input: str = "aaaa"
// Output: 3
// Explanation: "aaa" is the longest proper prefix and suffix. 


// Expected Time Complexity: O(|str|)
// Expected Auxiliary Space: O(|str|)


// Constraints:
// 1 ≤ |str| ≤ 106
// str contains lower case English alphabets


//   Solution:=>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int lps(string str) {
        // Your code goes here
        int n = str.length();
        int p = 0, s = 1, pos = 1, count = 0;
        while(p<n && s<n) {
            if(str[p] == str[s]) {
                p++;
                s++;
                count++;
            } else {
                p = 0;
                pos++;
                s = pos;
                count = 0;
            }
        }
        return count; 
    }
};

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.lps(str) << "\n";
    }

    return 0;
}
