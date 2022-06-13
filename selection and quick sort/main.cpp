#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <time.h>
using namespace std;

class TestSorting
{
private:
    int size;
    int*array;
public:
    TestSorting (){}
    TestSorting (int s)
    {
        size=s;
        array = new int [size];
    }
    void GenerateRandomList(int min, int max)
    {
        int low = min, up = max-1, random_number;

        for(int i=0; i<size; i++)
        {
            random_number = (rand() % up) + low;
            array[i] = random_number;
        }
    }
    void SelectionSort()
    {
        int i, j, min_index;
        for (i=0; i<size-1; i++)
        {
            min_index = i;
            for (j = i+1; j<size; j++)
            {
                if (array[j] < array[min_index]) {
                    min_index = j;
                }
            }
            swap( array[min_index], array[i] );
        }
    }
    int partition (int left, int right)
    {
        int pivot = array[right];
        int i = (left - 1);
        for (int j = left; j <= right - 1; j++)
        {
            if (array[j] < pivot)
            {
                i++;
                swap( array[i], array[j] );
            }
        }
        swap( array[i + 1], array[right] );
        return (i + 1);
    }
    void QuickSort(int left, int right)
    {
        if (left < right)
        {
            int pi = partition(left, right);
            QuickSort(left, pi - 1);
            QuickSort(pi + 1, right);
        }
    }
    double RunOnce(int sorter)
    {
        if(sorter==1)
        {
            float start = clock();
            SelectionSort();
            float finish = clock();
            double totaltime = (float)finish -(float) start/1000000;
            cout << "Time taken by function: " << totaltime/CLOCKS_PER_SEC << " microseconds" << endl;
            return totaltime/CLOCKS_PER_SEC;
        }
        else if(sorter==2)
        {
            float start = clock();
            QuickSort(0,size-1);
            float finish = clock();
            double totaltime = (float)finish -(float) start/1000000;
            cout << "Time taken by function: " << totaltime/CLOCKS_PER_SEC<< " microseconds" << endl;
            return totaltime/CLOCKS_PER_SEC;
        }
    }
    double RunAndAverage(int sorter,int min,int max,int size)
    {
        double k;
        k=this->RunOnce(sorter);
        cout<<*this<<endl;
        cout<<"---------------------------------------------"<<endl;
        return k;
    }
    void sorting(int min,int max,int size,int sets_num)
    {
        double sum=0.0,ava=0.0;
        for(int i=0; i<sets_num; i++){
            int l=0;
        GenerateRandomList(min,max);
        cout<<*this<<endl;
        cout<<"enter 1 if you want Selection sort"<<endl;
        cout<<"enter 2 if you want Quick sort"<<endl;
        cin>>l;
        sum+=RunAndAverage(l,min,max,size);
        }
        ava=sum/sets_num;
        cout<<"avarage of sets = "<<ava<<endl;
    }
    friend ostream&operator<<(ostream&print,TestSorting&list)
    {
        for(int i=0; i<list.size; i++){
             print<<list.array[i]<<"  ";
        }
        return print;
    }
};

int main()
{
    int s,mn,mx,num;
    cout<<"enter the sets num"<<endl;
    cin>>num;
    cout<<"enter the size"<<endl;
    cin>>s;
    TestSorting sort(s);
    cout<<"enter the min"<<endl;
    cin>>mn;
    cout<<"enter the max"<<endl;
    cin>>mx;
    cout<<"---------------------------------------------"<<endl;
    sort.sorting(mn,mx,s,num);
    return 0;
}
