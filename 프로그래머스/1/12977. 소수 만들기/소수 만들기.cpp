    #include <vector>
    #include <iostream>
    using namespace std;

   int solution(vector<int> nums) {
    int answer = 0;
  
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (i == j || i == k || j == k)
                    continue;
                
                int sum = nums[i] + nums[j] + nums[k];
                int count = 0;
                for (int q = 2; q * q <= sum; q++)
                {
                    if (q != sum && sum % q == 0)
                        count++;
                }
                if (count == 0)
                    answer++;
            }
        }
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}