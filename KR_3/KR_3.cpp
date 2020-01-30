#include <iostream>
using namespace std;

class human
{

protected:
    string  name;
    int     age;
    string  gender;

public: human(string name, int age, string gender)
{
    this->name  = name;
    this->age   = age;
    this->gender = gender;
};

protected: void outName()
{
    cout << "Name: " << this->name;
}

protected: void outAge()
{
    cout << "Age: " << this->age;
}

protected: void outGender()
{
    cout << "Gender: " << this->gender;
}

};

class student : protected human {

private:
    string  nameGroup;
    int     courseStudy;

public: student(string name, int age, string gender, string nameGroup, int courseStudy) :human(name, age, gender)
{
    this->nameGroup     = nameGroup;
    this->courseStudy   = courseStudy;
};

public: void outNameGroup()
{
    cout << "Name Group: " << this->nameGroup;
}

public: void outCourseStudy()
{
    cout << "Course Study: " << this->courseStudy;
}

public: void outInformationAboutStudent()
{
    cout << "Information About Student: " << endl;
    human::outName();
    cout << endl;
    human::outAge();
    cout << endl;    
    human::outGender();
    cout << endl;
    this->outNameGroup();
    cout << endl;
    this->outCourseStudy();
    cout << endl << endl;

}

};

class teacher : protected human {

private:
    string  nameItem;
    string  academicDegree;

public: teacher(string name, int age, string gender, string nameItem, string academicDegree) :human(name, age, gender)
{
    this->nameItem          = nameItem;
    this->academicDegree    = academicDegree;
}

public: void outNameItems()
{
    cout << "Name Item: " << this->nameItem;
}

public: void outAcademicDegree()
{
    cout << "Academic Degree: " << this->academicDegree;
}

public: void outInformationAboutTeacher()
{
    cout << "Information About Teacher: " << endl;
    human::outName();
    cout << endl;
    human::outAge();
    cout << endl;
    human::outGender();
    cout << endl;
    this->outNameItems();
    cout << endl;
    this->outAcademicDegree();
    cout << endl << endl;

}

};



int main()
{
    student objStudent = student("Arsiom", 23, "Man", "Information Systems and Technologies", 1);
    teacher objTeacher = teacher("Andrew", 27, "Man", "Programming languages", "Assistant professor");

    objStudent.outInformationAboutStudent();
    objTeacher.outInformationAboutTeacher();

    cin.get();

    return 0;
}
