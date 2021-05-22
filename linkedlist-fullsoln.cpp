#include<iostream>
#include <conio.h>
struct Node
{
int data;
Node *next=NULL;
};


class LinkedList
{
private:
Node *head=nullptr;
void recursiveReverseLL(Node *);
public:
LinkedList(){};
~LinkedList(){clear();};
void addNode(int num);
void deleteNode(int val);
void printNode();
void clear();
void reversingLLIterative();
int intersectionOfLinkedLists(LinkedList *);
void recursiveReverseLLWrapper();
inline Node* getNode(){return head;}
int detectLoopInLL(LinkedList *);
void createLoopInLL(LinkedList *);
};


void LinkedList::clear()
{
  if (head == nullptr)
  {
    return;
  }
  else
  {
     while (head!=nullptr)
     {
       Node *temp = head;
       temp=temp->next;
       delete head;
       head = temp;
     }
  }
}


void LinkedList::printNode()
{
   Node *temp = head;
   while(temp!=NULL)
   {
     std::cout<<temp->data<<" ";
     temp=temp->next;
   }
   std::cout<<std::endl;
}


void LinkedList::addNode(int num)
{
  Node *newNode= new Node;
  newNode->data = num;
  newNode->next=NULL;

  if (head == NULL)
  {
    //first node
    head=newNode;
  }
  else
  {
    Node *temp = head;
    while(temp->next != NULL)
    {
      temp=temp->next;
    }
    //now we are on our last node
    temp->next = newNode; 	
  }
}


void LinkedList::deleteNode(int val)
{

   Node *temp = head;
   //if we need to delete the first node
   if (head->data == val)
   {
       temp=head->next;
       delete head;
       head = temp;
       return;
   }
   else
   {

      Node *prev = head;
      temp=temp->next;
   
      while (temp!=NULL)
      {
        if(temp->data == val)
        {
           prev->next = temp->next;
           delete temp;
           break;
        }
        temp=temp->next;	
        prev=prev->next;
      }
    }
}

void LinkedList::reversingLLIterative()
{

Node *prev = NULL;
Node * curr = head;
Node *next =NULL;

while(curr != NULL)
{
   next = curr->next;
   curr->next = prev;
   prev = curr;
   curr = next;
}
head = prev;
}

void LinkedList::recursiveReverseLLWrapper()
{
   recursiveReverseLL(head);
}

void LinkedList::recursiveReverseLL(Node *temp)
{
if(temp->next == NULL)
{
head = temp;
return;
}
recursiveReverseLL(temp->next);
temp->next->next=temp;
temp->next=NULL;
}

int LinkedList::intersectionOfLinkedLists(LinkedList *LinkedListll2)
{
   int val=-1;

   int len1=0U;
   int len2=0U;

   Node * temp1 = this->getNode(); 
   Node * temp2 = LinkedListll2->getNode(); 
  
   while(temp1!=nullptr)
   {
     temp1=temp1->next;
    len1++;
   }

   while(temp2!=nullptr)
   {
     temp2=temp2->next;
     len2++;
   }

   temp1 = this->getNode(); 
   temp2 = LinkedListll2->getNode(); 

//find difference of elements between 2 lists
  int diff = len1-len2;

  if( diff < 0 )
  { 
    //means 2nd ll is bigger ..so shift the 2nd ll ahead
    for (int i=0;i<(len2-len1);i++)
    {
      temp2 = temp2->next;
    } 
  }
  else
  {

    // 1st ll is bigger
    for (int i=0;i<(len1-len2);i++)
    {
      temp1 = temp1->next;
    }
  }

//now that both linked lists are equal, start comparing the 2 lists

while(temp1!=NULL && temp2!=NULL)
{
   if(temp1->data == temp2->data)
   {
     return temp1->data;
   }
   temp1=temp1->next;
   temp2=temp2->next;
}
return val;
}


void LinkedList::createLoopInLL(LinkedList *ll)
{
   ll->getNode()->next->next->next->next->next =ll->getNode();
}

int LinkedList::detectLoopInLL(LinkedList *ll)
{
  Node *temp = ll->getNode();
  Node *slow = temp;
  Node *fast = temp;
  Node *prev = NULL;
  bool res = false;

 //Implementing Floyd's algorithm
 while (fast != nullptr) 
 { 
   // we will maintain a pointer to a node just before the slow pointer ,
   //in order to remove the loop,if detected
   prev = slow; 
   slow = slow->next;
   fast = fast->next->next;
   if (slow->data == fast->data)
   {
     std::cout<<"Loop present at "<<slow->data<<std::endl;
     res=true;
     std::cout<<"Lets fix the loop"<<std::endl;
     prev->next = nullptr;
     break;
   }
 }
return res;
}

int main()
{
using namespace std;
LinkedList ll;   //create a linked list object
ll.addNode(5);
ll.addNode(25);
ll.addNode(25);
ll.addNode(25);
ll.addNode(25);
ll.addNode(25);
ll.addNode(15);
ll.addNode(115);
ll.addNode(191);
ll.addNode(151);
ll.addNode(14);
ll.addNode(54);
ll.printNode();
cout<<"Deleting 15 "<<endl;
ll.deleteNode(15);
ll.printNode();
cout<<"Reversing a linked list"<<endl;
ll.reversingLLIterative();
ll.printNode();
cout<<"Recursive reverse .."<<endl;
ll.recursiveReverseLLWrapper();
ll.printNode();
cout<<"Lets prepare another linked list and find intersection node"<<endl;
LinkedList ll2;
ll2.addNode(24422);
ll2.addNode(22542);
ll2.addNode(3222);
ll2.addNode(3222);
ll2.addNode(22312);
ll2.addNode(22312);
ll2.addNode(22312);
ll2.addNode(22312);
ll2.addNode(3222);
ll2.addNode(222);
ll2.addNode(3222);
ll2.addNode(14);
ll2.addNode(54);
int myval = ll.intersectionOfLinkedLists(&ll2);
if(myval>=0)
{
cout<<"Intersection at "<<myval<<endl;
}
else
{
cout<<"the lists do not intersect"<<endl;
}

ll.clear(); ll2.clear();
cout<<"*********************************************"<<endl;
cout<<"Detect loop in linked list"<<endl;

LinkedList ll3;
ll3.addNode(14);
ll3.addNode(24);
ll3.addNode(34);
ll3.addNode(44);
ll3.addNode(54);
ll3.printNode();

ll3.createLoopInLL(&ll3);
bool res = ll3.detectLoopInLL(&ll3);
if (res == false)
{
cout<<" No loop present"<<endl;
}
cout<<" Now that loop has been removed ,lets print the nodes again.."<<endl;
ll3.printNode();
getch();
return 0;
}
