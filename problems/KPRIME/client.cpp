﻿/*
########Count K-Primes #######3

Alice and Bob are studying for their class test together. The topic of the test is Prime Numbers. The preparation is getting too boring for their liking. To make it interesting, they turn it into a game. The winner will get an ice-cream treat from the other.
The game is called Count K-Primes. A number is a k-prime if it has exactly k distinct prime factors. The game is quite simple. Alice will give three numbers A, B & K to Bob. Bob needs to tell Alice the number of K-prime numbers between A & B (both inclusive). If Bob gives the correct answer, he gets a point. If not, Alice gets a point. They play this game T times.
Bob hasn't prepared so well. But he really wants to win the game. He wants you to tell him the correct answer.
Input

First line of input contains a single integer T, the number of times they play. Each game is described in a single line containing the three numbers A,B & K.
Output

For each game, output on a separate line the number of K-primes between A & B.
Constraints:

1 ≤ T ≤ 10000
2 ≤ A ≤ B ≤ 100000
1 ≤ K ≤ 5
Example:

Input
4
2 5 1
4 10 2
14 15 2
2 20 3

Output
4
2
2
0

Source : https://www.codechef.com/problems/KPRIME
*/

#include "count.h"
#include <conio.h>

int main()
{
	int nT;
	int start;
	int end;
	int k;

	std::cout << "Enter value of T (number of games to play) --> ";
	std::cin >> nT;
	std::cout << std::endl;


	for (short playCount = 0; playCount < nT; playCount++)
	{
		std::cout << "Enter start --> ";
		std::cin >> start;
		std::cout << std::endl;

		std::cout << "Enter end --> ";
		std::cin >> end;
		std::cout << std::endl;

		std::cout << "Enter K --> ";
		std::cin >> k;
		std::cout << std::endl;

		CountKPrime ob(start, end, k);
		int result = ob.findKPrimes();

		std::cout << "K Prime is " << result;
		std::cout << std::endl << std::endl;
	}
	_getch();
	return 0;
}