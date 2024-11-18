#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

void gotoxy(int, int);
void menu();
void addEx();
void addIn();
void view_ex();
void view_in();
void balance();
void search();
void modify();
void delete();

struct tracker
{
	char type[10];
	char remark[50];
	char category[20];
	int ex_amount;
	int in_amount;
	int id;
};
int count;

int main()
{
	struct tracker std;
	FILE *fp = fopen("Tracker.txt", "rb+");
	if (fp == NULL)
	{
		fp = fopen("Tracker.txt", "w");
		if (fp == NULL)
		{
			printf("Error in opening file");
			exit(1);
		}
		count = 1480;
		fclose(fp);
	}
	else
	{
		while (fread(&std, sizeof(std), 1, fp) == 1)
		{
			count = std.id;
		}
	}
	fclose(fp);
	system("cls");
	gotoxy(15, 8);
	printf("<--:Expense Tracker:-->");
	gotoxy(19, 15);
	printf("Press any key to continue.");
	getch();
	menu();
	return 0;
}

void menu()
{
	int choice;
	system("cls");
	gotoxy(10, 3);
	printf("<--:MENU:-->");
	gotoxy(10, 5);
	printf("Enter appropriate number to perform following task.");
	gotoxy(10, 7);
	printf("1 : Add Expense.");
	gotoxy(10, 8);
	printf("2 : Add Income.");
	gotoxy(10, 9);
	printf("3 : View Expense.");
	gotoxy(10, 10);
	printf("4 : View Income.");
	gotoxy(10, 11);
	printf("5 : View Balance.");
	gotoxy(10, 12);
	printf("6 : Search Record.");
	gotoxy(10, 13);
	printf("7 : Modify Record.");
	gotoxy(10, 14);
	printf("8 : Delete Record.");
	gotoxy(10, 15);
	printf("9 : Exit.");
	gotoxy(10, 18);
	printf("Enter your choice.");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		addEx();
		break;
	case 2:
		addIn();
		break;
	case 3:
		view_ex();
		break;
	case 4:
		view_in();
		break;
	case 5:
		balance();
		break;
	case 6:
		search();
		break;
	case 7:
		modify();
		break;
	case 8:
		delete (1);
		break;
	case 9:
		exit(1);
		break;
	default:
		gotoxy(10, 17);
		printf("Invalid Choice.");
	}
}

void addEx()
{
	FILE *fp;
	struct tracker std;
	char another = 'y';
	system("cls");

	fp = fopen("Tracker.txt", "ab+");

	if (fp == NULL)
	{
		gotoxy(10, 5);
		printf("Error opening file");
		exit(1);
	}

	fflush(stdin);

	while (another == 'y' || another == 'Y')
	{
		strcpy(std.type, "Expense");
		gotoxy(10, 3);
		fflush(stdin);
		printf("<--:ADD Expense:-->");
		gotoxy(10, 5);
		printf("Enter details of Expense.");
		gotoxy(10, 7);
		printf("Enter category : ");
		gets(std.category);
		gotoxy(10, 8);
		printf("Enter Remark : ");
		gets(std.remark);
		fflush(stdin);
		gotoxy(10, 9);
		printf("Enter Amount : ");
		scanf("%d", &std.ex_amount);
		fflush(stdin);
		count++;
		std.id = count;
		fwrite(&std, sizeof(std), 1, fp);
		gotoxy(10, 15);
		printf("Want to add of another record? Then press 'y' else 'n'.");
		fflush(stdin);
		another = getch();
		system("cls");
		fflush(stdin);
	}

	fclose(fp);
	menu();
}

void addIn()
{
	FILE *fp;
	struct tracker std;
	char another = 'y';
	system("cls");

	fp = fopen("Tracker.txt", "ab+");

	if (fp == NULL)
	{
		gotoxy(10, 5);
		printf("Error opening file");
		exit(1);
	}

	fflush(stdin);

	while (another == 'y' || another == 'Y')
	{
		gotoxy(10, 3);
		printf("<--:ADD INCOME:-->");
		gotoxy(10, 5);
		printf("Enter details of Income.");
		strcpy(std.type, "Income");
		gotoxy(10, 7);
		printf("Enter category : ");
		gets(std.category);
		gotoxy(10, 8);
		printf("Enter Remark : ");
		fflush(stdin);
		gets(std.remark);
		gotoxy(10, 9);
		printf("Enter Amount : ");
		scanf("%d", &std.in_amount);
		fflush(stdin);
		count++;
		std.id = count;
		fwrite(&std, sizeof(std), 1, fp);
		gotoxy(10, 15);
		printf("Want to add of another record? Then press 'y' else 'n'.");
		fflush(stdin);
		another = getch();
		system("cls");
		fflush(stdin);
	}

	fclose(fp);
	menu();
}

