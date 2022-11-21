#include"FileHandling.h"


int main()
{
    // 1 Read the information of one examinee.

    // ifstream file("data.txt");
    // string line;
    // if(file.is_open())
    // {
    //     while(getline(file, line));
    //     Examinee a = readExaminee(line);
    //     cout << a.id << " " << a.biology;
    //     file.close();
    // }
    // else cout << "Unable to open file";

    // 2 Read the information of a list of examinees.

    // vector<Examinee> List = readExamineeList("data.txt");
    // // Print vector<Examinee> List
    // for (int i = 0; i < List.size(); i++) 
    // {
    //         cout << List[i].id << " " << List[i].biology << endl;
    // }


    // 3 Write scores of examinees to file.

    vector<Examinee> List = readExamineeList("data.txt");
    writeScores(List, "Score.txt");
    return 0;
}