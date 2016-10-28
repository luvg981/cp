#include <iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* root=NULL;
int count = 0;

struct node* insert(struct node* root, int value){
//	cout<<"hello\n";
	struct node* newNode;
//	cout<<"hello\n";
	newNode = (struct node*)malloc(sizeof(struct node));
//	cout<<"hello\n";
	newNode->data = value;
//	cout<<"hello\n";
//	cout<<root<<"\n";
	if(root==NULL){
		newNode->left = NULL;
		newNode->right = NULL;
		root = newNode;
//		cout<<root<<"\n";
//		cout<<root->data<<"\n";
		count++;
//		cout<<count<<"\n";
	}
	else{
		if(count%2 != 0){
//			cout<<"helloLeft\n";
			root->left = insert(root->left, value);

		}
		else{
//			cout<<"hiRight\n";
			root->right = insert(root->right, value);
		}
	}

	return root;
}

void displayIn(struct node* root){
	if(root==NULL){
//		cout<<"hellopp\n";
		return;
	}
	displayIn(root->left);
	printf("%d -> ",root->data);
	displayIn(root->right);

}

void displayPre(struct node* root){
	if(root!=NULL){
		printf("%d -> ",root->data);
		displayPre(root->left);
		displayPre(root->right);
	}
}

void displayPost(struct node* root){
	if(root!=NULL){
		displayPost(root->left);
		displayPost(root->right);
		printf("%d-> ",root->data);
	}
}

int main(){
	int choice, value;
	printf("!.....BINARY TREE.....!\n");
	printf("1. Insert\n2. Display\n3. Exit\n");
	while(true){
		printf("Enter choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Enter value: ");
					scanf("%d",&value);
					insert(root,value);
					break;
			case 2: int ch;
					printf("Which order:\n1. InOreder\n2. PreOrder\n3. PostOrder\n");
					scanf("%d",&ch);
					switch(ch){
						case 1: displayIn(root); 
								break;
						case 2: displayPre(root);
								break;
						case 3: displayPost(root);
								break;
					}
					break;
			case 3: return 0;

			default: printf("Enter a correct option\n");
		}

	}
}