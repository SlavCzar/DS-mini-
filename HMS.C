#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
int i,entries;
struct doctor
{
char Name[100],Qual[100],Spec[100];
struct doctor *next;
};
struct doctor *first=NULL;
struct patient
{
 int ID;
 char name[100];
 char address[100];
 char disorder[100];
 struct patient *next;
};
struct patient *start=NULL;
void delete(int );
void display();
void create();
void ShowID(int );
void delete_id(int );
void patient_switch();
void doctors();
void disp_doc();
void patient_switch()
{
 int option,k,l;
 do
 {
 printf("\n\n1.details\n2.display\n3.Show patient ID\n4.DeleteID\n5.EXIT\n");
 scanf("%d",&option);
 switch(option)
 {
 case 1:create();
 break;
 case 2:display(start);
 break;
 case 3:printf("Enter the id of the patient\n");
 scanf("%d",&l);
 ShowID(l);
 break;
 case 4:printf("Enter the unique id\n");
 scanf("%d",&k);
 delete_id(k);
 break;
 }
 }while(option !=5);
}
void create()
{
 struct patient *p,*pnode;
 int i,n;
 //printf("Enter -1 to end\n");
 printf("Enter the number of patients\n");
 scanf("%d",&n);
 //printf("Enter the Details of each patient\n");
 //printf("Id\tName\taddress\tdisorder\n");
 for(i=0;i<n;i++)
 {
 printf("Enter the details of the patient\n\n");
 printf("Id\tName\tAddress\t\tDisorder\n");
 pnode=(struct patient*)malloc(sizeof(struct patient));
 scanf("%d %s %s %s",&pnode->ID,&pnode->name,&pnode->address,&pnode->disorder);
 printf("\n");
 pnode->next=NULL;
 if(start==NULL)
 {
 start=p=pnode;
 }
 else
 {
 p->next=pnode;
 p=pnode;
 }
}
}
void display()
{
 struct patient *p;
 if(start==NULL)
 {
 printf("No Such Record!!");
 }
 else
 {
 printf("The Patient records are as follows:\n");
 printf("Id\tName\tAddress\tDisorder\n\n");
 p=start;
 while(p!=NULL)
 {
 printf("\n%d\t%s\t%s\t%s",p->ID,p->name,p->address,p->disorder);
 p=p->next;
 }
 }
}
void ShowID(int l)
{
 struct patient *p;
 p=start;
 while(p!=NULL)
 {
 if(p->ID==l)
 {
 printf("\nID:%d\nPATIENTNAME:%s\nADDRESS:%s\nDISORDER:%s\n",p->ID,p->name,p->address,p->disorder);
 break;
 }
 else
 p=p->next;
 }
printf("\n");
}
void delete_id(int k)
{
 struct patient *p,*follow;
 p=start;
 follow=NULL;
 while(p!=NULL)
 {
 if(p->ID==k)
 break;
 follow=p;
 p=p->next;
 }
 if(p==start)
 start=start->next;
 else
 follow->next=p->next;
 free(p);
}
void doctors()
{
 struct doctor *p,*pnode;
 printf("Doctor records\n");
 printf("Enter the number of entries\n");
 scanf("%d",&entries);
 for(i=1;i<=entries;i++)
 {
 printf("Enter the doctor details\n\n");
 printf("Name\tQualification\tSpecialization\t\tDisorder\n");
 pnode=(struct doctor*)malloc(sizeof(struct doctor));
 scanf("%s %s %s",pnode->Name,pnode->Qual,pnode->Spec);
 printf("\n");
 pnode->next=NULL;
 if(first==NULL)
 {
 first=p=pnode;
 }
 else
 {
 p->next=pnode;
 p=pnode;
 }
}
}
void main()
{
 int choice;
 printf("\n\t\t\t\t++\tPROMETHEUS HOSPITAL\t++\n\n");
 do
 {
 printf("Welcome To Prometheus Hospital!! What Can We Do ForYou\n\n");
 printf("\n1.Doctor Tabs\n2.Patient tabs\n3.Display doctorrecords\n4.EXIT\n");
 printf("\n__Enter your choice__\n");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:doctors();
 break;
 case 2:patient_switch();
 break;
 case 3:disp_doc();
 break;
 }
 }while(choice!=4);
}
void disp_doc()
{
 char n[25],a[25],s[25];
 struct doctor *p;
 if(start==NULL)
 {
 printf("No Such Record!!");
 }
 else
 {
 printf("The Patient records are as follows:\n");
 printf("Id\tName\tAddress\tDisorder\n\n");
 p=first;
 while(p!=NULL)
 {
 strcpy(n,p->Name);
 strcpy(a,p->Qual);
 strcpy(s,p->Spec);
 printf("\n%s\t%s\t%s",n,a,s);
 p=p->next;
 }
 }
}