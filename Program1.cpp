#include<iostream>
#include <fstream>
using namespace std;

struct  PERSON {
    char  Name[20];
    float Balance; };
void Display(char name[], int amount);

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
  PERSON account[counter];
file.open("data.txt");

  }
}

void Display(char name[], int amount)
{
  cout<<endl<<"hi";
}
