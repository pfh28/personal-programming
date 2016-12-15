def get_option_index_input(prompt, option_List):
	print(prompt)
	for i in range(len(option_List)):
		print("{}) {}".format(i+1, option_List[i]))
	choice = 0
	while choice < 1 or choice > len(option_List):
		choice = input("Please enter your choice\n")
	return choice
	
def ask_YN(prompt):
	choice = raw_input("{} Y/n\n".format(prompt))
	if choice.lower() == "y":
		return True
	return False
	
def prompt_input(prompt):
	return raw_input("{}\n".format(prompt));