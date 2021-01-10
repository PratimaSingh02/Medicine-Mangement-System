#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<dos.h>
int gd=DETECT,gm;
void dummy(float *a)
{
float b=*a;
dummy(&b);
} //dummy
struct medicine
{
char medname[20][20],expdate[20][10];
int medquant[20];
float medcost[20];
}med;
struct account
{
char cusname[30],cusemail[30],cusconno[10],cusadd[200],medpurdate[20][10],cusmedname[20][20];
int cusmedquant[20],cusage;
float cusmedtotalcost;
}a[20];


int searchmedicine(int m)
{
char search[10];
int count2,count3,count4,i,j;
printf("\nNOTE:If it is a first letter in the string,type it in UPPERCASE.\nSearch your medicine and enter the same name to purchase.\n");
printf("\nEnter a correct substring: ");
scanf("%s",&search);
count2=strlen(search);
printf("\nName\tQuantity\tDate of expiry\tCost");
for(m=1;m<=20;m++)
{
if(strcmp(med.medname[m],"\0")!=0)
{
count4=0;
count3=strlen(med.medname[m]);
for(i=0;i<count3;i++)
{
if(med.medname[m][i]==search[0] &&med.medname[m][i+1]==search[1])
break;
else if(count2==1 &&med.medname[m][i]==search[0])
break;
else
continue;
}//inner for1
for(j=0;j<count2;j++)
{
if(med.medname[m][i]==search[j])
count4++;
i++;
}
if(count4==count2)
{
printf("\n%s\t%d\t\t%s\t%f",med.medname[m],med.medquant[m],med.expdate[m],med.medcost[m]);
}//if
}//if
}//for
return 0;
}//searchmedicine




void purchase(int i,int m)
{
int n1,i1,i2,i3,one4;
clrscr();
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
setbkcolor(GREEN);
for(i3=1;i3<=20;i3++)
{
if(strcmp(a[i].cusmedname[i3],"\0")==0)
break;
}
printf("\nEnter number of various medicines= ");
scanf("%d",&n1);
for(i1=1;i1<=n1;i1++)
{
searchmedicine(m);
printf("\n\nMedicine %d:\nName: ",i1);
scanf("%s",&a[i].cusmedname[i3]);
for(i2=1;i2<=20;i++)
{
if(strcmp(a[i].cusmedname[i3],med.medname[i2])==0)
break;
}//inner for
if(strcmp(a[i].cusmedname[i3],med.medname[i2])==0)
{
if(med.medquant[i2]<=0)
{
printf("\n%s not available.",med.medname[i2]);
strcpy(a[i].cusmedname[i3],"\0");
break;
}// if
printf("\nExpiry date: %s\nQuantity available: %d\nCost: %f",med.expdate[i2],med.medquant[i2],med.medcost[i2]);
printf("\nTodays' date: ");
scanf("%s",&a[i].medpurdate[i3]);
printf("\nQuantity: ");
scanf("%d",&a[i].cusmedquant[i3]);
if(a[i].cusmedquant[i3]>med.medquant[i2])
{
printf("\nNo %d of %s available.\n%s available= %d",a[i].cusmedquant[i3],med.medname[i2],med.medname[i2],med.medquant[i2]);
printf("\nQuantity: ");
scanf("%d",&a[i].cusmedquant[i3]);
}//if
med.medquant[i2]=med.medquant[i2]-a[i].cusmedquant[i3];
a[i].cusmedtotalcost=a[i].cusmedtotalcost+a[i].cusmedquant[i3]*med.medcost[i2];
}//if true
else
{
strcpy(a[i].cusmedname[i3],"\0");
printf("\nYou entered an unavailable medicine!\nPress 1 to search again orelse press any key: ");
scanf("%d",&one4);
if(one4==1)
purchase(i,m);
}//else
}//for
if(med.medquant[i2]>0 && a[i].cusmedtotalcost!=0)
printf("\n\nTotal cost: Rs.%f",a[i].cusmedtotalcost);
}//purchase


