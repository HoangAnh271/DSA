#include <iostream>    // stream I/O
#include <fstream>
#include<sstream>
#include <string>      // string
#include <cassert>     // assert()
using namespace std;

char CaesarEncode(char ch, int key);


// Question 1. Write a function returns the position of the key, if the key does not exist, returns -1
int LinearSearch(int* a, int n, int key) 
{
  for(int i = 0; i < n; i++)
  {
    if(a[i] == key)
      return i;
  }
  return -1;
}

// Question 2. Write a function prints the binary form of the positive integer n
void PrintBinary(int n)
{
  {
      int temp;
      if( n == 1)
      { 
        cout << n;
        return;
      }
      temp = n%2;
      PrintBinary(n/2);
      cout << temp;
      return;
}

}


//  Question 3. 
bool encode_message()
{

  // 0. Display introductory message 
  cout << "\nThis program uses the Caesar cipher to encode the contents of a"
       << "\nfile and writes the encoded characters to another file.\n";
  
  // 1. (0.25 point) Open inFile for reading 
  string inFile = "message.txt";

  ifstream file(inFile);



  // 2. (0.25 point) If file is failed to open, display an error message and return False; otherwise, display success message

  if(!file.is_open())
  {
    cout << "cant open file!";
    return false;
  }
  cout << "open success!" << endl;

  // 3. (0.25 point) Open outFile for output.
  string outFile = "encoded_message.txt";

  ofstream outFILE(outFile);


  // 4. (0.25 point) If file is failed to open, display an error message and return False; otherwise, display success message

  if(!outFILE.is_open())
  {
    cout << "cant open file !" << endl;
    return false;
  }
  cout << "open success!" << endl;

  
  // 5. (3.0 point) Read the content of inFile and encode the message then write the encoded message to outFile 
  char charac;
  while(!file.eof())
  {
        file.get(charac);
        outFILE << CaesarEncode(charac, 5);
  }

  
  // 6. (0.5 point) close the connection to the input and output file
  outFILE.close();
  file.close();

  // 7. display a 'successful completion' message
  cout << "\nProcessing complete.\n Encoded message is in "  << outFile << endl;
  return true;
}

int main()
{
  int n = 6;
  int *a = new int[n]{1,2,3,4,5,0};
  int key = 0;

  int pos = LinearSearch(a, 6, 0);
  cout << "\nVi tri cua " << key << " trong mang la: " << pos << endl;

  /* uncomment this block to run question 2*/
  cout << "Dang nhi phan cua " << n << " la: ";
  PrintBinary(n);
  cout << "\n";
  

  encode_message(); // uncomment this line to run question 3

  return 1;
}

/*============================================================
 * CaesarEncode function       
 *                                                                    
 * Receive: ch, a character.                                         
 *          key, the amount by which to rotate ch.                   
 * Return:  The character that is key positions after ch,            
*/

#include <cctype>      // isupper(), islower()

char CaesarEncode(char ch, int key)
{
  const int FIRST_UPPER = 65,
            FIRST_LOWER = 97,
            NUM_CHARS = 26;

  if (key <= 0 || key >= NUM_CHARS)
    {
      cerr << "\n*** CaesarEncode: key must be between 1 and 25\n" << endl;
      exit(1);
    }
  
  if (isupper(ch))
    return (ch - FIRST_UPPER + key) % NUM_CHARS + FIRST_UPPER;
  else if (islower(ch))
    return (ch - FIRST_LOWER + key) % NUM_CHARS + FIRST_LOWER;
  else
    return ch;
}


