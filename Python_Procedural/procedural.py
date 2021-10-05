import csv
from typing import Match
from bubble_sort import bubble_sort

def get_maximum_value(list):
    """
    Given a list of numbers as input that will return the maximum value.

    :param list: the list of numbers given as input
    :return: the maximum value in the list
    """
    maximum = list[0]
    for l in list:
        if maximum < l:
            maximum = l
    return maximum

def get_minimum_value(list):
    """
    Given a list of numbers as input that will return the minimum value.

    :param list: the list of numbers given as input
    :return: the minimum value in the list
    """
    minimum = list[0]
    for l in list:
        if minimum > l:
            minimum = l
    return minimum
            
def get_average(list):
    """ 
        Given a list of numbers as input this function will return the numerical average.
    
        :param list: the list of numbers given as input
        :return: the numerical average of the list
    """
    total = 0
    for l in list:
        total += l
        
    average = total / len(list)
    return average

def get_median_value(list):
    """ 
        Given a list of numbers as input this function will return the median value.
    
        :param list: the list of numbers given as input
        :bubble function called within function to sort list
        :return: the median value of the list
    """
    list1 = list.copy()
    bubble_sort(list1)
    median = list1[int(len(list1)/2)]
    return median

    
def get_mode(list):
    """ 
        Given a list of numbers as input this function will return the mode value.
    
        :param list: the list of numbers given as input
        :return: the mode value of the list
    """
    highest_freq = 0
    mode = scores[0]
    for score in scores:
        frequency = 0
        for score2 in scores:
            if score == score2:
                frequency += 1
        if frequency > highest_freq:
            mode = score
            highest_freq = frequency
    return mode

def read_scores_from_csv(filename):
    """ 
        Given a file name.csv and return a specific column of data within that file
    
        :param list: filename.csv
        :return: the median value of the list
    """
    scores = []
    with open(filename, mode ='r') as file:   
        csvFile = csv.DictReader(file)
    
        for lines in csvFile:
            score = int(lines["Score"])
            scores.append(score)    
    return scores

def variance(list):
    m = get_average(list)

    res = sum((x-m)**2 for x in list)/(len(list))
    return res

def sqrt_Func_Newton(x):

    #Approx start point dividing input number by 2
    approx = x/2
        
    #Loop while absolute of value of f(x) is greater or equal than 0.01
    #Ref https://www.youtube.com/watch?v=2158QbsunA8
    while abs(approx**2-x) >= 0.01:
        approx = approx - (approx**2 - x)/(2*approx)

    #Return approx number at end of loop rounded to 1 decimel place
    return round(approx,2)

def stdev(list):
    var = variance(list)
    std_dev = sqrt_Func_Newton(var)
    return std_dev

    
if __name__ == "__main__":

    scores = read_scores_from_csv('example.csv')
    
    average = get_average(scores)
    minimum = get_minimum_value(scores)   
    maximum = get_maximum_value(scores)
    median = get_median_value(scores)
    mode = get_mode(scores)
    variance_of = variance(scores)
    stand_dev = stdev(scores) 
    

    print(f'Average: {average} Median: {median} Smallest: {minimum} Largest: {maximum} mode: {mode} variance {variance_of} standard deviation {stand_dev}')

def read__from_csv(filename,ind):
    """ 
        Given a file name.csv and return a specific column of data within that file
    
        :param list: filename.csv
        :return: the median value of the list
    """
    info = []
    with open(filename, mode ='r') as file:   
        csvFile = csv.DictReader(file)
    
        for lines in csvFile:
            res = (lines[ind])
            info.append(res)    
    return info


print('')


import numpy as np

min_value = min(scores)
max_value = max(scores)
total_value = sum(scores)
average_value = np.average(scores)

print('From Built in functions')
print(f'Average: {average_value}  Smallest: {min_value} Largest: {max_value}  Sum {total_value}')