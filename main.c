#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// struct for products

typedef struct // I've used typedef to make my code more readable and easier to debug
{

    int code; // this var will hold the product ID
    char name[50]; // this var will hold the product name
    int price; // this var will hold the product price
    int TTC;
    int quantity; // this var will hold the product quantity
    char *Time_now; // this var will holde the time of action(like buying or adding)
    int zero;

}Product; // name of struct 

int count = 0;
int broughtCount = 0;

Product products[500];
Product broughtProducts[500];



// this function is for adding products to the database

void addProduct()
{

   
    int TTC;

    /* == Product name == */
    printf("What is the product name ? :");
    scanf("%s", &products[0].name);


    /* == Product id == */
    printf("What is the product id ? : ");
    scanf("%d" , &products[0].code);


    /* == Product price == */
    printf("What is the product price ? :");
    scanf("%d" , &products[0].price);

    products[0].TTC = products[0].price + (products[0].price*0.15);

    /* == Product Qunatity == */
    printf("What is the product qunatity ? :");
    scanf("%d", &products[0].quantity );
    /* == Action Qunatity == */
    time_t now = time(NULL);
    products[0].Time_now = ctime(&now);

    /* == message == */

    printf("The product has been added!");

    count++;
}



void AddManyProducts(int num)
{

    int i , j;

    //Product *products = calloc(num, sizeof(Product)); // set an array using calloc so user could controle the size of it

    for(i = count; i < num+count; i++){

        /*  == products name == */
        printf("Enter the name of product [%d] : " , i+1); // ask user to type a name 
        scanf("%s" , &products[i].name); // push the value the user typed to the var above

        /*  == products id == */

        int id;
        printf("Enter the id of product [%d] : ", i+1);
        scanf("%d" , &products[i].code);

        /*  == products price == */

        int price; 
        printf("Please enter the price of product [%d] : " , i+1);
        scanf("%d", &products[i].price);
        products[i].TTC = products[i].price + (products[i].price * 0.15);

        /* == products qunatity == */

        int qunatity;
        printf("Enter the product quantity of product [%d] : ", i+1);
        scanf("%d", &products[i].quantity );

        /* == time of action == */

        time_t now = time(NULL);
        products[i].Time_now = ctime(&now);

    }
    printf("The products hase been added !");

    count+=num;

}

/* !== This function is for sortingg products by price ==! */


void ListOfProductsByPrice(int num)
{

    int i,j;

    // Bubble sort

    for(i = 0; i < count; i++){
        
        for(j = 0; j < count; j++){

            if(products[j].price < products[j+1].price){

                Product temp = products[j];
                products[j] = products[j+1];
                products[j+1] = temp;

            }

        }

    }

    // to show the sorted version in screen

    for(i = 0; i < count; i++){

        printf("!== Product N %d ==!\n", i+1);
        printf("Product name : %s\n" , &products[i].name);
        printf("Product price : %d\n" , products[i].price);
        printf("Product TTC price : %d\n" , products[i].TTC);
        printf("Product code :%d\n", products[i].code);
        printf("Product qunatity : %d\n", products[i].quantity);
        printf("Time of buying : %s\n", products[i].Time_now);

    }

}


/* !== this function is for sorting products by names ==! */


