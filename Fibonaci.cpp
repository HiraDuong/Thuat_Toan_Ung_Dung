#include <iostream>
using namespace std;
// Fibonacci Words
/**
 * fibonacci words :
 * F1 = 'A'
 * F2 = 'B'
 * Fk = Fk-2 + Fk-1
 * Fk is a string
 * example : F3 = 'AB'
 *           F4 = 'BAB'
 *           .........
*/


// findLengthTerm (đệ quy)
int findLengthTerm(int k){
    if (k == 1|| k ==2) return 1;
    else return findLengthTerm(k-1)+findLengthTerm(k-2);
}

int findIndex(int i){
    int k = 1;
    while(findLengthTerm(k) <i){
        k++;
    }
    return k;
}

char Fibonacci(int n,int i){
        if(n>=3){
            if (i <= findLengthTerm(n-2)){
                Fibonacci(n-2,i);

            }
            else{
                
                Fibonacci(n-1,i-findLengthTerm(n-2));
            }
        }
        else{
            
            if (n==2) return 'B';
            if(n==1) return 'A';
        }

    }

int main()
{
    int n,i;
    cin>>n>>i;
    int k = findIndex(i);
    
    cout<<Fibonacci(n,i);
    return 0;
}
