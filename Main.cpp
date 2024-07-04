#include <iostream>

using namespace std;

class ListNode {
 public:
  int val;
  ListNode* next;

  // Default constructor
  ListNode() {
    val = 0;
    next = NULL;
  }

  // Parameterised Constructor
  ListNode(int data) {
    this->val = data;
    this->next = NULL;
  }
};

// Linked list class to
// implement a linked list.
class LinkedList {
 public:
  ListNode* head;

  // Default constructor
  LinkedList() { head = NULL; }

  // Function to insert a
  // node at the end of the
  // linked list.
  void insertNode(int);

  // Function to print the
  // linked list.
  void printList() const;

  // Function to delete the
  // node at given position
  void deleteNode(int);
};

// Function to delete the
// node at given position
void LinkedList::deleteNode(int nodeOffset) {
  ListNode *temp1 = head, *temp2 = NULL;
  int ListLen = 0;

  if (head == NULL) {
    cout << "List empty." << endl;
    return;
  }

  // Find length of the linked-list.
  while (temp1 != NULL) {
    temp1 = temp1->next;
    ListLen++;
  }

  // Check if the position to be
  // deleted is greater than the length
  // of the linked list.
  if (ListLen < nodeOffset) {
    cout << "Index out of range" << endl;
    return;
  }

  // Declare temp1
  temp1 = head;

  // Deleting the head.
  if (nodeOffset == 1) {
    // Update head
    head = head->next;
    delete temp1;
    return;
  }

  // Traverse the list to
  // find the node to be deleted.
  while (nodeOffset-- > 1) {
    // Update temp2
    temp2 = temp1;

    // Update temp1
    temp1 = temp1->next;
  }

  // Change the next pointer
  // of the previous node.
  temp2->next = temp1->next;

  // Delete the node
  delete temp1;
}

// Function to insert a new node.
void LinkedList::insertNode(int data) {
  // Create the new Node.
  ListNode* newNode = new ListNode(data);

  // Assign to head
  if (head == NULL) {
    head = newNode;
    return;
  }

  // Traverse till end of list
  ListNode* temp = head;
  while (temp->next != NULL) {
    // Update temp
    temp = temp->next;
  }

  // Insert at the last.
  temp->next = newNode;
}

// Function to print the
// nodes of the linked list.
void LinkedList::printList() const {
  ListNode* temp = head;

  // Check for empty list.
  if (head == NULL) {
    cout << "List empty" << endl;
    return;
  }

  // Traverse the list.
  while (temp != NULL) {
    cout << temp->val << " ";
    temp = temp->next;
  }
}

static ListNode* foo(ListNode* head) {
  ListNode* dummy = new ListNode(0);
  ListNode* current = dummy;
  int sum = 0;

  for (ListNode* temp = head->next; temp != NULL; temp = temp->next) {
    if (temp->val == 0) {
      if (sum != 0) {
        current->next = new ListNode(sum);
        current = current->next;
        sum = 0;
      }
    } else {
      sum += temp->val;
    }
  }

  ListNode* result = dummy->next;
  delete dummy;  // Clean up the dummy node
  return result;
}

int main() {
  LinkedList list;
  list.insertNode(0);
  list.insertNode(3);
  list.insertNode(1);
  list.insertNode(0);
  list.insertNode(4);
  list.insertNode(5);
  list.insertNode(2);
  list.insertNode(0);

  ListNode* result = foo(list.head);

  return 0;
}
