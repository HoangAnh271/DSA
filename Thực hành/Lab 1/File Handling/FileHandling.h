#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<iomanip>
using namespace std;

struct Examinee
{
    string id;
    float maths, literature, physics, chemistry, biology, history, geography, civic_education, natural_science, social_science, foreign_language;
    string note, province;
};

Examinee readExaminee(string line_info);

vector<Examinee> readExamineeList(string file_name);

void writeScores(vector<Examinee> examinee_list, string out_file_name);
