#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
 


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

struct Customer custOrder()
{
    
    FILE *fp = fopen("customer.csv", "r");
    if(fp == NULL) {
    perror("Unable to open file!");
    exit(1);
}

    char line[128];

    fgets(line, sizeof(line), fp);
    char *a = strtok(line, ",");
    char *b = strtok(NULL, ",");
    char *custName = malloc(sizeof(char) * 50);
    double custBudget = atof(b);
    strcpy(custName, a); 
	struct Customer customer = { custName, custBudget};
    printf("NAME %s BUDGET %.2f\n",custName,custBudget);


    while(fgets(line, sizeof(line), fp) != NULL) {
		// TODO process remaining lines
        char *pn = strtok(line, ","); //product name
		char *qy = strtok(NULL, ","); //quantity
		int quantity = atoi(qy);
		char *productName = malloc(sizeof(char) * 50);
		strcpy(productName, pn);
		struct Product product = {productName};
		struct ProductStock orderItem = {product, quantity};
		customer.shoppingList[customer.index++] = orderItem;
        printf("PRODUCT %s ORDER %d\n",pn,quantity);
	}        
	return customer;
}   


int main(void) 
{
    struct Customer customer = custOrder();
	printf("Customer name is: %s and they have: %.2f for their budget\n", customer.name, customer.budget);
    
    
    return 0;
}