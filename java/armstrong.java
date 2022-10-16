class armtrong
    {
        public void display(int n)
        {
            int sum=0;
            int m=n;
            while(n>0)
            {
             int d=n%10;
                  n=n/10;
         sum=d*d*d+sum;
         }
         if(sum==m)
             System.out.println(m+" is a armstrong number");
             else
             System.out.println(m+"is not a armstrong number");
         }
     }
             
