//create a binary search tree
#include<iostream>
#include<conio.h>
using namespace std;


class BST
{ 
    int data;
    BST *left;
    BST *right;
    BST * createNode(int val);

    public:
    BST();
    ~BST();
    BST*InsertNode(BST *root, int val);
    BST* SearchNode(BST *root, int val);
    void printInOrderBST(BST *root);
    void breadthFirstTraversal(BST *root); 
    int getdata(){return data;}

    
};

BST::BST()
{
data=0;left=right=nullptr;
}

BST::~BST(){}


BST* BST::createNode(int val)
{
    BST *temp = new BST();
    temp->left=nullptr;
    temp->right=nullptr;
    temp->data = val;
    return temp;
}

BST* BST::InsertNode(BST *root,int val)
{  
   if (root == nullptr)
   {
      root = createNode(val);
   }
   else
   {
       if(val < root->data )
       {
            root->left = InsertNode(root->left,val);
       }
       else
       {
            root->right = InsertNode(root->right,val);
       }
   }
    return root;
}

void BST::printInOrderBST(BST* root)
{    
    if (root == nullptr) return;
    printInOrderBST(root->left);
    cout<<root->data<<endl ;
    printInOrderBST(root->right);
}

// returns null if no node found
BST* BST::SearchNode(BST *root, int val)
{
    if ((root == nullptr) || (root->data == val))
    {
        return root;
    }
    else if ( val < root->data )
    {
        return SearchNode(root->left,val);
    }
    else
    {
        return SearchNode(root->right,val);
    }
}
 
void breadthFirstTraversal(BST *root)
{

}

int main()
{
    BST b, *root=nullptr;
    root = b.InsertNode(root,5);
    b.InsertNode(root,10);
    b.InsertNode(root,2);
    b.InsertNode(root,25);
    b.InsertNode(root,13);
    b.printInOrderBST(root);
    cout<<"test the search func"<<endl<<endl;
    BST *found = b.SearchNode(root,25);
    if (found == nullptr)
    {
        cout<<"Node not found"<<endl;
    }
    else
    {
        cout<<"Node found ...value is "<<found->getdata()<<endl;
    }


	return 0;
}

