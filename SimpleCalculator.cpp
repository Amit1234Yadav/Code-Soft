#include<iostream>
using namespace std;
int main()
{
    double firstNum, SecondNum;;
    cout<<"Enter the First Number:"<<endl;
    cin>>firstNum;
    
    cout<<"Enter the Second Number:"<<endl;
    cin>>SecondNum;
     char optr;
    cout<<"Enter the Operator that u want to perform the Operation"<<endl;
    cin>>optr;
    switch(optr)
    {
        case '+':
           cout<<"The Addition of "<<firstNum<<" and "<<SecondNum<<" is :"<<firstNum+SecondNum<<endl;
           break;
        case '-':
           cout<<"The Substraction from "<<firstNum<<" to "<<SecondNum<<" is :"<<firstNum-SecondNum<<endl;
           break;
        
        case '*':
           cout<<"The Multiplication of "<<firstNum<<" and "<<SecondNum<<" is :"<<firstNum*SecondNum<<endl;
           break;
        
        case '/':
           if(SecondNum==0)
           {
            cout<<"Not defined"<<endl;
           }
           else
           { 
           cout<<"The Division of "<<firstNum<<" and "<<SecondNum<<" is :"<<firstNum/SecondNum<<endl;
           break;
           }
        
        default:
            
            cout<<" this is the default operator "<<endl;
    }

}