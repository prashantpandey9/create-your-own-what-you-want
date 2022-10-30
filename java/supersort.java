//WAP to arrange the elements of a dynamic array such that all even numbers
//are followed by all odd numbers using a single loop.
import java.util.*;
class supersort
{
    public void disp()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of the array");
        int n=sc.nextInt();
        int x=n-1;
        int c=0;
        int arr[]=new int[n];
        int a[]=new int[n];
        for(int i=0;i<n;i++)
        {
            System.out.println("Enter the array element in position"+ i);
            arr[i]=sc.nextInt();
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]%2==0)
            {
            a[c]=arr[i];
            c++;
            }
            else
            {
            a[x]=arr[i];
            x--;
            }
        }
        for(int i=0;i<n;i++)
        {
            System.out.print(a[i]+" ");
        }
    }
}
