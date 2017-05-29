import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		ArrayList<String> dates = new ArrayList<String>();
		ArrayList<Float> values = new ArrayList<Float>();
		BufferedReader br = null;
		String[] temp;
		
		try {
			br = new BufferedReader(new FileReader("Data.csv"));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		try {
			String line = br.readLine();
			line = br.readLine();
			
			while(line != null)
			{
				temp = line.split(",");
				dates.add(temp[0]);
				values.add(Float.parseFloat(temp[6]));
				//System.out.println(temp[6]);
				line = br.readLine();
			}
			
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		System.out.println(dates);
		System.out.println(values);
		
		int worstStart = 0, worstEnd = 0;
		float current = 0, worst = 0;
		for(int start = 0; start < dates.size(); start++)
		{
			for(int end = 0; end < start; end++)
			{
				current = values.get(end) - values.get(start);
				if(current < worst)
				{
					worstStart = start;
					worstEnd = end;
					worst = current;
					System.out.println(worst);
				}
			}
		}
		
		System.out.println("The worst value change happens between " + dates.get(worstStart) + " and " + dates.get(worstEnd) + ".");
		String formattedWorst = String.format("%.02f", worst);
		System.out.println("The worst result was: " + formattedWorst);
		
	}

}
