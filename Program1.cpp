#include<iostream>
#include <fstream>
using namespace std;

struct  PERSON {
    char  Name[20];
    float Balance; };

int main()
{
  ifstream file;
  file.open("data.txt");
  int counter=0;
  string temp;
  while(file)
  {
    getline(file,temp);
    counter++;
  }
  file.close();
  counter--;
}
