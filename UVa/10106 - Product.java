import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		
		while(cin.hasNextBigInteger())
		{
			BigInteger a = cin.nextBigInteger();
			BigInteger b = cin.nextBigInteger();
			a = a.multiply(b);
			System.out.println(a);
		}
		
		cin.close();
	}
}