#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/* 수확한 귤 중 k 개 를 골라 상자 하나에 담는다.
*  귤을 크기 별로 담아야한다.
*  ex) 귤 크기가 { 1, 3, 2, 5, 4, 5, 2, 3 } 이라면
*  크기가 1, 4 인 귤을 제외한 귤을 담으면
*  귤 크기의 종류가 3가지가 되고 이때 서로 다른 종류가 최소이다.
*  귤 k 개를 고를때 크기가 서로다른 종류의 수의 최소값을 return 하기
*  tangerine 이라는 귤 배열이 있는데 여기서 k 개를 꺼낼때 크기의 종류가 최소값을 구해라
*  1. 귤 갯수 별로 내림차순 정렬한다.
*  2. map 에 key 를 귤크기 int, value 를 갯수
*  3. 정렬하기 위해 vector 만들어서 크기 저장
*/
int solution(int k, vector<int> tangerine) {

    unordered_map<int, int> counts;
    
    for (int size : tangerine)
    {
        counts[size]++;
    }
    
    vector<int> nums;
    for (auto count : counts)
    {
        nums.push_back(count.second);
    }

    sort(nums.begin(), nums.end(), greater<>());

    int count = 0;
    int type = 0;
    for (int num : nums)
    {
        count += num;
        type++;
        
        if (count >= k)
            break;
    }
   
    return type;
}