#include <conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int ct = 0; //number of students
char p[] = "part";   //if you want to print only one element
char t[] = "total";  //if you want to print whole

struct student
{
  char roll[20];
  char name[20];
  char branch[20];
  char gen[10];
  char add[20];
  int math;
  int phy;
  int chem;
};
typedef struct student std;

void line(int,char);
void right(int,char[]);
void center(char []);
void header(char []);
void footer(char []);

void options();

void newAddmission(std []);
void listRecords(std []);
  void printTabs(std stdArr[],char [],int ind);

void searchRecords(std []);
  //searching....
  void searchRollNo(std [],char []);
  void searchName(std [],char []);
  void searchBranch(std [],char []);
  void searchGen(std [],char []);
  void searchAdd(std [],char []);

void modifyRecords(std []);
  //modifying....
  void modifyRollNo(std [],char [], char []);
  void modifyName(std [],char [], char []);
  void modifyBranch(std [],char [], char []);
  void modifyGen(std [],char [], char []);
  void modifyAdd(std [],char [], char []);

void deleteRecords(std []);
  //deleting...
  void deleteRollNo(std [],char []);
  void deleteName(std [],char []);
  void deleteBranch(std [],char []);
  void deleteGen(std [],char []);
  void deleteAdd(std [],char []);

void failureReports(std []);
  int percent(std [], int);

void highestScorer(std []);

void sortRecords(std []);
  int compareRoll(const void *a, const void *b);
  void sortRollNo(std []);
  int compareName(const void *a, const void *b);
  void sortName(std []);
  int compareBranch(const void *a, const void *b);
  void sortBranch(std []);
  int compareGen(const void *a, const void *b);
  void sortGen(std []);
  int compareAdd(const void *a, const void *b);
  void sortAdd(std []);


int main()
{
    std stdArr[10] = {
    {"69","C","A","C","A",66,88,88},

    {"70","B","B","B","B",6,7,7},

    {"71","A","C","A","C",6,6,6}};
    ct=3;
    int opn=0;
    do
    {
      clrscr();
      fflush(stdout);
      line(80,205);
      header("<<< STUDENT MANAGEMENT SYSTEM >>>");
      options();
      center("Choos an option (0 for back) : ");

      footer("DEVELOPER : MOHD ASRAR MALIK");
      gotoxy(57,19);

      scanf("%d",&opn);

      switch(opn)
      {
	case 1:
	  newAddmission(stdArr);
	  break;
	case 2:
	  listRecords(stdArr);
	  break;
	case 3:
	  searchRecords(stdArr);
	  break;
	case 4:
	  modifyRecords(stdArr);
	  break;
	case 5:
	  deleteRecords(stdArr);
	  break;
	case 6:
	  failureReports(stdArr);
	  break;
	case 7:
	  highestScorer(stdArr);
	  break;
	case 8:
	  sortRecords(stdArr);
	  break;
	case 0:
	  clrscr();
	  gotoxy(1,12);
	  center("Visit again. Happy day. ;) ");
	  getch();
	  break;
	default:
	  clrscr();
	  gotoxy(1,12);
	  center("Wrong option!!!");
	  getch();
      }
    }while(opn!=0);
    return 0;
}

void line(int l,char ch)
{
  int i;
  for(i=1; i<=l; i++)
  {
    printf("%c",ch);
  }
}
void right(int ps,char str[])
{
  int i;
  for(i=0; i<ps-strlen(str); i++)
  {
    printf(" ");
  }
  printf("%s",str);
}
void center(char str[])
{
  int i;
  for(i=1; i<=40-strlen(str)/2; i++)
  {
    printf(" ");
  }
  printf("%s\n",str);
}
void header(char str[])
{
  line(80,205);
  center(str);
  line(80,205);
  printf("\n\n\n");
}

void footer(char str[])
{
  gotoxy(1,24);
  line(80,205);
  right(80,str);
}

