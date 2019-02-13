#include<iostream>
#include <fstream>
#include <cstring>
#include<iomanip>
using namespace std;

struct  PERSON {
    char  Name[20];
    float Balance; };
void Display(PERSON P[], int size);
void FindRichest(PERSON P[],int size);
void Deposit(string CustName,PERSON P[],int size);
void NewCopy(string fileName, PERSON P[], int size);
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
        fullName=str1+" "+str2;
        strcpy(P[i].Name,fullName.c_str());
        P[i].Balance=num;
    }
    file.close();
    Display(P,counter);
    FindRichest(P,counter);
    string custName;
    cout<<"Enter you full name to deposit money: ";
    getline(cin,custName);
    Deposit(custName,P,counter);
    NewCopy("data.txt",P,counter);
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
    cout<<endl;
}

void FindRichest(PERSON P[],int size)
{
    float topBalance=P[0].Balance;
    char richest[20];
    for (int i=0;i<size;i++)
    {
        if(P[i+1].Balance>P[i].Balance)
        {
            topBalance=P[i+1].Balance;
            strcpy(richest,P[i+1].Name);
        }
    }
    
    cout<<"The customer with maximum balance is "<<richest<<endl;
}

void Deposit(string CustName,PERSON P[],int size)
{
    float add;
    cout<<CustName<<", how much would you like to deposit? ";
    cin>>add;
    for(int i=0;i<size;i++)
    {
        if (P[i].Name==CustName)
        {
            P[i].Balance+=add;
            cout<<"Now your new Balance is "<<P[i].Balance<<endl;
            break;
        }
    }
    
}
void NewCopy(string fileName, PERSON P[], int size)
{
    fstream file;
    file.open(fileName,fstream::out);
    for (int i=0;i<size;i++)
    {
        file.precision(2);
        file<<P[i].Name<<" "<<fixed<<P[i].Balance<<endl;
        cout<<endl;
    }
   
    
}