void view_ex()
{
	FILE *fp;
	int i = 1, j;
	struct tracker std;
	system("cls");
	gotoxy(10, 3);
	printf("<--:VIEW EXPENSE:-->");
	gotoxy(10, 5);
	printf("S.No\tID\tCategory\tAmount\tTotal-Expense\tRemark");
	gotoxy(10, 6);
	printf("------------------------------------------------------------");

	fp = fopen("Tracker.txt", "rb+");
	if (fp == NULL)
	{
		gotoxy(10, 8);
		printf("Error opening file.");
		exit(1);
	}

	j = 8;
	int ex_total = 0;
	char str[] = "Income";

	while (fread(&std, sizeof(std), 1, fp) == 1)
	{
		if (strcmp(str, std.type) != 0)
		{
			ex_total += std.ex_amount;
			gotoxy(10, j);
			printf("%d\t%d\t%s\t\t%d\t%d\t\t%s", i, std.id, std.category, std.ex_amount, ex_total, std.remark);
			i++;
			j++;
		}
	}

	fclose(fp);
	gotoxy(10, j + 3);
	printf("Press any key to continue.");
	getch();
	menu();
}

void view_in()
{
	FILE *fp;
	int i = 1, j;
	struct tracker std;
	system("cls");
	gotoxy(10, 3);
	printf("<--:VIEW INCOME:-->");
	gotoxy(10, 5);
	printf("S.No\tID\tCategory\tAmount\tTotal-Income\tRemark");
	gotoxy(10, 6);
	printf("------------------------------------------------------------");

	fp = fopen("Tracker.txt", "rb+");
	if (fp == NULL)
	{
		gotoxy(10, 8);
		printf("Error opening file.");
		exit(1);
	}

	j = 8;
	int in_total = 0;
	char str[] = "Income";

	while (fread(&std, sizeof(std), 1, fp) == 1)
	{
		if (strcmp(str, std.type) == 0)
		{
			in_total += std.in_amount;
			gotoxy(10, j);
			printf("%d\t%d\t%s\t\t%d\t%d\t\t%s", i, std.id, std.category, std.in_amount, in_total, std.remark);
			i++;
			j++;
		}
	}

	fclose(fp);
	gotoxy(10, j + 3);
	printf("Press any key to continue.");
	getch();
	menu();
}

void balance()
{
	FILE *fp;
	struct tracker std;
	system("cls");

	gotoxy(10, 3);
	printf("<--:VIEW BALANCE:-->");

	fp = fopen("Tracker.txt", "r");
	if (fp == NULL)
	{
		gotoxy(10, 8);
		printf("Error opening file.");
		exit(1);
	}

	int ex_total = 0;
	int in_total = 0;
	int balance = 0;
	char str[] = "Income";

	while (fread(&std, sizeof(std), 1, fp) == 1)
	{
		if (strcmp(str, std.type) != 0)
		{
			ex_total += std.ex_amount;
		}
		else
		{
			in_total += std.in_amount;
		}
	}
	balance += in_total - ex_total;

	gotoxy(10, 5);
	printf("Balance = %d", balance);
	gotoxy(10, 6);
	printf("Total Income = %d", in_total);
	gotoxy(10, 7);
	printf("Total Expense = %d", ex_total);

	gotoxy(10, 10);
	printf("Press any key to continue: ");
	getch();
	menu();
}