void options()
{
  center("01. NEW ADMISSION");
  center("02. LIST RECORDS");
  center(" 03. SEARCH RECORDS");
  center(" 04. MODIFY RECORDS");
  center(" 05. DELETE RECORDS");
  center(" 06. FAILUR REPORTS");
  center(" 07. HIGHEST SCORER");
  center("08. SORT RECORDS");
  printf("\n");
  center("0. EXIT\n\n");
}

void newAddmission(std stdArr[])
{

  int opn=0;
  do
  {
    clrscr();
    header("<<< NEW ADDMISSSION >>>");
    gotoxy(34,8);
    printf("Stundets : %d",ct);
    gotoxy(1,12);
    center("Confirm y(1)/n(0) : ");
    gotoxy(52,12);
    scanf("%d",&opn);
    if(opn == 1)
    {
      clrscr();
      header("<<< NEW ADDMISSSION >>>");
      gotoxy(34,8);
      printf("Stundets : %d\n\n\n",ct);
      printf("Enter Roll number of student: ");
      scanf("%s",stdArr[ct].roll);
      fflush(stdin);
      printf("Enter Name of student: ");
      gets(stdArr[ct].name);
      fflush(stdin);
      printf("Enter Student Branch: ");
      gets(stdArr[ct].branch);
      fflush(stdin);
      printf("Enter Student Gender: ");
      gets(stdArr[ct].branch);
      fflush(stdin);
      printf("Enter Student Address: ");
      gets(stdArr[ct].add);
      fflush(stdin);
      printf("Enter math's marks :");
      scanf("%d",&stdArr[ct].math);
      printf("Enter physic's marks :");
      scanf("%d",&stdArr[ct].phy);
      printf("Enter chemistry's marks :");
      scanf("%d",&stdArr[ct].chem);

      clrscr();
      ct++;
    }
  }while(opn!=0);

}

void listRecords(std stdArr[])
{

  int i;
  clrscr();
  header("<<< List Records >>>");
  printf("Students : %d\n", ct);
  printTabs(stdArr,t,0);
  getch();

}
//tabs+++++++++++++++++++++++++++++++++++++++++++++++++++++++
void printTabs(std stdArr[],char ch[],int ind)
{
    printf("%-11s%-15s%-11s%-7s%-20s%-4s%-4s%-4s%-4s\n","RollNo", "Name",
     "Branch", "Gender", "City","Mth","Phy","Che","Rslt");
    line(80,'~');

    if(strcmpi(ch, t) == 0)
    {
      int i;
      for(i=0; i<ct; i++)
      {
	if(percent(stdArr,i)<35)
	{
	  printf("%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
	  stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
	  stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"F");
	}
	else
	{
	  printf("%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
	  stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
	  stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"P");
	}
      }
    }
    else if(strcmpi(ch,p) == 0)
    {
      if(percent(stdArr,ind)<35)
      {
	printf("%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[ind].roll,stdArr[ind].name,
	stdArr[ind].branch,stdArr[ind].gen,stdArr[ind].add,stdArr[ind].math,
	stdArr[ind].phy,stdArr[ind].chem,"F");
      }
      else{
      printf("%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[ind].roll,stdArr[ind].name,
      stdArr[ind].branch,stdArr[ind].gen,stdArr[ind].add,stdArr[ind].math,
	stdArr[ind].phy,stdArr[ind].chem,"P");
      }
    }
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void searchRecords(std stdArr[])
{
  int opn=0;
  do
  {
    clrscr();
    header("<<< SEARCH RECORDS >>>");
    gotoxy(40,7);
    printf("Students : %d\n\n",ct);
    center("       01. BY ROLL NUMBER");
    center("02. BY NAME");
    center("  03. BY BRANCH");
    center("  04. BY GENDER");
    center("05. BY CITY");
    center("  06. BY STATE");
    center("  07. BY DISTIC");
    center("         08. BY NATIONALITY\n");
    center("      0. EXIT\n\n");

    center("Choos an option (0 for back) : ");
    gotoxy(58,21);
    scanf("%d",&opn);
    fflush(stdin);

    switch(opn)
    {
      case 1:
	char str[20];
	clrscr();
	header("<<<  BY ROLL NO  >>>");
	printf("Enter Roll number : ");
	gets(str);
	searchRollNo(stdArr,str);
	break;
      case 2:
	clrscr();
	header("<<<  BY NAME  >>>");
	printf("Enter name : ");
	gets(str);
	fflush(stdin);
	center(str);
	getch();
	searchName(stdArr,str);
	break;
      case 3:
	clrscr();
	header("<<<  BY BRANCH  >>>");
	printf("Enter branch : ");
	gets(str);
	searchBranch(stdArr,str);
	break;
      case 4:
	str[20];
	clrscr();
	header("<<<  BY GENDER  >>>");
	printf("Enter gender : ");
	gets(str);
	searchGen(stdArr,str);
	break;
      case 5:
	str[20];
	clrscr();
	header("<<<  BY ADDRESS  >>>");
	printf("Enter address : ");
	gets(str);
	searchAdd(stdArr,str);
	break;
      case 6:
	break;
      case 7:
	break;
      case 8:
	break;
      case 0:
	clrscr();
	gotoxy(1,12);
	center("Backed!!!");
	getch();
	break;
      default:
	clrscr();
	gotoxy(1,12);
	center("Wrong option!!!");
	getch();
    }
  }while(opn!=0);

}
//searching.....
void searchRollNo(std stdArr[],char str[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].roll, str)==0)
    {
      fg=1;
      break;
    }
    index++;
  }

  if(fg==1)
  {
    printTabs(stdArr,p,index);
    getch();
  }
  else
  {
    clrscr();
    gotoxy(1,12);
    center("Not found");
    getch();
  }
}

