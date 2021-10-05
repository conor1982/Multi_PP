#Write a program that asks the user for a number n 
# and gives them the possibility to choose between 
# computing the sum and computing the product of 1,…,n.

n = int(input('Enter a number: '))

choice = input('Would you like the sum or the product? ')

sum = 0
product = 1

if choice == 'sum':
    for i in range(1,n+1):
        sum = sum +i
    print("The sum of 1 to %d, was %d" % (n,sum))
elif choice == 'product':
    for i in range(1,n+1):
        product = product *i
    print("The product of 1 to %d, was %d" % (n,product))
else:
    print('i didnt understand choice')