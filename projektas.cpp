#include <iostream>
#include <string>
#include <vector>
#include <numeric>   
#include <iomanip>

using namespace std;

class Student
{
private:
    string firstName;
    string lastName;
    int grades_amount;
    float average;
public:
    void setLastname(string);
    void setFirstname(string);
    void setGradesAmount(int);
    void setAvg(int);
    string getLastname() const { return lastName; }
    string getFirstname() const { return firstName; }
    int getGradesAmount() const { return grades_amount; }
    float getAvg() const { return average; }

    //create a constructor
    Student(string firstName, string lastName, int grades_amount, float average)
        : firstName(firstName), lastName(lastName), grades_amount(grades_amount), average(average)
    {}
};

int main()
{
    vector<Student> emp;
    int count = 0;
    cout << "Enter the amount of students to add:" << endl;
    cin >> count;

    string firstName, lastName;
    int grades_amount, marks;
    double average, exam_mark;
    //vector<int> g1;
    for (int i = 0; i < count; ++i)
    {
        cout << "Please enter the first and last names" << endl;

        cin >> firstName;
        cin >> lastName;
        cout << "Please enter amount of grades" << endl;
        cin >> grades_amount;


        vector<int> g1;

        for (int i = 0; i < grades_amount; i++)
        {
            cout << "Please enter your marks: " << endl;

            cin >> marks;//10,8

            g1.push_back(marks);
        }
        cout << "Enter exam mark" << endl;

        cin >> exam_mark;

        average = (accumulate(g1.begin(), g1.end(), 0.0) / g1.size()) * 0.4;
        average = average + (exam_mark * 0.6);
        //cout << "The average is" <<fixed << setprecision(2) <<average << endl;  


        for (auto i = g1.begin(); i != g1.end(); ++i)
        {
            cout << *i << " " << endl;

        }
        emp.emplace_back(firstName, lastName, grades_amount, average);
    }
    cout << "Vardas " << "Pavarde " << "Galutinis " << endl;
    cout << "----------------------------------------" << endl;
    for (const Student& e : emp)
    {
        cout << e.getFirstname() << "     " << e.getLastname() << "      " << e.getAvg() << endl;
    }
}
