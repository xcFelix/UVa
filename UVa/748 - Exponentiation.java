import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext())
		{
			BigDecimal a = cin.nextBigDecimal();
			int n = cin.nextInt();
			String s = a.pow(n).stripTrailingZeros().toPlainString();
			if(s.charAt(0)=='0')
				System.out.println(s.substring(1));
			else
				System.out.println(s);
		}
		
		cin.close();
	}
}