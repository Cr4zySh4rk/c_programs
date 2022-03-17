#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;

void preorder(node *root)
{
   if(root==NULL) return;
   printf("\t%d", root->data);
   preorder(root->left);
   preorder(root->right);
}

void postorder(node *root)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("\t%d", root->data);
}

void inorder(node *root)
{
    if(root==NULL) return;
    inorder(root->left);
    printf("\t%d", root->data);
    inorder(root->right);
}

node *insert(node *root, int d)
{
    node *temp, *current, *prev;
    temp = (node*) malloc(sizeof(node));
    temp->data = d;
    temp->left = temp->right = NULL;
    if(root==NULL)
        return NULL;
    prev=NULL;
    current=root;
    while(current!=NULL)
    {
        prev=current;
        if(d<current->data)
            current=current->left;
        else
            current=current->right;
    }
    if(d<prev->data)
        prev->left=temp;
    else
        prev->right=temp;
    return root;
}

int search(node *root)
{
    int ele;
    printf("Enter the search element: ");
    scanf("%d", &ele);
    if(root==NULL)
        printf("BST is empty!\n");
    else
    {
        while(root!=NULL)
        {
            if(root->data==ele)
            {
                return 1;
            }
            else if(ele<root->data)
            {
                root=root->left;
            }
            else
            {
                root=root->right;
            }
        }
        return 0;
    }
}

void main()
{
    node *root=NULL;
    int ch, n, fd;
    while(1)
    {
        printf("\n----------Menu----------");
        printf("\n[1] Create BST");
        printf("\n[2] Preorder");
        printf("\n[3] Postorder");
        printf("\n[4] Inorder");
        printf("\n[5] Search");
        printf("\n[6] Exit");
        printf("\n------------------------");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: root=(node*) malloc(sizeof(node));
                    printf("Enter the number of elements: ");
                    scanf("%d", &n);
                    printf("Enter the elements: ");
                    for(int i=0; i<n; i++)
                    {
                        if(i==0)
                        {
                            scanf("%d", &fd);
                            root->data=fd;
                            root->left = root->right = NULL;
                        }
                        else
                        {
                            scanf("%d", &fd);
                            root=insert(root, fd);
                        }
                    }
                    break;
            case 2: if(root==NULL)
                    {       
                        printf("BST is empty!\n");
                    }
                    else
                    {
                        printf("Preorder: ");
                        preorder(root);
                    }
                    break;
            case 3: if(root==NULL)
                        printf("BST is empty!\n");
                    else
                    {
                        printf("Postorder: ");
                        postorder(root);
                    }
                    break;
            case 4: if(root==NULL)
                        printf("BST is empty!\n");
                    else
                    {
                        printf("Inorder: ");
                        inorder(root);
                    }
                    break;
            case 5: if(search(root))
                        printf("Element is present!\n");
                    else
                        printf("Element is not present!\n");
                    break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}