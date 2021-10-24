#include <iostream>
#include <vector>
#include<iomanip>
#include <string> 
#include <algorithm>
#include <fstream>
#include <sstream>
#include <functional>
//#include "Kursiokai.txt";
using namespace std;

class Student {
    string name;
    string lastname;
    int testGrade;
    int markSize;
    string answer;
    double avg = 0;
    int sum = 0;
    double total = 0;
    vector<int> arr; //medianos skaiaciavimui
    vector<string> myStudent;
public:
    // parameterized constructor
    // Student();
    // Student();

public:
    void setName(string name)
    {
        myStudent.push_back(name);
    }
    void setLastname(string lastname)
    {
        myStudent.push_back(lastname);
    }
    void setTotal(string total)
    {
        myStudent.push_back(total);
    }

    void output()
    {
        cout << "Vardas         " << "Pavarde         " << "Pazymys mediana /Pazymys vidurkis       " << endl;
        for (int i = 0; i < myStudent.size(); i++)
        {
            int e = i;
            e++;
            string x = myStudent.at(i);
            cout << x << "        ";
            if (e % 3 == 0) { //after every student add endl;
                cout << "" << endl;
            }
        }
    }
    void calculate() {
        avg /= sum;
        total = (avg * 0.4) + testGrade * 0.6;
        setTotal(to_string(total));
    }
    void calculateWithMedian() {
        int n;
        n = markSize;
        //array size odd
        if (n % 2 == 1) {
            //median is arr[n/2] if array is sorted
            //can do the same using nth_element
            nth_element(arr.begin(), arr.begin() + n / 2, arr.end());
            //cout << "Median is: " << arr[n / 2] << endl;
            int t = (arr[n / 2] * 0.4) + (testGrade * 0.6);

            cout << t;
            myStudent.push_back(to_string(t));
        }
        else { //array size even
            //median is arr[n/2-1]+arr[n/2] if array is sorted

            //n/2th element
            nth_element(arr.begin(), arr.begin() + n / 2, arr.end());
            int a = arr[n / 2];
            //n/2-1 th element
            nth_element(arr.begin(), arr.begin() + n / 2 - 1, arr.end());
            int b = arr[n / 2 - 1];
            //cout << "Median is: " << (a + b) / 2.0 << endl;
            double t = (((a + b) / 2.0) * 0.4) + (testGrade * 0.6);
            cout << t << endl;
            myStudent.push_back(to_string(t));
        }

    }
    void input() {
        string name;
        string lastname;
        int size;
        int grade;
        string answer;
        int random;

        cout << "How many students to create? ";
        cin >> size;

        for (int i = 0; i < size; i++) {
            cout << "Student #" << i + 1 << " : Enter name = ";
            cin >> name;
            cout << "Student #" << i + 1 << " : Enter lastname = ";
            cin >> lastname;
            cout << "Do you want to generate grades randomly? Choose 1 if random, 0 if write in " << endl;
            cin >> random;

            if (random == 1) {
                cout << "How many grades there will be?" << endl;
                cin >> markSize;
                setName(name);
                setLastname(lastname);
                srand(time(0));
                for (int i = 0;i < markSize;i++) {
                    sum++;
                    int randomNumber = (rand() % 10) + 1;
                    avg += randomNumber;
                    arr.push_back(randomNumber);
                }
                testGrade = (rand() % 10);
                cout << testGrade << endl;
            }
            else {
                cout << "Do you know how many grades have you? Choose yes or no" << endl;
                cin >> answer;
                if (answer == "no") {
                    setName(name);
                    setLastname(lastname);
                    do {
                        cout << "Enter a number (-1 to quit): ";
                        cin >> grade;
                        if (grade != -1) {
                            avg += grade;
                            cout << avg;
                            arr.push_back(grade);
                            sum++;
                        }
                    } while (grade != -1);
                    markSize = sum;
                    cout << "Enter student test grade: " << endl;
                    cin >> testGrade;
                    while (testGrade > 10) {
                        cout << "Test grade can not be higher than  10" << endl;
                        cin >> testGrade;
                        cout << testGrade;
                    }
                }
                else {
                    cout << "How many grades there will be?" << endl;
                    cin >> markSize;
                    setName(name);
                    setLastname(lastname);
                    for (int i = 0; i < markSize; i++) {
                        sum++;
                        cout << "Enter grade " << endl;
                        cin >> grade;
                        while (grade > 10) {
                            cout << "Grade can not be higher than  10" << endl;
                            cin >> grade;
                        }
                        avg += grade;
                        arr.push_back(grade);
                    }
                    cout << "Enter student test grade: " << endl;
                    cin >> testGrade;
                    while (testGrade > 10) {
                        cout << "Test grade can not be higher than  10" << endl;
                        cin >> testGrade;
                    }
                }
            }

            int choice;
            bool gameOn = true;
            while (gameOn != false) {
                cout << "*******************************\n";
                cout << " 1 - Calculate with average.\n";
                cout << " 2 - Calculate with median.\n";
                cout << " Enter your choice and press return: ";

                cin >> choice;

                switch (choice)
                {
                case 1:
                    //cout << "Average!\n";
                    calculate();
                    gameOn = false;
                    break;
                case 2:
                    //cout << "Median\n";
                    calculateWithMedian();
                    gameOn = false;
                    break;
                default:
                    cout << "Not a Valid Choice. \n";
                    cout << "Choose again.\n";
                    cin >> choice;
                    break;
                }
            }
        }
    }
    bool getFileContent(std::string fileName, std::vector<std::string>& vecOfStrs)
    {
        // Open the File
        std::ifstream in(fileName.c_str());
        // Check if object is valid
        if (!in)
        {
            std::cerr << "Cannot open the File : " << fileName << std::endl;
            return false;
        }
        std::string str;
        // Read the next line from File untill it reaches the end.
        while (std::getline(in, str))
        {
            // Line contains string of length > 0 then save it in vector
            if (str.size() > 0)
                vecOfStrs.push_back(str);
        }
        //Close The File
        in.close();
        return true;
    }
};
void SplitString(string s, vector<string>& v) {

    string temp = "";
    for (int i = 0;i < s.length();++i) {

        if (s[i] == ' ') {
            v.push_back(temp);
            temp = "";
        }
        else {
            temp.push_back(s[i]);
        }

    }
    v.push_back(temp);

}

void PrintVector(vector<string> v) {
    for (int i = 0;i < v.size();++i)
        if (v[i] == "1" ) {
            cout << v[i] << endl;
        }
    //cout << "\n";
}
int main() {

    Student students;
    students.input();
    students.output();

    return 0;
}
