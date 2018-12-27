/*
==========================================================================
 * ASSIGNMENT NO.4
 *AUTHOR:POOJA SUNIL UDAWANT.
 *ROLL NO.:H2971.
 =========================================================================
 */
#include<stdio.h>
#include<ctype.h>
#include<string.h>
struct lib                       //declaration of structure
{
	char book_name[30];
	char author[30];
	char publisher[30];
	int price;
	int available_stock;
	int isbnbook_no;
	int flag;
};


void input(struct lib l[30], int i)
{
	int c,j,r,num,n;
	char ch,b[50];

		l[i].isbnbook_no=r;

		//validating name
		ch=getchar();
		do
		{
		c=0;
		printf("\nEnter the name of the book:");
		gets(b);
		n=strlen(b);
			for(j=0;j<n;j++)
			{
			   if(isalpha(b[j]))
			     continue;
			   else
			     break;
			}
			if(j==n)
		          strcpy(l[i].book_name,b);
			else
			{
			  printf("The name is not valid\n");
			  c=1;
			}
		}
		while(c==1);
		do
		{
		c=0;
		printf("\nEnter the author of the book:");
		gets(b);
		n=strlen(b);
			for(j=0;j<n;j++)
			{
			   if(isalpha(b[j]))
			     continue;
			   else
			     break;
			}
			if(j==n)
		          strcpy(l[i].author,b);
			else
			{
			  printf("The name of author is not valid\n");
			  c=1;
			}
		}
		while(c==1);
		do
		{
		c=0;
		printf("\nEnter the name of  publisher the book:");
		gets(b);
		n=strlen(b);
			for(j=0;j<n;j++)
			{
			   if(isalpha(b[j]))
			     continue;
			   else
			     break;
			}
			if(j==n)
		          strcpy(l[i].publisher,b);
			else
			{
			  printf("The name of publisher is not valid\n");
			  c=1;
			}
		}while(c==1);
	        do
	        {
		printf("\nEnter the price of the book: ");
		scanf("%d",&num);
		if(num>100 && num<10000)
		{
		   l[i].price=num;
		   c=0;
		}
		else
		{
		   printf("Invalid price\n");
		   c=1;
		}
		}
		while(c==1);
		  do
	        {
		printf("\nEnter the avaialble stock of the book: ");
		scanf("%d",&num);
		if(num>0 && num<1000)
		{
		   l[i].available_stock=num;
		   c=0;
		}
		else
		{
		   printf("Invalid available stock\n");
		   c=1;
		}
		}
		while(c==1);
		l[i].flag=0;		
}

int create(struct lib l[30],int n)
{
  int i,r,ch;

	for(i=0;i<n;i++)
	{
	    do
	    {
		printf("\nEnter the isbnbook_no. of book: ");
		scanf("%d",&r);
			if(r>0 && r<1000)
			{
			  input(l,i);
			  ch=0;
			}
			else
			{
			  printf("The isbnbook no. is not valid\n");
			  ch=1;
			}
		
	    }while(ch==1);
	 }
return n;
}


void display(struct lib l[30],int n)
{
 int i;

	printf("\nISBNBOOK_NO\tBOOK_NAME\tBOOK_AUTHOR\tBOOK_PUBLISHER\tBOOK_PRICE\tBOOK_AVAILABLESTOCK\n");

	for(i=0;i<n;i++)
	{
		if(l[i].flag==1)
	printf("\n %d\t\t%s\t%s\t%s\t%d\t%d\n",l[i].isbnbook_no,l[i].book_name,l[i].author,l[i].publisher,l[i].price,l[i].available_stock);
	}
}


void add(struct lib l[30],int n)
{
  int i,r,ch;
      
      do
	    {
		printf("\nEnter the isbn no. of book you want to add: \n");
      		scanf("%d",&r);
			if(r>0 && r<1000)
			{
			     if(search(l,n)==-1)
			       printf("The record already exist\n");
      			     else
      			     {
      			       input(l,i);
			       n=n+1;
			       display(l,n);
      			     }
	
			     ch=0;
			}
			else
			{
			  printf("The isbn no. is not valid\n");
			  ch=1;
			}
	    }while(ch==1);
  
      
}
	
int search(struct lib l[30],int n)
{
	int i,r;
	
	for(i=0;i<n;i++)
	{
	  if(r==l[i].isbnbook_no)
	   break;
	}
	if(i!=n)
	   return i; //found
	else
	   return -1; 
    }
void modify(struct lib l[30],int n)
{
    int i,ch,r;
	    do
	    {
		printf("\nEnter the isbn no. of book you want to modify: \n");
		scanf("%d",&r);
	
			if(r>0 && r<1000)
			{
			    i=search(l,n);
			    if(i==-1)
	 		      printf("The record does not exist\n");
			    else
			    {
			      input(l,i);		    
			      display(l,n);
			    }
			    ch=0;
			}
			else
			{
			    printf("The isbn  no. is not valid\n");
			    ch=1;
			}
		

	    }while(ch==1);
  	
	
}

void deletr(struct lib l[30],int n )
{
  int r,i,ch;
	do
	    {
		printf("\nEnter the isbn no. of book you want to delete: \n");
		scanf("%d",&r);
	
	
			if(r>0 && r<1000)
			{
			    i=search(l,n);
			    if(i==-1)
	 		      printf("The record does not exist\n");
			    else
			    {
	 		      l[i].flag=1;
	 		      display(l,n);
			    }
			    ch=0;
			}
			else
			{
			    printf("The isbn no. is not valid\n");
			    ch=1;
			}
		

	    }while(ch==1);
  	
  	
}





int main()
{
struct lib l[30];
  int n,ch,c,n1,r;

	printf("Enter number of books: ");
	scanf("%d",&n);

	create(l,n);
	display(l,n);
	
	
	  do
	  {

		printf("Choose your choice: \n");
		printf("1 for Add\n");
		printf("2 for Search\n");
		printf("3 for Modify\n");
		printf("4 for Delete\n");
		printf("5 Exit\n");
		scanf("%d",&c);

			switch(c)
			{
			   case 1:
			   	add(l,n);
			   	break;

			   case 2:
			   	do
	    		   	{
					printf("\nEnter the isbn no. of book: \n");
			   		scanf("%d",&r);
					if(r>0 && r<1000)
					{
			  	   	  search(l,n);
			  	   	  
			   	   	  if(search(l,n)==-1)
			    	     	    printf("The book is not present\n");
			   	   	  else
			    	     	    printf("The book is present\n");
			    	     	    
			  	   	  ch=0;
			        	}
			   		else
			   		{
			  	   	  printf("The isbn no. is not valid\n");
			           	  ch=1;
			   		}
		
	    		  	 }while(ch==1);
			   	 break;

			   case 3:
			    	modify(l,n);
			    	break;
			    
			   case 4:	
			        deletr(l,n);
			        break;

			   case 5:
			   	break;

			}
			
	  }while(c!=5);
return 0;
}

