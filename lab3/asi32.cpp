#include<bits/stdc++.h>
using namespace std;
int maxCrossingSum(const vector<int>& arr, int low, int mid, int high) {
    int leftSum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; --i) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }
    int rightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; ++i) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }
    return leftSum + rightSum;
}
int maxSubArraySum(const vector<int>& arr, int low, int high) {
    if (low == high) {
        return arr[low];
    }
    int mid = (low + high) / 2;
    return max({
        maxSubArraySum(arr, low, mid),
        maxSubArraySum(arr, mid + 1, high),
        maxCrossingSum(arr, low, mid, high)
    });
}
int main() {
     freopen("input32.txt","r",stdin);
    freopen("output32.txt","w",stdout);
     vector<int> numbers;
    int n;
    cin>>n;
    int a;
    for(int i=0;i<n;i++)cin>>a,numbers.push_back(a);
    int result = maxSubArraySum(numbers,0,n-1);
    cout << "The largest possible sum of a subsequence is: " << result << endl;
    return 0;
}
