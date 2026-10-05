#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
int menu;
int studentCount = 0;
struct Student{
    int niu;
    std::string name;
    std::string birthDate;
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
    std::cout << "6. Calculate Average IPK" << std::endl;
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

    std::cout << "\nBack to main menu? (input any char)";
    std::cin >> back;

    return;
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

        return;
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

        return;
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

        return;
    }


    std::cout << "\nStudent with NIU " << searchNIU << " was not found." << std::endl;
}

void averageIpk(){
    
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

            default:
                break;
        }
        std::cout << std::endl;
    }
}