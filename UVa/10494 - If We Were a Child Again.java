import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		
		while(cin.hasNextBigInteger())
		{
			BigInteger a = cin.nextBigInteger();
			String s = cin.next();
			BigInteger b = cin.nextBigInteger();
			
			if(s.charAt(0)=='/') System.out.println(a.divide(b));
			else System.out.println(a.mod(b));
		}
		
		cin.close();
	}
}