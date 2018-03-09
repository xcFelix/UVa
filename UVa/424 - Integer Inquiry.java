import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		BigInteger a = BigInteger.ZERO;
		
		while(cin.hasNextBigInteger())
		{
			BigInteger b = cin.nextBigInteger();
			if(b.compareTo(BigInteger.ZERO)==0) break;
			a = a.add(b);
		}
		
		System.out.println(a);
		cin.close();
	}
}