void search()
{
	FILE *fp;
	struct tracker std;
	char category[20];
	int i = 1, j;
	char str[] = "Income";
	system("cls");
	gotoxy(10, 3);
	printf("<--:SEARCH RECORD:-->");
	gotoxy(10, 5);
	printf("Enter category : ");
	fflush(stdin);
	gets(category);
	fp = fopen("Tracker.txt", "r");

	if (fp == NULL)
	{
		gotoxy(10, 6);
		printf("Error opening file");
		exit(1);
	}

	gotoxy(10, 8);
	printf("S.No\tID\tType\tCategory\tAmount\tRemark");
	gotoxy(10, 9);
	printf("------------------------------------------------------------");
	j = 10;
	while (fread(&std, sizeof(std), 1, fp) == 1)
	{

		if (strcmp(category, std.category) == 0)
		{
			if (strcmp(str, std.type) != 0)
			{
				gotoxy(10, j);
				printf("%d\t%d\t%s\t%s\t\t%d\t%s", i, std.id, std.type, std.category, std.ex_amount, std.remark);
				i++;
				j++;
			}
			else
			{
				gotoxy(10, j);
				printf("%d\t%d\t%s\t%s\t\t%d\t%s", i, std.id, std.type, std.category, std.in_amount, std.remark);
				i++;
				j++;
			}
		}
	}
	if (j <= 10)
	{
		gotoxy(15, j + 1);
		printf("No Data Found.");
	}

	fclose(fp);
	gotoxy(10, j + 4);
	printf("Press any key to continue.");
	getch();
	menu();
}

void modify()
{
	int id;
	boolean status = FALSE;
	FILE *fp;
	struct tracker std;
	system("cls");
	gotoxy(10, 3);
	printf("<--:MODIFY RECORD:-->");
	gotoxy(10, 5);
	printf("Enter ID of transection to modify record : ");
	scanf("%d", &id);
	fflush(stdin);
	fp = fopen("Tracker.txt", "rb+");

	if (fp == NULL)
	{
		gotoxy(10, 6);
		printf("Error opening file");
		exit(1);
	}

	rewind(fp);
	fflush(stdin);

	while (fread(&std, sizeof(std), 1, fp) == 1)
	{

		if (id == std.id)
		{
			gotoxy(10, 7);
			printf("Enter category : ");
			gets(std.category);
			gotoxy(10, 8);
			printf("Enter Remark : ");
			gets(std.remark);
			fflush(stdin);
			gotoxy(10, 9);
			printf("Enter Amount : ");
			scanf("%d", &std.ex_amount);
			fseek(fp, -sizeof(std), SEEK_CUR);
			fwrite(&std, sizeof(std), 1, fp);
			gotoxy(10, 13);
			printf("Record Modified Successfully.");
			status = TRUE;
			break;
		}
	}

	if (status == FALSE)
	{
		gotoxy(10, 13);
		printf("Record Not Found/Invalid ID.");
	}
	fclose(fp);
	gotoxy(10, 16);
	printf("Press any key to continue.");
	getch();
	menu();
}

void delete()
{
	int id;
	boolean status = FALSE;
	FILE *fp, *ft;
	struct tracker std;
	system("cls");
	gotoxy(10, 3);
	printf("<--:DELETE RECORD:-->");
	gotoxy(10, 5);

	printf("Enter ID of transection to delete record : ");
	fflush(stdin);
	scanf("%d", &id);
	fp = fopen("Tracker.txt", "rb+");

	if (fp == NULL)
	{
		gotoxy(10, 6);
		printf("Error opening file");
		exit(1);
	}

	ft = fopen("temp.txt", "wb+");

	if (ft == NULL)
	{
		gotoxy(10, 6);
		printf("Error opening file");
		exit(1);
	}

	while (fread(&std, sizeof(std), 1, fp) == 1)
	{

		if (id != std.id)
		{
			fwrite(&std, sizeof(std), 1, ft);
		}
		else
		{
			status = TRUE;
		}
	}

	fclose(fp);
	fclose(ft);
	remove("Tracker.txt");
	rename("temp.txt", "Tracker.txt");
	if (status == TRUE)
	{
		gotoxy(10, 7);
		printf("Record Deleted successfully.");
	}
	else
	{
		gotoxy(10, 7);
		printf("Record Not Deleted/Invalid ID.");
	}
	gotoxy(10, 10);
	printf("Press any key to continue.");
	getch();
	menu();
}

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}