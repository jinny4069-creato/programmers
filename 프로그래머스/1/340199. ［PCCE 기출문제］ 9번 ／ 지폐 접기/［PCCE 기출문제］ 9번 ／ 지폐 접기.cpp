#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int first = 0;
    int second = 1;

    while (true)
    {
        if (wallet[first] >= bill[first] && wallet[second] >= bill[second])
            break;
        
        if (wallet[first] >= bill[second] && wallet[second] >= bill[first])
            break;
        

        if (bill[first] > bill[second])
            bill[first] = bill[first] / 2;
        else
            bill[second] = bill[second] / 2;
        answer++;

    }
    
    return answer;
}