void searchName(std stdArr[],char str[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].name, str)==0)
    {
      fg=1;
      break;
    }
    index++;
  }

  if(fg==1)
  {
    printTabs(stdArr,p,index);
    getch();
  }
  else
  {
    clrscr();
    gotoxy(1,12);

    center("Not found");
    getch();
  }
}

void searchBranch(std stdArr[],char str[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmp(stdArr[i].branch, str)==0)
    {
      fg=1;
      break;
    }
    index++;
  }

  if(fg==1)
  {
    printTabs(stdArr,p,index);
    getch();
  }
  else
  {
    clrscr();
    gotoxy(1,12);
    center("Not found");
    getch();
  }
}

void searchGen(std stdArr[],char str[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmp(stdArr[i].gen, str)==0)
    {
      fg=1;
      break;
    }
    index++;
  }

  if(fg==1)
  {
    printTabs(stdArr,p,index);
    getch();
  }
  else
  {
    clrscr();
    gotoxy(1,12);
    center("Not found");
    getch();
  }
}

void searchAdd(std stdArr[],char str[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmp(stdArr[i].add, str)==0)
    {
      fg=1;
      break;
    }
    index++;
  }

  if(fg==1)
  {
    printTabs(stdArr,p,index);
    getch();
  }
  else
  {
    clrscr();
    gotoxy(1,12);
    center("Not found");
    getch();
  }
}
//ENDED SEARCHING

