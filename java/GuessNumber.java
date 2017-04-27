import java.util.Scanner;

public class GuessNumber
{
	public static void main(String[] args)
	{
		int answer =(int)(Math.random()*100);
		System.out.println("enter your guess");
		Scanner in = new Scanner(System.in);
		int inpt;
		do
		{
			inpt = in.nextInt();
			if(inpt > answer)
				System.out.println("Too High");
			else if(inpt < answer)
				System.out.println("Too Low");
		}
		while(inpt != answer);
		
		System.out.println("Correct");
	}
}