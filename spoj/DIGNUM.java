import java.io.*;
class DIGNUM
{
     public static void main(String args[])throws IOException
     {
           BufferedReader input=new BufferedReader(new InputStreamReader(System.in));
           String num[];
           num=new String[3];
           num[0]=input.readLine();
           while(num[0]!=null)
           {
               
              // if(num[0]==EOF)
               //break;
               num[1]=input.readLine();
               num[2]=input.readLine();
               for(int i=0;i<(num[0].length()/3);i++)
               {
                   if(num[0].charAt(1+i*3)==' ')  //1,4
                   {
                       if(num[1].charAt(1+i*3)=='_')
                       System.out.print("4");
                       else
                       System.out.print("1");
                    }
                   else //0,2,3,5,6,7,8,9
                   {
                       if(num[1].charAt(0+i*3)=='|') //0,5,6,8,9
                       {
                            if(num[1].charAt(1+i*3)=='_') //5,6,8,9
                            {
                                 if(num[1].charAt(2+i*3)=='|') //8,9
                                 {
                                       if(num[2].charAt(0+i*3)=='|') //8
                                       System.out.print("8");
                                       else
                                       System.out.print("9");
                                 }
                                 else //5,6
                                 {
                                     if(num[2].charAt(0+i*3)=='|')
                                     System.out.print("6");
                                     else
                                     System.out.print("5");
                                 }
                            }
                            else
                            System.out.print("0");
                        }
                        else // 2,3,7
                        {
                           if(num[1].charAt(1+i*3)=='_') //2,3
                           {
                               if(num[2].charAt(0+i*3)=='|')
                               System.out.print("2");
                               else
                               System.out.print("3");
                           }
                           else     //7
                           System.out.print("7");
                        }
                   }
                }
                System.out.println();
                num[0]=input.readLine();
            }
        }
    }
                            