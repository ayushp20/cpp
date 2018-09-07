
#include <stdio.h>
#include <conio.h>

int fibonacci(int term);
int main(){
    int terms, counter;
    printf("Enter number of terms in Fibonacci series: ");
    scanf("%d", &terms);

    printf("Fibonacci series till %d terms\n", terms);
    for(counter = 1 ; counter <= terms; counter++){
        printf("%d ", fibonacci(counter));
    }
    return 0;
}
int fibonacci(int term){

    if(term < 2) /* Exit condition of recursion*/
       return term;
    return fibonacci(term - 1) + fibonacci(term - 2);
}
