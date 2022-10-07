#pragma once
#include <iostream>
using namespace std;
#define N 10
class StackArray
{
private:
	//Declaring an array with top pointer to point on the top of stack
	int A[N], top; 
public:
	//Initializing the top with in constructor
	StackArray() {
		top = 0;
	}
	//creating a check method to check if stack is full or not
	bool isFull() {
		if (top == N)
			return true;
		return false;
	}
	//creating the check method to check if stack is empty or not
	bool isEmpty() {
		if (top == 0)
			return true;
		return false;
	}
	//method to push in the stack
	bool push(int y) {
		if (isFull())
			return false;
		A[top] = y;
		top++;
		return true;

	}
	//method to pop from the stack
	int pop() {
		if (!isEmpty()) {
			top--;
			int x = A[top];
			return true;
		}
		return false;
	}
	//Method to print the whole stack
	bool print() {
		if (isEmpty())
			return false;
		for (int i = 0; i < top; i++)
			cout << A[i] << " ,";
		return true;
	}
};
