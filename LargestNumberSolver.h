/*

Date : 03/27/2025
Author : Dain Min, Isabella Andrews, KATHERINE JANG

*/

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include <limits.h>

using namespace std;

bool Compare(string a, string b)
{
	string ab = a + b;
	string ba = b + a;
	return ab > ba;
}

bool normalCompare(string a, string b)
{
	return a > b;
}

template <class T>
void insertionSort(vector<T> &arr, bool (*Compare)(string, string))
{
	T temp;
	int x;

	for (int i = 1; i < arr.size(); i++)
	{
		temp = arr[i];
		x = i - 1;
		while (x >= 0 && Compare(to_string(temp), to_string(arr[x])))
		{
			arr[x + 1] = arr[x];
			x--;
		}
		arr[x + 1] = temp;
	}
};

string findLargestNumber(vector<int> x)
{
	insertionSort(x, Compare);

	string k = "";

	if (x.empty())
	{
		k = "0";
	}
	else
	{
		for (int i = 0; i < x.size(); i++)
		{
			k += to_string(x[i]);
		}
	}
	return k;
}

int findLargestInt(vector<int> x)
{
	insertionSort(x, Compare);

	string LargestNumber;
	for (int number : x)
	{
		LargestNumber += to_string(number);
	}

	try
	{
		return stoi(LargestNumber);
	}
	catch (const out_of_range &e)
	{
		throw out_of_range(" too large for the int data type");
	}
}

long long findLargestLong(vector<int> list)
{
	long long largest = LLONG_MIN;
	string largestString;
	vector<int>::iterator it = list.begin();

	insertionSort(list, Compare);

	for (it; it != list.end(); it++)
	{
		largestString += to_string(*it);
	}

	try
	{
		return stoll(largestString);
	}
	catch (const out_of_range &e)
	{
		throw out_of_range(" too large for the long data type");
	}
}

long long sum(vector<vector<int>> list)
{
	long long res = 0;
	long long largest = 0;
	vector<vector<int>>::iterator it = list.begin();

	for (it; it != list.end(); it++)
	{
		largest = findLargestLong(*it);
		res += largest;
	}
	return res;
}

vector<int> findKthLargest(vector<vector<int>> list, int k)
{
	vector<int> originalVec;
	vector<int> sortedVec;
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

	copy(originalVec.begin(), originalVec.end(), back_inserter(sortedVec));
	insertionSort(sortedVec, normalCompare);

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
