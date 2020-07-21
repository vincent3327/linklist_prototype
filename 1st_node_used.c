/**************************************************************
*此为链表学习程序
*第一个node被使用的链表
*6/8/2019
*vincent you
*nanshan hi-tech park ShenZhen
***************************************************************/
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef struct student_tag{
	char name[100];
	double score;
	struct student_tag *next;
}student;

student *createlist(int n)
{ 
			assert(n);
			student *head,*node,*end;
			
			head = (student*)malloc(sizeof(student));
			printf("keyin the first student's name & score:\n");
			scanf("%s%lf",&head->name,&head->score);
			end = head;
			for(int i = 1;i<n;i++)
			{
				node = (student*)malloc(sizeof(student));
				printf("keyin the %dst student's name & score:\n",(i+1));
				scanf("%s%lf",&node->name,&node->score);
				end->next = node;
				end = node;
			}
			end->next = NULL;
			return head;
}

void printlist(student * p_stu)
{
	 int i = 1;
	student *origin_p = p_stu;
	while(NULL!=p_stu)
	{
		//wrong approach! linklist is not array
		//printf("the %dst student's score = %d\n",(p_stu-origin_p)/(sizeof(*p_stu)),p_stu->score);
		printf("the %dst student's name:%s,score:%f\n",i,p_stu->name,p_stu->score);
		p_stu = p_stu->next;
		i++;
		//p_stu = p_stu->next;
	}
}

int main()
{	
	int n;
	printf("enter the number of linklist:\n");
	scanf("%d",&n);
	student *p_stu_head = createlist(n);
	printlist(p_stu_head);
}