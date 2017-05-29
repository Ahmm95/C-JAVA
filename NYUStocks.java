
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Date;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class NYUStocks
{
  
   public static void main(String args[]) throws FileNotFoundException, ParseException
   {
       Scanner read = new Scanner(new File(""C:/Users/SARZ/Desktop/Data.csv""));
       // for csv file read.useDelimiter(",");
ArrayList<Stock> stocks=new ArrayList<Stock>();
       //System.out.println(dateString);

       DateFormat formatter = new SimpleDateFormat("M/dd/yyyy");
      
       read.nextLine(); //reads the column headers
      
       while(read.hasNext())
       {
          
          
       Stock s=new Stock();
          
       s.date = formatter.parse(read.next());
       for(int i=0;i<5;i++)
       {
           read.next();
       }
      
       s.adj=read.nextDouble();
      
      
       stocks.add(s);
       }
      
      
      
       Collections.sort(stocks);
      
       Date d1 = null; Date d2=null; double profit=0;
      
       System.out.println("sorted stocks by adj");
       System.out.println(stocks);
       outer:for(int i=stocks.size()-1;i>=0;i--)
       {
          
           d2=stocks.get(i).date;
           for(int j=0;j<i;j++)
           {
               d1=stocks.get(j).date;
               if(d2.after(d1))// if d2 fallse after d1 hence valid
               {
                   profit=stocks.get(i).adj-stocks.get(j).adj;
                   break outer;
               }
           }
       }
      
       System.out.println("");
       System.out.println(String.format("The maximum possible profit occurs between %s and %s with a net profit per shar of %f",d1,d2,profit));
   }
}