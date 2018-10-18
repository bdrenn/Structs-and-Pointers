/*
 Name: Brian Drennan
 Class: CECS 282-05
 Project Name: Prog 2 - Structs and Pointers
 Due Date: 10/17/2018
 */
#include <iostream>
#include "myDate.hpp"
#include <time.h>
#include <iomanip>

struct Student;
void Populate(Student sa[]);
int StudentID();
myDate Birthdays();
char Grades();
void SortByName(Student *sa[]);
void SortByGrade(Student *sa[]);
void SortByID(Student *sa[]);
void SortByBirthdays(Student *sa[]);
void SortByHomeTown(Student *sa[]);
void display(Student *sa[]);
void display2(Student sp[]);


struct Student {
    char name[20]; //cstring or null terminated character array
    int ID;
    char grade;
    myDate birthday;
    string homeTown;
};

int main() {
    //time
    srand( static_cast<unsigned int>(time(NULL)));
    
    //arrays
    Student myClass[10]; //original
    Student *names[10]; //name sort
    Student *grades[10]; //grade sort
    Student *IDs[10]; //ID sort
    Student *Birthdays[10]; //Birthday Sort
    Student *HomeTown[10]; //HomeTown Sort
    
    //Populating students in array
    Populate(myClass);
    
    //populating the array of pointers
    for(int x = 0; x < 10; x++){
        names[x] = &myClass[x];
        grades[x] = &myClass[x];
        IDs[x] = &myClass[x];
        Birthdays[x] = &myClass[x];
        HomeTown[x] = &myClass[x];
    }
    
    //printing name sort
    SortByName(names);
    SortByGrade(grades);
    SortByID(IDs);
    SortByBirthdays(Birthdays);
    SortByHomeTown(HomeTown);

    
    cout << "\n0) Display Original list\n";
    cout << "1) Display list sorted by Name\n";
    cout << "2) Display list sorted by Student ID\n";
    cout << "3) Display list sorted by Grade\n";
    cout << "4) Display list sorted by Birthday\n";
    cout << "5) Display list sorted by HomeTown\n";
    cout << "6) Exit\n";
    
    int response;
    cin >> response;
    
    //control for game play
    while(response != 6){
        
        if(response == 0){
            display2(myClass);
        }
        else if(response == 1){
            display(names);
        }
        else if(response == 2){
            display(IDs);
        }
        else if(response == 3){
            display(grades);
        }
        else if(response == 4){
            display(Birthdays);
        }
        else if(response == 5){
            display(HomeTown);
        }
        else{
            cout << "You have exited";
        }
        
        cout << "\n0) Display Original list\n";
        cout << "1) Display list sorted by Name\n";
        cout << "2) Display list sorted by Student ID\n";
        cout << "3) Display list sorted by Grade\n";
        cout << "4) Display list sorted by Birthday\n";
        cout << "5) Display list sorted by HomeTown\n";
        cout << "6) Exit\n";
        
        cin >> response;
    }
}

void Populate(Student sa[]){
    for(int x = 0; x < 10; x++){
        sa[x].ID = StudentID();
        sa[x].grade = Grades();
        sa[x].birthday = Birthdays();
    }
    
    strcpy(sa[0].name, "Steve");
    strcpy(sa[1].name, "Joe");
    strcpy(sa[2].name, "Marve");
    strcpy(sa[3].name, "Manoli");
    strcpy(sa[4].name, "Dom");
    strcpy(sa[5].name, "Luke");
    strcpy(sa[6].name, "Brian");
    strcpy(sa[7].name, "Rich");
    strcpy(sa[8].name, "Alex");
    strcpy(sa[9].name, "Shem");
    
    sa[0].homeTown = "Brooklyn";
    sa[1].homeTown = "Mercury";
    sa[2].homeTown = "Venus";
    sa[3].homeTown = "Mars";
    sa[4].homeTown = "Moon";
    sa[5].homeTown = "Ocean";
    sa[6].homeTown = "Space";
    sa[7].homeTown = "Milky Way";
    sa[8].homeTown = "Star9";
    sa[9].homeTown = "Jupiter";
}

