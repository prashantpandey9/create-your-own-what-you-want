import java.util.methodoverloading;
public class subtract {
    static int sub(int a, int b)
    {
        int result;
        result=a-b;
      System.out.println("Result of 1 is :" +result);
      return result;
    }
    static float sub(float a, float b)
    {
        float result;
        result=a-b;
      System.out.println("Result of 2 is :" +result);
      return result;
    }
    static int sub(int b)
    {
        int a=10;
        int result;
        result=a-b;
        System.out.println("Result of 3 is :" +result);
        return result;
    }  
}
    public static void main(String args[]) {
        subtract ob= new subtract();
        ob.sub(4, 5);
        ob.sub(5.54f, 2.65f);
        ob.sub(4);
    }

