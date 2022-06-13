#include <iostream>
using namespace std;

void insertionSort (int arr[],int n)
{
    int counter=0,i,key,j;
    for (i=1; i<n; i++)
    {
        key=arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            counter++;
        }
        arr[j + 1] = key;
    }
    cout<<"number of comparisons is : "<<counter<<endl;
}

void selectionSort(int arr[],int n)
{
    int counter=0, i, j, min_idx;
    for (i=0; i<n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j<n; j++)
        {
            if (arr[j] < arr[min_idx]){
                min_idx = j;
                counter++;
            }
        }
        swap( arr[min_idx], arr[i] );
    }
    cout<<"number of comparisons is : "<<counter<<endl;
}

int main()
{
    int n;
    cout<<"enter array length"<<endl;
    cin>>n;
    int array[n];
    cout<<"enter array elements"<<endl;
    for (int i=0;i<n;i++){
        cin>>array[i];
    }
    int choose;
    cout<<"enter 1 if you want Insertion Sort "<<endl;
    cout<<"enter 2 if you want Selection Sort "<<endl;
    cin>>choose;
    if (choose==1){
        insertionSort(array,n);
        for (int i=0;i<n;i++){
            cout<<array[i]<<" ";
        }
    }
    if (choose==2){
        selectionSort(array,n);
        for (int i=0;i<n;i++){
            cout<<array[i]<<" ";
        }
    }
    return 0;
}
