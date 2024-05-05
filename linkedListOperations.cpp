/******************************************************************************

Linked list class could be done away with and we could just let create nodes 
and make them point to each other in main 
*******************************************************************************/
#include <iostream>
using std::endl, std::cout;

struct Node 
{
  int value;
  Node* next;
  Node(int num = 0) : value{num}, next{nullptr} {}
};

class LinkedList {

 public:
  LinkedList() : head{nullptr} {}
  ~LinkedList()
  {
      while(head != nullptr)
      {
          Node* temp = head;
          head = head->next;
          delete temp;
      }
  }
  void insert(int value)
  {
     Node* temp = new Node(value);
     if(head == nullptr)
     {
         head = temp;
     }
     else
     { 
         Node* current = head;
         while(current->next != nullptr) 
         {
           current = current->next;
         }
         current->next = temp;
     }
      
  }
  void display()
  {
      Node* current = head;
      while(current != nullptr)
      {
          std::cout << current->value << endl;
          current = current->next;
          
      }
  } 
  double compAvg()
  {
      int sum = 0; 
      double counter = 0.0;
      double avg = 0.0;
      Node* current = head;
      if(head == nullptr){
          throw std::runtime_error("Empty list");
      }
      while(current != nullptr) 
      {
        sum += current->value;
        counter++;
        current = current->next;
          
      }
      avg = sum / counter;
      return avg;
      
  }
  void insertAtFront(int data)
  {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
  }
  
  private:
    Node* head;
 
};

int main() {
    // could create nodes here and send them into insert member f as parameters 
    LinkedList myList;
    
    myList.insert(18);
    myList.insert(7);
    myList.insert(15); 
    myList.insertAtFront(33);
    myList.insertAtFront(12);
    
    
    myList.display();
    
    cout << myList.compAvg() << endl;

    return 0;
}