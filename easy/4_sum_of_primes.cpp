#include <iostream>
#include <cmath>

using namespace std;

bool if_prime(int number);


int main(){
    int sum = 0;
    int prime = 1;
    for(int i = 2 ; prime <= 1000 ; i++){
        if(if_prime(i) == true){
            prime ++ ;
            sum += i;
        }
    }
    cout<<sum;
    return 0;
}

bool if_prime(int number){
    for(int i = 2 ; i <= sqrt(number) ; i++){
        if (number%i == 0){
            return false;
        }
    }
    return true;
}
