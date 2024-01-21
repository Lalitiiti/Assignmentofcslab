#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& A,int k, int m, int n) {
    int j = m+1;
    int i=k;
    while (i <j && j <= n) {
        if (A[i] <= A[j]) {
            i++;
        } else {
            int temp = A[j];
            for (int k = j; k > i; k--) {
                A[k] = A[k - 1];
            }
            A[i] = temp;
            i++;
            j++;
        }
    }
}

void mergeSort(vector<int>& A, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}
int main() {
    freopen("input23.txt","r",stdin);
    freopen("output23.txt","w",stdout);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    mergeSort(v, 0, n - 1);
    for (int num : v) {
        cout << num << " ";
    }

    return 0;
}
