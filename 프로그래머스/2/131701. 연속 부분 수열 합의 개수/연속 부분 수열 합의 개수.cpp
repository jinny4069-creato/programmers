#include <string>
#include <vector>
#include <set>

using namespace std;

/* 원형 수열의 연속하는 부분 수열의 합으로 만들 수 있는 수가 모두 몇가지 인가
*  원형 수열의 모든 원소 elements 원형수열의 연속 부분 수열 합으로 만들 수 있는 수의 개수 return
*  ex) { 7, 9, 1, 1, 4 } 라면 길이가 1일때 합이 {1, 4, 7, 9 } 가 되고
*  길이가 2일때 각 배열의 왼쪽, 오른쪽 숫자들만 서로 합한다 {2, 5, 10, 11, 16 } 이 나온다.
*  1. 이중 for 문 for (int i = 1; i <= elements.size(); i++)
*     for (int j = 0; j < elements.size(); j++)
*  2. for 문으로 한개의 elements[i] 칸에서 len 를 늘리는 방식
*  3. i 마다 sum 생성 -> i 기준 
*  5. 중복 없애는 set<int> 사용
*/
int solution(vector<int> elements) {
    int answer = 0;

    set<int> results;

    for (int i = 0; i < elements.size(); i++)
    {
        int sum = 0;

        for (int len = 0; len < elements.size(); len++)
        {
            sum += elements[(len + i) % elements.size()];

            results.insert(sum);
        }
    }

    return results.size();
}