int StudentID(){
    int randomID = rand() % 9999 + 1000;
    return randomID;
}

myDate Birthdays(){
    int startDate = 2449718;
    int endDate = 2451909;
    int diff = endDate - startDate;
    
    int randomDate = rand() % diff + startDate;
    myDate d1 = myDate(randomDate);
    
    return d1;
}

char Grades(){
    int randomNum = rand() % 6;
    while(randomNum + 'A' == 69){
        randomNum = rand() % 6;
    }
    char randGrade = 'A' + randomNum;
    
    return randGrade;
}

void SortByName(Student *sp[]){
    for(int i = 0; (i < 9); i++){
        for(int x = 0; x < 9 - i; x++){
            if(strcmp(sp[x]->name,sp[x + 1]->name) > 0){
                Student *temp;
                temp = sp[x];
                sp[x] = sp[x + 1];
                sp[x + 1] = temp;
            }
        }
    }
}

void SortByGrade(Student *sp[]){
    for(int i = 0; (i < 9); i++){
        for(int x = 0; x < 9 - i; x++){
            if((sp[x]->grade + 0) > (sp[x + 1]->grade + 0)){
                Student *temp;
                temp = sp[x];
                sp[x] = sp[x + 1];
                sp[x + 1] = temp;
            }
        }
    }
}

void SortByID(Student *sp[]){
    for(int i = 0; (i < 9); i++){
        for(int x = 0; x < 9 - i; x++){
            if((sp[x]->ID) > (sp[x + 1]->ID)){
                Student *temp;
                temp = sp[x];
                sp[x] = sp[x + 1];
                sp[x + 1] = temp;
            }
        }
    }
}

void SortByBirthdays(Student *sp[]){
    for(int i = 0; (i < 9); i++){
        for(int x = 0; x < 9 - i; x++){
            if(sp[x]->birthday.daysBetween(sp[x + 1]->birthday) > 0){
                Student *temp;
                temp = sp[x];
                sp[x] = sp[x + 1];
                sp[x + 1] = temp;
            }
        }
    }
}

void SortByHomeTown(Student *sp[]){
    for(int i = 0; (i < 9); i++){
        for(int x = 0; x < 9 - i; x++){
            if(sp[x]->homeTown.compare(sp[x + 1]->homeTown) < 0){
                Student *temp;
                temp = sp[x];
                sp[x] = sp[x + 1];
                sp[x + 1] = temp;
            }
        }
    }
}

void display(Student *sp[]){
    //fix the date print
    cout << left << setw(20) << "Name" << setw(20) << "Student ID" << setw(20) << "Grade" << setw(20) << "Birthday" << setw(20) << "HomeTown" << '\n';
    cout << left << setw(20) << "__________" << setw(20) << "_________" << setw(20) << "_________" << setw(20) << "__________" << setw(20) << "__________" << '\n';
    
    for(int x = 0; x < 10; x++){
        cout << left << setw(20) << sp[x]->name << setw(20) << sp[x]->ID << setw(20) << sp[x]->grade << setw(20) << sp[x]->birthday.displayDateString() << setw(20) << sp[x]->homeTown << "\n";
    }
}

void display2(Student sp[]){
    //fix the date print
    cout << left << setw(20) << "Name" << setw(20) << "Student ID" << setw(20) << "Grade" << setw(20) << "Birthday" << setw(20) << "HomeTown" << '\n';
    cout << left << setw(20) << "__________" << setw(20) << "_________" << setw(20) << "_________" << setw(20) << "__________" << setw(20) << "__________" << '\n';
    
    for(int x = 0; x < 10; x++){
        cout << left << setw(20) << sp[x].name << setw(20) << sp[x].ID << setw(20) << sp[x].grade << setw(20) << sp[x].birthday.displayDateString() << setw(20) << sp[x].homeTown << "\n";
    }
}

