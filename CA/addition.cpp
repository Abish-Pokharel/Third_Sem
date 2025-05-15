#include<iostream>
#include<string>
#include<cmath>
using namespace std;

string convert_Binary(int a){
    int remainder;
    string rslt = "";
    while (a > 0){
        remainder = a % 2;
        a = a / 2;
        rslt = to_string(remainder) + rslt;
    }
    return rslt;
}

string add_binary( string result1, string result2){
    int l1 = result1.length();
    int l2 = result2.length();
    int carry;
    string result = "";

    if (l1 > l2){
        result2 = string(l1 - l2, '0');
    } else if(l1<l2){
        result1 = string( l2 -l1, '0');
    }
    

    for (int i = l1 - 1; i >= 0; i--){
            int sum;
            int bit1 = result1[i] - '0';
            int bit2 = result2[i] - '0';
            sum = bit1 + bit2 + carry;

            result = to_string(sum % 2) + result;
            carry = sum /2 ; 
    }
    if (carry){
        result = '1' + result;
    }   
    return result;
}

int main(){
    int uservalue1, uservalue2;
    string result1 = "", result2 = "";
    string sum = "";

    cout << "Enter first value:";
    cin >> uservalue1 ;
    cout << "Enter second value:";
    cin >> uservalue2 ;

    result1 = convert_Binary(uservalue1);
    cout << "Binary of " << uservalue1 << " is: " << result1 << endl;
    result2 = convert_Binary(uservalue2);
    cout << "Binary of " << uservalue2 << " is: " << result2 << endl;
    
    sum = add_binary(result1, result2);
    cout << "Sum of " << uservalue1 << "and " << uservalue2 << " is:" << sum << endl;     
    return 0;
}