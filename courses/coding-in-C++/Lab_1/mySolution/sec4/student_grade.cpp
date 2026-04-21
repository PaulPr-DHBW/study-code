#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

//Basis functions
void read_student_data(std::string& name, u_int16_t& homework, u_int16_t& midterm, u_int16_t& finalExam);
void calculate_grade(std::string& name, u_int16_t& homework, u_int16_t& midterm, u_int16_t& finalExam, float& finalGrade, char& letterGrade);
void print_report(std::string& name, u_int16_t& homework, u_int16_t& midterm, u_int16_t& finalExam, float& finalGrade, char& letterGrade);

int main(void)
{
    std::string student_name;
    u_int16_t student_homework = 0;
    u_int16_t student_midterm = 0;
    u_int16_t student_finalExam = 0;

    read_student_data(student_name, student_homework, student_midterm, student_finalExam);

    float student_finalGrade = 0;
    char student__letterGrade = 'F';

    calculate_grade(student_name, student_homework, student_midterm, student_finalExam, student_finalGrade, student__letterGrade);
    print_report(student_name, student_homework, student_midterm, student_finalExam, student_finalGrade, student__letterGrade);

    return 0;
}

void read_student_data(std::string& name, u_int16_t& homework, u_int16_t& midterm, u_int16_t& finalExam)
{
    //Read in Name
    std::cout << "Enter your Name: ";
    std::getline(std::cin, name);

    //Read in homework
    while (true)
    {
        std::cout << "Homework score: ";
        if (!(std::cin >> homework))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Homework score is invalid" << std::endl;
            continue;
        }
        
        if (homework > 100)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Homework score is invalid" << std::endl;
            continue;
        }    
        break;
    }

    //Read in Midterm
    while (true)
    {
        std::cout << "Midterm score: ";
        if (!(std::cin >> midterm))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Midterm score is invalid" << std::endl;
            continue;
        }
        
        if (midterm > 100)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Midterm score is invalid" << std::endl;
            continue;
        }    
        break;
    }

    //read in finalExam
     while (true)
    {
        std::cout << "Final Exam score: ";
        if (!(std::cin >> finalExam))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Exam score is invalid" << std::endl;
            continue;
        }
        
        if (finalExam > 100)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Exam score is invalid" << std::endl;
            continue;
        }    
        break;
    }
    
}
void calculate_grade(std::string& name, u_int16_t& homework, u_int16_t& midterm, u_int16_t& finalExam, float& finalGrade, char& letterGrade)
{
    finalGrade = (0.4*static_cast<float>(homework) + 0.25*static_cast<float>(midterm) + 0.35*static_cast<float>(finalExam));
    if (finalGrade >= 90)
    {
        letterGrade = 'A';
    }
    else if(finalGrade >= 80)
    {
        letterGrade = 'B';
    }   
    else if(finalGrade >= 70)
    {
        letterGrade = 'C';
    }   
    else if(finalGrade >= 60)
    {
        letterGrade = 'D';
    }  
    else if(finalGrade >= 50)
    {
        letterGrade = 'E';
    }  
    else
    {
        letterGrade = 'F';
    }

}
void print_report(std::string& name, u_int16_t& homework, u_int16_t& midterm, u_int16_t& finalExam, float& finalGrade, char& letterGrade)
{
    std::cout << std::setfill('-') << std::setw(40) << "" << '\n';
    std::cout << "Student Report\n";
    std::cout << std::setw(40) << "" << '\n';

    std::cout << std::setfill(' ');
    std::cout << "Name: " << name << "\n\n";

    std::cout << "Scores\n";
    std::cout << std::setfill('-') << std::setw(40) << "" << '\n';
    std::cout << std::setfill(' ');

    std::cout << std::left << std::setw(16) << "Homework"     << ": " << std::right << std::fixed << std::setprecision(2) << homework   << '\n';
    std::cout << std::left << std::setw(16) << "Midterm"      << ": " << std::right << std::fixed << std::setprecision(2) << midterm    << '\n';
    std::cout << std::left << std::setw(16) << "Final Exam"   << ": " << std::right << std::fixed << std::setprecision(2) << finalExam  << "\n\n";

    std::cout << std::left << std::setw(16) << "Final Grade"  << ": " << std::right << std::fixed << std::setprecision(2) << finalGrade << '\n';
    std::cout << std::left << std::setw(16) << "Letter Grade" << ": " << std::right << letterGrade << '\n';

    std::string status = "Failed";
    if (finalGrade >= 50)
    {
        status = "Passed";
    }

    std::cout << std::left << std::setw(16) << "Status"       << ": " << std::right << status << '\n';

    std::cout << std::setfill('-') << std::setw(40) << "" << '\n';
}