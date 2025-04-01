
#pragma once

#include "LargestNumberSolver.h"
#include <chrono>
#include <iostream>
#include <vector>
#include <cstdlib> // rand()

using namespace std;

void MatrixTime()
{
    // Number of times to repeat the timed function (used to calculate average)
    int timesToLoop = 200;

    // For each problem size n . . . (n values can be changed to include different size ranges)
    for (int n = 10; n <= 1000; n += 100)
    {
        vector<vector<int>> vec(n, vector<int>());

        // 벡터 내부 요소 개수
        int innerSize = 10; // innerSize를 충분히 크게 설정

        // 랜덤한 숫자로 벡터 초기화
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < innerSize; j++)
            {
                vec[i].push_back(rand() % 1000); // 0~999 범위
            }
        }
        // 랜덤한 target 값 설정 (벡터에 존재하는 값으로 설정)
        int k = rand() % n;

        // Now, run the test
        auto startTime = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < timesToLoop; i++)
        {
            findKthLargest(vec, k);
        }

        auto stopTime = std::chrono::high_resolution_clock::now();

        // Compute the time it takes for the timing operation.
        auto totalTime = std::chrono::duration_cast<std::chrono::nanoseconds>(stopTime - startTime).count();

        // 평균 실행 시간 계산
        long averageTime = totalTime / timesToLoop;

        cout << n << "\t" << averageTime << " ns" << endl;
    }
}
