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
        {7, 42, 97},
        {88, 51},
        {15, 63, 21},
        {99, 100},
        {3, 8, 14, 27}};

    vector<int> expectedResults[] = {
        {99, 100},
        {7, 42, 97},
        {88, 51},
        {15, 63, 21},
        {3, 8, 14, 27}};

    for (int k = 0; k < 6; ++k)
    {
        try
        {
            vector<int> result = findKthLargest(list, k);

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
    }

    return 0;
}