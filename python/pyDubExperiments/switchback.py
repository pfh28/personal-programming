#Takes an audio segment, splits it into 1-second slices,
#and plays each slice forward, backward, then forward.
from pydub import AudioSegment
song = AudioSegment.from_wav("test2.wav")

interval = 1000
myList = []
for i in range(int(song.duration_seconds)):
	myList.append(song[:interval])
	song = song[interval:]
fixList = []
fixList.append(myList[0])
for i in range(1, len(myList)-1):
	#fixList.append(myList[i].overlay(myList[i-1].reverse().fade_out(interval)))
	fixList.append(myList[i])
	fixList.append(myList[i].reverse())
	fixList.append(myList[i])
out = AudioSegment.empty()
for second in fixList:
	out = out+second
#song = song._spawn(arr)

out.export("out.wav", "wav")