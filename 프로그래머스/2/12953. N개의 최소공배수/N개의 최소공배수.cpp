#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* 두 수의 최소 공배수 ex) 2 와 7의 최소공배수는 14
*  n 개의 숫자를 담은 배열 arr 이 수들의 최소공배수를 반환
*  1. 최소공배수, 최대공약수 공식 사용
*  2. 최대공약수 int a, b 를 나머지가 0이 될때 까지 반복한다. (유클리드 호제법)
*  3. 최소공배수 공식 -> a * b / gcd(a, b) 사용한다.
*/

int gcd(int a, int b)
{
    while (b != 0)
    {
        int num = a % b;
        a = b;
        b = num;
    }
    return a;
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int solution(vector<int> arr) {
    
    int num = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        num = lcm(num, arr[i]);
    }

    return num;
}