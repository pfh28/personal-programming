import java.util.Scanner;

public class NumberGuesser
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int guess = 50;
		
		String resp;
		boolean isCorrect = false;
		do
		{
			System.out.println(guess);
			resp = in.nextLine();
			if(resp.equals("higher"))
				guess = increase(guess);
			else if(resp.equals("lower"))
				guess = decrease(guess);
			else
				isCorrect = true;
		}
		while(!isCorrect);
	}
	
	public static int increase(int guess)
	{
		return guess++;
	}
	
	public static int decrease(int guess)
	{
		return guess++;
	}
}