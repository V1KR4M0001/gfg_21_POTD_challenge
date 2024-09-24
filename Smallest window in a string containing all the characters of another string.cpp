// Given two strings s and p. Find the smallest window in the string s consisting of all the characters(including duplicates) of the string p.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index.
// Note : All characters are in Lowercase alphabets. 


// Examples:
// Input: s = "timetopractice", p = "toc"
// Output: toprac
// Explanation: "toprac" is the smallest substring in which "toc" can be found.

// Input: s = "zoomlazapzo", p = "oza"
// Output: apzo
// Explanation: "apzo" is the smallest  substring in which "oza" can be found.


// Expected Time Complexity: O(|s|)
// Expected Auxiliary Space: O(n), n = len(p)


// Constraints: 
// 1 ≤ |s|, |p| ≤ 105

//   Solution:=>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        if(p.length() > s.length()) return "-1";
        int n=s.length(), m=p.length(), start = -1, end = -1, len = INT_MAX, c = 0, c2 = 0, j = 0;
        vector<int> forS(26,0), forP(26,0);
        for(int i = 0; i < m; i++){
            forP[p[i] - 'a']++;
            if(forP[p[i] - 'a'] == 1) c++;
        }
        for(int i = 0; i < n; i++) {
            forS[s[i] - 'a']++;
            if(forS[s[i] - 'a'] == forP[s[i] - 'a']) c2++;
            if(c2 == c) {
                while(forS[s[j] - 'a'] > forP[s[j] - 'a']) forS[s[j++] - 'a']--;
                if(len > i-j+1) {
                    start = j;
                    end = i;
                    len = i-j+1;
                }
            }
        }
        if(start == -1) return "-1";
        return s.substr(start, len);
    }
};

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
