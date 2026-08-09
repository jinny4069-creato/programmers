#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
 
    sort(A.begin(), A.end(), less<>());
    sort(B.begin(), B.end(), less<>());

    for (int i = 0; i < A.size(); i++)
    {
         answer += A[i] * B[B.size() - (i + 1)];
    }
    return answer;
}