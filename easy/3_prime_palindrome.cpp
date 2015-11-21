#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

bool if_prime(int number);
bool if_palindrome(int number);


int main(){
    int thenumber = 0;
    for (int i = 1 ; i < 1000 ; i++){
        if (if_prime(i) == true){
            if(if_palindrome(i) == true){
                thenumber = i;
            }
        }
    }
    cout<<thenumber<<endl;
    return 0;
}

bool if_prime(int number){
    for (int i = 2 ; i <= sqrt(number) ; i++){
        if (number%i == 0){
            return false;
        }
    }
    return true;
}

bool if_palindrome(int number){
    stringstream ss;
    ss << number;
    string num = ss.str();

    for (int i = 0 ; i <= (num.length()-1)/2 ; i++){
        if(num[i] != num[(num.length()-1)-i]){
            return false;
        }
    }
    return true;
}