void ListOfProductsByName(int num)
{

    int i,j;
    // Bubble sort
    do
    {
        i=0;

        for(j = 0; j < count; j++){

            if(strcmp(products[j].name, products[j+1].name) <  0 ){
                i++;
                Product temp = products[j];
                products[j] = products[j+1];
                products[j+1] = temp;

            }
            

        }

    }while(i > 0);
        



    // to show the sorted version in screen

    for(i = 0; i < count; i++){

        printf("!== Product N %d ==!\n", i+1);
        printf("Product name : %s\n" , products[i].name);
        printf("Product price : %d\n" , products[i].price);
        printf("Product TTC price : %d\n" , products[i].TTC);
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
                    printf("Product TTC price : %d" , products[i].TTC);
                    printf("Proudct code : %d\n" , products[i].code);
                    printf("Type 0 to exit the programm or 1 to continue : ");
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

                
                if(products[i].quantity - quantityHolder >= 0){
                    printf("Product with code : %d\n", products[i].code);
                    products[i].quantity = products[i].quantity - quantityHolder;
                    strcpy(broughtProducts[i].name,products[i].name);
                    broughtProducts[i].code = products[i].code;
                    broughtProducts[i].quantity = products[i].quantity;
                    broughtProducts[i].price = products[i].price;
                    broughtProducts[i].TTC = products[i].TTC;
                    time_t now = time(NULL);
                    broughtProducts[i].Time_now = ctime(&now);
                    printf("Has been bought successfully!\n");
                
                }else {
                    printf("Sorry, there no enough quantity of this product!\n");
                }
                
                printf("Type 0 to exit the programm or 1 to continue : \n");
                scanf("%d", &chiox);
                break;
        }

        

    }
    broughtCount+=quantityHolder;
        
    } while (chiox != 0);
    



}

// this function will show the products with quantity less than 3; 

void StockStatus(int num)
{
    int i;
    for(i = 0; i < num; i++){

        if(products[i].quantity < 3){

            printf(" !== Products with quantity less than 3 : ==! \n");
            printf("%s\n", &products[i].name);

        }

    }

}
// this function is for modifying product quantity
void modifyQuantityOfProduct(int num)
{

    int productCode,i,newQuantity;

    printf("Enter the product code : ");
    scanf("%d", &productCode);

    for(i = 0; i < num; i++){

        if(products[i].code == productCode){

            printf("Enter new quantity : ");
            scanf("%d", &newQuantity);

            products[i].quantity+=newQuantity;

        };

    }

}

// delete an element 

void deleteElement(int num)
{
    int i ,codeHolder,count;

    for(i = 0; i < num; i++){

        if(products[i].code == codeHolder){

            products[i] = products[i+1];

        };
        count++;

    }

    if(count==0){

        printf("Sorry, this item do not exsit");

    };

}
// this function will hande the statistique options 

void StatistiqueOptions(int num)
{
    int chiox,i,sum,exit = 1;
    printf("Wich service you'll like to use ? : \n 1 : Revenue \n 2 : Brought products  ");
    scanf("%d", &chiox);

    do{

        switch(chiox){

            case 1: 
                for(i = 0; i < num; i++){

                    sum+=broughtProducts[i].price*broughtCount;
            
                }

                printf("Day revenue : %d\n" , sum);
                break;

            case 2:
                printf(" prodct brought today : %d\n" , broughtCount );
                break;

        }
    printf("If you want t exit the programm type : 0  \n Your choice : ");
    scanf("%d" , &exit);
    }while(exit != 0);

    

}


// this function is for shwing the menu for users;

void Menu()
{

    // this var will hold the user choice 

    int c,num;

    printf("\n=== Pharmacie menu ===\n- Add new product : press 1 \n- Add many new products : press 2  \n- List of products : press 3\n- Search product : press 4\n- Buy product : press 5\n- Stock status : 6\n- Modify quantity of products : 7\n- delete an element : 8\n- statistique : 9 \nChosen service : ");
    scanf("%d" , &c);

    if(c != 1 && c != 2 && c != 3 && c != 4  && c != 5 && c != 6 && c != 7 && c != 7 && c != 8 && c != 9){ // if users typed a number else 1 2 3 4 printf the following : 
        
        printf("Sorry, this service isn't avialble");

    }else if(c == 1){ // if user type 1 then call the addProduct function

        addProduct();

    }else if(c == 2){ // if user type 2 then call the AddManyProducts() function;

        
        printf("How many product you want to add ? : "); // asking user about how many products he wants to add
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

    }else if(c == 7){
        
        modifyQuantityOfProduct(num);

    }else if(c == 8){

        deleteElement(num);

    }else if(c == 9){

        StatistiqueOptions(broughtCount);

    };


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