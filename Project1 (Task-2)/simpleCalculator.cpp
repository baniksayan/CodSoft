/*Develop a calculator program that performs basic arithmetic
operations such as addition, subtraction, multiplication, and
division. Allow the user to input two numbers and choose an
operation to perform*/

#include<iostream>
#include<string>
using namespace std;

bool isValidNumber(const string& str) {
    for (char c : str) {
        if (!isdigit(c) && c != '.') {
            return false;
        }
    }
    return true;
}

int main() {
    cout <<"Welcome to the Simple Calculator!\n"<< endl;

    string firstInput;
    cout <<"Please enter the first number: ";
    cin >> firstInput;

    if (!isValidNumber(firstInput)) {
        cout <<"You have entered a wrong input. Please enter a valid number and try again."<< endl;
        return 1;
    }
    double userFirstInput = stod(firstInput);

    char operation;
    cout<<"Enter the operation you'd like to calculate (+, -, *, /): ";
    cin >>operation;

    if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
        cout<< "You have entered a wrong input. Please enter a valid operation (+, -, *, /) and try again."<<endl;
        return 1;
    }

    string secondInput;
    cout<<"Please enter the second number: ";
    cin>>secondInput;

    if (!isValidNumber(secondInput)) {
        cout<<"You have entered a wrong input. Please enter a valid number and try again."<<endl;
        return 1;
    }
    double userSecondInput = stod(secondInput);

    double output;

    switch(operation) {
        case '+':
            output = userFirstInput + userSecondInput;
            break;
        case '-':
            output = userFirstInput - userSecondInput;
            break;
        case '*':
            output = userFirstInput * userSecondInput;
            break;
        case '/':
            if(userSecondInput != 0)
                output = userFirstInput / userSecondInput;
            else {
                cout<<"Error: Division by zero is not allowed."<<endl;
                return 1;
            }
            break;
    }

    cout<<"\nCalculated Successfully. Here's your result: "<<output<<endl;

    return 0;
}
