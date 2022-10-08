/* 
  PROBLEM STATEMENT:
  There are N people standing in a circle waiting to be executed. 
  The counting out begins at some point in the circle and proceeds around the circle in a fixed direction.
  In each step, a certain number of people are skipped and the next person is executed.
  The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom. 
  
  INPUT:
  Given the total number of persons N and a number k which indicates that k-1 persons are skipped and the kth person is killed in a circle.
  The task is to choose the person in the initial circle that survives.
  
  */

// LIST APPROACH
#include <bits/stdc++.h>

using namespace std;

void Josh(vector<int> person, int k, int index)
{
	// Base case , when only one person is left
	if (person.size() == 1) {
		cout << person[0] << endl;
		return;
	}

	// find the index of first person which will die
	index = ((index + k) % person.size());

	// remove the first person which is going to be killed
	person.erase(person.begin() + index);

	// recursive call for n-1 persons
	Josh(person, k, index);
}

int main()
{
	int n = 14; // specific n and k values for original
				// josephus problem
	int k = 2;
	k--; // (k-1)th person will be killed
	int index
		= 0; // The index where the person which will die

	vector<int> person;
	// fill the person vector
	for (int i = 1; i <= n; i++) {
		person.push_back(i);
	}

	Josh(person, k, index);
}

// Time Complexity: O(N^2)
// Auxiliary Space: O(N) For recursion stack


// ITERATIVE APPROACH
#include <bits/stdc++.h>
using namespace std;

int Josephus(int, int);

int Josephus(int n, int k)
{
	k--;
	int arr[n];

	// Makes all the 'n' people alive by
	// assigning them value = 1
	for (int i = 0; i < n; i++) {
		arr[i] = 1;
	}
	int cnt = 0, cut = 0,
		// Cut = 0 gives the sword to 1st person.
		num = 1;

	// Loop continues till n-1 person dies.
	while (cnt < (n - 1)) {

		// Checks next (kth) alive persons.
		while (num <= k) {
			cut++;

			// Checks and resolves overflow
			// of Index.
			cut = cut % n;
			if (arr[cut] == 1) {
				// Updates the number of persons
				// alive.
				num++;
			}
		}

		// Refreshes value to 1 for next use.
		num = 1;

		// Kills the person at position of 'cut'
		arr[cut] = 0;

		// Updates the no. of killed persons.
		cnt++;
		cut++;

		// Checks and resolves overflow of Index.
		cut = cut % n;

		// Checks the next alive person the
		// sword is to be given.
		while (arr[cut] == 0) {
			cut++;

			// Checks and resolves overflow
			// of Index.
			cut = cut % n;
		}
	}

	// Output is the position of the last
	// man alive(Index + 1);
	return cut + 1;
}

// Driver code
int main()
{
	int n = 14, k = 2;
	cout << Josephus(n, k);
	return 0;
}

//Time Complexity: O(N^2)
//Auxiliary Space: O(N)



// RECURSIVE APPROACH

#include <bits/stdc++.h>
using namespace std;

// Recursive function to implement the Josephus problem
int josephus(int n, int k)
{
	if (n == 1)
		return 1;
	else
		// The position returned by josephus(n - 1, k)
		// is adjusted because the recursive call
		// josephus(n - 1, k) considers the
		// original position k % n + 1 as position 1
		return (josephus(n - 1, k) + k - 1) % n + 1;
}

// Driver code
int main()
{
	int n = 14;
	int k = 2;
	cout << "The chosen place is " << josephus(n, k);
	return 0;
}

// Time Complexity: O(N)
//Auxiliary Space: O(N) the space used in recursion call stack
