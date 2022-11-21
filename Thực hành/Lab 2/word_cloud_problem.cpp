#include<iostream>
#include<string>
#include<vector>

using namespace std;

void swap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}

int wordCloudProblem1(string differentWord[], int frequencyArray[] , string wordList[], int n)
{
    vector<bool> visited(n, false);
    int k = 0;
    for(int i = 0;  i < n; i++)
    {
        if(visited[i] == true)
            continue;

        int count = 1;
        for(int j = i + 1; j < n; j++)
        {
            if(wordList[i] == wordList[j])
            {
                visited[j] = true;
                count++;
            }
        }
        frequencyArray[k] = count;
        differentWord[k] = wordList[i];
        k++;
    }
    return k;
}

int wordCloudProblem2(string differentWord[], int frequencyArray[] , string wordList[], int n)
{
    for(int i = 0; i < n; i++)
        frequencyArray[i] = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(wordList[i] == wordList[j])
                swap(wordList[++i], wordList[j]);
        }
    }
    int k = 0;
    for(int i = 0; i < n; i++)
    {
        if(wordList[i] == wordList[i+1])
            frequencyArray[k]++;
        
        else
        {   
            differentWord[k] = wordList[i];
            frequencyArray[k]++;
            k++;
        }
    }
    return k;
}

int main()
{
    string wordList[] = {"one", "one", "two", "two", "one", "four", "five", "two", "five", "one", "haha"};
    int n = sizeof(wordList)/sizeof(wordList[0]);
    int frequencyArray[n];
    string differentWord[n];
    //int numberOfDifferentWord = wordCloudProblem1(differentWord, frequencyArray, wordList, n);
    int numberOfDifferentWord = wordCloudProblem2(differentWord, frequencyArray, wordList, n);
    for(int i = 0; i < numberOfDifferentWord; i++)
        cout << differentWord[i] << " = " << frequencyArray[i] << endl;
    
    
    return 0;
}