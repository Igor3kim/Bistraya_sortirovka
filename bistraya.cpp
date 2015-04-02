#include <iostream>
#include <ctime>

using namespace std;

void Input_array(int arr[], int size)
{
	for(int i=0; i < size; i++)
		arr[i]=10-rand() % 20;
}
void Output_array(int arr[], int size)
{
	for(int i=0; i< size; i++)
		cout << arr[i] << " ";
	cout<<endl;
}

void q_sort(int s_arr[], int first, int last)
{
	int i = first, j = last, x = s_arr[(first + last) / 2];
	do {
		while (s_arr[i] < x) i++;
		while (s_arr[j] > x) j--;
		if(i <=j) {
			if(i < j) swap(s_arr[i], s_arr[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (i < last)
		q_sort(s_arr, i, last);
	if (first < j)
		q_sort(s_arr, first, j);
}

int main()
{setlocale(LC_ALL,"Rus");
	srand(time(NULL));
	const int size = 10;
	int arr[size];
	cout<<"======================================"<<endl;
	Input_array(arr, size);
	Output_array(arr,size);
	cout << "Q_Sort" << endl;
	q_sort(arr,0,size-1);
	Output_array(arr,size);
	cout<<"======================================"<<endl;
	return 0;
}
