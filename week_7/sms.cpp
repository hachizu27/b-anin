#include <iostream>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <string>
int menu;
int studentCount = 0;
struct Student{
    int niu;
    std::string name;
    std::string major;
    int year;
    double ipk;
};
struct Student students[26];

int chooseMenu(){
    std::cout << "==============================" << std::endl;
    std::cout << "   STUDENT MANAGEMENT SYSTEM  " << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "1. Add Student" << std::endl;
    std::cout << "2. View All Students" << std::endl;
    std::cout << "3. Search Student" << std::endl;
    std::cout << "4. Update Student" << std::endl;
    std::cout << "5. Delete Student" << std::endl;
    std::cout << "6. Calculate Average IPK Students" << std::endl;
    std::cout << "7. Show Ranking IPK" << std::endl;
    std::cout << "8. Show Pass/Fail Students" << std::endl;
    std::cout << "9. Count Students" << std::endl;
    std::cout << "10. Students Statistics" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "Choose menu: ";
    std::cin >> menu;
    return menu;
}

bool backToMenu(){
    std::string back;
    std::cout << "\nBack to main menu? (input any char)";
    std::cin >> back;

    return true;
}

void addStudent(){
    char inputAgain;
    int niu;
    double ipk;

    std::cout << "\nADD STUDENT'S DATA" << std::endl;
    std::cout << "\nEnter NIU: ";
    std::cin >> niu;

    for(int i = 0; i < studentCount; i++){
        if(students[i].niu == niu){
            std::cout << "NIU already registered";
            return;
        }
    }

    students[studentCount].niu = niu;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter Full Name: ";
    std::getline(std::cin, students[studentCount].name);

    std::cout << "Enter Major: ";
    std::getline(std::cin, students[studentCount].major);

    std::cout << "Enter Entrance Year: ";
    std::cin >> students[studentCount].year;

    std::cout << "Enter IPK (0-4): ";
    std::cin >> ipk;

    if(ipk >= 0 && ipk <= 4){
        students[studentCount].ipk = ipk;
    } else {
        std::cout << "IPK out of range.\n";
        std::cout << "Try Again." << std::endl;
        return;
    }

    std::cout << "Succesfully added a new data." << std::endl;
    studentCount++;

    std::cout << "\nDo you want to input another data(y/n)? ";
    std::cin >> inputAgain;

    if(inputAgain == 'y'){
        addStudent();
    }
}

bool showNoData(){
    if(studentCount == 0){
        std::cout << "\nThere is no student data." << std::endl;
        return true;
    }
    return false;
}

void viewAllStudents(){
    if(showNoData()){
        return;
    }

    char back;
    std::size_t noWidth = std::string("No").length();
    std::size_t nameWidth = std::string("Name").length();
    std::size_t niuWidth = std::string("NIU").length();
    std::size_t majorWidth = std::string("Major").length();
    std::size_t yearWidth = std::string("Entrance Year").length();
    std::size_t ipkWidth = std::string("IPK").length();

    for(int i = 0; i < studentCount; i++){
        if(std::to_string(i + 1).length() > noWidth){
            noWidth = std::to_string(i + 1).length();
        }
        if(students[i].name.length() > nameWidth){
            nameWidth = students[i].name.length();
        }
        if(std::to_string(students[i].niu).length() > niuWidth){
            niuWidth = std::to_string(students[i].niu).length();
        }
        if(students[i].major.length() > majorWidth){
            majorWidth = students[i].major.length();
        }
        if(std::to_string(students[i].year).length() > yearWidth){
            yearWidth = std::to_string(students[i].year).length();
        }
        if(std::to_string(students[i].ipk).length() > ipkWidth){
            ipkWidth = std::to_string(students[i].ipk).length();
        }
    }

    std::size_t tableWidth = noWidth + nameWidth + niuWidth + majorWidth + yearWidth + ipkWidth + 15;
    std::cout << std::right << std::setw(static_cast<int>(noWidth)) << "No" << " | "
              << std::left << std::setw(static_cast<int>(nameWidth)) << "Name" << " | "
              << std::right << std::setw(static_cast<int>(niuWidth)) << "NIU" << " | "
              << std::left << std::setw(static_cast<int>(majorWidth)) << "Major" << " | "
              << std::right << std::setw(static_cast<int>(yearWidth)) << "Entrance Year" << " | "
              << std::right << std::setw(static_cast<int>(ipkWidth)) << "IPK" << std::endl;
    std::cout << std::string(tableWidth, '-') << std::endl;

    for(int i = 0; i < studentCount; i++){
        std::cout << std::right << std::setw(static_cast<int>(noWidth)) << i + 1 << " | "
                  << std::left << std::setw(static_cast<int>(nameWidth)) << students[i].name << " | "
                  << std::right << std::setw(static_cast<int>(niuWidth)) << students[i].niu << " | "
                  << std::left << std::setw(static_cast<int>(majorWidth)) << students[i].major << " | "
                  << std::right << std::setw(static_cast<int>(yearWidth)) << students[i].year << " | "
                  << std::right << std::setw(static_cast<int>(ipkWidth)) << std::fixed << std::setprecision(2)
                  << students[i].ipk << std::endl;
    }

    if(backToMenu()){
        return;
    }
}

