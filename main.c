#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#define FILENAME "gym_members.txt"

typedef struct {
    int id;
    char name[50];
    int age;
    char category[20];
    char memberSince[20];
} Member;

COORD c;

void clearScreen(){
    system("cls");
}

void gotoXY(int x,int y){
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int getNextId() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) return 1;

    Member member;
    int maxId = 0;
    while (fscanf(file, "%d %s %d %s %s", &member.id, member.name, &member.age, member.category, member.memberSince) != EOF) {
        if (member.id > maxId) {
            maxId = member.id;
        }
    }

    fclose(file);
    return maxId + 1;
}

void abortSearch(){
    while(1){
        gotoXY(20,25);
        printf("[-1]Search from start");
        gotoXY(60,25);
        printf("[0]Main Menu");
        int ch;
        gotoXY(20,19);
        printf("Program aborted.");
        gotoXY(20,21);
        printf("Enter choice: ");
        scanf("%d",&ch);
        if(ch==-1){
            searchMember();
            break;
        }
        else if(ch==0){
            mainMenu();
            break;
        }
        else{
            gotoXY(20,22);
            printf("Invalid choice. Please try again");
        }
    }
}

void abortDelele(){
    while(1){
        gotoXY(20,25);
        printf("[-1]Delete from start");
        gotoXY(60,25);
        printf("[0]Main Menu");
        int ch;
        gotoXY(20,19);
        printf("Program aborted.");
        gotoXY(20,21);
        printf("Enter choice: ");
        scanf("%d",&ch);
        if(ch==-1){
            updateMember();
            break;
        }
        else if(ch==0){
            mainMenu();
            break;
        }
        else{
            gotoXY(20,22);
            printf("Invalid choice. Please try again");
        }
    }
}

void abortUpdate(){
    int count=0;
    while(1){
        gotoXY(20,25);
        printf("[-1]Update from start");
        gotoXY(60,25);
        printf("[0]Main Menu");
        int ch;
        gotoXY(20,19);
        printf("Program aborted.");
        gotoXY(20,21);
        printf("Enter choice: ");
        scanf("%d",&ch);
        if(ch==-1){
            updateMember();
            break;
        }
        else if(ch==0){
            mainMenu();
            break;
        }
        else{
            gotoXY(20,22);
            printf("Invalid choice. Please try again");
        }
    }
}

void abortAdd(){
    while(1){
        gotoXY(20,25);
        printf("[-1]Add from start");
        gotoXY(60,25);
        printf("[0]Main Menu");
        int ch;
        gotoXY(20,19);
        printf("Program aborted.");
        gotoXY(20,21);
        printf("Enter choice: ");
        scanf("%d",&ch);
        if(ch==-1){
            addMember();
            break;
        }
        else if(ch==0){
            mainMenu();
            break;
        }
        else{
            gotoXY(20,22);
            printf("Invalid choice. Please try again");
        }
    }
}
void nameSearch(){
    clearScreen();
    Member member;
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Could not open file.\n");
        return;
    }

    gotoXY(20,25);
    printf("[-2]Abort");
    char s[100];
    gotoXY(20,5);
    printf("Enter the name you want to search: ");
    scanf("%s",s);

    int found=1;

    if(strcmp(s,"-2")==0){
        abortSearch();
    }
    else{
        while(fscanf(file,"%d %s %d %s %s",&member.id,member.name,&member.age,member.category,member.memberSince)!=EOF){
            for(int i=0;i<strlen(member.name);i++){
                if(tolower(member.name[i])!=tolower(s[i])){
                    found=0;
                    break;
                }
            }
            if(found==1){
                gotoXY(20,7);
                printf("Member Details:\n");
                gotoXY(20,8);
                printf("ID: %d\n", member.id);
                gotoXY(20,9);
                printf("Name: %s\n", member.name);
                gotoXY(20,10);
                printf("Age: %d\n", member.age);
                gotoXY(20,11);
                printf("Category: %s\n", member.category);
                gotoXY(20,12);
                printf("Member Since: %s\n", member.memberSince);
                break;
            }
        }
    }
    if(found==0){
        gotoXY(20,13);
        printf("Member not found.");
    }

    gotoXY(15,25);
    printf("[-1]Search from start");
    gotoXY(55,25);
    printf("[0]Main Menu");
    gotoXY(90,25);
    printf("[1]Search from name");

    int count=0;

    while(1){
        if(count==0){
            gotoXY(20,16);
            printf("Enter Choice: ");
            char choice;
            scanf("%c",&choice);
            if(choice=='-1'){
                searchMember();
                break;
            }
            else if(choice=='0'){
                mainMenu();
                break;
            }
            else if(choice=='1'){
                nameSearch();
                break;
            }
            else{
                count++;
            }
        }
        else{
            gotoXY(20,16);
            printf("Enter Choice: ");
            char choice;
            scanf("%c",&choice);
            if(choice=='-1'){
                searchMember();
                break;
            }
            else if(choice=='0'){
                mainMenu();
                break;
            }
            else if(choice=='1'){
                nameSearch();
                break;
            }
            else{
                gotoXY(20,17);
                printf("Invalid choice. Please try again...");
            }
        }
    }
}

