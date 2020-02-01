#include <iostream>
using namespace std;

bool needsSorting( int arr[] , int SIZE, int i )
{
    bool status = false;
    int start = 0;
    
    for(int i = start; i < SIZE; i++){
        for(int k = start + 1; k <= SIZE; k++){
            if(arr[i] > arr[k])
                status = true;
            else
                status = false;
        }
    }
    return status;
}

int main()
{
    const int SIZE = 7;
    int arr[SIZE] = { 4, 6, 9, 2, 1, 3, 7 };
    int i = 0;

        if (needsSorting(arr, SIZE, i) == 0)
            cout << "Needs sorting" << endl; 
        else 
            cout << "No sorting needed" << endl;  
}

// if (arr[i] < arr[k])
     //     status = false;
//cout << needsSorting(arr, SIZE, i) << endl;
//{4, 6, 9, 2, 1, 3, 7}