void modifyRecords(std stdArr[])
{
  int opn=0;

  do
  {
    clrscr();
    header("<<< MODIFY RECORDS >>>");

    center("       01. BY ROLL NUMBER");
    center("02. BY NAME");
    center("  03. BY BRANCH");
    center("  04. BY GENDER");
    center("05. BY CITY");
    center("  06. BY STATE");
    center("  07. BY DISTIC");
    center("         08. BY NATIONALITY\n");
    center("      0. EXIT\n\n");

    center("Choos an option (0 for back) : ");
    gotoxy(58,19);
    scanf("%d",&opn);
    fflush(stdin);

    switch(opn)
    {
      case 1:
	char key[20];
	char value[20];
	clrscr();
	header("<<<  BY ROLL NO  >>>");
	printf("Enter old roll number : ");
	gets(key);
	printf("Enter new roll number : ");
	gets(value);
	modifyRollNo(stdArr,key,value);
	break;
     case 2:
	clrscr();
	header("<<<  BY NAME  >>>");
	printf("Enter old name : ");
	gets(key);
	printf("Enter new name : ");
	gets(value);
	modifyName(stdArr,key,value);
	break;
      case 3:
	clrscr();
	header("<<<  BY BRANCH  >>>");
	printf("Enter old branch : ");
	gets(key);
	printf("Enter new branch : ");
	gets(value);
	modifyBranch(stdArr,key,value);
	break;
      case 4:
	clrscr();
	header("<<<  BY GENDER  >>>");
	printf("Enter old gender : ");
	gets(key);
	printf("Enter new gender : ");
	gets(value);
	modifyGen(stdArr,key,value);
	break;
      case 5:
	clrscr();
	header("<<<  BY ADDRESS  >>>");
	printf("Enter old address : ");
	gets(key);
	printf("Enter new address : ");
	gets(value);
	modifyAdd(stdArr,key,value);
	break;
      case 6:
	break;
      case 7:
	break;
      case 8:
	break;
      case 0:
	clrscr();
	gotoxy(1,12);
	center("Backed");
	getch();
	break;
      default:
	clrscr();
	gotoxy(1,12);
	center("Wrong option!!!");
	getch();
    }
  }while(opn!=0);

}

//modifying.....
void modifyRollNo(std stdArr[],char key[],char value[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].roll, key)==0)
    {
      fg=1;
      break;
    }
    index++;
  }

  if(fg==1)
  {
    strcpy(stdArr[i].roll, value);
    printTabs(stdArr,p,index);
    getch();
  }
  else
  {
    clrscr();
    gotoxy(1,12);
    center("Not found");
    getch();
  }
}


void modifyName(std stdArr[],char key[],char value[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].name, key)==0)
    {
      fg=1;
      break;
    }
    index++;
  }

  if(fg==1)
  {
    strcpy(stdArr[i].name, value);
    printTabs(stdArr,p,index);
    getch();
  }
  else
  {
    clrscr();
    gotoxy(1,12);
    center("Not found");
    getch();
  }
}

void modifyBranch(std stdArr[],char key[],char value[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].branch, key)==0)
    {
      fg=1;
      break;
    }
    index++;
  }

  if(fg==1)
  {
    strcpy(stdArr[i].branch, value);
    printTabs(stdArr,p,index);
    getch();
  }
  else
  {
    clrscr();
    gotoxy(1,12);
    center("Not found");
    getch();
  }
}

void modifyGen(std stdArr[],char key[],char value[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].gen, key)==0)
    {
      fg=1;
      break;
    }
    index++;
  }

  if(fg==1)
  {
    strcpy(stdArr[i].gen, value);
    printTabs(stdArr,p,index);
    getch();
  }
  else
  {
    clrscr();
    gotoxy(1,12);
    center("Not found");
    getch();
  }
}

void modifyAdd(std stdArr[],char key[],char value[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].add, key)==0)
    {
      fg=1;
      break;
    }
    index++;
  }

  if(fg==1)
  {
    strcpy(stdArr[i].add, value);
    printTabs(stdArr,p,index);
    getch();
  }
  else
  {
    clrscr();
    gotoxy(1,12);
    center("Not found");
    getch();
  }
}
//ended modifying

