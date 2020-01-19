#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string replace(string s, vector<char> firstSub, vector<char> secondSub) {
    string st = s;
    int i, j;
    int k = 0;
    for (i = 0; i < firstSub.size(); i++) {
        for (k = 0; k < st.length(); k++) {
            if (st[k] == firstSub[i]) {
                st[k] = secondSub[i];
            } else if (st[k] == secondSub[i]){
                st[k] = firstSub[i];
            }
        }
    }
    
    return st;
}


int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, i;
        string s;
        cin>>s;
        cin>>n;
        vector<char> fSub, sSub;
        char c;
        for (i=0; i<n; i++) {
            cin>>c;
            fSub.push_back(c);
        }
        for (i=0; i<n; i++) {
            cin>>c;
            sSub.push_back(c);
        }
        cout<<replace(s, fSub, sSub)<<endl;
    }
    
	return 0;
}
