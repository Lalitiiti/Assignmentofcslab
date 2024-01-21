#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& A, int m, int n) {
    int i = 0, j = m;
    while (i < j && j < n) {
        if (A[i] <= A[j]) {
            i++;
        } 
        else {
            int temp = A[j];
            for (int k = j; k > i; k--) {
                A[k] = A[k - 1];
            }
            A[i] = temp;
            j++;
        }
    }
}

int main() {
    freopen("input22.txt","r",stdin);
    freopen("output22.txt","w",stdout);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    merge(v, m, n);
    for (int num : v) {
        cout << num << " ";
    }
    return 0;
}