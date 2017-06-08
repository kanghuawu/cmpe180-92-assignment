#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int MAXNUM = 100;    //maximum number in this Sieve of Eratosthenes
int DOTNUM = MAXNUM+1;    //set a number greater than MAXNUM so it won't interfere while finding sum
bool isPrime(int n);    //check the number is a prime or not
void createSofE(int arr[]);    //create a Sieve of Eratosthenes
void printSofE(int arr[]);    //print out the entire Sieve of Eratosthenes in a 10 by 10 array
void setDot(int arr[], int num);    //set the number to a dot with a given input number
void setNum(int arr[], int position);    //set the position of array to a number
void findSum(int arr[], int sum);    //find and print all possible two numbers which can add up to a given number


int main()
{
    int arr[MAXNUM];
    createSofE(arr);
    printSofE(arr);
    
    cout << "Test of Goldbach's Conjecture:" << endl;
    int sum = 4;    // starting number of Goldbach’s conjecture
    while (sum <= MAXNUM) {
        cout << endl;
        cout << setw(3) << sum << ":";
        findSum(arr, sum);
        sum += 2;
    }
    return 0;
}

bool isPrime(int n){
    for(int i=2; i<n/2; i++){
        if(n%i == 0) return false;
    }
    return true;
}

void createSofE(int arr[]){
    int findPrime = sqrt(MAXNUM);
    for (int i=2; i<=findPrime; i++) {
        if (isPrime(i)) {
            int delNum = i*i;
            while (delNum <= MAXNUM) {
                setDot(arr, delNum);
                delNum += i;
            }
        }
    }
    setDot(arr, 1);
    for (int i=0; i<MAXNUM; i++) {
        if (arr[i] != DOTNUM) {
            setNum(arr, i);
        }
    }
    
}

void setDot(int arr[], int num){
    arr[num-1] = DOTNUM;
}

void setNum(int arr[], int position){
    arr[position] = position+1;
}

void printSofE(int arr[]){
    cout << "Primes:" << endl << endl;
    for (int i=0; i<MAXNUM; i++) {
        if (arr[i] == DOTNUM) {
            cout << setw(3) << ".";
        }else{
            cout << setw(3) << arr[i];
        }
        if((i+1)%10==0){
            cout << endl;
        }
    }
    cout << endl;
}

void findSum(int arr[], int sum){
    int firstNum;
    int secondNum;
    bool firstSet = true;
    for (int i=0; i<MAXNUM; i++) {
        if (arr[i] != DOTNUM) {
            firstNum = arr[i];
            secondNum = sum - firstNum;
            for (int j=i; j<MAXNUM; j++) {
                if (arr[j] == secondNum && firstSet) {
                    cout << setw(3) << arr[i] << setw(3) << arr[j] << endl;
                    firstSet = false;
                }else if (arr[j] == secondNum)
                    cout << setw(7) << arr[i] << setw(3) << arr[j] << endl;
            }
        }
    }
}