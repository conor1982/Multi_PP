#include <string.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <stdio.h>
//#include <fstream>


struct Product {
    char* name;
    double price;
};

struct ProductStock {
    struct Product product;
    int quantity;
 };

 struct Shop {
     double cash;
     struct ProductStock stock[20];
     int index;
 
 };

 struct  Customer {
    char* name;
    double budget;
    struct ProductStock shoppingList[10];
    int index;
};

void printProduct(struct Product p)
{
   printf("PRODUCT NAME: %s \nPRODUCT PRICE: %.2f\n",p.name,p.price); 
   printf("--------------\n");
}

void printCustomer(struct Customer c)
{
   printf("CUSTOMER NAME: %s \nCUSTOMER BUDGET: %.2f\n",c.name,c.budget); 
   printf("--------------\n");
   for(int i = 0; i < c.index;i++)
   {
       printProduct(c.shoppingList[i].product);
       printf("%s ORDERS %d OF ABOVE PRODUCT\n",
    c.name,c.shoppingList[i].quantity);
       double cost = c.shoppingList[i].quantity *
    c.shoppingList[i].product.price;  
       printf("THE COST TO %s WILL BE\n %.2f",c.name, cost);
   }
}

void createandstockshop()
{
    struct Shop shop = {200};

    FILE *fp = fopen("stock.csv", "r");
     if(fp == NULL) {
         perror("Unable to open file!");
         exit(1);
     }

     char chunk[128];
 
     while(fgets(chunk, sizeof(chunk), fp) != NULL) {
         //fputs(chunk, stdout);
         char *name = strtok(chunk,",");
         char *price = strtok(NULL,",");
         char *q = strtok(NULL,",");
        int quantity = atoi(q);

         printf("NAME OF PRODUCT %s PRICE %s QUANTITY %s\n",name,price,quantity);
     }
}

int main(void)
{
    //struct Customer conor ={"Conor",100.00};
       
    //struct Product coke ={"Can Coke",1.10};
    //struct Product bread = {"Bread",0.7};
    //printProduct(coke);

    //struct ProductStock  cokeStock ={coke,20};
    //struct ProductStock  breadStock ={bread,2};

    //conor.shoppingList[conor.index++] = cokeStock;
    //conor.shoppingList[conor.index++] = breadStock;

    //printCustomer(conor);

    createandstockshop();
     //printf("The shop has %d of the product %s\n",cokeStock.quantity, cokeStock.product.name);


    return 0;
}