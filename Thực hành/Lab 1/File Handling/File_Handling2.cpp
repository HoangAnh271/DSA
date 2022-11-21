#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<string>
#include<vector>

using namespace std;

struct Examinee
{
    string id;
    float maths, literature, physics, chemistry, biology, history, geography, civic_education, natural_science, social_science, foreign_language;
    string note, province;
};

Examinee readExaminee(string line_info)
{
    Examinee student;
    stringstream buffer(line_info);
    stringstream temp;
    int count = 0;
    student.maths = 0;
    student.literature = 0;
    student.physics = 0;
    student.chemistry = 0;
    student.biology = 0;
    student.history = 0;
    student.geography = 0;
    student.civic_education = 0;
    student.natural_science = 0;
    student.social_science = 0;
    student.foreign_language = 0;
    while(getline(buffer, line_info, ','))
    {
        count++;
        if(line_info != "")
        {
            if(count == 1)
            {
                student.id = line_info;
            }
            if(count == 3)
            {
                temp << line_info;
                temp >> student.maths;
                temp.clear();
            }
            if(count == 4)
            {
                temp << line_info;
                temp >> student.literature;
                temp.clear();
            }
            if(count == 6)
            {
                temp << line_info;
                temp >> student.physics;
                temp.clear();
            }
            if(count == 7)
            {
                temp << line_info;
                temp >> student.chemistry;
                temp.clear();
            }
            if(count == 8)
            {
                temp << line_info;
                temp >> student.biology;
                temp.clear();
            }
            if(count == 9)
            {
                temp << line_info;
                temp >> student.history;
                temp.clear();
            }
            if(count == 10)
            {
                temp << line_info;
                temp >> student.geography;
                temp.clear();
            }
            if(count == 11)
            {
                temp << line_info;
                temp >> student.civic_education;
                temp.clear();
            }
            if(count == 12)
            {
                temp << line_info;
                temp >> student.natural_science;
                temp.clear();
            }
            if(count == 13)
            {
                temp << line_info;
                temp >> student.foreign_language;
                temp.clear();
            }
            if(count == 14)
            {
                student.note = line_info;
            }
            if(count == 15)
            {
                student.province = line_info;
            }

        }
    }
    return student;
}

vector<Examinee> readExamineeList(string file_name)
{
    ifstream file(file_name);
    string line;
    vector<Examinee> ExamineeList;
    if(file.is_open())
    {
        while(getline(file, line))
        {
            ExamineeList.push_back(readExaminee(line));
        }
        file.close();
    }
    else    
        cout << "cant open file";

    return ExamineeList;
}

void writeScore(vector<Examinee> ExamineeList, string out_file_name)
{
    ofstream outFile (out_file_name);
    if(outFile.is_open())
    {
        outFile << setw(12) << "So bao danh" << setw(12);
        for(int i = 0; i < ExamineeList.size(); i++)
        {
            outFile << ExamineeList[i].maths << setw(12) << ExamineeList[i].literature << setw(12) << ExamineeList[i].chemistry;
        }
        outFile.close();
    }
    else
        cout << "cant open file";
}

int main()
{
    // readExaminee
    // ifstream file ("data.txt");
    // if(file.is_open())
    // {
    //     string line;
    //     getline(file, line);
    //     getline(file, line);
    //     Examinee a = readExaminee(line);
    //     cout << a.maths << a.biology;
    //     file.close();
    // }
    // else
    //     cout << "cant open file";
    
    // read Examinee List
    vector<Examinee> list = readExamineeList("data.txt");
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i].maths << " " << list[i].biology << endl;
    }

    // vector<Examinee> List = readExamineeList("data.txt");
    // writeScore(List, "outFile.txt");
    return 0;
}