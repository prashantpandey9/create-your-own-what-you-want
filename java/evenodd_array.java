import java.util.*;
class evenodd
{
    public static void main(String args[])
    {
        int a[]=new int[10];
        Scanner sc=new Scanner(System.in);
        for(int i=0;i<10;i++)
        {
            System.out.println("enter the number at position"+i);
            a[i]=sc.nextInt();
        }
        System.out.println("Even numbers are");
        for(int i=0;i<10;i++)
        {
            if(a[i]%2==0)
            {
                System.out.println(a[i]);
            }
        }
        System.out.println("Odd numbers are");
        for(int i=0;i<10;i++)
        {
            if(a[i]%2!=0)
            {
                System.out.println(a[i]);
            }
        }
    }
}
