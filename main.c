#include <stdio.h>
#include <stdlib.h>

// data structure for products 

typedef struct // I've used typedef to make my code more readable and easier to debug
{

    int code; // this var will hold the product ID
    char *name; // this var will hold the product name
    int price; // this var will hold the product price
    int quantity // this var will hold the product quantity

}Product; // name of struct 

// creating a file 

FILE *Fpharmacie;

// this function is for adding products to the database

void addProduct()
{

    // asking the user about wich service they wants to use

    int c;

    printf("=== Add product === \n 1 : Add one product \n 2 : Add many products \n Your choice : ");
    scanf("%d" , &c);

    if(c != 1 && c != 2){

        printf("Sorry , this service isn't avialble");
        
    }else if(c == 1){

        // open the file and write in it 

        Fpharmacie = fopen("Pharmacie_products.txt", "w");

        int id;
        char name[12];
        int price;
    /* == Product id == */
        printf("What is the product id ? : ");
        scanf("%d" , &id);


    /* == Product name == */
        printf("What is the product name ? :");
        scanf("%s", &name);

    /* == Product price == */
        printf("What is the product price ? :");
        scanf("%d" , &price);

        // wrtinig info in file 
        fprintf(Fpharmacie , "%d\n" , id);
        fprintf(Fpharmacie, "%s\n", name);
        fprintf(Fpharmacie, "%d\n", price);

    // After writing all informations close the file
    fclose(Fpharmacie);

    Fpharmacie = fopen("Pharmacie_products.txt", "r");

    printf("Product name : %s" , name);

    }else if(c == 2){

        printf("Do somthing!"); // if user typed 1 then ask him how many products he wants to added , therefor call a function to manage data 

    }
    

}


// this function is for shwing the menu for users;

void Menu()
{

    // this var will hold the user choice 

    int c;

    printf("\n=== Pharmacie menu ===\n- Add new product : press 1 \n- Add many new products : press 2 \n- List of products : press  \n- Buy a product : press 4\n Chosen service : ");
    scanf("%d" , &c);

    if(c != 1 && c != 2 && c != 3 && c != 4){ // if users typed a number else 1 2 3 4 printf the following : 
        
        printf("Sorry, this service isn't avialble");

    }else if(c == 1){ // if user type 1 then call the addProduct function

        addProduct();

    };


}

int main()
{
    
    Menu();

    return 0;
};