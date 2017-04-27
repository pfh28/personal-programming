import java.awt.Robot;
import java.awt.event.KeyEvent;
import java.lang.Math;
import java.util.ArrayList;

public class Typist
{
	Robot rob;
	public static final int PRESS = 0;
	public static final int RELEASE = 1;
	public static final int DELAY = 2;

	public Typist()
	{
		try
		{
			rob = new Robot();
			rob.setAutoDelay(250);
		}catch(Exception e)
		{e.printStackTrace();}
	}
//format: keys, time delays:[p/r/t,<key>/<ms>]
	public void type(ArrayList<int[]> commands)		
	{
		for(int[] cmd : commands)
		{
			cmd[1] = Math.abs(cmd[1]);

			switch(cmd[0])
			{
				case PRESS:
					rob.keyPress(cmd[1]);
					break;
				case RELEASE:
					rob.keyRelease(cmd[1]);
					break;
				case DELAY:
					rob.delay(cmd[1]);
					break;
			}
		}
	}
}