void deleteRecords(std stdArr[])
{
  int opn=0;
  do
  {
    clrscr();
    header("<<< DELETE RECORDS >>>");
    center("       01. BY ROLL NUMBER");
    center("02. BY NAME");
    center("  03. BY BRANCH");
    center("  04. BY GENDER");
    center("05. BY CITY");
    center("  06. BY STATE");
    center("  07. BY DISTIC");
    center("         08. BY NATIONALITY\n");
    center("      0. EXIT\n\n");

    center("Choos an option (0 for back) : ");
    gotoxy(58,19);
    scanf("%d",&opn);
    fflush(stdin);

    switch(opn)
    {
      case 1:
	char str[20];
	clrscr();
	header("<<<  BY ROLL NO  >>>");
	printf("Enter roll number : ");
	gets(str);
	deleteRollNo(stdArr,str);
	break;
      case 2:
	clrscr();
	header("<<<  BY NAME  >>>");
	printf("Enter name : ");
	gets(str);
	fflush(stdin);
	center(str);
	getch();
	deleteName(stdArr,str);
	break;
      case 3:
	clrscr();
	header("<<<  BY BRANCH  >>>");
	printf("Enter branch : ");
	gets(str);
	deleteBranch(stdArr,str);
	break;
      case 4:
	str[20];
	clrscr();
	header("<<<  BY GENDER  >>>");
	printf("Enter gender : ");
	gets(str);
	deleteGen(stdArr,str);
	break;
      case 5:
	str[20];
	clrscr();
	header("<<<  BY ADDRESS  >>>");
	printf("Enter address : ");
	gets(str);
	deleteAdd(stdArr,str);
	break;
      case 6:
	break;
      case 7:
	break;
      case 8:
	break;
      case 0:
	clrscr();
	gotoxy(1,12);
	center("Backed");
	getch();
	break;
      default:
	clrscr();
	gotoxy(1,12);
	center("Wrong option!!!");
	getch();
    }
  }while(opn!=0);

}

//deleting....
void deleteRollNo(std stdArr[],char str[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].roll, str)==0)
    {
      fg=1;
      index++;
      break;
    }
    else
    {
      index++;
    }
  }

  if(fg==1)
  {
    int i;
    clrscr();
    gotoxy(1,12);
    printTabs(stdArr,p,index-1);
    center("DELETED SUCCESSFULLY");
    for(i=index-1; i<ct; i++)
    {
     stdArr[i] = stdArr[i+1];
    }
    getch();
    ct--;
  }
  else
  {
    clrscr();
    gotoxy(1,12);
    center("Not found");
    getch();
  }
}

void deleteName(std stdArr[],char str[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].name, str)==0)
    {
      fg=1;
      index++;
      break;
    }
    else
    {
      index++;
    }
  }

  if(fg==1)
  {
    int i;
    clrscr();
    gotoxy(1,12);
    printTabs(stdArr,p,index-1);
    center("DELETED SUCCESSFULLY");
    for(i=index-1; i<ct; i++)
    {
     stdArr[i] = stdArr[i+1];
    }
    getch();
    ct--;
  }
  else
  {
    clrscr();
    gotoxy(1,12);
    center("Not found");
    getch();
  }
}

void deleteBranch(std stdArr[],char str[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].branch, str)==0)
    {
      fg=1;
      index++;
      break;
    }
    else
    {
      index++;
    }
  }

  if(fg==1)
  {
    int i;
    clrscr();
    gotoxy(1,12);
    printTabs(stdArr,p,index-1);
    center("DELETED SUCCESSFULLY");
    for(i=index-1; i<ct; i++)
    {
     stdArr[i] = stdArr[i+1];
    }
    getch();
    ct--;
  }
  else
  {
    clrscr();
    gotoxy(1,12);
    center("Not found");
    getch();
  }
}

