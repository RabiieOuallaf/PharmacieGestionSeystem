#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// data structure for products 

typedef struct // I've used typedef to make my code more readable and easier to debug
{

    int code; // this var will hold the product ID
    char *name; // this var will hold the product name
    int price; // this var will hold the product price
    int quantity; // this var will hold the product quantity
    char *Time_now; // this var will holde the time of action(like buying or adding)

}Product; // name of struct 

int count = 0;

Product products[20];


// this function is for adding products to the database

void addProduct()
{

    // asking the user about wich service they wants to use

    int c;

    printf("=== Add product === \n 1 : Add one product ");
    scanf("%d" , &c);

    if(c != 1){

        printf("Sorry , this service isn't avialble");
        
    }else if(c == 1){

        int id;
        char name[50];
        int price;
        int qunantity;
    /* == Product id == */
        printf("What is the product id ? : ");
        scanf("%d" , &id);
        products[0].code = id;


    /* == Product name == */
        printf("What is the product name ? :");
        scanf("%s", &name);
        products[0].name = name;

    /* == Product price == */
        printf("What is the product price ? :");
        scanf("%d" , &price);
        products[0].price = price;

    /* == Product Qunatity == */
        printf("What is the product qunatity ? :");
        scanf("%d", &qunantity );
        products[0].quantity = qunantity;
    /* == Action Qunatity == */
        time_t now = time(NULL);
        products[0].Time_now = ctime(&now);
    }
    count++;
}

void AddManyProducts(int num)
{

    int i , j;

    //Product *products = calloc(num, sizeof(Product)); // set an array using calloc so user could controle the size of it

    for(i = 0; i < num; i++){

        /*  == products name == */
        char *name; // this var will hold the product name
        printf("Enter the name of product [%d] :" , i+1); // ask user to type a name 
        scanf("%s" , &name); // push the value the user typed to the var above
        products[i].name = name; // push evreything to struct


        /*  == products id == */
        int id;
        printf("Enter the id of product [%d] :", i+1);
        scanf("%d" , &id);
        products[i].code = id;


        /*  == products price == */
        int price; 
        printf("Please enter the price of product [%d] :" , i+1);
        scanf("%d", &price);
        products[i].price = price;
        /* == products qunatity == */
        int qunatity;
        printf("Enter the product quantity of product [%d] : ", i+1);
        scanf("%d", &qunatity);
        products[i].quantity = qunatity;
        /* == time of action == */
        time_t now = time(NULL);
        products[i].Time_now = ctime(&now);
 

    }

    count+=num;

}

/* !== This function is for sortingg products by price ==! */


void ListOfProductsByPrice(int num)
{

    int i,j;

    // Bubble sort

    for(i = 0; i < num; i++){
        
        for(j = 0; j < num; j++){

            if(products[j].price < products[j+1].price){

                Product temp = products[j];
                products[j] = products[j+1];
                products[j+1] = temp;

            }

        }

    }

    // to show the sorted version in screen

    for(i = 0; i < num; i++){

        printf("!== Product N %d ==!\n", i+1);
        printf("Product name : %s\n" , &products[i].name);
        printf("Product price : %d\n" , products[i].price);
        printf("Product code :%d\n", products[i].code);
        printf("Product qunatity : %d\n", products[i].quantity);
        printf("Time of buying : %s\n", products[i].Time_now);

    }

}


/* !== this function is for sorting products by names !== */


void ListOfProductsByName(int n)
{

    int i,j;
    // Bubble sort
    for(i = 0; i < n; i++){

        for(j = i+1; j < n; j++){

            if(strcmp(&products[i].name, &products[j].name) > 0 ){

                Product temp = products[j];
                products[j] = products[i];
                products[i] = temp;

            }

        }

    }

    // to show the sorted version in screen

    for(i = 0; i < n; i++){

        printf("!== Product N %d ==!\n", i+1);
        printf("Product name : %s\n" , &products[i].name);
        printf("Product price : %d\n" , products[i].price);
        printf("Product code :%d\n", products[i].code);
        printf("Product qunatity : %d\n", products[i].quantity);
        printf("Time of buying : %s\n", products[i].Time_now);

    }

}

/* !== This function is for searching by code ==! */

