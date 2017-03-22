#include<bits/stdc++.h>

using namespace std;

#define INF 10e9

void print_heap(int arr[],int n)
{
	for(int i=0;i<=log2(n) && i<=n;i++)
	{
		for(int j = (1<<i); j < (1<<(i+1)) && j<=n;j++)
			cout<<arr[j]<<" ";
		cout<<"\n";
	}
}
void heapify(int arr[],int i,int n)
{
	int left = (2*i) , right = 2*i+1; // Index of Left and Right Child
	int largest = i; //Initialize Parent as largest.
	if( left <= n && arr[left] > arr[i]) // Check Existence of Left Child
										 // and whether it is larger
		largest = left;
	if( right<= n && arr[right] > arr[largest] ) //Check Exitence of Right CHild
											     // Compare it with larger of left or parent
		largest = right;
	if( largest != i) // if largest value is not in parent, then swap it with largest.
	{
		swap(arr[i],arr[largest]);
		heapify(arr,largest,n);
	}
	return;
}

void build_heap(int arr[],int size)
{
	for(int i = (size/2); i>=1; i--)
		heapify(arr,i,size);
	return;
}

int main()
{
	int n;
	cin>>n;
	int arr[n+1];
	//arr[0]=INF;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	build_heap(arr,n);
	cout<<"\nHeap\n\n";
	print_heap(arr,n);
	return 0;
}