void deleteGen(std stdArr[],char str[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].gen, str)==0)
    {
      fg=1;
      index++;
      break;
    }
    else
    {
      index++;
    }
  }

  if(fg==1)
  {
    int i;
    clrscr();
    gotoxy(1,12);
    printTabs(stdArr,p,index-1);
    center("DELETED SUCCESSFULLY");
    for(i=index-1; i<ct; i++)
    {
     stdArr[i] = stdArr[i+1];
    }
    getch();
    ct--;
  }
  else
  {
    clrscr();
    gotoxy(1,12);
    center("Not found");
    getch();
  }
}
void deleteAdd(std stdArr[],char str[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].add, str)==0)
    {
      fg=1;
      index++;
      break;
    }
    else
    {
      index++;
    }
  }

  if(fg==1)
  {
    int i;
    clrscr();
    gotoxy(1,12);
    printTabs(stdArr,p,index-1);
    center("DELETED SUCCESSFULLY");
    for(i=index-1; i<ct; i++)
    {
     stdArr[i] = stdArr[i+1];
    }
    getch();
    ct--;
  }
  else
  {
    clrscr();
    gotoxy(1,12);
    center("Not found");
    getch();
  }
}
//.....................

void failureReports(std stdArr[])
{
    clrscr();
    header("<<< FAILUR REPORTS >>>");
    printf("%-11s%-15s%-11s%-7s%-20s%-4s%-4s%-4s%-4s\n","RollNo", "Name",
    "Branch", "Gender", "City","Mth","Phy","Che","Rslt");
    line(80,'~');
    int i;
    for(i=0; i<ct; i++)
    {
      if(percent(stdArr,i)<35)
      {
	printf("%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
	stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
	stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"F");
      }
    }
    getch();
}

//percentage.......
int percent(std stdArr[],int ind)
{
  int m = stdArr[ind].math;
  int p = stdArr[ind].phy;
  int c = stdArr[ind].chem;
  int per = (m+p+c)/3;
  return per;
}//ended percent

void highestScorer(std stdArr[])
{
  clrscr();
  header("<<< HIGHEST SCORER >>>");
  printf("%-11s%-15s%-11s%-7s%-20s%-4s%-4s%-4s%-4s\n","RollNo", "Name",
  "Branch", "Gender", "City","Mth","Phy","Che","Rslt");
  line(80,'~');
  int i;
  int ind=0;
  int max = percent(stdArr,0);
  for(i=0; i<ct; i++)
  {
    if(percent(stdArr,i)>max)
    {
       ind++;
    }
  }
  printf("%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[ind].roll,
  stdArr[ind].name,stdArr[ind].branch,stdArr[ind].gen,stdArr[ind].add,
  stdArr[ind].math,stdArr[ind].phy,stdArr[ind].chem,"P");
  getch();
}

void sortRecords(std stdArr[])
{
  int opn=0;
  do
  {
    clrscr();
    header("<<< SORT RECORDS >>>");
    gotoxy(38,6);
    printf("Students : %d\n\n",ct);
    center("       01. BY ROLL NUMBER");
    center("02. BY NAME");
    center("  03. BY BRANCH");
    center("  04. BY GENDER");
    center("05. BY CITY");
    center("  06. BY STATE");
    center("  07. BY DISTIC");
    center("         08. BY NATIONALITY\n");
    center("      0. EXIT\n\n");

    center("Choos an option (0 for back) : ");
    gotoxy(58,20);
    scanf("%d",&opn);
    fflush(stdin);

    switch(opn)
    {
      case 1:
	clrscr();
	header("<<<  BY ROLL NO  >>>");
	sortRollNo(stdArr);
	break;
      case 2:
	clrscr();
	header("<<<  BY NAME >>>");
	sortName(stdArr);
	break;
      case 3:
	clrscr();
	header("<<<  BY BRANCH  >>>");
	sortBranch(stdArr);
	break;
      case 4:
	clrscr();
	header("<<<  BY GENDER  >>>");
	sortGen(stdArr);
	break;
      case 5:
	clrscr();
	header("<<<  BY ADDRESS  >>>");
	sortAdd(stdArr);
	break;
      case 6:
	break;
      case 7:
	break;
      case 8:
	break;
      case 0:
	clrscr();
	gotoxy(1,12);
	center("Backed!!!");
	getch();
	break;
      default:
	clrscr();
	gotoxy(1,12);
	center("Wrong option!!!");
	getch();
    }
  }while(opn!=0);
}

