/**
 * Choose problems that:
 * - Are difficult for you
 * - Help you learn new topic
 *
 * During practice:
 * - Give yourself ~ 30 minutes of being stuck before reading editorial
 * - If you do need the editorialm read it bit-by-bit and process it
 * - Code the solution once you understand it
 * - Note down what you're doing / thinking of as you do it.
 *
 * General Info:
 * - Make sure you know how to use the big idea/topics from solved problems
 * - Treat every problem as a learning process
 * - Your practice will tell you what topics you need.
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, cnt = 0;

    cin >> n >> m;

    /*
    approach:
    1. if n is smaller than m then, multiply by 2
    2. if n is larger than m then, subtract by 1.

    example:
    n: 3 m: 10
    3 -> 6 -> 12 -> 11 -> 10 (5 times)

    How to assure that above approch will give minimum number.

    Thinking above edgy case:
    n: 3, m: 4
    3 -> 6 -> 5 -> 4

    best way
    3 -> 2 -> 4

    develop approach:
    If (n - 1) * 2 is still smaller than m then, -1

    failed case:
    n: 2, m: 10
    2 -> 4 -> 8 -> 7 -> 6 -> 5 -> 10
    2 -> 4 -> 3 -> 6 -> 5 -> 10


    Try another way:
    let a = n * 2;
    if a > m then,
    b = a / m + a % m;
    if a < m then,
    b = m / a + m % a;

    Need to find out minumum cost of steps when I choose button A or B.

    But If there is way to find the minimum cost of step for number n.

    Then I don't have to use greedy.

    If n > m then
    Only thing I can do is substract 1
    so when n is bigger than m, minimum steps would be n - m

    so think is when should I multiply by 2.

    -> if abs(n -m) > abs(2n - m) ?
    i.e. n = 2, m = 10
    2 -> 4 -> 3 -> 6 -> 5 -> 10

10 -> 5 ->
    */

    while (n != m)
    {
        int b, a = n * 2;
        if (a >= m)
        {
            b = a / m + a % m;
        }
        else
        {
            b = m / a + m % a;
        }

        int c = n - 1;

        if (c >= m)
        {
            c = c / m + c % m;
        }
        else
        {
            c = m / c + m % c;
        }

        cout << b << " " << c << " " << n << endl;

        if (b >= c)
        {
            n--;
        }
        else
        {
            n *= 2;
        }

        cnt++;
    }

    cout << cnt << endl;

    return 0;
}
