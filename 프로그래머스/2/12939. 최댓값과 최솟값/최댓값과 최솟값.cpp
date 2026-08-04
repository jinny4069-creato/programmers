#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

/* 문자열 s str 에 나타나는 숫자 중 최소값과 최대값 찾기
*  return "최소값 최대값"
*/

string solution(string s) {
    string answer = "";
    vector<int> nums;

    string iString = s;
    istringstream iss(iString);
    int num;
    while (iss >> num)
    {
        nums.push_back(num);
    }
    
    sort(nums.begin(), nums.end(), less<>());
   
    answer = (to_string(nums[0])) + " " + to_string(nums[nums.size() - 1]);

    return answer;
}