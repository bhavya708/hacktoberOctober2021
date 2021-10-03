
#include <iostream>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* MakeNode(int x)
{
    Node* p=new Node();
    p->data=x;
    p->left=p->right=NULL;
    return p;
}
void inOrder(Node* tree)
{
    if(tree!=NULL)
    {
        inOrder(tree->left);
        cout<<tree->data<<"->";
        inOrder(tree->right);
    }


}
Node* insertion(Node* tree,int x)
{
    queue<Node*> q;
    if(tree==NULL)
    {
        Node* p=MakeNode(x);
        return p;
    }
    else
    {
        q.push(tree);
        while(!q.empty())
        {
            Node* temp=q.front();
            q.pop();
            if(temp->left!=NULL)
                q.push(temp->left);
            else
            {
                temp->left=MakeNode(x);
                return tree;
            }
            if(temp->right!=NULL)
                q.push(temp->right);
            else
            {
                temp->right=MakeNode(x);
                return tree;
            }
        }
    }
}
void levelTraversal(Node* tree)
{
    queue<Node*> q;
    if(tree==NULL)
    {
        //Node* p=MakeNode(x);
        //return p;
        cout<<"NULL";
    }
    else
    {
        q.push(tree);
        while(!q.empty())
        {
            Node* temp=q.front();
            cout<<temp->data<<"->";
            q.pop();
            if(temp->left!=NULL)
                q.push(temp->left);
                //return tree;

            if(temp->right!=NULL)
                q.push(temp->right);
                //return tree;

        }
    }
    //return tree;
}
int main() {
	struct Node* root=NULL;
	root=MakeNode(40);
	root->left=MakeNode(30);
	root->right=MakeNode(50);
	root->left->left=MakeNode(20);
	root=insertion(root,10);
	inOrder(root);
	cout<<"tree\n";
	levelTraversal(root);
	return 0;
}
