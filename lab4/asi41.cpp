#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("input41.txt","r",stdin);
    freopen("output41.txt","w",stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    set<int> s;
    int count = 0;
    for (int i = 0; i < n; i++) {
        auto p = s.lower_bound(a[i]);
        count += distance(p, s.end());
        s.insert(a[i]);
    }
    cout << count << endl;
    return 0;
}
