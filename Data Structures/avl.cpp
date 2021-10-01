#include<bits/stdc++.h>
using namespace std;

struct node{

	int val;
	int height;

	node* left;
	node* right;

	node(int x){
		val = x;
		height = 1;
		left = NULL;
		right = NULL;
	}
};

class avl{
	public:
		int size;
		node* root;
		avl(){
			root = NULL;
			size = 0;
		}
		avl(int x){
			root = new node(x);
			size = 1;
		}

		int height(node *root){
			if(root==NULL)
				return 0;
			return root->height;
		}

		int getBalance(node *N){  
		    if (N == NULL)  
		        return 0;  
		    return height(N->left) - height(N->right);  
		}  

		node* minNode(node *A){
			node *temp = A;
			while(temp && temp->left){
				temp = temp->left;
			}
			return temp;
		}

		node* maxNode(node *A){
			node *temp = A;
			while(temp && temp->right){
				temp = temp->right;
			}
			return temp;
		}

		node* add(int x,node* root){
			node *temp = new node(x);
			if(root==NULL){
				size++;
				return temp;
			}

			if(x>root->val)
				root->right = add(x,root->right);

			else if(x<=root->val)
				root->left  = add(x,root->left);
			
			root->height = max(height(root->left),height(root->right)) + 1;
			int balance = getBalance(root);

			// Left-left Case
			if(balance>1 && x<root->left->val){
				return rotateRight(root);
			}

			// Left-right Case
			if(balance>1 && x>root->left->val){
				root->left = rotateLeft(root->left);
				return rotateRight(root);
			}

			// Right-right Case
			if(balance<-1 && x>root->right->val){
				return rotateLeft(root);
			}

			// Right-left Case
			if(balance<-1 && x<root->right->val){
				root->right = rotateRight(root->right);
				return rotateLeft(root);
			}

			return root;
		}

		node* deleteNode(node *&root,int x){
			if(root==NULL)
				return root;
			if(x>root->val)
				root->right = deleteNode(root->right,x);
			else if(x<root->val)
				root->left  = deleteNode(root->left,x);
			else{

				// No children
				if(root->left==NULL && root->right==NULL){
					delete root;
					root = NULL;
				}
				// One Child
				else if(root->right==NULL){
					root = root->left;
				}
				// One Child
				else if(root->left==NULL){
					root = root->right;
				}
				else{
				// Two Children using inorder succesor

					node *temp = minNode(root->right);
					root->val = temp->val;
					root->right = deleteNode(root->right,temp->val);

				// Two Children using inorder predecessor
					// node *temp = maxNode(root->left);
					// root->val = temp->val;
					// deleteNode(root->left,temp->val);
				}

			}
			if(root==NULL)
				return root;
			root->height = max(height(root->right),height(root->left)) + 1;
			int balance = getBalance(root);

			// Left-left case
			if(balance>1 && getBalance(root->left)>=0)
				return rotateRight(root);
			// Left-right case
			else if(balance>1){
				root->left = rotateLeft(root->left);
				return rotateRight(root);
			}

			// Right-right case
			if(balance<-1 && getBalance(root->right)>=0)
				return rotateLeft(root);
			// Right-left case
			else if(balance<-1){
				root->right = rotateRight(root->right);
				rotateLeft(root);
			}

			return root;

		}

		void print2DUtil(node *root, int space)  
		{  	int COUNT =10;
		    if (root == NULL)  
		        return;  
		    space += COUNT;  
		    print2DUtil(root->right, space);  
		    cout<<endl;  
		    for (int i = COUNT; i < space; i++)  
		        cout<<" ";  
		    cout<<root->val<<"\n";  
		    print2DUtil(root->left, space);  
		}

		node* rotateRight(node* root){
			node* B = root->left;
			root->left = B->right;
			B->right = root;
			root->height = max(height(root->right),height(root->left)) + 1;
			B->height = max(height(B->right),height(B->left)) + 1;
			return B;
		}

		node* rotateLeft(node* root){
			node* B = root->right;
			root->right = B->left;
			B->left = root;
			root->height = max(height(root->right),height(root->left)) + 1;
			B->height = max(height(B->right),height(B->left)) + 1;
			return B;
		}

		void inorder(node *root){
			if(root==NULL)
				return;
			inorder(root->left);
			cout << root->val << " " << root->height << "  " << endl;
			inorder(root->right);
		}
};

int main(){
	avl a;
	a.root = a.add(20,a.root);
	a.root = a.add(30,a.root);
	a.root = a.add(35,a.root);
	a.root = a.add(25,a.root);
	a.root = a.add(40,a.root);
	a.root = a.add(15,a.root);
	a.root = a.add(34,a.root);
	a.root = a.add(26,a.root);
	a.root = a.add(5,a.root);
	a.root = a.add(6,a.root);
	a.root = a.add(4,a.root);
	// a.root = a.deleteNode(a.root,2);
	a.print2DUtil(a.root,10);
	a.root = a.deleteNode(a.root,23);
	a.print2DUtil(a.root,10);

	// a.print2DUtil(a.root = a.rotateLeft(a.root),10);
	// a.print2DUtil(a.root = a.rotateRight(a.root),10);


}