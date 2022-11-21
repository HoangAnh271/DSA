#include <iostream>
#include <string>
#include <ctime>
#include <time.h>
using namespace std;

void command_line2(int argc, char* argv[]);
void command_line3(int argc, char* argv[]);
void command_line4(int argc, char* argv[]);
void command_line5(int argc, char* argv[]);

void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%n;
	}
}

int algorithmNameToNumber(char* argv)
{
    int num = 0;
    if(strcmp(argv, "-rand") == 0)
        num = 1;
    else if(strcmp(argv, "-nsorted") == 0)
        num = 2;
    else if(strcmp(argv, "-sorted") == 0)
        num = 3;
    else if(strcmp(argv, "-rev") == 0)
        num = 4;    
    return num;
}

int dataOrderToNumber(char* argv)
{
    int num = 0;
    if(strcmp(argv, "-rand") == 0)
        num = 1;
    else if(strcmp(argv, "-nsorted") == 0)
        num = 2;
    else if(strcmp(argv, "-sorted") == 0)
        num = 3;
    else if(strcmp(argv, "-rev") == 0)
        num = 4;    
    return num;
}

int outParameterToNumber(char* argv)
{
    int num = 0;
    if(strcmp(argv, "-time") == 0)
        num = 1;
    else if(strcmp(argv, "-comp") == 0)
        num = 2;
    else if(strcmp(argv, "-both") == 0)
        num = 3;   
    return num;
}
void command_line2(int argc, char* argv[])
{
    int algorithm_name = algorithmNameToNumber(argv[2]);
    int data_order = dataOrderToNumber(argv[4]);
    int output_parameter = outParameterToNumber(argv[5]);

    unsigned long long count_compare = 0;
    int* a = new int[n]
    
    
    float running_time = 0;
    clock_t start_time, end_time;
    start_time = clock();
    end_time = clock();
    running_time = (((float)end_time - start_time)/ CLOCKS_PER_SEC) * 1000;


}

int main( int argc, char *argv[]) 
{
    srand(time(NULL));
    string command_line_argument[argc];
    for(int i = 0; i < argc; i++)
        command_line_argument[i] = argv[i];


    command_line2(argc, argv);
}