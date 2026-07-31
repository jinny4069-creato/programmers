#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int sum = 0;
    sort(score.begin(), score.end(), greater<>());

    for (int i = 0; i < score.size(); i++)
    {
        if ((i + 1) % m == 0)
            sum += score[i] * m;
        
    }

    return sum;
}