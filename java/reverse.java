import java.io.*;
class reverse
{
    public void main()throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter your string");
        String a= br.readLine();
        String w="";
        int l=a.length();
        for(int i=0;i<l;i++)
        {
            char ch=a.charAt(i);
            w=ch+w;
        }
        System.out.println(w);
    }
}
