#include <iostream>
#include <vector>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int max = root;   //Assume root is largest

   //set indices of left and right children
   int left = root * 2;
   int right = left + 1;

   // Check if left or right child > max
   if (left < n && arr[left] > arr[max])
   {
      max = left;
   }
   if (right < n && arr[right] > arr[max])
   {
      max = right;
   }
   // swap root if max is not root
   if (max != root)
   {
      swap(arr[root], arr[max]);
      heapify(arr, n, max);   // Recursively heapify
   }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   int start = (n / 2) - 1;
   for (int i = start; i >= 0; i--)
   {
      heapify(arr, n, i);
   }

   // extracting elements from heap one by one
   for (int i = n - 1; i >= 0; i--)
   {
      swap(arr[0], arr[i]);    // Move the root to the end
      heapify(arr, i, 0);  // heapify the root
   }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   vector<int> arr;
   int a;
   //add elements from user input
   cout<<"Enter -1 to complete input."<<endl;
   cout<<"Input array elements : ";
   while(cin>>a && a != -1)
   {
      arr.push_back(a);
   }

   int n = (int)arr.size();
   int heap_arr[n];
   copy(arr.begin(), arr.end(), heap_arr);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
