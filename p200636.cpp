#include <iostream>
using namespace std;

void sortRowWise(int arr[][3], int r, int c)
{
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int min = j;
            for (int k = j; k < c; k++)
            {
                if (arr[i][min] > arr[i][k])
                {
                    min = k;
                }
            }
            int temp = arr[i][j];
            arr[i][j] = arr[i][min];
            arr[i][min] = temp;
        }
    }

    for (int i = 1; i < 2; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int min = j;
            for (int k = j; k < c; k++)
            {
                if (arr[i][min] < arr[i][k])
                {
                    min = k;
                }
            }
            int temp = arr[i][j];
            arr[i][j] = arr[i][min];
            arr[i][min] = temp;
        }
    }

    for (int k = 2; k < 3; k++)
    {
        int i, key, j;
        for (i = 0; i < r; i++)
        {
            key = arr[k][i];
            j = i - 1;

            while (j >= 0 && arr[k][j] > key)
            {
                arr[k][j + 1] = arr[k][j];
                j = j - 1;
            }
            arr[k][j + 1] = key;
        }
    }

    // Display code
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

// Driver code
int main()
{
    int arr[][3] = {{24, 20, 14}, {12, 90, 13}, {8, 9, 0}};
    int c = sizeof(arr[0]) / sizeof(arr[0][0]);
    int r = sizeof(arr) / sizeof(arr[0]);
    sortRowWise(arr, r, c);
    return 0;
}