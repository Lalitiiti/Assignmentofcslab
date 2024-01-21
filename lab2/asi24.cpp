#include <bits/stdc++.h>
using namespace std;
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int Partition(int arr[], int l, int r)
{
	int lst = arr[r], i = l, j = l;
	while (j < r) {
		if (arr[j] < lst) {
			swap(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	swap(&arr[i], &arr[r]);
	return i;
}
int randomPartition(int arr[], int l,
					int r)
{
	int n = r - l + 1;
	int pivot = rand() % n;
	swap(&arr[l + pivot], &arr[r]);
	return Partition(arr, l, r);
}

void MedianUtil(int arr[], int l, int r,
				int k, int& a, int& b)
{
	if (l <= r) {
		int partitionIndex
			= randomPartition(arr, l, r);
		if (partitionIndex == k) {
			b = arr[partitionIndex];
			if (a != -1)
				return;
		}
		else if (partitionIndex == k - 1) {
			a = arr[partitionIndex];
			if (b != -1)
				return;
		}
		if (partitionIndex >= k)
			return MedianUtil(arr, l,
							partitionIndex - 1,
							k, a, b);
		else
			return MedianUtil(arr,
							partitionIndex + 1,
							r, k, a, b);
	}

	return;
}
void findMedian(int arr[], int n)
{
	int ans, a = -1, b = -1;
	if (n % 2 == 1) {
		MedianUtil(arr, 0, n - 1,
				n / 2, a, b);
		ans = b;
	}
	else {
		MedianUtil(arr, 0, n - 1,
				n / 2, a, b);
		ans = (a + b) / 2;
	}
	cout << "Median = " << ans;
}
int main()
{
    freopen("input24.txt","r",stdin);
    freopen("output24.txt","w",stdout);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
	findMedian(arr, n);
	return 0;
}
