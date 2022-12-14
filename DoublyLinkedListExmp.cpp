#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define MAXNAME 20
//kisinin alabilceği maximum harf
typedef struct node
{
	struct node *prev;
	int number;
	char name[MAXNAME];
	struct node * next;
}node;



void DisplayLinkedList(node *head);
void RDisplayLinkedList(node * head);

node * CreateLinkedList(int x);
node * InsertBeg(node *head);
node * InsertEnd(node *head);
node *InsertMid(node *head);
node *DelBeg(node *head);
node *DelEnd(node *head);
node *DelNode(node *head);




int main()
{
	int n=0;
	node * head=NULL;	
	
	printf("Kac adet kisi olsun\n");
	scanf("%d",&n);
	head=CreateLinkedList(n);
	head=DelNode(head);
	


	DisplayLinkedList(head);
	RDisplayLinkedList(head);

	
}
//Aradaki koşula göre düğüm silme
node *DelNode(node * head)
{
	node *preptr,*ptr;
	ptr=head;
	int x;
	printf("\n Isimde gore silmek icin 1\n Numarasina gore silmek icin 2 ");
	scanf("%d",&x);
	switch(x)
	{
		case 1:
			char name[MAXNAME];
			printf("\nSilincek ismi yazin ");
			scanf("%s",&name);
			
			
			if(strcmp(ptr->name,name)==0)
			{
				//ilk isim silincek demek
				head=DelBeg(head);
				return head;
			}
			else
			{
				while(ptr!=NULL&&strcmp(ptr->name,name)!=0)
				{
					preptr=ptr;
					ptr=ptr->next;
				}
				if(ptr!=NULL)
				{
					preptr->next=ptr->next;
					ptr->next->prev=preptr;
					free(ptr);
				}
				return head;
				
			}
		case 2:
			int number;
			printf("Silincek numarayi yazin");
			scanf("%d",&number);
			if(ptr->number==number)
			{
				head=DelBeg(head);
			}
			else
			{
				while(ptr!=NULL&&ptr->number!=number)
				{
					preptr=ptr;
					ptr=ptr->next;
				}
				if(ptr!=NULL)
				{
					preptr->next=ptr->next;
					ptr->next->prev=preptr;

					free(ptr);
				}
				return head;
			}
			
		default:
			
			printf("Yanlis deger girdin");
			return head;
			
	}
}






//Son düğümü silme
node *DelEnd(node * head)
{
	node *ptr;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->prev->next=NULL;

	free(ptr);
	return head;
	
	
	
}
//İlk düğümü silme
node *DelBeg(node *head)
{
	node * ptr;
	ptr=head->next;
	ptr->prev=NULL;
	free(head);
	head=ptr;

	return head;
}

//Ad numara veya sıraya göre ekleme
node *InsertMid(node *head)
{
	node *ptr,*preptr;
	ptr=head;
	node* new_node;
	//*************************
	new_node=(node*)malloc(sizeof(node));
	printf("\nYeni kisinin adini gir");
	scanf("%s",&(new_node->name));
	printf("\nYeni kisinin numarasini gir");
	scanf("%d",&(new_node->number));
	//*************************

	int x;
	printf("\n Isimden sonra eklemek icin 1\n Numarasindan sonra eklemek icin 2 ");
	scanf("%d",&x);
	
	switch(x)
	{
		case 1:
			

			char new_name[20];
			
			printf("\nHangi isimden sonra eklencek ");
			scanf("%s",&new_name);

							
			
			while(ptr!=NULL&&strcmp(preptr->name,new_name)!=0)
			{
			
				preptr=ptr;
				ptr=ptr->next;
				
			}
			if(ptr!=NULL)
			{
				preptr->next=new_node;
				new_node->next=ptr;
				new_node->prev=preptr;
				ptr->prev=new_node;
				
			}
			
            	return head;
        case 2:

			int new_number;
			
			printf("\nHangi numaradan sonra eklencek ");
			scanf("%d",&new_number);

							
			
			while(ptr!=NULL&&preptr->number!=new_number)
			{
			
				preptr=ptr;
				ptr=ptr->next;
				
			}
			if(ptr!=NULL)
			{
				preptr->next=new_node;
				new_node->next=ptr;
				new_node->prev=preptr;
				ptr->prev=new_node;
				
			}
			
            return head;
        	
            	
		default:
			printf("\nHicbir islem yapilmadi");
			return head;
			
	}
}




//Bağlı listenin sonuna eklicem
node * InsertEnd(node * head)
{
	node * iter=head;
	node * temp;
	
	temp=(node*)malloc(sizeof(node));
	temp->next=NULL;
	printf("Son siraya eklencek kKisinin adini gir\n");
	scanf("%s",&(temp->name));
	printf("Son siraya eklencek kisinin nuamarisini gir\n");
	scanf("%d",&(temp->number));
	
	
	
	while(iter->next!=NULL)
	{
		iter=iter->next;
	}
	iter->next=temp;
	temp->prev=iter;
	return head;
	
	
}




//Bağlı listenin başına eleman ekleme
node * InsertBeg(node* head)
{
	node *temp;	
	temp=(node*)malloc(sizeof(node));
	printf("Ilk sirada girenin adini gir\n");
	scanf("%s",&(temp->name));
	printf("Ilk sirada girenin numarasini gir\n");
	scanf("%d",&(temp->number));
	
	
	temp->next=head;
	temp->prev=NULL;
	head->prev=temp;
	head=temp;
	
	return head;
	
	
	
}






//listenin başınnın adreisni geri gönderilen link list yazdık
node * CreateLinkedList(int x)
{
	node * head=NULL;
	node * temp=NULL;
	node * p=NULL;
	for(int i=0;i<x;i++)
	{
		//boş bir liste oluşturduk ama mallocla yer kaplıyor
		temp=(node*)malloc(sizeof(node));
		printf("Kisi ad gir\n");
		scanf("%s",&(temp->name));
		printf("Kisi numara gir\n");
		scanf("%d",&(temp->number));
		//sonra da boşlğua bağlıyoz
		temp->prev=NULL;
		temp->next=NULL;
		if(head==NULL)
		{
			//linked lsit boşsa temp ilk node olcak
			head=temp;
		}
		else
		{
			p=head;
			while(p->next !=NULL)
			{
				p=p->next;
			}
			p->next=temp;
			temp->prev=p;
			
			
		}
		
		
	}
	return head;	
}
void DisplayLinkedList(node * head)
{
	int i=1;
	node * ptr=head;
	printf("\nNORMAL SIRALANMIS LINKED LIST ");

	while(ptr!=NULL)
	{
		printf("\n%d\t%s\t%d",i,ptr->name,ptr->number);
		ptr=ptr->next;
		i++;
		
	}
}
//Revers linked list gösterimi
void RDisplayLinkedList(node * head)
{
	int i=1;
	node * ptr=head;
	printf("\nTERSTEN SIRALANMIS LINKED LIST ");
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;		
	}
	while(ptr!=NULL)
	{
		printf("\n%d\t%s\t%d",i,ptr->name,ptr->number);
		i++;
		ptr=ptr->prev;
	}
}







