def squares_of_evens(lst):
    evens = []
    for i in range(len(lst)):
            if lst[i]%2==0:
                evens.append(lst[i] *lst[i])
    return evens    
    pass