int searchStudentByNiu(int niu){
    for(int i = 0; i < studentCount; i++){
        if(students[i].niu == niu){
            return i;
        }
    }
    return -1;
}



void searchStudent(){
    if(showNoData()){
        return;
    }

    int searchNiu, indexData;

    std::cout << "\nSEARCH STUDENT" << std::endl;
    std::cout << "Enter NIU: ";
    std::cin >> searchNiu;

    indexData = searchStudentByNiu(searchNiu);

    if(indexData >= 0){
        std::cout << "\nStudent found!" << std::endl;
        std::cout << "------------------------------" << std::endl;
        std::cout << "NIU        : " << students[indexData].niu << std::endl;
        std::cout << "Name       : " << students[indexData].name << std::endl;
        std::cout << "Major      : " << students[indexData].major << std::endl;
        std::cout << "Entrance Year : " << students[indexData].year << std::endl;
        std::cout << "IPK        : " << std::fixed << std::setprecision(2) << students[indexData].ipk << std::endl;
        std::cout << "------------------------------" << std::endl;

        if(backToMenu()){
            return;
        }
    }

    std::cout << "\nStudent with NIU " << searchNiu << " was not found." << std::endl;
}


void updateData(){
    if(showNoData()){
        return;
    }

    int searchNiu;
    double ipk;
    std::string name, major;
    
    std::cout<<"UPDATE DATA "<<std:: endl;
    std::cout<< "Enter NIU: ";
    std:: cin>> searchNiu;
    
    int indexData = searchStudentByNiu(searchNiu);
    if(indexData >= 0){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter New Name: " ;
        std::getline(std::cin, name);

        if(name.length() > 0){
            students[indexData].name = name;
        }

        std::cout << "Enter New Major: " ;
        std::getline(std:: cin, major);

        if(major.length() > 0){
            students[indexData].major = major;
        }

        std::cout << "Enter New Entrance Year: " ;
        std::cin >> students[indexData].year;

        std::cout << "Enter New IPK (0-4): ";
        std::cin >> ipk;

        if(ipk >= 0 && ipk <= 4){
            students[indexData].ipk = ipk;
        } else {
            std::cout << "IPK out of range.\n";
            std::cout << "Try Again." << std::endl;
            return;
        }

        std::cout << "\nStudent data successfully updated!" << std::endl;

        if(backToMenu()){
            return;
        }
    }

    std::cout << "\nStudent with NIU " << searchNiu << " was not found." << std::endl;
}

void deleteData(){
    if(showNoData()){
        return;
    }

    int searchNIU;
    char deleteData;

    std::cout << "\nDELETE STUDENT" << std::endl;
    std::cout << "Enter NIU of student: ";
    std::cin >> searchNIU;\

    int indexData = searchStudentByNiu(searchNIU);
    if(indexData >= 0){
        std::cout << "\nStudent found!" << std::endl;

        std::cout << "Name : " << students[indexData].name << std::endl;
        std::cout << "NIU : "<< students[indexData].niu << std::endl;
        std::cout << "Are you sure to delete the data? (y/n)? ";
        std::cin >> deleteData;

        if(deleteData == 'y'){

            for(int i = indexData;
                i < studentCount - 1;
                i++){

                students[i] = students[i + 1];
            }

            studentCount--;

            std::cout << "Successfully deleted the data." << std::endl;
        }
        else{
            std::cout << "Canceled deleting data." << std::endl;
        }

        if(backToMenu()){
            return;
        }
    }


    std::cout << "\nStudent with NIU " << searchNIU << " was not found." << std::endl;
}

