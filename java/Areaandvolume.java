import java.util.*;
class room
{
    int length,breadth,width,height;
    Scanner sc= new Scanner(System.in);
    void getdata()
    {
	System.out.println("Enter Length of room:"); 
	length=sc.nextInt();
	System.out.println("Enter Breadth of room:"); 
	breadth=sc.nextInt();
	System.out.println("Enter Width of room:"); 
	width=sc.nextInt();
	System.out.println("Enter Hight of room:"); 
	height=sc.nextInt();
    }
}
class operation extends room
{
   int area,volume;
   void area()
   {
	
	area=(length*breadth);
   }
   void volume()
   {
	
	volume=(length*height*width);
   }
   void display()
   {
	System.out.println("Area of Room="+area);
	System.out.println("Volume of Room="+volume);
   }
}
public class Areaandvolume
{
   public static void main(String args[])
   {
	operation o1=new operation();
	o1.getdata();
	o1.area();
	o1.volume();
	System.out.println("***AREA & VOLUME OF ROOM***");
	o1.display();
    }
}