//sorting..........................
int compareRoll(const void *a, const void *b)
{
  return strcmpi(((std *)a)->roll, ((std *)b)->roll);
}

void sortRollNo(std stdArr[])
{

  qsort(stdArr,ct,sizeof(std),compareRoll);
  printf("%-11s%-15s%-11s%-7s%-20s%-4s%-4s%-4s%-4s\n","RollNo", "Name",
  "Branch", "Gender", "City","Mth","Phy","Che","Rslt");
  line(80,'~');
  int i;
  for(i=0; i<ct; i++)
  {
    if(percent(stdArr,i)>35)
    {
      printf("%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
      stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
      stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"P");
    }
    else
    {
      printf("%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
      stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
      stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"F");
    }
  }
  getch();
}

int compareName(const void *a, const void *b)
{
  return strcmpi(((std *)a)->name, ((std *)b)->name);
}
void sortName(std stdArr[])
{

  qsort(stdArr,ct,sizeof(std),compareName);

  header("<<< SORT NAME >>>");
  printf("%-11s%-15s%-11s%-7s%-20s%-4s%-4s%-4s%-4s\n","RollNo", "Name",
  "Branch", "Gender", "City","Mth","Phy","Che","Rslt");
  line(80,'~');
  int i;
  for(i=0; i<ct; i++)
  {
    if(percent(stdArr,i)>35)
    {
      printf("%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
      stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
      stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"P");
    }
    else
    {
      printf("%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
      stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
      stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"F");
    }
  }
  getch();
}

int compareBranch(const void *a, const void *b)
{
  return strcmpi(((std *)a)->branch, ((std *)b)->branch);
}
void sortBranch(std stdArr[])
{

  qsort(stdArr,ct,sizeof(std),compareBranch);

  header("<<< SORT BRANCH >>>");
  printf("%-11s%-15s%-11s%-7s%-20s%-4s%-4s%-4s%-4s\n","RollNo", "Name",
  "Branch", "Gender", "City","Mth","Phy","Che","Rslt");
  line(80,'~');
  int i;
  for(i=0; i<ct; i++)
  {
    if(percent(stdArr,i)>35)
    {
      printf("%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
      stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
      stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"P");
    }
    else
    {
      printf("%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
      stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
      stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"F");
    }
  }
  getch();
}

int compareGen(const void *a, const void *b)
{
  return strcmpi(((std *)a)->gen, ((std *)b)->gen);
}
void sortGen(std stdArr[])
{

  qsort(stdArr,ct,sizeof(std),compareGen);

  header("<<< SORT BRANCH >>>");
  printf("%-11s%-15s%-11s%-7s%-20s%-4s%-4s%-4s%-4s\n","RollNo", "Name",
  "Branch", "Gender", "City","Mth","Phy","Che","Rslt");
  line(80,'~');
  int i;
  for(i=0; i<ct; i++)
  {
    if(percent(stdArr,i)>35)
    {
      printf("%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
      stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
      stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"P");
    }
    else
    {
      printf("%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
      stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
      stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"F");
    }
  }
  getch();
}

int compareAdd(const void *a, const void *b)
{
  return strcmpi(((std *)a)->add, ((std *)b)->add);
}
void sortAdd(std stdArr[])
{

  qsort(stdArr,ct,sizeof(std),compareAdd);

  header("<<< SORT BRANCH >>>");
  printf("%-11s%-15s%-11s%-7s%-20s%-4s%-4s%-4s%-4s\n","RollNo", "Name",
  "Branch", "Gender", "City","Mth","Phy","Che","Rslt");
  line(80,'~');
  int i;
  for(i=0; i<ct; i++)
  {
    if(percent(stdArr,i)>35)
    {
      printf("%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
      stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
      stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"P");
    }
    else
    {
      printf("%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
      stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
      stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"F");
    }
  }
  getch();
}
//.....................