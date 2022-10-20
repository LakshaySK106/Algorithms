#include <iostream>
using namespace std;

struct node
{
  int data;
  struct node *next;
};

class linkedlist
{
private:
  node *head;

public:
  linkedlist();
  void insert_at_beg(int);
  void insert_at_end(int);
  void display();
  void delete_at_end();
  void delete_at_beg();
};

linkedlist ::linkedlist()
{
  head = NULL;
}

void linkedlist ::insert_at_beg(int d)
{

  node *temp;
  temp = new node;
  temp->data = d;
  temp->next = head;
  head = temp;
}
void linkedlist ::insert_at_end(int d)
{
  node *temp, *ptr;
  temp = new node;
  temp->next = NULL;

  if (head == NULL)
  {
    temp->data = d;
    head = temp;
    return;
  }

  ptr = head;
  temp->data = d;

  while (ptr->next != NULL)
  {
    ptr = ptr->next;
  }
  ptr->next = temp;
}

void linkedlist ::display()
{
  node *ptr = head;
  if (ptr == NULL)
  {
    cout << endl
         << "Linked list is Empty." << endl;
    cout << endl;

    return;
  }
  while (ptr != NULL)
  {
    cout << ptr->data << " ";
    ptr = ptr->next;
  }
  cout << endl;
}
void linkedlist ::delete_at_beg()
{
  if (head == NULL)
  {
    cout << endl
         << "Nothing to delete !!" << endl;
  }
  else
  {
    node *ptr;
    ptr = head->next;
    head = ptr;
  }
}
void linkedlist ::delete_at_end()
{
  if (head == NULL)
  {
    cout << endl
         << "Nothing to delete !!" << endl;
  }
  else
  {
    node *temp = head;
    node *ptr = head->next;
    while (ptr->next != NULL)
    {
      ptr = ptr->next;
      temp = temp->next;
    }
    temp->next = NULL;
    delete (ptr);
  }
}
int main()
{
  int choice, data;
  linkedlist d;
  cout << "1.Insert at beginning" << endl
       << "2.Insert at End" << endl
       << "3.Display" << endl
       << "4.delete at beginning" << endl
       << "5.delete at end" << endl;

  while (1)
  {

    cout << "Enter your choice :";
    cin >> choice;
    switch (choice)
    {

    case 1:
      cout << "Enter the data you want to add : ";
      cin >> data;
      d.insert_at_beg(data);
      break;

    case 2:
      cout << "Enter the data you want to add : ";
      cin >> data;
      d.insert_at_end(data);
      break;

    case 3:
      d.display();
      break;

    case 4:
      d.delete_at_beg();
      break;
    case 5:
      d.delete_at_end();
      break;
    }
  }

  return 0;
}
