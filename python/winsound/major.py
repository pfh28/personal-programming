import winsound

notes = {"C":16.35, "D":18.32, "E":20.6, "F":21.83,
		"G":24.5,"A":27.5,"B":30.87}

def play(note, number = 4, duration = 1000):
	winsound.Beep(int(notes[note]*(2**number)), duration)


play("C", 4, 1000)
play("D", 4, 1000)
play("E", 4, 1000)
play("F", 4, 1000)
play("G", 4, 1000)
play("A", 4, 1000)
play("B", 4, 1000)
play("C", 5, 1000)




#frequency = 262
#duration = 1000
#winsound.Beep(frequency, duration)