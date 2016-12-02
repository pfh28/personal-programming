#a simple program that takes a set of strings and assigns the shortest unique representation to each word


def toLower(wordlist):

	for i in range(0,len(wordlist)):
		wordlist[i] = wordlist[i].lower()

def sort_by_length(wordlist):
	for i in range(0, len(wordlist)):
		smallest = findSmallest(wordlist, i)
		swap(wordlist, smallest, i)
		
def findSmallest(wordlist, startIndex):
	smallest = startIndex
	for i in range(startIndex, len(wordlist)):
		if len(wordlist[smallest]) > len(wordlist[i]):
			smallest = i
	return smallest
		
def swap(wordlist, i, j):
	tmp = wordlist[i]
	wordlist[i] = wordlist[j]
	wordlist[j] = tmp
	
def remove_duplicates(wordlist):
	return list(set(wordlist))

permlist = []						#defined outside of recursive calls	
def makePermList(word, perm):
	if len(word) == 0:
		permlist.append(perm)
	else:
		makePermList(word[1:], perm)
		makePermList(word[1:], perm+word[0])
	
def make_codes(wordlist):
	dictionary
	for word in wordlist:
		makePermList(word, "")
		
	
wordlist = [
			"Bulbasaur", "Ivysaur", "Venusaur", "Charmander",
			"Charmeleon", "Charizard", "Squirtle", "Wartortle",
			"Blastoise", "Caterpie", "Metapod", "Butterfree",
			"Weedle", "Kakuna", "Beedrill", "Pidgey", "Pidgeotto",
			"Pidgeot", "Rattata", "Raticate", "Spearow", "Fearow",
			"Ekans", "Arbok", "Pikachu", "Rattata", "Raticate",
			"Spearow", "Fearow", "Ekans", "Arbok", "Pikachu"
			]
			
print wordlist

toLower(wordlist)
wordlist = remove_duplicates(wordlist)
sort_by_length(wordlist)

print wordlist

#make_codes(wordlist)