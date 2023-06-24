#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// This structure holds all medicine data
struct Drugs
{
	char medicineName[30];
	float medicinePrice;
	int medicineId;
	int medicineStock;
	char medicineCompany[30];
};

struct Drugs *inventory; // This array contails all medicines with their details

#define INITIAL_STOCK 25
#define PRINT_ALL 0	 // For printing all information
#define PRINT_SUPP 1 // For printing suppliers

void printMainMenu();
void mainMenu(int);
void initializeMedicineInventory();
void printInventory(int);
void printSupplierMenu();
void supplierMenu(int);
void searchSupplier();
void newSupplier(int);
void buyMedicine();
void customerInformation();
void printCustomerInfo();
void supplierCall();
void replenishStock();

int totalMedicines = 25; // Variable to keep track of number of medicines.
int refreshStock = 1;

int main(void)
{
	initializeMedicineInventory();
	int userChoice;

	do
	{
		if (refreshStock % 5 == 0) // After every 5 buys, stock will be restored.
		{
			replenishStock();
		}
		printMainMenu();
		scanf("%d", &userChoice);
		mainMenu(userChoice);
	} while (userChoice > 1 || userChoice < 5);

	free (inventory);

	return 0;
}

void initializeMedicineInventory()
{

	inventory = (struct Drugs *)malloc(25 * sizeof(struct Drugs));

	strcpy(inventory[0].medicineName, "Ethambutol");
	strcpy(inventory[1].medicineName, "Amphotericin B");
	strcpy(inventory[2].medicineName, "Clotrimazole");
	strcpy(inventory[3].medicineName, "Fluconazole");
	strcpy(inventory[4].medicineName, "Flucytosine");
	strcpy(inventory[5].medicineName, "Griseofulvin");
	strcpy(inventory[6].medicineName, "Itraconazole");
	strcpy(inventory[7].medicineName, "Moxifloxacin");
	strcpy(inventory[8].medicineName, "Pyrazinamide");
	strcpy(inventory[9].medicineName, "Rifabutin");
	strcpy(inventory[10].medicineName, "Rifampicin");
	strcpy(inventory[11].medicineName, "Rifapentine");
	strcpy(inventory[12].medicineName, "Amikacin");
	strcpy(inventory[13].medicineName, "Amoxicillin");
	strcpy(inventory[14].medicineName, "Bedaquiline");
	strcpy(inventory[15].medicineName, "Clofazimine");
	strcpy(inventory[16].medicineName, "Cycloserine");
	strcpy(inventory[17].medicineName, "Delamanid");
	strcpy(inventory[18].medicineName, "Ethionamide");
	strcpy(inventory[19].medicineName, "Levofloxacin");
	strcpy(inventory[20].medicineName, "Linezolid");
	strcpy(inventory[21].medicineName, "Meropenem");
	strcpy(inventory[22].medicineName, "Moxifloxacin");
	strcpy(inventory[23].medicineName, "P-aminosalicylic acid");
	strcpy(inventory[24].medicineName, "Streptomycin");

	strcpy(inventory[0].medicineCompany, "sinopharm");
	strcpy(inventory[1].medicineCompany, "roche pharma");
	strcpy(inventory[2].medicineCompany, "novartis");
	strcpy(inventory[3].medicineCompany, "merck");
	strcpy(inventory[4].medicineCompany, "abbvie");
	strcpy(inventory[5].medicineCompany, "janssen");
	strcpy(inventory[6].medicineCompany, "glaxosmithkline");
	strcpy(inventory[7].medicineCompany, "bristol myers");
	strcpy(inventory[8].medicineCompany, "pfizer");
	strcpy(inventory[9].medicineCompany, "sanofi");
	strcpy(inventory[10].medicineCompany, "takeda pharma");
	strcpy(inventory[11].medicineCompany, "astrazeneca");
	strcpy(inventory[12].medicineCompany, "gilead sciences");
	strcpy(inventory[13].medicineCompany, "eli lilly");
	strcpy(inventory[14].medicineCompany, "amgen");
	strcpy(inventory[15].medicineCompany, "bayer");
	strcpy(inventory[16].medicineCompany, "novo nordisk");
	strcpy(inventory[17].medicineCompany, "boehringer");
	strcpy(inventory[18].medicineCompany, "teva pharma");
	strcpy(inventory[19].medicineCompany, "merck");
	strcpy(inventory[20].medicineCompany, "biogen");
	strcpy(inventory[21].medicineCompany, "viatris");
	strcpy(inventory[22].medicineCompany, "astellas pharma");
	strcpy(inventory[23].medicineCompany, "daiichi sankyo");
	strcpy(inventory[24].medicineCompany, "otsuka holdings");

	inventory[0].medicinePrice = 3.184;
	inventory[1].medicinePrice = 66.5722;
	inventory[2].medicinePrice = 20;
	inventory[3].medicinePrice = 445.83;
	inventory[4].medicinePrice = 160.0;
	inventory[5].medicinePrice = 160;
	inventory[6].medicinePrice = 128;
	inventory[7].medicinePrice = 285.65;
	inventory[8].medicinePrice = 144.56;
	inventory[9].medicinePrice = 210.71;
	inventory[10].medicinePrice = 112.6;
	inventory[11].medicinePrice = 88.79;
	inventory[12].medicinePrice = 35;
	inventory[13].medicinePrice = 326.87;
	inventory[14].medicinePrice = 72.34;
	inventory[15].medicinePrice = 144;
	inventory[16].medicinePrice = 259.66;
	inventory[17].medicinePrice = 356.43;
	inventory[18].medicinePrice = 400;
	inventory[19].medicinePrice = 108.79;
	inventory[20].medicinePrice = 61.2;
	inventory[21].medicinePrice = 179.84;
	inventory[22].medicinePrice = 215.51;
	inventory[23].medicinePrice = 95.6;
	inventory[24].medicinePrice = 25.4;
	int i;
	for (i = 0; i < totalMedicines; i++)
	{
		inventory[i].medicineId = i + 100;
		inventory[i].medicineStock = INITIAL_STOCK;
	}
}

