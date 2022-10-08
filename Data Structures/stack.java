import java.util.*; 
import java.io.*; 

public class StackDemo { 
	public static void main(String args[]) 
	{ 
		// Creating an empty Stack 
		Stack<Integer> stack = new Stack<Integer>(); 

		// Use add() method to add elements 
		stack.push(10); 
		stack.push(15); 
		stack.push(30); 
		stack.push(20); 
		stack.push(5); 

		// Displaying the Stack 
		System.out.println("Initial Stack: " + stack); 

		// Removing elements using pop() method 
		System.out.println("Popped element: "
						+ stack.pop()); 
		System.out.println("Popped element: "
						+ stack.pop()); 

		// Displaying the Stack after pop operation 
		System.out.println("Stack after pop operation "
						+ stack); 
	} 
}
