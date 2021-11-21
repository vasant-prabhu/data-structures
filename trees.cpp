//create a binary search tree

#include<iostream>
#include<conio.h>
#include<queue>

using namespace std;

class BST
{ 
    int data;
    BST *left;
    BST *right;
    BST * createNode(int val);
    bool IsBSTUtil(BST* root,int min,int max);
    
    public:
    BST();
    ~BST();
    BST*InsertNode(BST *root, int val);
    BST* SearchNode(BST *root, int val);
    void printInOrderBST(BST *root);
    void breadthFirstTraversal(BST *root); 
    int getdata(){return data;}
    void checkTreeIsBST(BST* root);
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
        return SearchNode(root->left,val); //not sure why use return here
    }
    else
    {
         return SearchNode(root->right,val);//not sure why use return here
    }
}
 
void BST::breadthFirstTraversal(BST *root)
{
    if (root==nullptr) return;
    //first push all elements into the queue
    queue<BST*> q;
    q.push(root);
    while (!q.empty())
    {
        BST *bNode = q.front();
        cout<<bNode->getdata()<<" ";

        if (bNode->left)
        {
            q.push(bNode->left);
        }
        
        if (bNode->right)
        {
            q.push(bNode->right);
        }
        q.pop();
    }
}

void BST::checkTreeIsBST(BST* root)
{ 
    int min = -500;
    int max = 500;
    bool result = false;
    if (root == nullptr)
    {
        cout<<"the tree is empty";
        return;
    }

    result = IsBSTUtil(root,min,max);
    if (true == result)
    {
        cout<<"the tree is BST";    
    }
    else
    {
        cout<<"the tree is not BST";
    }
}

//IsBSTUtil(root20,-500,500)
bool BST::IsBSTUtil(BST* root,int min,int max)
{
    if (root == nullptr)
    {
        return true;
    }

    if ( (root->getdata()>min) && (root->getdata()<max)
    &&   IsBSTUtil(root->left,min,root->getdata())
    &&   IsBSTUtil(root->right,root->getdata(),max) )
    {
        return true;
    }
    else
    {
        return false;
    }   
}

//TODO :-
//height of binary tree
// in order successor
//smallest element or largest element in tree.


int main()
{

    BST b, *root=nullptr;
    root = b.InsertNode(root,25);
    b.InsertNode(root,20);
    b.InsertNode(root,30);
    b.InsertNode(root,10);
    b.InsertNode(root,22);
    b.InsertNode(root,27);
    b.InsertNode(root,32);  
    cout<<"test the inorder traversal"<<endl;
    b.printInOrderBST(root);
    cout<<"test the search func"<<endl;
    BST *found = b.SearchNode(root,27);
    if (found == nullptr)
    {
        cout<<"Node not found"<<endl;
    }
    else
    {
        cout<<"Node found ...value is "<<found->getdata()<<endl;
    }
    cout<<"test the BFS"<<endl;
    b.breadthFirstTraversal(root);

    cout<<"check if tree is BST or not.."<<endl;
    b.checkTreeIsBST(root);
    return 0;
}


