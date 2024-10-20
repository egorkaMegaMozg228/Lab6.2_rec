#include <iostream>
#include <iomanip>

using namespace std;

void create(int* arr, int size, int Min = -20, int Max = 30, int i = 0)
{


    if (i < size)
    {
        arr[i] = Min + rand() % (Max - Min + 1);
        i++;
        create(arr, size, Min, Max, i);
    }
}

void Print(int* arr, int size, int i = 0)
{
    if (i < size) {
        cout << setw(4) << arr[i];
        i++;
        Print(arr, size, i);
    }

}

int Sum(int* arr, const int size) // рекурсивний спосіб
{
    if (size < 0)
        return 0;
    else if (arr[size] % 2 == 0)
        return arr[size] + Sum(arr, size - 1);
    else Sum(arr, size - 1);
}
int Count(int* arr, int size, int count = 0)
{

    if (size < 0)
        return 0;
    else if (arr[size] % 2 == 0)
        return 1 + Count(arr, size - 1, count + 1);
    else Count(arr, size - 1, count);
}

void updateArray(int* arr, int size, int i = 0)
{
    if (i < size)
    {
        if (arr[i] % 2 != 0)
        {
            arr[i] = 0;
            updateArray(arr, size, i + 1);
        }
        else updateArray(arr, size, i + 1);
    }
}


int main()
{
    srand((unsigned)time(NULL));
    int n;
    cout << "n = "; cin >> n;
    cout << endl;
    const int size = n;
    int* arr = new int[size];;
    create(arr, size);
    Print(arr, size);
    cout << endl;
    cout << "count = " << Count(arr, n) << endl;
    cout << "avg = " << 1. * Sum(arr, size)/Count(arr,size) << endl;
    updateArray(arr, size);
    Print(arr, size);
    return 0;
}