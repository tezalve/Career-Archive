#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>

struct player
{
    char name[30];
    float age;
    char shortHistory[500];
    char position[50];
    float inningsPlayed;
    char kindofBatsman[100];
    float totalRuns;
    float highestRuns;
    float average;
    float total50s;
    float total100s;
    char kindofBowler[50];
    float totalWickets;
    float highestWickets;
    char bestFigure[20];
    float fastestBall;
    char records[500];

}list;

int c,choice;
FILE *fp;
char b,filename[30];

int main()
{
    printf("\n   **** Welcome to Bangladesh National Cricket Teams's Career Archive  ****");
    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new player\n\t\t[2] View a Player's career\n\t\t[3] Remove a player's data\n\t\t[4] Edit a players career\n\t\t[0] Exit\n\t\t=================\n\t\t");

    printf("Enter the choice:");
    scanf("%d",&choice);

    switch(choice)
    {
    case 0:

        system("cls");

        printf("\n\n\t\tAre you sure you want to exit?[Y/N]");
        fflush(stdin);
        scanf("%c",&b);

        if(b=='N'||b=='n')
        {
            system("cls");
            return main();
        }
        else
            return 0;

    case 1:

        system("cls");

        for (;;)

        {
            printf("To return to Main Menu enter 0 in Show Name\n");

            printf("Show Name:");
            fflush(stdin);
            scanf("%s",&filename);

            if( stricmp(filename,"0")==0 )
            {
                system("cls");
                return main();
            }

            fp=fopen(filename,"a");

            fflush(stdin);
            printf("\n\nFull Name:");
            scanf("%s",&list.name);


            fflush(stdin);
            printf("Age:");
            scanf("%d",&list.age);

            fflush(stdin);
            printf("Short History:");
            gets(list.shortHistory);
            fflush(stdin);

            printf("Playing As:");
            gets(list.position);
            fflush(stdin);

            printf("Total Innings Played:");
            scanf("%f",&list.inningsPlayed);
            fflush(stdin);

            printf("Kind of Batsman:");
            gets(list.kindofBatsman);
            fflush(stdin);

            printf("Total Runs:");
            scanf("%f",&list.totalRuns);
            fflush(stdin);

            printf("Highest Runs:");
            scanf("%f",&list.highestRuns);
            fflush(stdin);

            printf("Average Runs:");
            scanf("%f",&list.average);
            fflush(stdin);

            printf("Total 50s:");
            scanf("%f",&list.total50s);
            fflush(stdin);

            printf("Total 100s:");
            scanf("%f",&list.total100s);
            fflush(stdin);

            printf("Kind of Bowler:");
            scanf("%s",&list.kindofBowler);
            fflush(stdin);

            printf("Total Wickets:");
            scanf("%f",&list.totalWickets);
            fflush(stdin);

            printf("Highest Wickets:");
            scanf("%f",&list.highestWickets);
            fflush(stdin);

            printf("Best Figure:");
            scanf("%s",&list.bestFigure);
            fflush(stdin);

            printf("Records:");
            gets(list.records);
            fflush(stdin);


            printf("\n");

            fprintf(fp,"Full Name:%s\nAge:%f\nShort History:%s\nPosition:%s\nInnings Played:%.1f\nKind of Batsman:%s\nTotal Runs:%.1f\nHighest Runs:%.1f\nAverage:%.1f\nTotal 50s:%.1f\nTotal 100s:%.1f\nKind of Bowler:%s\nTotal Wickets:%.1f\nHighest Wickets:%.1f\nBest Figure:%s\nFastest Ball:%.1f\nRecords:%s\n\n",list.name,list.age,list.shortHistory,list.position,list.inningsPlayed,list.kindofBatsman,list.totalRuns,list.highestRuns,list.average,list.total50s,list.total100s,list.kindofBowler,list.totalWickets,list.highestWickets,list.bestFigure,list.fastestBall,list.records);

            fclose(fp);

        }


    case 2:

        system("cls");

        printf("\n\t\t================================\n\t\t\t Career \n\t\t================================\n");


        fflush(stdin);
        printf("Players Name:");
        scanf("%s",&filename);

        fp=fopen(filename,"r");

        if(fp == NULL)
        {
            printf("No player by that name.\n");
            fflush(stdin);
            printf("Press any key to return.");
            getchar();
            system("cls");
            return main();
        }

        while(1)
        {
            c = fgetc(fp);

            if(feof(fp))
                break;

            printf("%c",c);
        }
        printf("\n");

        printf("Do you want return to Main Menu?[Y/N]");
        fflush(stdin);
        scanf("%c",&b);
        if (b=='y' || b=='Y')
        {
            fclose(fp);
            system("cls");
            return main();
        }

        fclose(fp);
        return 0;


    case 3:

        system("cls");

        fflush(stdin);
        printf("Players Name:");
        scanf("%s",filename);

        char ch;
        fflush(stdin);

        printf("Are you sure?[Y/N]");
        scanf("%c",&ch);

        if (ch == 'n' || ch == 'N')
        {
            fclose(fp);
            system("cls");
            return main();
        }
        else
            remove(filename);

        printf("%s removed successfully\n",filename);

        printf("Return to Main Menu?[Y/N]");
        fflush(stdin);
        scanf("%c",&ch);
        if (ch == 'y' || ch == 'y')
        {
            system("cls");
            return main();
        }
        else
            return 0;


    case 4:

        system("cls");

        for (;;)

        {
            printf("To return to Main Menu enter 0 in Name\n");

            printf("Name:");
            fflush(stdin);
            scanf("%s",&filename);

            if( stricmp(filename,"0")==0 )
            {
                system("cls");
                return main();
            }

            fp=fopen(filename,"r");

            if(fp == NULL)
            {
                printf("No player by that name.\n");
                fflush(stdin);
                printf("Press any key to return.");
                getchar();
                system("cls");
                return main();
            }

            fclose(fp);
            remove(filename);

            fp=fopen(filename,"a");

            fflush(stdin);
            printf("Age:");
            scanf("%d",&list.age);

            fflush(stdin);
            printf("Short History:");
            gets(list.shortHistory);
            fflush(stdin);

            printf("Playing As:");
            gets(list.position);
            fflush(stdin);

            printf("Total Innings Played:");
            scanf("%f",&list.inningsPlayed);
            fflush(stdin);

            printf("Kind of Batsman:");
            gets(list.kindofBatsman);
            fflush(stdin);

            printf("Total Runs:");
            scanf("%f",&list.totalRuns);
            fflush(stdin);

            printf("Highest Runs:");
            scanf("%f",&list.highestRuns);
            fflush(stdin);

            printf("Average Runs:");
            scanf("%f",&list.average);
            fflush(stdin);

            printf("Total 50s:");
            scanf("%f",&list.total50s);
            fflush(stdin);

            printf("Total 100s:");
            scanf("%f",&list.total100s);
            fflush(stdin);

            printf("Kind of Bowler:");
            scanf("%s",&list.kindofBowler);
            fflush(stdin);

            printf("Total Wickets:");
            scanf("%f",&list.totalWickets);
            fflush(stdin);

            printf("Highest Wickets:");
            scanf("%f",&list.highestWickets);
            fflush(stdin);

            printf("Best Figure:");
            scanf("%s",&list.bestFigure);
            fflush(stdin);

            printf("Records:");
            gets(list.records);
            fflush(stdin);


            printf("\n");

            fprintf(fp,"Age:%f\nShort History:%s\nPosition:%s\nInnings Played:%.1f\nKind of Batsman:%s\nTotal Runs:%.1f\nHighest Runs:%.1f\nAverage:%.1f\nTotal 50s:%.1f\nTotal 100s:%.1f\nKind of Bowler:%s\nTotal Wickets:%.1f\nHighest Wickets:%.1f\nBest Figure:%s\nFastest Ball:%.1f\nRecords:%s\n\n",list.age,list.shortHistory,list.position,list.inningsPlayed,list.kindofBatsman,list.totalRuns,list.highestRuns,list.average,list.total50s,list.total100s,list.kindofBowler,list.totalWickets,list.highestWickets,list.bestFigure,list.fastestBall,list.records);

            fclose(fp);

        }

}
}
