#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    int iMax = 1000000;
    int countN = 0;
    string strN = "";

    int iN = n;
    while (iN > 0)
    {
        int remain = iN % 2;
        strN += to_string(remain);
        iN = iN / 2;
    }
    for (auto ch : strN)
    {
        if (ch == '1')
            countN++;
    }
        
    int iO = 0;
    for (int i = n + 1; n <= iMax; i++)
    {
        string strO = "";
        iO = i;
        int count = 0;
        while (iO > 0)
        {
            int remain = iO % 2;
            strO += to_string(remain);
            iO = iO / 2;
        }
        for (auto ch : strO)
        {
            if (ch == '1')
                count++;
        }

        if (countN == count)
        {
            answer = i;
            break;
        }
    }


    return answer;
}