void addmedicine(int m)
{
int count1=-1,ch2,one2=0,addquant=0;
char medexist[20],yes2[3];
do
{
clrscr();
printf("\n1.Add quantity to an existing medicine.\n2.Add new medicine.\n\nEnter your choice= ");
scanf("%d",&ch2);
switch(ch2)
{
case 1:
clrscr();
printf("\nEnter existing medicine name: ");
scanf("%s",&medexist);
for(m=1;m<=20;m++)
{
if(strcmp(medexist,med.medname[m])==0)
{
printf("\nName: %s\nQuantity: %d\nDate of expiry: %s\nCost: %d",med.medname[m],med.medquant[m],med.expdate[m],med.medcost[m]);
printf("\nPress 1 to add more %s orelse press any key: ",med.medname[m]);
scanf("%d",&one2);
if(one2==1)
{
printf("\nNumber of %s: ",med.medname[m]);
scanf("%s",&addquant);
med.medquant[m]=med.medquant[m]+addquant;
printf("\n%s expiry day-month-year(2-8-2018): ",med.medname[m]);
scanf("%s",&med.expdate[m]);
printf("\n%s updated.");
}//inner if
}//outer if
}//for
break;
case 2:
clrscr();
for(m=1;m<=20;m++)
{
count1=-1;
if(strcmp(med.medname[m],"\0")==0)
{
count1++;
break;
}
}//for
if(count1==20)
printf("\nNo space for medicines!");
else //medicine can be added
{
printf("\nEnter medicine:\nName: ");
scanf("%s",&med.medname[m]);
printf("\nQuantity: ");
scanf("%d",&med.medquant[m]);
printf("\n%s expiry date[day-month-year(2-8-2018)]: ",med.medname[m]);
scanf("%s",&med.expdate[m]);
printf("\nOne %s cost:Rs.",med.medname[m]);
scanf("%f",&med.medcost[m]);
printf("\n\n\t\tMedicine added successfully.");
}//else
break;
default:
printf("\nInvalid input!");
break;
}//switch
printf("\n\n\nType 'yes' to insert more medicines orelse press any key:\n");
scanf("%s",&yes2);
}while((strcmp(yes2,"YES")==0)||(strcmp(yes2,"yes")==0)||(strcmp(yes2,"Yes")==0));
}//addmedicine