void idSearch(){
    clearScreen();
    Member member;
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Could not open file.\n");
        return;
    }

    gotoXY(20,25);
    printf("[-2]Abort");
    int id;
    gotoXY(20,5);
    printf("Enter the id you want to search: ");
    scanf("%d",&id);

    int found=0;

    if(id==-2){
        abortSearch();
    }
    else{
        while(fscanf(file,"%d %s %d %s %s",&member.id,member.name,&member.age,member.category,member.memberSince)!=EOF){
            if(member.id==id){
                found=1;
                gotoXY(20,7);
                printf("Member Details:\n");
                gotoXY(20,8);
                printf("ID: %d\n", member.id);
                gotoXY(20,9);
                printf("Name: %s\n", member.name);
                gotoXY(20,10);
                printf("Age: %d\n", member.age);
                gotoXY(20,11);
                printf("Category: %s\n", member.category);
                gotoXY(20,12);
                printf("Member Since: %s\n", member.memberSince);
                break;
            }
        }
    }
    if(found==0){
        gotoXY(20,13);
        printf("Member not found.");
    }

    gotoXY(15,25);
    printf("[-1]Search from start");
    gotoXY(55,25);
    printf("[0]Main Menu");
    gotoXY(90,25);
    printf("[1]Search from id");

    int count=0;

    while(1){
        if(count==0){
            gotoXY(20,16);
            printf("Enter Choice: ");
            char choice;
            scanf("%c",&choice);
            if(choice=='-1'){
                searchMember();
                break;
            }
            else if(choice=='0'){
                mainMenu();
                break;
            }
            else if(choice=='1'){
                idSearch();
                break;
            }
            else{
                count++;
            }
        }
        else{
            gotoXY(20,16);
            printf("Enter Choice: ");
            char choice;
            scanf("%c",&choice);
            if(choice=='-1'){
                searchMember();
                break;
            }
            else if(choice=='0'){
                mainMenu();
                break;
            }
            else if(choice=='1'){
                idSearch();
                break;
            }
            else{
                gotoXY(20,17);
                printf("Invalid choice. Please try again...");
            }
        }
    }
}

void exitApp(){
    clearScreen();
    gotoXY(20,5);
    printf("GYM APPLICATION SYSTEM\n");
    gotoXY(15,8);
    printf("Prepared by:");
    gotoXY(15,10);
    printf("Mohammad Ashraful Alam");
    gotoXY(15,11);
    printf("ID: 2309025");
    gotoXY(15,12);
    printf("Reg: 57109\n");
    exit(0);
}

