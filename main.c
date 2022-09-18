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
char ch;

Product *products;

// this function is for adding products to the database

void addProduct()
{

    // asking the user about wich service they wants to use

    int c;

    printf("=== Add product === \n 1 : Add one produc \n Your choice : ");
    scanf("%d" , &c);

    if(c != 1){

        printf("Sorry , this service isn't avialble");
        
    }else if(c == 1){

        Product product;

        // open the file and write in it 

        Fpharmacie = fopen("Pharmacie_products.txt", "a");

        

        int id;
        char name[12];
        int price;
    /* == Product id == */
        printf("What is the product id ? : ");
        scanf("%d" , &id);
        product.code = id;


    /* == Product name == */
        printf("What is the product name ? :");
        scanf("%s", &name);
        product.name = name;

    /* == Product price == */
        printf("What is the product price ? :");
        scanf("%d" , &price);
        product.price = price;

        

        // wrtinig info in file 
        
        fprintf(Fpharmacie , "%d\n" , product.code);
        fprintf(Fpharmacie, "%s\n", product.name);
        fprintf(Fpharmacie, "%d\n", product.price);

    
       
    // After writing all informations close the file
    fclose(Fpharmacie);
    }
}

void AddManyProducts(int num)
{

    int i , j;

    Product *products = calloc(num, sizeof(Product)); // set an array using calloc so user could controle the size of it

    Fpharmacie = fopen("Pharmacie_products.txt", "a"); // open file for reading and writing 

    for(i = 0; i < num; i++){

        /*  == products name == */
        char *name; // this var will hold the product name
        printf("Enter the name of product [%d]" , i+1); // ask user to type a name 
        scanf("%s" , &name); // push the value the user typed to the var above
        products[i].name = name; // push evreything to struct
        fprintf(Fpharmacie, "Product [%d] name : %s\n" ,i+1 , &products[i].name); // push evreything to file


        /*  == products id == */
        int id;
        printf("Enter the id of product [%d]", i+1);
        scanf("%d" , &id);
        products[i].code = id;
        fprintf(Fpharmacie, "Product [%d] code : %d\n" ,i+1 ,products[i].code);

        /*  == products price == */
        int price; 
        printf("Please enter the price of product [%d]" , i+1);
        scanf("%d", &price);
        products[i].price = price;
        fprintf(Fpharmacie, "Product [%d] price : %d\n" , i+1,products[i].price);

        fscanf(stdin, "This is a test %d" , products[i].code);

    }

    for(int i = 0; i < num; i++){

        printf("Product code : %d", products[i].code);

    };

    fclose(Fpharmacie); // close file


}

/*
void ListOfProducts()
{

    Fpharmacie = fopen("Pharmacie_products.txt", "r");


    ch=fgetc(Fpharmacie);

    while(ch != EOF)
    {
        printf("%c" , ch);
        ch=fgetc(Fpharmacie);
    }

    fclose(Fpharmacie);


}

*/



// this function is for shwing the menu for users;

void Menu()
{

    // this var will hold the user choice 

    int c,num;

    printf("\n=== Pharmacie menu ===\n- Add new product : press 1 \n- Add many new products : press 2  \n- List of products : press 3\n Chosen service : ");
    scanf("%d" , &c);

    if(c != 1 && c != 2 && c != 3 && c != 4){ // if users typed a number else 1 2 3 4 printf the following : 
        
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

        if(chiox != 1 && chiox != 2){

            printf("Please select an aviablbe servie !");

        }else if(chiox == 1){
            
            printf("Hey , you picked 1");

        }else if(chiox == 2){

            printf("Hey . you picked 2");

        }

    };


}

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