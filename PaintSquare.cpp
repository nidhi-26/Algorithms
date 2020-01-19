#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int paint(int n, string s) {
	int ans = -1;
	int dp[n][2], i, j;
		
    if (s[0] == '1') {
		dp[0][0] = 1;
        dp[0][1] = 0;
    } else {
    	dp[0][0] = 0;
        dp[0][1] = 1;
    }
    
    for (i=1; i<s.length(); i++) {
    	if (s[i] == '1') {
    	    dp[i][1] = dp[i-1][0];
            dp[i][0] = 1 + dp[i-1][1];
        } else {
    		dp[i][0] = dp[i-1][1];
      	    dp[i][1] = 1 + dp[i-1][0];
        }
    }
    
    ans = min(dp[n-1][0], dp[n-1][1]);

    return ans;
}


int main() {
  
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        cout<<paint(n, s)<<endl;
    }
	
	return 0;
}