void main()
{
char menu[4],yes[3],medicine[8],medexpiry[10],cusnamecheck[20];
int choice,m,ch1,i,in,one6;
struct date d;
clrscr();
do
{
clrscr();
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
setbkcolor(RED);
printf("\n\t\t\tBlue Earth Medical &Drugist Store\n\n\n\t1.View medicines update.\t4.Customer details.\n\n\n\t2.Create account.\t\t5.Add medicines.\n\n\n\t3.Purchase medicine.\n\n\n\t\t\tEnter  your  choice= ");
scanf("%d",&choice);
switch(choice)
{
case 1://main case1
do
{//inner case1 do
clrscr();
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
setbkcolor(GREEN);
printf("\t1.Available medicines.\t3.Expiry dates.\n\n\t2.Search medicines.\t4.Add medicines.\n\t5.Medicines over.\n\n\t\tEnter your choice= ");
scanf("%d",&ch1);
switch(ch1)
{
case 5://inner case5
for(m=1;m<=20;m++)
{
if(strcmp(med.medname[m],"\0")!=0)
{
if(med.medquant[m]==0 || med.medquant[m]==1 || med.medquant[m]==2)
{
printf("\n%s\t%d\t\t%s\t%f",med.medname[m],med.medquant[m],med.expdate[m],med.medcost[m]);
}//inner if
}//if
}//for
break;
case 1://inner case1
clrscr();
printf("\t\t*********Available  medicines*********");
printf("\nName\tQuantity\tDate of expiry\tCost");
for(m=1;m<=20;m++)
{
if(strcmp(med.medname[m],"\0")!=0)
printf("\n%s\t%d\t\t%s\t%f",med.medname[m],med.medquant[m],med.expdate[m],med.medcost[m]);
}//for
break;//inner case1 break
case 2://inner case2
searchmedicine(m);
break;//inner case2 break
case 3://inner case2
clrscr();
getdate(&d);
sprintf(medexpiry,"%d-%d-%d",d.da_day,d.da_mon,d.da_year);
printf("\nMedicine name\tExpiry date\tQuantity");
for(m=1;m<=20;m++)
{
if(strcmp(med.medname[m],"\0")!=0)
{
if(strcmp(medexpiry,med.expdate[m])==0)
printf("\n%s\t%s\t%d",med.medname[m],med.expdate[m],med.medquant[m]);
}//if
}//for
break;//inner case3 break
case 4://inner case4
addmedicine(m);
break;//inner case4 break
default:
printf("\n\n\t\tInput unavailable!");
break;//inner default break
}//inner case1 switch
printf("\nType 'medicine' to return back:\n");
scanf("%s",&medicine);
}while((strcmp(medicine,"medicine")==0)||(strcmp(medicine,"Medicine")==0)||(strcmp(medicine,"MEDICINE")==0));//inner case1 do
break;//main case1 break
case 2://main case2
clrscr();
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
setbkcolor(GREEN);
for(i=1;i<=20;i++)
{
if(strcmp(a[i].cusname,"\0")==0)
break;
}//for
printf("\nEnter customer:\nName= ");
scanf("%s",&a[i].cusname);
printf("\nAge: ");
scanf("%d",&a[i].cusage);
printf("\nAddress: ");
scanf("%s",&a[i].cusadd);
printf("\nEmail address: ");
scanf("%s",&a[i].cusemail);
printf("\nContact number: ");
scanf("%s",&a[i].cusconno);
printf("\nDo you want to purchase medicines?\nType 'yes' orelse press any key:\n");
scanf("%s",&yes);
if((strcmp(yes,"YES")==0)||(strcmp(yes,"Yes")==0)||(strcmp(yes,"yes")==0))
{
purchase(i,m);
}//if
break; //main case2 break
case 3://main case 3
clrscr();
printf("\nEnter your name if you have an account: ");
scanf("%s",&cusnamecheck);
for(i=1;i<=20;i++)
{
if(strcmp(cusnamecheck,a[i].cusname)==0)
break;
}
purchase(i,m);
break;//main case 3 break
case 4://main case4
clrscr();
printf("\nEnter your name if you have an account: ");
scanf("%s",&cusnamecheck);
for(i=1;i<=20;i++)
{
if(strcmp(cusnamecheck,a[i].cusname)==0)
break;
}
printf("\nCustomer:\nName: %s\nAge: %d\nAddress: %s\nEmail: %s\n\nPress 1 to see medicines purchased orelse press any key= ",a[i].cusname,a[i].cusage,a[i].cusadd,a[i].cusemail);
scanf("%d",&one6);
if(one6==1)
{
clrscr();
printf("\nMedicine:\nName\tQuantity\tDate of purchase");
for(in=1;in<=20;in++)
{
if(strcmp(a[i].cusmedname[in],"\0")!=0)
{
printf("\n%s\t\t%d\t\t%s",a[i].cusmedname[in],a[i].cusmedquant[in],a[i].medpurdate[in]);
}//inner if
} //for
}//if
break;//main case4 break
case 5://main case 5
addmedicine(m);
break;//main case5 break
default:
printf("\n\n\t\tInput not available.");
break;//main default break
}//main switch
printf("\n\nType 'menu' to go to homepage orelse press any key to exit:\n");
scanf("%s",&menu);
}while((strcmp(menu,"menu")==0)||(strcmp(menu,"Menu")==0)||(strcmp(menu,"MENU")==0));//do
}//main

