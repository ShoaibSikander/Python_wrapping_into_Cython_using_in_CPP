def work_py(a, b, c):
	print('Printing from Python: ' + a)
	print('Printing from Python: ' + b)
	print('Printing from Python: ' + c)
	
	dict_1 = {"id":0, "name":a, "year":1992}
	dict_2 = {"id":1, "name":b, "year":1992}
	dict_3 = {"id":2, "name":c, "year":1992}

	name_list = []
	name_list.append(dict_1)
	name_list.append(dict_2)
	name_list.append(dict_3)

	print(name_list)

	return name_list