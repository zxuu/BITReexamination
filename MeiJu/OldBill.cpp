/*
题目描述
    Among grandfather's papers a bill was found.     72 turkeys $_679_     The first and the last digits of the number that obviously
    represented the total price of those turkeys are replaced here by blanks (denoted _), for they are faded and are illegible. What are
    the two faded digits and what was the price of one turkey?     We want to write a program that solves a general version of the above
    problem.     N turkeys $_XYZ_     The total number of turkeys, N, is between 1 and 99, including both. The total price originally
    consisted of five digits, but we can see only the three digits in the middle. We assume that the first digit is nonzero, that the
    price of one turkeys is an integer number of dollars, and that all the turkeys cost the same price.     Given N, X, Y, and Z, write a
    program that guesses the two faded digits and the original price. In case that there is more than one candidate for the original price,
    the output should be the most expensive one. That is, the program is to report the two faded digits and the maximum price per turkey
    for the turkeys.
输入描述:
    The first line of the input file contains an integer N (0<N<100), which represents the number of turkeys. In the following line,
    there are the three decimal digits X, Y, and Z., separated by a space, of the original price $_XYZ_.
输出描述:
    For each case, output the two faded digits and the maximum price per turkey for the turkeys.
示例1
输入
72
6 7 9
5
2 3 7
78
0 0 5
输出
3 2 511
9 5 18475
0
 */

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        int x, y, z, i = 0, j = 0, k = 0;
        scanf("%d %d %d", &x, &y, &z);
        for (int a = 1; a <=9 ; a++) {
            for (int b = 0; b <=9 ; b++) {

                if ((a * 10000 + x * 1000 + y * 100 + z * 10 + b) % n == 0) {
                    i=a;
                    j=b;
                    k = (a * 10000 + x * 1000 + y * 100 + z * 10 + b) / n;

                }
            }
        }
        if (i != 0) {
            printf("%d %d %d\n", i, j, k);
        } else
            printf("0\n");
    }

    return 0;
}