void replenishStock()
{
	int i;
	for (i = 0; i < totalMedicines; i++)
	{
		inventory[i].medicineStock = INITIAL_STOCK;
	}
}

void printMainMenu()
{
	printf("\t\t**********MEDICAL STORE MANAGEMENT SYSTEM**********\n\n");
	printf("1) Supplier Information\n\n");
	printf("2) Customer Information\n\n");
	printf("3) Medicine Inventory\n\n");
	printf("4) Buy medicine\n\n");
	printf("5) Exit\n\n");
	printf("Please enter the number present besides the menu to access it: ");
}

void mainMenu(int userChoice)
{
	switch (userChoice)
	{
	case 1:
		supplierCall();
		break;
	case 2:
		printCustomerInfo();
		break;
	case 3:
		printInventory(PRINT_ALL);
		break;
	case 4:
		buyMedicine();
		customerInformation();
		break;
	case 5:
		exit(0);
		break;
	default:
		printf("Please enter a valid menu number.\n");
		break;
	}
}

void printInventory(int whatToPrint)
{
	int i;
	printf("\n");

	if (whatToPrint == 0) // For printing all
	{
		printf("%-30s%-30s%-15s%-15s%-15s", "Name", "Company name", "ID", "Stock", "Price");
		printf("\n");
		printf("\n");
		for (i = 0; i < totalMedicines; i++)
		{
			printf("%-30s", inventory[i].medicineName);
			printf("%-30s", inventory[i].medicineCompany);
			printf("%-15d", inventory[i].medicineId);
			printf("%-15d", inventory[i].medicineStock);
			printf("%-15f", inventory[i].medicinePrice);
			printf("\n");
		}
	}
	else if (whatToPrint == 1) // For printing suppliers
	{
		printf("%-15s", "Company name");
		printf("\n");
		printf("\n");
		for (i = 0; i < totalMedicines; i++)
		{
			printf("%d) %-15s\n", i + 1, inventory[i].medicineCompany);
		}
	}

	printf("\n");
	printf("\n");
}

void printSupplierMenu()
{
	printf("\t\t**********SUPPLIER MENU**********\n\n");
	printf("1) Add a new supplier\n\n");
	printf("2) Search for a supplier\n\n");
	printf("3) Show existing suppliers\n\n");
	printf("4) Main menu\n\n");
	printf("Please enter the number present besides the menu to access it: ");
}

void supplierMenu(int userChoice)
{
	switch (userChoice)
	{
	case 1:
		newSupplier(totalMedicines);
		break;
	case 2:
		searchSupplier();
		break;
	case 3:
		printInventory(PRINT_SUPP);
		break;
	case 4:
		main();
		break;
	default:
		printf("Please enter a valid menu number.\n");
		break;
	}
}

