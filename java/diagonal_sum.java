import java.util.Scanner;
class sumdiagonal
 {
    public static void main(String agrs[]) {
        
       Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the matrix");
        int n=sc.nextInt();
       int a[][]=new int[n][n];int r=0,l=0;
       System.out.println("Enter array");
       for(int j=0;j<n;j++){
        for(int i=0;i<n;i++)
       {
           System.out.print("Enter element in position " +i+","+j+":");
         a[j][i] = sc.nextInt();
       }
       }

       for(int i=0;i<3;i++)
       {
         l=l+a[i][i];
       }
       for(int i=0;i<3;i++)
       {
         r=r+a[i][2-i];
       }
       System.out.println("Left diagonal sum="+l);
       System.out.println("Right diagonal sum="+r);
    }
}
