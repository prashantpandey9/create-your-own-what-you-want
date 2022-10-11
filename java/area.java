import java.io.*;
class area
{
void findarea(int b)
    {
       System.out.println( "\n Area of square with length "+b+ " is :" + b*b);
    }
  
void findarea(double r)
       {
         System.out.println( "\n Area of circle with  radius " +r+ " is :" + 3.14 * r * r);
       }
  
 void findarea(int a, int b, int c)
    {
        double temp = (a + b + c);
        double s= temp/2;
        double triarea = Math.sqrt(s*(s-a)*(s-b)*(s-c));
        System.out.println( "\n Area of triangle with lenght of sides  "+a+"," +b+ " and " +c+" is : "+ triarea);
 }

public static void main(String p[]) throws IOException
 {
     area d = new area();
     BufferedReader Br = new BufferedReader(new InputStreamReader(System.in));
     System.out.print("\n Find area of \n 1 . Square \n 2 . Triangle \n 3 . Circle \n\nSelect a choice : ");
     int choice =Integer.parseInt(Br.readLine());
  switch(choice)
  {
    case 1:
          System.out.print("\n Enter the lenghth : ");
          int b=Integer.parseInt(Br.readLine());
          d.findarea(b);
          break;
    case 2:
         System.out.print("\n Enter the lenght of first side : ");
         int x =Integer.parseInt(Br.readLine());
         System.out.print("\n Enter the lenght of second side : ");
         int y=Integer.parseInt(Br.readLine());
         System.out.print("\n Enter the lenght of third side : ");
         int z =Integer.parseInt(Br.readLine());
         d.findarea(x,y,z);
         break;
    case 3:
         System.out.print("\n Enter the radius : ");
         double r =Double.parseDouble(Br.readLine());
         d.findarea(r);
         break;
    default:
         System.out.println("Invalid choice");
      }
  }
}