double totalIpk(){
    double totalIpk = 0;
    for(int i = 0; i < studentCount; i++){
        totalIpk += students[i].ipk;
    }
    return totalIpk;
}

double calculateAverageIpk(){
    double averageIpk;

    return totalIpk() / studentCount;
}

void averageIpk(){
    if(showNoData()){
        return;
    }

    std::cout << "Average IPK: " << calculateAverageIpk() << std::endl;

    if(backToMenu()){
        return;
    }
}

void rankingIpk(){
    if(showNoData()){
        return;
    }

    Student rankedStudents[26];
    for(int i = 0; i < studentCount; i++){
        rankedStudents[i] = students[i];
    }

    std::sort(rankedStudents, rankedStudents + studentCount, [](const Student& first, const Student& second){
        return first.ipk > second.ipk;
    });

    std::cout << "\nTOP IPK STUDENTS" << std::endl;
    std::cout << "Rank | Name | IPK" << std::endl;
    std::cout << "------------------------------" << std::endl;
    int topCount = studentCount < 3 ? studentCount : 3;
    for(int i = 0; i < topCount; i++){
        std::cout << i + 1 << " | " << rankedStudents[i].name << " | " << std::fixed << std::setprecision(2) << rankedStudents[i].ipk << std::endl;
    }

    if(backToMenu()){
        return;
    }
}

void showPassOrFailStudent(){
    if(showNoData()){
        return;
    }

    int searchNiu;
    std::cout<< "Pass Or Fail" << std::endl;
    std::cout<< "Enter NIU: ";
    std:: cin>> searchNiu;
    
    int indexData = searchStudentByNiu(searchNiu);
    if(indexData >= 0){
        if(students[indexData].ipk >= calculateAverageIpk()){
            std::cout << "Student with NIU " << searchNiu << " passed.";
        } else {
            std::cout << "Student with NIU " << searchNiu << " failed.";
        }

        if(backToMenu()){
            return;
        }
    }
    std::cout << "\nStudent with NIU " << searchNiu << " was not found." << std::endl;
}

void showTotalStudents(){
    std::cout << "Total students is " << studentCount << std::endl;

    if(backToMenu()){
        return;
    }
}

int findHighestIpkIndex(){
    if(studentCount == 0){
        return -1;
    }

    int highestIndex = 0;
    for(int i = 1; i < studentCount; i++){
        if(students[i].ipk > students[highestIndex].ipk){
            highestIndex = i;
        }
    }
    return highestIndex;
}

int findLowestIpkIndex(){
    if(studentCount == 0){
        return -1;
    }

    int lowestIndex = 0;
    for(int i = 1; i < studentCount; i++){
        if(students[i].ipk < students[lowestIndex].ipk){
            lowestIndex = i;
        }
    }
    return lowestIndex;
}

void studentsStatistic(){
    if(showNoData()){
        return;
    }

    int passed = 0;
    int failed = 0;
    double average = calculateAverageIpk();
    for(int i = 0; i < studentCount; i++){
        if(students[i].ipk > average){
            passed++;
        } else {
            failed++;
        }
    }

    int highestIndex = findHighestIpkIndex();
    int lowestIndex = findLowestIpkIndex();

    std::cout << "Students Statistic" << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "Total Students: " << studentCount << std::endl;
    std::cout << "Total IPK: " << totalIpk() << std::endl;
    std::cout << "Average IPK: " << average << std::endl;
    std::cout << "Highest IPK: " << students[highestIndex].name << " ("
              << students[highestIndex].ipk << ")" << std::endl;
    std::cout << "Lowest IPK: " << students[lowestIndex].name << " ("
              << students[lowestIndex].ipk << ")" << std::endl;
    std::cout << "Total Passed Students: " << passed << std::endl;
    std::cout << "Total Failed Students: " << failed << std::endl;

    if(backToMenu()){
        return;
    }
}

int main(){
    while(menu = chooseMenu()){
        switch(menu){
            case 1:
                addStudent();
                break;

            case 2:
                viewAllStudents();
                break;

            case 3:
                searchStudent();
                break;
            
            case 4:
                updateData();
                break;

            case 5:
                deleteData();
                break;

            case 6: 
                averageIpk();
                break;

            case 7:
                rankingIpk();
                break;

            case 8:
                showPassOrFailStudent();
                break;

            case 9:
                showTotalStudents();
                break;

            case 10:
                studentsStatistic();
                break;

            default:
                break;
        }
        std::cout << std::endl;
    }
}