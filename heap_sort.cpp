#include <iostream>
#include <algorithm>

using namespace std;
template<class T> void heapify(T *arr, int currentIndex, int maxIndex)
{
	int leftIndex = 2*currentIndex + 1, rightIndex = 2*currentIndex + 2, maxValIndex = currentIndex;

	if(leftIndex < maxIndex && arr[leftIndex] > arr[maxValIndex]) maxValIndex = leftIndex;
	if(rightIndex < maxIndex && arr[rightIndex] > arr[maxValIndex]) maxValIndex = rightIndex;
	
	if(currentIndex != maxValIndex)
	{
		swap(arr[currentIndex], arr[maxValIndex]);
		heapify<T>(arr, maxValIndex, maxIndex);
	}
}



template<class T,size_t N> void heapSort(T (&arr)[N])
{
	// 1. Build heap
	for(int index = N/2-1; index >=0; --index) heapify<T>(arr, index, N);

	//print 
	cout << "after build heap: " << endl;
	for(int index = 0; index < N; ++index) cout << arr[index] << "    "; cout << endl;

	// 2. sort
	for(int index = N-1; index >0; --index)
	{
		swap(arr[0], arr[index]);
		heapify<T>(arr, 0, index);

	}

	//print
	cout << "after heap sort: " << endl;
        for(int index = 0; index < N; ++index) cout << arr[index] << "    "; cout << endl;
}

int main()
{
	int arr[] { 9, 1, 7, 3, 2, 8, 6, 4, 5, 0 };
	for(int index = 0; index < 10; ++index) cout << arr[index] << "    "; cout << endl;
	heapSort(arr);
}
