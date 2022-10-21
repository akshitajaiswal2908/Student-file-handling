#include<stdio.h>
#include<stdlib.h>
struct student {
	int rno;
	char name[20];
	struct subject{
		int scode;
		char sname[20];
		int marks;
	}sub[3];
	int total;
	float per;
}typedef student;

void create()
{
	 student	*s;
	FILE *fp;
	int n,i,j;
	printf("HOW MANY STUDENTS YOU WANT: ");
	scanf("%d",&n);
	
    s = (student*)calloc(n, sizeof(student));
	
	
	fp=fopen("mystudents.txt","w");
	
	for(i=0;i<n;i++){
		s[i].total = 0;
		s[i].per = 0;
		printf("ENETR ROLL NO.: ");
		scanf("%d",&s[i]); 
		fflush(stdin); 
		printf("ENTER NAME: ");
		scanf("%[^\n]s",s[i].name);
		for(j=0;j<3;j++){
			printf("ENTER MARKS OF SUBJECT %d: ",j+1);
			scanf("%d",&s[i].sub[j].marks);
			fflush(stdin);
			s[i].total+=s[i].sub[j].marks;
		}
		s[i].per=s[i].total/3.0;
		fwrite(&s[i],sizeof(student),1,fp);
	}
	
	fclose(fp);
}
void display(){ 
	student s1;
	FILE *fp;
	int j;
	fp=fopen("mystudents.txt","r");
	
	while(fread(&s1,sizeof(student),1,fp))
	{
		printf("\n%-5d%-20s",s1.rno,s1.name);
		for(int j=0;j<3;j++){
			printf("%4d", s1.sub[j].marks);
		}
		printf("%5d%7.2f",s1.total,s1.per);
	}
	
	
	fclose(fp);

}
void append(){	 student	*s;
	FILE *fp;
	int n,i,j;
	printf("HOW MANY STUDENTS YOU WANT TO ADD: ");
	scanf("%d",&n);
	
    s = (student*)calloc(n, sizeof(student));
	
	
	fp=fopen("mystudents.txt","a");
	
	for(i=0;i<n;i++){
		s[i].total = 0;
		s[i].per = 0;
		printf("ENETR ROLL NO.: ");
		scanf("%d",&s[i]); 
		fflush(stdin); 
		printf("ENTER NAME: ");
		scanf("%[^\n]s",s[i].name);
		for(j=0;j<3;j++){
			printf("ENTER MARKS OF SUBJECT %d: ",j+1);
			scanf("%d",&s[i].sub[j].marks);
			fflush(stdin);
			s[i].total+=s[i].sub[j].marks;
		}
		s[i].per=s[i].total/3.0;
		fwrite(&s[i],sizeof(student),1,fp);
	}
	
	fclose(fp);
}

void noofrec()
{
	student s1;
	FILE *fp;
	fp=fopen("mystudents.txt","r");
	fseek(fp,0,2);
	long int n= ftell(fp)/sizeof(student);
	printf("NO. OF RECORDS ARE= %d",n);
}

void search()
{
	student s1;
	FILE *fp;
	int j,rno,found=0;
	fp=fopen("mystudents.txt","r");
	printf("ENTER THE ROLL NO TO SEARCH: ");
	scanf("%d",&rno);
	
	while(fread(&s1,sizeof(student),1,fp))
	{
		if(s1.rno==rno)
		{
			printf("\n%-5d%-20s",s1.rno,s1.name);
			for(int j=0;j<3;j++)
			{
				printf("%4d", s1.sub[j].marks);
			}
			printf("%5d%7.2f",s1.total,s1.per);
			found=1;
		}
	}
	if(!found)
	{
		printf("\nNO RECORD FOUND\n");
	}
	
	fclose(fp);
}

int main()
{
	int ch;
	do{
		printf("\n1.  CREATE");	
		printf("\n2.  DISPLAY");	
		printf("\n3.  APPEND");	
		printf("\n4.  NO.OF RECORDS");
		printf("\n5.  SEARCH");
		printf("\n6.  UPDATE");
		printf("\n0.  EXIT");	
		
		printf("\nENTER YOUR CHOICE: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			 create();
			break;
			case 2:
				display();
			break;
			case 3:
				append();
			break;
			case 4:
				noofrec();
			break;	
			case 5:
				search();
			break;
					
		}
	}while(ch!=0);
	
	
	
	return 0;
}