import java.io.*;
class copy_content
{
    public static void main(String args[])throws IOException
    {
	File f1=new File("GPA");
	File f2=new File("Vikram");
	FileInputStream fis= new FileInputStream(f1);
	FileOutputStream fos= new FileOutputStream(f2);
	int x;
	while((x=fis.read())!=-1)
	{
	    fos.write(x);
	}
	System.out.println("File Writtern successfully!!!!!!!!!!");
	fis.close();
	fos.close();
    }
}