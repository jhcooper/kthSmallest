#include <iostream>
using namespace std;
//helper function to swap values in an array
void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}
//partition sorts all elements smaller than pivot to the left and all elements larger to the right
int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
//finds the kth smallest element in an array
void kthSmallest(int arr[], int low, int high, int k){
	if (low < high) { //make sure the bounds are valid
		int pi = partition(arr, low, high); //partitioning index
		if (k < pi){ //if there are more than k values smaller than pivot, sort the smaller values
			kthSmallest(arr, low, pi - 1,k);
		}
		if (k > pi){ //if there are less than k values smaller than pivot, sort the larger values
			kthSmallest(arr, pi + 1, high,k);
		}
		//otherwise, k = pi
	}
}
int main(){
	int arr[] = {92,12,1,5,46,17,19,22,7,13,15,13,7,14,47,55,58};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k;
	cout << "Enter k: \n";
	cin >> k;
	kthSmallest(arr, 0, n - 1, k-1);
	cout << "\n kth smallest: " << arr[k-1] << endl;
    	return 0;
}