void resetData(){
    clearScreen();

    gotoXY(20,15);
    printf("[Y/y]Yes");
    gotoXY(60,15);
    printf("[Any]No");
    gotoXY(40,15);
    printf("[0]Main Menu");

    gotoXY(20,5);
    printf("Are you sure you want to reset all data?: ");

    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        if (remove(FILENAME) == 0) {
            gotoXY(20,7);
            printf("All data has been reset successfully.\n");
        }
        else{
            gotoXY(20,7);
            printf("Error resetting data. File may not exist.\n");
        }
    }
    else if(choice=='0'){
        mainMenu();
    }
    else{
        gotoXY(20,7);
        printf("Data reset canceled.\n");
    }

    while (1){
        gotoXY(20,11);
        printf("Enter choice: ");
        int cmd;
        scanf("%d", &cmd);
        if(cmd==0) {
            mainMenu();
            break;
        }
        else{
            gotoXY(20,12);
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void deleteMember(){
    clearScreen();
    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (!file || !tempFile) {
        printf("Could not open file.\n");
        return;
    }

    gotoXY(20,25);
    printf("[-2]Abort");

    int id;
    gotoXY(20,5);
    printf("Enter ID of the member to delete: ");
    scanf("%d", &id);
    if(id==-2){
        abortDelele();
    }

    Member member;
    int found = 0;
    int flag = 0;

    while(fscanf(file, "%d %s %d %s %s", &member.id, member.name, &member.age, member.category, member.memberSince) != EOF) {
        if(member.id == id) {
            found = 1;
            gotoXY(20,7);
            printf("Member Details:\n");
            gotoXY(20,8);
            printf("ID: %d\n", member.id);
            gotoXY(20,9);
            printf("Name: %s\n", member.name);
            gotoXY(20,10);
            printf("Age: %d\n", member.age);
            gotoXY(20,11);
            printf("Category: %s\n", member.category);
            gotoXY(20,12);
            printf("Member Since: %s\n", member.memberSince);
            gotoXY(20,25);
            printf("[-1]Delete from start");
            gotoXY(60,25);
            printf("[0]Main Menu");
            gotoXY(20,14);
            printf("Do you really want to delete this member? (y/n): ");
            char choice;
            scanf(" %c", &choice);

            if (choice == 'y' || choice == 'Y') {
                flag = 1;
                continue;
            }
            else if(choice == 'n' || choice == 'N') {
                flag = 0;
            }
        }
        fprintf(tempFile, "%d %s %d %s %s\n", member.id, member.name, member.age, member.category, member.memberSince);
    }

    fclose(file);
    fclose(tempFile);

    if(found){
        if(flag){
            remove(FILENAME);
            rename("temp.txt", FILENAME);
            gotoXY(20,16);
            printf("Member deleted successfully.\n");
        }
        else{
            remove("temp.txt");
            gotoXY(20,16);
            printf("Member deletion prevented.\n");
        }
    }
    else{
        remove("temp.txt");
        gotoXY(20,16);
        printf("Member not found.\n");
    }

    while(1){
        gotoXY(20,19);
        printf("Enter choice: ");
        int cmd;
        scanf("%d", &cmd);
        if (cmd==0) {
            mainMenu();
            break;
        }
        else if(cmd==-1){
            deleteMember();
            break;
        }
    }
}

void updateMember(){
    clearScreen();
    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (!file || !tempFile) {
        printf("Could not open file.\n");
        return;
    }

    gotoXY(20,25);
    printf("[-2]Abort");
    gotoXY(20,5);
    int id;
    printf("Enter ID of the member to update: ");
    scanf("%d", &id);
    if(id==-2){
        abortUpdate();
    }

    Member member;
    int found = 0;

    while (fscanf(file, "%d %s %d %s %s", &member.id, member.name, &member.age, member.category, member.memberSince) != EOF) {
        if (member.id == id) {
            found = 1;
            gotoXY(20,7);
            printf("Enter new Name: ");
            scanf("%s", member.name);
            if(strcmp(member.name,"-2")==0){
                abortUpdate();
            }

            gotoXY(20,9);
            printf("Enter new Age: ");
            scanf("%d", &member.age);
            if(member.age==-2){
                abortUpdate();
            }

            gotoXY(20,11);
            printf("Enter new Member Since (DD-MMM-YYYY): ");
            scanf("%s", member.memberSince);
            if(strcmp(member.name,"-2")==0){
                abortUpdate();
            }

        }
        fprintf(tempFile, "%d %s %d %s %s\n", member.id, member.name, member.age, member.category, member.memberSince);
    }

    fclose(file);
    fclose(tempFile);

    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found) {
        gotoXY(20,16);
        printf("Member updated successfully.\n");
    }
    else{
        gotoXY(20,16);
        printf("Member not found.\n");
    }

    while(1){
        gotoXY(20,25);
        printf("[-1]Update from start");
        gotoXY(60,25);
        printf("[0]Main Menu");
        gotoXY(20,18);
        printf("Enter Choice: ");
        int cmd;
        scanf("%d", &cmd);
        if(cmd==0) {
            mainMenu();
            break;
        }
        else if(cmd==1){
            updateMember();
            break;
        }
        else{
            gotoXY(20,19);
            printf("Invalid Choice. Please try again.");
        }
    }
}

void searchMember(){
    clearScreen();
    gotoXY(20,25);
    printf("[1]NAME");
    gotoXY(90,25);
    printf("[2]ID");

    gotoXY(20,5);
    printf("Do you want to search by NAME or ID: ");
    switch(getch()){
    case '1':
        gotoXY(20,10);
        printf("Redirecting to search by name...");
        gotoXY(20,11);
        printf("Press any key to continue...");
        getch();
        nameSearch();
        break;
    case '2':
        gotoXY(20,10);
        printf("Redirecting to search by id...");
        gotoXY(20,11);
        printf("Press any key to continue...");
        getch();
        idSearch();
        break;
    default:
        gotoXY(20,11);
        printf("Invalid input. Press any key to try again...");
        getch();
        searchMember();
    }
}

void displayMembers(){
    clearScreen();
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Could not open file.\n");
        return;
    }

    Member member;
    gotoXY(20,5);
    printf("----------------------------------------------\n");
    gotoXY(20,6);
    printf("Category     ID   Name      Age   Member Since\n");
    gotoXY(20,7);
    printf("----------------------------------------------\n");
    int i=20,j=7;
    while (fscanf(file, "%d %s %d %s %s", &member.id, member.name, &member.age, member.category, member.memberSince) != EOF) {
        j++;
        gotoXY(i,j);
        printf("%s",member.category);
        i+=13;
        gotoXY(i,j);
        printf("%d",member.id);
        i+=5;
        gotoXY(i,j);
        printf("%s",member.name);
        i+=10;
        gotoXY(i,j);
        printf("%d",member.age);
        i+=6;
        gotoXY(i,j);
        printf("%s",member.memberSince);
        i=20;
    }

    gotoXY(20,j+7);
    printf("[0]Main Menu");

    fclose(file);

    int count=0;

    while(1){
        if(count==0){
            gotoXY(20,j+4);
            printf("Enter choice: ");
            char cmd;
            scanf("%c",&cmd);
            if(cmd=='0'){
                mainMenu();
                break;
            }
            else{
                count++;
            }
        }
        else{
            gotoXY(20,j+4);
            printf("Enter choice: ");
            char cmd;
            scanf("%c",&cmd);
            if(cmd=='0'){
                mainMenu();
                break;
            }
            else{
                gotoXY(20,j+5);
                printf("Invalid input. Please try again...");
            }
        }
    }
}

