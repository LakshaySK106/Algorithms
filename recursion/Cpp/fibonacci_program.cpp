
// Fibonacci program

#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
	// Stop condition
	if (n == 0)
		return 0;

	// Stop condition
	if (n == 1 || n == 2)
		return 1;

	// Recursion function
	else
		return (fib(n - 1) + fib(n - 2));
}

int main()
{
	int n = 10;
	cout<<"Fibonacci series of 5 numbers is: ";
	// for loop to print the fibonacci series.
	for (int i = 0; i < n; i++)
	{
		cout<<fib(i)<<" ";
	}
	return 0;
}
