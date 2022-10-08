/*   
     Problem Statement
     Given pointer to the head node of a linked list, the task is to recursively reverse the linked list.
     Reversal of the list is to be performed by changing links between nodes. 
    
     EXAMPLES:
                 Input : Head of following linked list  
                         1->2->3->4->NULL
                 Output : Linked list should be changed to,
                         4->3->2->1->NULL

                 Input : Head of following linked list  
                        1->2->3->4->5->NULL
                 Output : Linked list should be changed to,
                        5->4->3->2->1->NULL

                 Input : NULL
                 Output : NULL

                 Input  : 1->NULL
                 Output : 1->NULL

*/

#include <iostream>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkedList {
	Node* head;
	LinkedList()
	{
		head = NULL;
	}

	/* Function to reverse the linked list */
	Node* reverse(Node* node)
	{
		if (node == NULL)
			return NULL;
		if (node->next == NULL) {
			head = node;
			return node;
		}
		Node* node1 = reverse(node->next);
		node1->next = node;
		node->next = NULL;
		return node;
	}

	/* Function to print linked list */
	void print()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void push(int data)
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
};

/* Driver program to test above function*/
int main()
{
	/* Start with the empty list */
	LinkedList ll;
	ll.push(20);
	ll.push(4);
	ll.push(15);
	ll.push(85);

	cout << "Given linked list\n";
	ll.print();

	ll.reverse(ll.head);

	cout << "\nReversed Linked list \n";
	ll.print();
	return 0;
}

