#include<iostream>
#include <fstream>
#include <cstring>
#include<iomanip>
using namespace std;

struct  PERSON {
    char  Name[20];
    float Balance; };
void Display(PERSON P[], int size);

int main()
{
    ifstream file;
    string str1,str2,fullName;
    float num;
    int counter=0;
    string temp;
    //count the number of files=========
    file.open("data.txt");
   while(file)
    {
        file>>temp;
        counter++;
    }
    file.close();
    counter=(counter-1)/3;
   
    //Input============
    PERSON P[counter];
    file.open("data.txt");
     for(int i =0;i <counter;i++)
    {
        file>>str1>>str2>>num;
        fullName=str1+"  "+str2;
        strcpy(P[i].Name,fullName.c_str());
        P[i].Balance=num;
    }
    file.close();
    Display(P,counter);
   
}


void Display(PERSON P[], int size)
{
    cout<<"           Name                Balance              "<<endl;
    cout<<"----------------------------------------------------"<<endl;
    for (int i=0;i<size;i++)
    {
        cout.precision(2);
        cout<<"       "<<setw(24)<<left<<P[i].Name <<right<<fixed<<P[i].Balance<<endl;
    }
}
