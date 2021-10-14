#include <string.h>
#include <stdlib.h>
#include <stdio.h>


struct Product {
    char* name;
    double price;
};

//model the stock
//struct that contains a struct
struct ProductStock {
    
    //based on product struct
    struct Product product;
    int quantity;
};

//must be before productstock struct
struct Shop{
    double cash;
    struct ProductStock stock[20];
};

// customer struct for customer data: name, budget
struct Customer {
    char* name;
    double budget;
    struct ProductStock shoppingList[10];
    int index;
};

//method to print product info
void printProduct(struct Product p)
{
    printf("PRODUCT NAME:  %s\n PRODUCT PRICE: %.2f\n ",p.name,p.price);
}

//method to print customer
void printCustomer(struct Customer c)
{
    
    printf("CUSTOMER NAME:  %s\n BUDGET: %.2f\n ",c.name,c.budget);
    
    //loop to pirnt out all items on shopping liast arrAY
    for(int i = 0;i < c.index;i++)
    
    {
        printProduct(c.shoppingList[i].product);
        printf("%s ORDERS %d OF ABOVE PRODUCT\n",c.name,c.shoppingList[i].quantity);

        //double cost = c.shoppingList[i].quantity* c.shoppingList[i].product.price;
        //printf("THE COST TO %s WILL BE %.2f",c.name,cost);
        //printf("---------------\n");

    }
}


int main(void)
{
    // initialise struct
    // call struct and alias
    struct Customer conor = {"Conor", 100};
    struct Customer james = {"James",50};
    
    
    // initialise struct
    // call struct and alias
    struct Product coke = {"Coke", 1.10};
    struct Product bread = {"Bread",1.50};
    
    // calling methods
    //printProduct(coke);
    //printProduct(bread);

    struct ProductStock cokeStock = {coke,20};
    struct ProductStock breadStock = {bread,50};
    conor.shoppingList[conor.index++] = cokeStock;
    conor.shoppingList[conor.index++] = breadStock;
    
    james.shoppingList[james.index++] = breadStock;

    printCustomer(conor);
    //printCustomer(james);
    


    
    return 0;
}

