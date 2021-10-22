from dataclasses import dataclass
from typing import List
import csv

@dataclass
class Product:
    name: str
    price: float

@dataclass
class ProductStock:
    product: Product
    quantity: int

@dataclass
class Shop:
    cash: float
    stock: List[ProductStock]

@dataclass
class Customer:
    name: str
    budget: float
    shopping_list: List[ProductStock]

def create_and_stock_shop():
    s = Shop(200.0, [])
    with open('stock.csv') as csv_file:
        csv_reader = csv.reader(csv_file,delimiter=',')
        line_count = 0
        for row in csv_reader:
            p = Product(row[0], float(row[1]))
            ps = ProductStock(p, float(row[2]))
            s.stock.append(ps)
    return s

def print_product(p):
    print(f'\nPRODUCT NAME: {p.name} \nPRODUCT PRICE {p.price}')

def print_customer(c):
    print(f'CUSTOMER NAME {c.name} \nCUSTOMER BUDGET {c.budget}')

    for item in c.shopping_list:
        print_product(item.product)

        print(f'{c.name} ORDERS {item.quantity} OF THE ABOVE PRODUCT')
        cost = item.quantity * item.product.price
        print(f'THE COST TO {c.name} will be €{cost}')

def print_shop(s):
    print(f'THE SHOP HAS {s.cash} IN CASH')
    for item in s.stock:
        print_product(item.product)
        print(f'THE SHOP HAS {item.quantity} OF THE ABOVE')

p = Product("Coke",1.0)
s = create_and_stock_shop()
print_shop(s)

#print_product(p)

