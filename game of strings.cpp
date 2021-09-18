/*Given a string s of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of ‘k’ characters. The value of a string is defined as the sum of squares of the count of each distinct character.
 

Example 1:

Input: s = abccc, k = 1
Output: 6
Explaination:
We remove c to get the value as 1^2 + 1^2 + 2^2*/
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        int has[26]={0};
        for(int i=0;i<s.length();i++)
            has[int(s[i]-97)]++;
        //cout<<has[1]<<endl;
        priority_queue<pair<int,char> > p;
        for(int i=0;i<26;i++){
            if(has[i]==0)
                continue;
            pair<int,char> a;
            a.first=has[i];
            a.second=char(i+97);
            p.push(a);
        }
       // cout<<p.top().second<<endl;
        for(int i=0;i<k;i++){
            pair<int,char> a=p.top();
            p.pop();
            a.first--;
            p.push(a);
        }
        int v=0;
        while(!p.empty()){
            
            v+=p.top().first*p.top().first;
            p.pop();
         //   cout<<v<<endl;
        }
        return v;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
