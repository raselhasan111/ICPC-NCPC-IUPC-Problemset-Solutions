///-------start_template---------///
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back

using namespace std;

const ll mod = 1e9 + 7;
const ll mx = 1e9 + 7;
const ll inf = 1e9 + 7;
const ld eps = 0.0000000001;
const char nl = '\n';

// check -> lowest input, max input
// check -> overflow, out of bounds

///------end_template--------///

int main() {

    ll n, test = 1;
    while(cin >> n and n) {
        ll res = 0;
        for(ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            if(x == 0) res--;
            else res++;
        }N

        cout << "Case " << test++ << ": " << res << nl;
    }

    return 0;
}








