#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// https://bigprimes.org/RSA-challenge
// 64 bit max
const unsigned long long N = 45032809;
// 2^17+1
const unsigned int e = 65537;

int IsSquare(int k)
{
	int sqrtK = sqrt(k);
	return k == sqrtK * sqrtK;
}

int InverseMod(int a, int m)
{
	int m0 = m;
	int y = 0, x = 1;
	if (m == 1)
	{
		return 0;
	}
	while (a > 1)
	{
		int q = a / m;
		int t = m;
		m = a % m, a = t;
		t = y;
		y = x - q * y;
		x = t;
	}
	if (x < 0)
	{
		x += m0;
	}
	return x;
}

int main()
{
	printf("N: %lld\n", N);
	int a = sqrt(N) + 1;
	int b = -1;
	while (a < N)
	{
		int b2 = a * a - N;
		if (IsSquare(b2))
		{
			b = sqrt(b2);
			break;
		}
		++a;
	}
	int p = a + b;
	int q = a - b;
	printf("P: %d\n", p);
	printf("Q: %d\n", q);
	printf("N == P * Q ? %d\n", N == p * q);
	int phiN = (p-1) * (q-1);
	int d = InverseMod(e, phiN);
	printf("D: %d\n", d);
	return 0;
}
