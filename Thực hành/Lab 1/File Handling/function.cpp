#include"FileHandling.h"

Examinee readExaminee(string line_info)
{
    Examinee student;

    stringstream buffer(line_info);
    stringstream temp;
    int count = 0;

    student.physics = 0.0;
    student.chemistry = 0.0;
    student.biology = 0.0;
    student.history = 0.0;
    student.geography = 0.0;
    student.civic_education = 0.0;
    student.natural_science = 0.0; 
    student.social_science = 0.0;

    while (getline (buffer, line_info, ','))
    {
        count++;
        if(line_info != "")
        {
            if(count == 1) student.id = line_info;

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

            if(count == 5)   
            {   
                temp << line_info;
                temp >> student.physics;
                student.natural_science += student.physics;
                temp.clear();
            }

            if(count == 6)   
            {   
                temp << line_info;
                temp >> student.chemistry;
                student.natural_science += student.chemistry; 
                temp.clear();
            }

            if(count == 7)   
            {   
                temp << line_info;
                temp >> student.biology;
                temp.clear();
                student.natural_science += student.biology;
            }

            if(count == 8)   
            {   
                temp << line_info;
                temp >> student.history;
                student.social_science += student.history;
                temp.clear();
            }

            if(count == 9)   
            {   
                temp << line_info;
                temp >> student.geography;
                student.social_science += student.geography; 
                temp.clear();
            }

            if(count == 10)   
            {   
                temp << line_info;
                temp >> student.civic_education;
                temp.clear();
                student.social_science += student.civic_education;
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
    else cout << "Unable to open file";

    return ExamineeList;
}

void writeScores(vector<Examinee> examinee_list, string out_file_name)
{
    ofstream outFile(out_file_name);
    
    outFile << left << setw (12) << "SDB" << setw (8) << "BB" << setw (8) << "KHTN" << setw (8) << "KHXH" << endl; 
    for (int i = 1; i < examinee_list.size(); i++)
    {
        outFile << setw(12) << examinee_list[i].id << setw(8) << examinee_list[i].maths +  examinee_list[i].literature + examinee_list[i].foreign_language << setw(8) << examinee_list[i].natural_science << setw(8) << examinee_list[i].social_science; 
        outFile << endl;
    }
    outFile.close();
}