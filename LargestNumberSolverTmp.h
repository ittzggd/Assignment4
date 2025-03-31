#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <sstream>

using namespace std;

class LargeProblemSolver
{
};

long long findLargestLong(vector<int> list)
{
    long long largest = LLONG_MIN;
    vector<string> strVec = {};
    vector<int>::iterator it = list.begin();
    string accumulatedString;

    // TODO: replace w/ implemented insertionSort
    for (it; it != list.end(); it++)
    {
        strVec.push_back(to_string(*it));
    }
    sort(strVec.begin(), strVec.end());
    accumulatedString = accumulate(strVec.begin(), strVec.end(), string(""));
    largest = std::stoi(accumulatedString);
    return largest;
}

long long sum(vector<vector<int>> list)
{
    long long res = 0;
    long long largest = 0;
    vector<vector<int>>::iterator it = list.begin();

    for (it; it != list.end(); it++)
    {
        // TODO: replace w/ implemented insertionSort
        sort(it->begin(), it->end());
        largest = findLargestLong(*it);
        res += largest;
    }
    return res;
}

vector<int> findKthLargest(vector<vector<int>> list, int k)
{
    vector<int> originalVec = {};
    vector<int> sortedVec = {};
    vector<vector<int>>::iterator it = list.begin();
    int listSize = list.size();
    int index = listSize - 1 - k;
    int kthLargest = 0;
    int kthIndex;

    if (index < 0 || index > listSize - 1)
    {
        throw invalid_argument("k is not a valid position in the list");
    }

    for (int i = 0; i < listSize; i++)
    {
        originalVec.push_back(findLargestLong(*it));
    }
    // TODO: replace w/ implemented insertionSort
    copy(originalVec.begin(), originalVec.end(), back_inserter(sortedVec));
    sort(sortedVec.begin(), sortedVec.end());

    kthLargest = sortedVec[index];
    auto kthIt = find(originalVec.begin(), originalVec.end(), kthLargest);
    kthIndex = kthIt - originalVec.begin();
    return list[kthIndex];
}

vector<vector<int>> readFile(string filename)
{
    vector<vector<int>> res;
    vector<int> lineVec;
    stringstream strings;
    int num;

    string filePath = "integers.txt";

    ifstream openFile(filePath.data());
    if (openFile.is_open())
    {
        string line;
        while (getline(openFile, line))
        {
            stringstream ss(line);
            while (ss >> num)
                lineVec.push_back(num);
            res.push_back(lineVec);
            lineVec.clear();
        }
        openFile.close();
    }

    return res;
}
