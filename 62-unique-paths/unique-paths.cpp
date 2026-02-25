#define ll long long
class Solution {
public:
    ll nCr(ll n, ll r){
        ll ans=1;
        for(ll i=1; i<=r; i++){
            ans = (ans*n--) / i;  
        }
        return ans;
    }

    int uniquePaths(int m, int n) {
        m = m-1,n=n-1;
        return nCr(m+n,  min(m,n) );
    }
};