#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
int n;
struct node *create_list()
{
    int i;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    struct node *p;
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            head=(struct node *)malloc(sizeof(struct node));
            p=head;
        }
        else
        {
            p->next=(struct node *)malloc(sizeof(struct node));
            p=p->next;
        }
        printf("enter the data in the node:");
        scanf("%d",&p->data);
    }
    p->next=NULL;
    return head;
}
struct node *insert_begin(struct node *head)
{
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->next=head;
    printf("enter the data in the newly inserted node:");
    scanf("%d",&new_node->data);
    head=new_node;
    return head;
}
struct node *insert_mid(struct node *head)
{
    struct node *p=head,*q,*new_node;
    int pos,cnt=0,c=1;
    printf("Enter the position you want to insert:");
    scanf("%d",&pos);
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data in the newly inserted node:");
    scanf("%d",&new_node->data);
    if(pos>0)
    {
        for(p=head;p!=NULL;p=p->next)
        {
            cnt++;
        }
        if(pos==1)
        {
            new_node->next=head;
            head=new_node;
            return head; 
        }
        else if(pos<=cnt)
        {
            p=head;
            while(p->next!=NULL&&c!=pos)
            {
                q=p;
                p=p->next;
                c++;
            }
            new_node->next=p;
            q->next=new_node;
            return head;
        }
        else if(pos==cnt+1)
        {
            p=head;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=new_node;
            new_node->next=NULL;
            return head;
        }
        else
        {
            printf("Node can't be inserted\n");
        }
    }
    else
    {
        printf("Node can't be inserted\n");
    }
    return head;
}
struct node *insert_end(struct node *head)
{
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    struct node *p;
    p=head;
    while(p->next!=NULL) p=p->next;
    p->next=new_node;
    printf("enter the data in the node inserted at last:");
    scanf("%d",&new_node->data);
    return head;
}
struct node *del_begin(struct node *head)
{
    head=head->next;
    return head;
}
struct node *del_mid(struct node *head)
{
    int cnt=0,pos,c=1;
    struct node *p=head,*q;
    printf("Enter the position you want to delete:");
    scanf("%d",&pos);
    while(p!=NULL)
    {
        p=p->next;
        cnt++;
    }
    if(pos>0)
    {
        if(pos==1)
        {
            p=head->next;
            head->next=NULL;
            head=p;
            return head;
        }
        else if(pos<=cnt)
        {
            p=head;
            while(p!=NULL&&c!=pos)
            {
                q=p;
                p=p->next;
                c++;
            }
            q->next=p->next;
            p->next=NULL;
            return head;
        }
        else if(pos==cnt+1)
        {
            p=head;
            while(p->next->next!=NULL)
            {
                p=p->next;
            }
            p->next=NULL;
            return head;
        }
        else
        {
            printf("Deletion of node is not possible\n");
        }
    }
    else
    {
        printf("Deletion of node is not possible\n");
    }
    return head;
}
struct node *del_end(struct node *head)
{
    struct node *p,*q;
    p=head;
    while(p->next->next!=NULL)      //p->next!=NULL
    {
       // q=p;      either q can also be used
        p=p->next;
    }
    p->next=NULL;           //q->next=NULL;
    return head;
}
void search(struct node *head)
{
    struct node *p;
    int ele,flag;
    int c=0;
    printf("enter the element you want to search:");
    scanf("%d",&ele);
    for(p=head;p!=NULL;p=p->next)
    {
        flag=0;
        c++;
        if(p->data==ele)
        {
            flag=1;
            break;
        }
    }
    if(flag==1) 
    {
        printf("found at position %d\n",c);
    }
    else printf("not found\n");
    return ;
}
void count(struct node *head)
{
    struct node *p;
    p=head;
    int c=0;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }
    printf("Number of nodes:%d\n",c);
    return ;
}
struct node *rev_list(struct node *head)
{
    struct node *prev=0,*curr,*nextnode=0;
    curr=head;
    while(curr!=NULL)
    {
        nextnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;
    }
    head=prev;
    return head;
}
void display(struct node *head)
{
    struct node *p;
    int c=1;
    for(p=head;p!=NULL;p=p->next)
    {
        printf("The data in %d node is %d\n",c,p->data);
        c++;
    }
    free(p);
}
int main()
{
    head=create_list();
    int choice;
    while(1)
    {
        printf("1.Insert at begin\n");
        printf("2.Insert at middle\n");
        printf("3.Insert at end\n");
        printf("4.Delete at begin\n");
        printf("5.Delete at middle\n");
        printf("6.Deleter at end\n");
        printf("7.Find an respective element\n");
        printf("8.Count the number of nodes\n");
        printf("9.Reverse the list\n");
        printf("10.Display the list\n");
        printf("Enter the operation you want to perform:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            head=insert_begin(head);
            break;
            case 2:
            head=insert_mid(head);
            break;
            case 3:
            head=insert_end(head);
            break;
            case 4:
            head=del_begin(head);
            break;
            case 5:
            head=del_mid(head);
            break;
            case 6:
            head=del_end(head);
            break;
            case 7:
            search(head);
            break;
            case 8:
            count(head);
            break;
            case 9:
            head=rev_list(head);
            break;
            case 10:
            display(head);
            break;
            default:
            printf("Your choice is not in the list and the code is exited\n");
            exit(1);
            break;
        }
    }
    exit(1);
}