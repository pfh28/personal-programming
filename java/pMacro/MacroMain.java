import java.util.ArrayList;

public class MacroMain
{
	public static void main(String[] args)
	{
		Typist typist = new Typist();
		MacroParser parser = new MacroParser();
		ArrayList<int[]> cmds = parser.parseFile("test");

		typist.type(cmds);

		for(int[] cmd : cmds)
		{
			System.out.printf("%d %d\n", cmd[0], cmd[1]);
		}
	}
}