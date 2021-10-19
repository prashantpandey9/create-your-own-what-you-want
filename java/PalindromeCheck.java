import java.util.Scanner;

public class PalindromeCheck{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Input string: ");
        String checkString = sc.nextLine();

        boolean isPalindrome = true;

        int stringLength = checkString.length();

        for(int i=0; i<stringLength/2; i++){
            if(checkString.charAt(i)!=checkString.charAt(stringLength-i-1)){
                isPalindrome = false;
                break;
            }
        }

        if(isPalindrome){
            System.out.println(checkString + " is a Palindrome");
        }else{
            System.out.println(checkString + " is not a Palindrome");
        }
    }
}