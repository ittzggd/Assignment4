#include "LargestNumberSolver.h"

// int main()
// {
//     vector<vector<int>> test = {{88, 51}, {7, 42, 97}};
//     vector<int> v1 = findKthLargest(test, 0);

//     for (const int n : v1)
//     {
//         cout << n;
//     }
//     cout << endl;
// }

int main()
{
    vector<vector<int>> list = {
        {3, 1, 4},
        {1, 5, 9},
        {2, 6, 5},
        {7, 8, 9},
        {2, 3, 5}};

    int k = 2;
    try
    {
        vector<int> result = findKthLargest(list, k);

        // 결과 출력
        cout << "The " << k << "th largest array is: ";
        for (int num : result)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    catch (const invalid_argument &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}