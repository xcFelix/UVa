import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		
		while(cin.hasNext())
		{
			String s1, s2, s3;
			s1 = cin.next();
			s2 = cin.next();
			s3 = cin.next();
			
			System.out.println(s1 + ' ' + s2 + ' ' + s3);
			BigInteger cmp = BigInteger.valueOf(Integer.MAX_VALUE);
			BigInteger a = new BigInteger(s1);
			BigInteger b = new BigInteger(s3);
			BigInteger c;
			if(s2.charAt(0)=='+') c = a.add(b);
			else c = a.multiply(b);
			
			if(a.compareTo(cmp)>0) System.out.println("first number too big");
			if(b.compareTo(cmp)>0) System.out.println("second number too big");
			if(c.compareTo(cmp)>0) System.out.println("result too big");
		}
		
		cin.close();
	}
}