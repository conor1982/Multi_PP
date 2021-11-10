#include <string.h>
#include <stdlib.h>
#include <stdio.h>



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
   printf("--------------\n");
   printf("PRODUCT NAME: %s \nPRODUCT PRICE: %.2f\n",p.name,p.price); 
   //printf("--------------\n");
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

struct Shop createAndStockShop()
{
    
    FILE *fp = fopen("stock.csv", "r");
    if(fp == NULL) {
    perror("Unable to open file!");
    exit(1);
}

    char line[128];

    fgets(line, sizeof(line), fp);
    float cash = atof(line);
    //printf("cash in shop is %.2f\n", cash);

    struct Shop shop = {cash};


    while(fgets(line, sizeof(line), fp) != NULL) {
    char *n =strtok(line,",");
    char *pri =strtok(NULL,",");
    char *quant =strtok(NULL,",");

    int quantity = atoi(quant);
    double price = atof(pri);
    char *name = malloc(sizeof(char)* 50);
    strcpy(name,n);
    struct Product product ={name,price};
    struct ProductStock stockItem = {product,quantity};
    shop.stock[shop.index++] = stockItem;

    printf("NAME OF PRODUCT %s PRICE %.2f QUANTITY %d\n",name,price,quantity);
    }
    //printProduct(shop.stock[0].product);
    return shop;
}

double find(struct Shop s, char* name)
{
	for (int i = 0; i < s.index; i++)
	{
		if (strcmp(name, s.stock[i].product.name) == 0){
			return s.stock[i].product.price;
		}
	}
	return 1;
}

void printshop(struct Shop s)
{
    printf("Shop has %.2f in cash\n", s.cash);
    for (int i = 0; i < s.index; i++)
    {

      printProduct(s.stock[i].product);
      printf("The shop has %d of the above product\n", s.stock[i].quantity);

    }



}

int main(void)
{
    struct Customer conor ={"Conor",100.00};
       
    struct Product coke ={"Can Coke",1.10};
    struct Product bread = {"Bread",0.7};
    //printProduct(coke);

    struct ProductStock  cokeStock ={coke,20};
    struct ProductStock  breadStock ={bread,2};

    //conor.shoppingList[conor.index++] = cokeStock;
    //conor.shoppingList[conor.index++] = breadStock;

    //printCustomer(conor);

    struct Product productA = { "Coke Can", 0.0 };
	struct Product productB = { "Big Bags", 0.0 };
	struct Product productC = { "Spaghetti", 0.0 };

    struct ProductStock  StockA ={productA,20};
    struct ProductStock  StockB ={productB,5};   
    struct ProductStock  StockC ={productC,2}; 

    struct ProductStock array[] = {StockA,StockB,StockC};

    struct Shop shop = createAndStockShop();
    //printshop(shop);

    
    //printf("The shop has %d of the product %s\n",StockA.quantity, StockA.product.name);
    double totalCostForCustomer = 0;
    for (int i=0; i<3; i++){
      struct Product p = array[i].product;
      double price = find(shop,p.name);
     // printf("The price of %s in the shop is %.2f\n",p.name,price);
      double totalCostOfItem = array[i].quantity * price;
     // printf("You want %d of %s,that will cost you %.2f\n",array[i].quantity,p.name,totalCostOfItem);
      totalCostForCustomer += totalCostOfItem;
    }
   // printf("\nTotal Cost for customer will be %.2f\n",totalCostForCustomer);


    return 0;
}