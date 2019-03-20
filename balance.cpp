//Guanlin Wang
// section 02
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
void Deposit(PERSON P[],int N,string custName, float amount);
void NewCopy(string fileName, PERSON P[], int size);
PERSON * readData(int & N);
void printmenu() {
    cout << "Please enter a choice:" << endl;
    cout << "1. Display records"<< endl;
    cout << "2. Deposit funds"<< endl;
    cout << "3. Find Highest Balance" << endl;
    cout << "4. Update records" << endl;
    cout << "5. Exit the program" << endl;
}

int main()
{
    ifstream file;
    int counter=0;
    string temp;
    file.open("data.txt");
    while(file)
    {
        file>>temp;
        counter++;
    }
    file.close();
    counter=(counter-1)/3;
    
    PERSON* P;
    P=new PERSON[counter];
    P=readData(counter);
    int choice;
    do
    {
        printmenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
            {  Display(P,counter);
                break;
            }
                
            case 2:
            {
                
               string custName;
                cout<<"Enter name: ";
                cin.ignore();
                getline(cin,custName);
                bool falseName=true;
                float add;
                for(int i=0;i<counter;i++)
                {
                    if (P[i].Name==custName)
                    {
                        falseName=true;
                        break;
                    }
                    falseName=false;
                }
                if (falseName==false)
                {
                    cout<<"Record not found"<<endl;
                }
                else{
                    
                    cout<<"Amount: ";
                    cin>>add;
                Deposit(P,counter,custName,add);
                }
                
                break;
            }
                
            case 3:
            {  FindRichest(P,counter);
                break;
            }
                
            case 4:
            {  NewCopy("data.txt",P,counter);
                break;
            }
                
            case 5:
            {   NewCopy("data.txt",P,counter);
                break;
            }
                
            default:
            { cout << "Invalid entry" << endl;
                break;}
             }
        cout << endl;
        }
         while(choice != 5);
    
         return 0;
}


void Display(PERSON P[], int size)
{
    
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
    
    for (int i=1;i<size;i++)
    {
        
        if(topBalance<P[i].Balance)
        {
            topBalance=P[i].Balance;
            strcpy(richest,P[i].Name);
        }
        if(topBalance==P[0].Balance)
        {
            strcpy(richest,P[0].Name);
        }
        
    }
    
    cout<<"Highest Balance: "<<richest<<endl;
}

void Deposit(PERSON P[],int N,string custName, float amount)
{
   
    for(int i=0;i<N;i++)
    {
        if (P[i].Name==custName)
        {
            P[i].Balance+=amount;
            cout<<"New Balance: "<<P[i].Balance<<endl;
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
    cout<<"File Updated...";
    
    
}

PERSON * readData(int & N)
{
  float num;
  string str1,str2,fullName;
  ifstream file;
  
    PERSON *P;
    P =new PERSON[N];
  
  file.open("data.txt");
  for(int i =0;i <N;i++)
 {
    file>>str1>>str2>>num;
    fullName=str1+" "+str2;
    strcpy(P[i].Name,fullName.c_str());
    P[i].Balance=num;
}
      file.close();
    return P;
}



