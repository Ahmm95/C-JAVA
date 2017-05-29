
/**
 * Created by SARZ (Syed Ahmed Raza Zaidi) on 4/21/2017.
 * COSC 1430, Professor Serkan Dursun, TA - Dr. Raafat and Dr. Dan
 * 04/20/2017, Homework 6 - Introduction to Computer Programming II.
 */

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
 
 
public class NYUStockExchange {

    public static void main(String[] args) {
        
 
        ArrayList<String> dates = new ArrayList<String>();
        ArrayList<Float> values = new ArrayList<Float>();
        BufferedReader br = null;
        String[] temp;
         
        try {
            br = new BufferedReader(new FileReader("C:/Users/SARZ/Desktop/Data.csv"));
        } catch (FileNotFoundException e) {
            
            e.printStackTrace();
        }
         
        try {
            String line = br.readLine(); line = br.readLine();
             
            while(line != null)
            {
                temp = line.split(",");
                dates.add(temp[0]);
                values.add(Float.parseFloat(temp[6]));
                
                line = br.readLine();
            }
             
             
        } catch (IOException e) {e.printStackTrace();}
         
         
        System.out.println(dates);
        System.out.println(values);
         
        int bestStart = 0, bestEnd = 0;
        float current = 0, best = 0;
        for(int start = 0; start < dates.size(); start++)
        {
            for(int end = 0; end < start; end++)
            {
                current =  values.get(start) - values.get(end); if(current < best)
                {
                    
                	bestStart = start; bestEnd = end; best = current;
                	System.out.println(-best);
                    
                }
            }
        }
         
        
        System.out.println("The best value change happens between " + dates.get(bestStart) + " and " + dates.get(bestEnd) + ".");
        String formattedbest = String.format("%.02f", -best);
        System.out.println("The best result was: " + formattedbest);
        
        	
         
    }
 
}