void Searching(int n)
{
    int codeSearch,chiox,quantitySearch;

    printf("Chose a way of searching : \n 1 : code \n 2 : quantity \n Your choice : ");
    scanf("%d", &chiox);
    
    do{

        switch (chiox)
        {
            case 1:
            printf("Enter the code : ");
            scanf("%d", &codeSearch);
            for(int i = 0; i < n; i++){

                if(products[i].code == codeSearch){

                    printf("!== Product with code : %d ==!\n", products[i].code);
                    printf("Product name : %s\n", &products[i].name);
                    printf("Product price : %d\n" , products[i].price);
                    printf("Proudct quantity : %d\n" , products[i].quantity);
                    printf("Type 0 to exit the programm : ");
                    scanf("%d", &chiox);
                    break;
                }

            }
            case 2:
            printf("Enter the quantity  : ");
            scanf("%d", &quantitySearch);
            for(int i = 0; i < n; i++){

                if(products[i].quantity == quantitySearch){

                    printf("!== Product with quantity : %d ==!\n", products[i].quantity);
                    printf("Product name : %s\n", &products[i].name);
                    printf("Product price : %d\n" , products[i].price);
                    printf("Proudct code : %d\n" , products[i].code);
                    printf("Type 0 to exit the programm : ");
                    scanf("%d", &chiox);
                    break;
                }

            }
            
                
        }

    }while(chiox != 0);
    

}
// this function is to handle the buying process
void buy(int n)
{
    int codeHolder,quantityHolder,chiox = 1;
    do
    {
        
        printf("Product code :");
        scanf("%d",&codeHolder);
        printf("Enter quantity : ");
        scanf("%d", &quantityHolder);


        for(int i = 0; i < n; i++){

            if(products[i].code == codeHolder){

                
                if(products[i].quantity - quantityHolder > 0){
                    printf("Product with code : %d\n", products[i].code);
                    products[i].quantity = products[i].quantity - quantityHolder;
                    printf("Has been bought successfully!\n");
                
                }else {
                    printf("Sorry, there no enough quantity of this product!");
                }
                
                printf("Type 0 to exit the programm : \n");
                scanf("%d", &chiox);
                break;
        }

    }
        
    } while (chiox != 0);
    



}

// this function will show the products with quantity less than 3; 

int StockStatus(int n)
{
    int i;
    for(i = 0; i < n; i++){

        if(products[i].quantity < 3){

            printf(" !== Products with quantity less than 3 : ==! \n");
            printf("%s\n", &products[i].name);

        }

    }

}


// this function is for shwing the menu for users;

void Menu()
{

    // this var will hold the user choice 

    int c,num;

    printf("\n=== Pharmacie menu ===\n- Add new product : press 1 \n- Add many new products : press 2  \n- List of products : press 3\n- Search product : press 4\n- Buy product : press 5\n- Stock status : 6\n Chosen service : ");
    scanf("%d" , &c);

    if(c != 1 && c != 2 && c != 3 && c != 4  && c != 5 && c != 6){ // if users typed a number else 1 2 3 4 printf the following : 
        
        printf("Sorry, this service isn't avialble");

    }else if(c == 1){ // if user type 1 then call the addProduct function

        addProduct();

    }else if(c == 2){ // if user type 2 then call the AddManyProducts() function;

        
        printf("How many product you want to add ?"); // asking user about how many products he wants to add
        scanf("%d" , &num);

        AddManyProducts(num);

    }else if(c == 3){ // if user type 2 then call a function to show a list of products

        int chiox;

        //ListOfProducts();
        printf("!== sort list style !== \n Price : 1 \n Name : 2 \n Your choice : ");
        scanf("%d", &chiox);

        switch (chiox)
        {
        case 1:
            ListOfProductsByPrice(num);;
            break;

        case 2:
            ListOfProductsByName(num);
            break;
        
        default:
            printf("Please select an aviablbe servie !");
            break;
        }


    }else if(c == 4){ // if user typed 4 then call the search function
        
        Searching(num);

    }else if(c == 5){ // if user typed 5 then call the buy() function

       buy(num);

    }else if(c == 6){

        StockStatus(num);

    }


    };




int main()
{

    int exit = 1;

    do
    {

        Menu();
        
        
    } while (exit == 1);
        printf("!== If you want to exit type 1 ==! \n !== If you want to continue type 3 !==\n Your choice : ");
        scanf("%d", &exit);
    

    return 0;
};