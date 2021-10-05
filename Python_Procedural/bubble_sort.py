def bubble_sort(list1):
    """ 
        Given a list of numbers as input this function will sort the list.
    
        :param list: the list of numbers given as input
        :return: the sorted list
    """
    for i in range(0,len(list1)-1):  
        for j in range(len(list1)-1):  
            if(list1[j]>list1[j+1]):  
                temp = list1[j]  
                list1[j] = list1[j+1]  
                list1[j+1] = temp
    return list1