void searchSupplier()
{
	char userSupplier[30];
	int flag = 0, i; // Used to avoid printing "supplier present" line multiple times if supplier
					 // provides multiple medicines.

	printf("\nPlease enter the name of the supplier you would like to search for.\n");
	fgetc(stdin);
	fgets(userSupplier, 30, stdin);
	// Since fgets also takes \n as an input, below for loop removes that \n
	for (i = 0; i < strlen(userSupplier); i++)
	{
		if (userSupplier[i] == '\n')
		{
			userSupplier[i] = '\0';
		}
	}

	for (i = 0; i < strlen(userSupplier); i++) // Convert the user inputted string to lower case
	{
		userSupplier[i] = tolower(userSupplier[i]);
	}

	for (i = 0; i < totalMedicines; i++)
	{
		if (strcmp(userSupplier, inventory[i].medicineCompany) == 0)
		{
			if (flag == 0)
			{
				printf("\n\nThis supplier is present. Following medicines are available from this supplier.\n");
				flag = 1;
			}
			printf("%s\n", inventory[i].medicineName);
		}
	}
}

void newSupplier(int oldSize)
{
	int i;
	float price = 0;
	char newAddition[30];

	printf("\n");

	// To accomodate a new supplier, more memory needs to be given to inventory.
	inventory = (struct Drugs *)realloc(inventory, (oldSize + 1) * sizeof(struct Drugs));

	printf("Please enter the name of the supplier: \n");
	fgetc(stdin);
	fgets(newAddition, 30, stdin);

	// Since fgets also takes \n as an input, below for loop removes that \n
	for (i = 0; i < strlen(newAddition); i++)
	{
		if (newAddition[i] == '\n')
		{
			newAddition[i] = '\0';
		}
	}

	for (i = 0; i < strlen(newAddition); i++)
	{
		newAddition[i] = tolower(newAddition[i]);
	}
	strcpy(inventory[oldSize].medicineCompany, newAddition);
	printf("\n");

	printf("Please enter the name of the medicine they will supply: \n");
	fgets(newAddition, 30, stdin);

	// Since fgets also takes \n as an input, below for loop removes that \n
	for (i = 0; i < strlen(newAddition); i++)
	{
		if (newAddition[i] == '\n')
		{
			newAddition[i] = '\0';
		}
	}
	strcpy(inventory[oldSize].medicineName, newAddition);
	printf("\n");

	printf("Please enter the price they will supply at: \n");
	scanf("%f", &price);
	inventory[oldSize].medicinePrice = price;

	++totalMedicines;

	inventory[oldSize].medicineId = (totalMedicines - 1) + 100;
	// Array starts from index 0, but totalMedicines starts from 1
	// So we will subtract 1 to get the correct ID number.
	inventory[oldSize].medicineStock = INITIAL_STOCK;
}

// This function collects together all the supplier calls so
// one does not need to write all calls individually.
void supplierCall()
{
	int userIn;
	printf("\n");
	printSupplierMenu();
	scanf("%d", &userIn);
	supplierMenu(userIn);
}

void buyMedicine()
{
	int num = 0, quantity = 0, i;
	float price = 0;

	printf("\n");
	printf("Please enter the number besides the medicine you would like to buy\n");
	for (i = 0; i < totalMedicines; i++) // Print all available medicines
	{
		printf("%d) %s\n", i + 1, inventory[i].medicineName);
	}

	printf("\n");
	scanf("%d", &num);
	printf("\n");
	printf("Please enter the quantity of the medicine you would like to buy\n");
	scanf("%d", &quantity);

	if (quantity > inventory[num - 1].medicineStock)
	{
		printf("Sorry, we do not have as many medicines available.\n");
	}
	else
	{
		inventory[num - 1].medicineStock -= quantity;
		price = quantity * inventory[num - 1].medicinePrice;
	}

	printf("\n********BILL******** \n");
	printf("%-30s%-30s%-30s%-30s\n", "Medicine", "Company name", "ID", "Total price");
	printf("%-30s", inventory[num - 1].medicineName);
	printf("%-30s", inventory[num - 1].medicineCompany);
	printf("%-30d", inventory[num - 1].medicineId);
	printf("%-30f", price);
	printf("\n\n");
	refreshStock++;
}

void customerInformation()
{
	char custName[30];
	long int custNum = 0;
	int i;
	FILE *fp;

	printf("Please enter your name: ");
	fgetc(stdin);
	fgets(custName, 30, stdin);

	// Since fgets also takes \n as an input, below for loop removes that \n
	for (i = 0; i < strlen(custName); i++)
	{
		if (custName[i] == '\n')
		{
			custName[i] = '\0';
		}
	}
	printf("\n");
	printf("Please enter your number: ");
	scanf("%ld", &custNum);

	fp = fopen("customerInfo.txt", "a");

	fprintf(fp, "%s\n%ld\n\n", custName, custNum);
	fclose(fp);
}

void printCustomerInfo()
{
	FILE *fp;

	char c;

	fp = fopen("customerInfo.txt", "r");
	// Read contents from file
	c = fgetc(fp);
	while (c != EOF)
	{
		printf("%c", c);
		c = fgetc(fp);
	}

	fclose(fp);
}