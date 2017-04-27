import java.util.HashMap;
import java.awt.event.KeyEvent;
import java.io.BufferedReader;
/*
	Class parses in which
	a) single key presses are represented by key names
	b) key combinations are space-delimited and released in reverse order of pressing
	c) delays are given as :<ms>
*/

import java.io.FileReader;
import java.util.Stack;
import java.util.ArrayList;

public class MacroParser
{
	HashMap<String, Integer> map;
	Typist typist;

	public MacroParser()
	{
		map = new HashMap<String, Integer>();
		map.put("Cancel",3);
		map.put("Backspace",8);
		map.put("Tab",9);
		map.put("Enter",10);
		map.put("Clear",12);
		map.put("Shift",16);
		map.put("Ctrl",17);
		map.put("Alt",18);
		map.put("Pause",19);
		map.put("Caps Lock",20);
		map.put("Escape",27);
		map.put("Convert",28);
		map.put("Space",32);
		map.put("Page Up",33);
		map.put("Page Down",34);
		map.put("End",35);
		map.put("Home",36);
		map.put("Left",37);
		map.put("Up",38);
		map.put("Right",39);
		map.put("Down",40);
		map.put("Comma",44);
		map.put("Minus",45);
		map.put("Period",46);
		map.put("Slash",47);
		map.put("0",48);
		map.put("1",49);
		map.put("2",50);
		map.put("3",51);
		map.put("4",52);
		map.put("5",53);
		map.put("6",54);
		map.put("7",55);
		map.put("8",56);
		map.put("9",57);
		map.put("Semicolon",59);
		map.put("Equals",61);
		map.put("A",65);
		map.put("B",66);
		map.put("C",67);
		map.put("D",68);
		map.put("E",69);
		map.put("F",70);
		map.put("G",71);
		map.put("H",72);
		map.put("I",73);
		map.put("J",74);
		map.put("K",75);
		map.put("L",76);
		map.put("M",77);
		map.put("N",78);
		map.put("O",79);
		map.put("P",80);
		map.put("Q",81);
		map.put("R",82);
		map.put("S",83);
		map.put("T",84);
		map.put("U",85);
		map.put("V",86);
		map.put("W",87);
		map.put("X",88);
		map.put("Y",89);
		map.put("Z",90);
		map.put("Open Bracket",91);
		map.put("Back Slash",92);
		map.put("Close Bracket",93);
		map.put("NumPad-0",96);
		map.put("NumPad-1",97);
		map.put("NumPad-2",98);
		map.put("NumPad-3",99);
		map.put("NumPad-4",100);
		map.put("NumPad-5",101);
		map.put("NumPad-6",102);
		map.put("NumPad-7",103);
		map.put("NumPad-8",104);
		map.put("NumPad-9",105);
		map.put("NumPad *",106);
		map.put("NumPad +",107);
		map.put("NumPad ,",108);
		map.put("NumPad -",109);
		map.put("NumPad .",110);
		map.put("NumPad /",111);
		map.put("F1",112);
		map.put("F2",113);
		map.put("F3",114);
		map.put("F4",115);
		map.put("F5",116);
		map.put("F6",117);
		map.put("F7",118);
		map.put("F8",119);
		map.put("F9",120);
		map.put("F10",121);
		map.put("F11",122);
		map.put("F12",123);
	}

	public ArrayList<int[]> parseFile(String fileName)
	{
		String line;
		ArrayList<int[]> rv = new ArrayList<int[]>();
		try
		{
			BufferedReader br = new BufferedReader(new FileReader(fileName));
			while ((line = br.readLine()) != null)
			{
    			rv.addAll(parseLine(line));
			}
		}catch(Exception e)
		{e.printStackTrace();}

		return rv;
	}

	public ArrayList<int[]> parseLine(String line)
	{
		Stack<String> stack = new Stack<String>();
		ArrayList<int[]> rv = new ArrayList<int[]>();
		String[] keys = line.split(" ");

		for(String key : keys)	//handle keypresses, delays, errors
		{
			int[] cmd = new int[2];
			if(map.containsKey(key))
			{
				cmd[0] = Typist.PRESS;
				cmd[1] = map.get(key);
				stack.push(key);
			}
			else if(key.matches("^:\\d+$"))
			{
				cmd[0] = Typist.DELAY;
				cmd[1] = Integer.parseInt(key.replaceAll(":", ""));
			}
			else
			{
				System.out.printf("\"%s\" Is not a supported key or delay time.", key);
				continue;	//prevents empty cmd from being added
			}
			rv.add(cmd);
		}

		while(!stack.empty())	//handle key releases
		{
			int[] cmd = new int[2];
			cmd[0] = Typist.RELEASE;
			cmd[1] = map.get(stack.pop());
			rv.add(cmd);
		}

		return rv;
	}
}