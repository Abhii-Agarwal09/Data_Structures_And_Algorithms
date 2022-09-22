#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  // Constructor
  Node()
  {
    // this->data = 0;
    this->next = NULL;
  }
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }

  // Destructor
  ~Node()
  {
    int value = this->data;
    if (this->next != NULL)
    {
      delete next;
      this->next = NULL;
    }
    cout << "Memory is free for node with data " << value << endl;
  }
};

// Insert at head of list
void insertAtHead(Node *&head, int data)
{

  Node *temp = new Node(data);
  temp->next = head;
  head = temp;
}

// Insert at tail of list
void insertAtTail(Node *&head, int data)
{

  Node *newNode = new Node(data);
  Node *temp = head;

  while (temp->next != NULL)
  {
    temp = temp->next;
  }

  temp->next = newNode;
}

// Insert at specific position in list
void insertAtPosition(Node *&head, int data, int position)
{

  // insert at head edge case
  if (position == 1)
  {
    insertAtHead(head, data);
    return;
  }

  Node *newNode = new Node(data);
  Node *temp = head;

  for (int i = 1; i < position - 1; i++)
  {
    temp = temp->next;
  }

  newNode->next = temp->next;
  temp->next = newNode;
}

// Delete a node in linked list
void deleteNode(Node *&head, int position)
{

  // Deleting first node
  if (position == 1)
  {
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
    return;
  }

  Node *curr = head;
  Node *prev = NULL;
  for (int i = 1; i < position; i++)
  {
    prev = curr;
    curr = curr->next;
  }
  prev->next = curr->next;
  curr->next = NULL;
  delete curr;
}

// Print linked list
void print(Node *&head)
{

  Node *temp = head;

  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

Node *mergeTwoLists(Node *list1, Node *list2)
{
  Node *temp1 = list1;
  Node *temp2 = list2;

  cout << "List 1: ";
  print(temp1);
  cout << "List 2: ";
  print(temp2);

  Node *merged = new Node();

  if (temp1 == NULL && temp2 == NULL)
  {
    return merged;
  }

  while (temp1 != NULL || temp2 != NULL)
  {
    cout << "Inside while" << endl;
    int temp1Data = temp1->data;
    int temp2Data = temp2->data;
    cout << temp1Data << " " << temp2Data << endl;
    if (temp1Data < temp2Data)
    {
      cout << "Inside if 1" << endl;
      insertAtTail(merged, temp1Data);
      temp1 = temp1->next;
    }
    else if (temp1Data > temp2Data)
    {
      cout << "Inside else if 1" << endl;
      insertAtTail(merged, temp2Data);
      temp2 = temp2->next;
    }
    else if (temp1Data == temp2Data)
    {
      cout << "Inside else if 2" << endl;
      insertAtTail(merged, temp1Data);
      insertAtTail(merged, temp2Data);
      temp1 = temp1->next;
      temp2 = temp2->next;
    }
    else
    {
      cout << "Inside else" << endl;
      temp1 = temp1->next;
      temp2 = temp2->next;
    }
  }
  while (temp1 != NULL)
  {
    insertAtTail(merged, temp1->data);
    temp1 = temp1->next;
  }
  while (temp2 != NULL)
  {
    insertAtTail(merged, temp2->data);
    temp2 = temp2->next;
  }
  cout << "Merged list: ";
  print(merged->next);
  return merged->next;
}

int main()
{
  Node *list1 = new Node();
  // insertAtTail(list1, 2);
  // insertAtTail(list1, 4);
  // insertAtTail(list1, 40);

  Node *list2 = new Node();
  // insertAtTail(list2, 3);
  // insertAtTail(list2, 4);
  // insertAtTail(list2, 35);

  Node *merged = mergeTwoLists(list1, list2);
  cout << "Merged: " << merged << endl;
  return 0;
}