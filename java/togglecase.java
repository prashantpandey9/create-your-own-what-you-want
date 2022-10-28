class toggle
{
    String n,w;
    
    void input(String a)
    {
        n=a;
    }
    void change()
    {
        int l=n.length();
        for(int i=0;i<l;i++)
        {
            char ch=n.charAt(i);
            if(ch>=97&&ch<=122)
            {
                w=w+(char)(ch+32);
                
            }
            else if(ch>=65&&ch<=90)
            {    w=w+(char)(ch-32);
                
            }
            else    
                w=w+ch;
            }
        }
    void display()
    {
        System.out.println("The inputed string"+n);
        System.out.println("The changed string"+w);
    }       
    public void main(String s)
    {
        toggle obj=new toggle();
        obj.input(s);
        obj.change();
        obj.display();
    }
}
        
