import java.util.Scanner;
class transpose_of_matrix
{
  int a[][]=new int[3][3];
  int i,j;
  void getdata()
  {
    Scanner sc = new Scanner (System.in);
    for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
      {
        System.out.println("Enter Number");
        a[i][j]=sc.nextInt();
      }
    }
  }
  void putdata()
  {
    for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
      {
        System.out.print(a[i][j]+"  ");
      }
      System.out.println();
    }
  }
  void transpose()
  {
    System.out.println("Transpose is :- ");
    for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
      {
        System.out.print(a[i][j]+"  ");
      }
      System.out.println();
    }
  }
}
class transpose_matrix
{
  public static void main(String args[])
  {
    transpose_of_matrix aa = new transpose_of_matrix();
    aa.getdata();
    System.out.println("original matrix :-");
    aa.putdata();
    aa.transpose();
  }
}
