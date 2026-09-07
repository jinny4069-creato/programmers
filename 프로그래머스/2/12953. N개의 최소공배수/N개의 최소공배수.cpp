#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* 두 수의 최소 공배수 ex) 2 와 7의 최소공배수는 14
*  n 개의 숫자를 담은 배열 arr 이 수들의 최소공배수를 반환
*  1. for 로 arr 값을 계속 돈다.
*  2. 제일 큰수의 곱 % arr[i] 해서 / 가 1이 될때까지 나눈다.
*  3. 1인데 나머지가 0이 아니면 제일 큰수의 곱 + 제일큰수
*  4. 모든 수가 나누었을때 1인데 나머지가 0 이면 for 종료
*/
int solution(vector<int> arr) {
    int answer = 0;

    sort(arr.begin(), arr.end());

    int maxNum = arr[arr.size() - 1];
    int mul = 1;

    for (int i = 0; i < arr.size();)
    {
        bool bCommon = true;
        int num = maxNum * mul;

        int remain = num % arr[i];
    
        if (remain != 0)
            bCommon = false;

        if (!bCommon)
        {
            mul++;
            i = 0;
        }
        else
            i++;
    }
      
    answer = maxNum * mul;

    return answer;
}