void addMember(){
    clearScreen();
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        printf("Could not open file.\n");
        return;
    }

    Member member;
    member.id = getNextId();

    gotoXY(20,7);
    printf("Select Category:\n");
    gotoXY(20,9);
    printf("[1] Staff\n");
    gotoXY(20,11);
    printf("[2] Trainer\n");
    gotoXY(20,13);
    printf("[3] Member\n");
    gotoXY(20,15);
    printf("[4] Back to main menu\n");
    gotoXY(20,17);
    printf("Enter choice: ");

    switch(getch()){
    case '1':
        strcpy(member.category, "Staff");
        break;
    case '2':
        strcpy(member.category, "Trainer");
        break;
    case '3':
        strcpy(member.category, "Member");
        break;
    case '4':
        mainMenu();
        break;
    default:
        gotoXY(20,19);
        printf("Invalid choice. Press any key to try again.\n");
        getch();
        addMember();
    }
    clearScreen();
    gotoXY(20,7);
    printf("Category: %s\n",member.category);
    gotoXY(20,9);
    printf("ID: %d\n",member.id);
    gotoXY(20,25);
    printf("[-2]Abort");
    gotoXY(20,11);
    printf("Name: ");
    scanf("%s", member.name);
    if(strcmp(member.name,"-2")==0){
        abortAdd();
    }

    gotoXY(20,13);
    printf("Age: ");
    scanf("%d", &member.age);
    if(member.age==-2){
        abortAdd();
    }
    gotoXY(20,15);
    printf("Member Since (DD-MMM-YYYY): ");
    scanf("%s", member.memberSince);
    if(strcmp(member.memberSince,"-2")==0){
        abortAdd();
    }

    fprintf(file, "%d %s %d %s %s\n", member.id, member.name, member.age, member.category, member.memberSince);
    fclose(file);

    gotoXY(20,17);
    printf("Member added successfully.\n");

    gotoXY(20,25);
    printf("[-1]Add from start");
    gotoXY(60,25);
    printf("[0]Main Menu");

    while(1){
        gotoXY(20,19);
        printf("Enter choice: ");
        char cmd;
        scanf("%c", &cmd);
        if(cmd=='0') {
            mainMenu();
            break;
        }
        else if(cmd=='-1'){
            addMember();
            break;
        }
        else{
            gotoXY(20,20);
            printf("Invalid choice. Please try again\n");
        }
    }
}

void mainMenu(){
    clearScreen();

    gotoXY(20,5);
    printf("\t\tGym Management System");
    gotoXY(20,9);
    printf("[1] Add Member");
    gotoXY(20,11);
    printf("[2] Display Members");
    gotoXY(20,13);
    printf("[3] Search Member");
    gotoXY(20,15);
    printf("[4] Update Member");
    gotoXY(20,17);
    printf("[5] Delete Member");
    gotoXY(20,19);
    printf("[6] Reset Data");
    gotoXY(20,21);
    printf("[7] Exit");
    gotoXY(20,24);
    printf("Enter your choice: ");

    switch(getch()){
        case '1':
            addMember();
            break;
        case '2':
            displayMembers();
            break;
        case '3':
            searchMember();
            break;
        case '4':
            updateMember();
            break;
        case '5':
            deleteMember();
            break;
        case '6':
            resetData();
            break;
        case '7':
            exitApp();
            break;
        default:
            gotoXY(20,26);
            printf("Wrong input. Press any key to try again...");
            getch();
            mainMenu();
    }
}

int main() {
    mainMenu();
    return 0;
}
