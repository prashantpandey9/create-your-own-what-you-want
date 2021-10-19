//this program is used to return a number of prime numbers that are less or equal with n

import java.util.Scanner;

public class PrimeNumbers{

    public static int getPrimeNumbers(int n){
        if(n<2){
            return 0;
        }
        else if(n==2){
            return 1;
        }
        else{
            int counter = 1; //get this where 2 is automatically added
            //loop through 3 till N, where the numbers only odd numbers since 2 is the only prime even number
            for(int i=3; i<=n; i+=2){
                boolean isPrime = true;
                for(int j=3; j<i; j+=2){
                    if(i%j==0){
                        isPrime = false;
                        break;
                    }
                }
                if(isPrime){
                    counter++;
                }
            }
            return counter;
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println("Number of all prime numbers less or equal with "+n+": "+getPrimeNumbers(n));

    }
}