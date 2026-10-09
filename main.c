#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index) // function definition for adding items
{
    item_list[index].price = price; // assigning price to item

    item_list[index].sku = malloc(strlen(sku) + 1); // allocating space for sku
    strcpy(item_list[index].sku, sku); // copying value to item

    item_list[index].name = malloc(strlen(name) + 1); // allocating space for name
    strcpy(item_list[index].name, name); // copying value to item

    item_list[index].category = malloc(strlen(category) + 1); // allocating space for category
    strcpy(item_list[index].category, category); // copying value to item
}

void print_items(Item *item_list, int size) // function definition to print item
{
    for (int i = 0; i < size; i++)
    {
        printf("###############\n");
        printf("item name = %s\n", item_list[i].name);
        printf("item sku = %s\n", item_list[i].sku);
        printf("item category = %s\n", item_list[i].category);
        printf("item price = %f\n", item_list[i].price);
    }
}

double average_price(Item *item_list, int size) // function definition to calculate average price
{
    double total = 0;

    for (int i = 0; i < size; i++)
    {
        total += item_list[i].price;
    }

    return total / size;
}

void free_items(Item *item_list, int size) // function definition to free item memory
{
    for (int i = 0; i < size; i++)
    {
        free(item_list[i].sku); // free memory of sku for each item
        free(item_list[i].name); // free memory of name for each item
        free(item_list[i].category); // free memory of category for each item
    }

    free(item_list); // free array
}

int main(int argc, char *argv[])
{
    Item *item_list = malloc(sizeof(Item) * 5); // allocating memory for array

    // adding items to the array
    add_item(item_list, 6.00, "111", "fruit", "kiwi", 0);
    add_item(item_list, 3.00, "121", "fruit", "apple", 1);
    add_item(item_list, 5.00, "131", "veggie", "broccoli", 2);
    add_item(item_list, 4.00, "141", "dairy", "milk", 3);
    add_item(item_list, 7.00, "151", "dairy", "cheese", 4);

    print_items(item_list, 5); // printing all items

    double average = average_price(item_list, 5); // calculating average price of all items
    printf("average price of items = %f\n", average); // print average price

    // searching for an item by sku from the command line
    if (argc < 2) // check that a sku was given
    {
        printf("invalid sku\n");
        return 1; // exit
    }

    int ct = 0; // index for item search

    // move to search item
    while (ct < 5 && strcmp(item_list[ct].sku, argv[1]) != 0)
    {
        ct++;
    }

    if (ct < 5) // found the item
    {
        printf("item name = %s\n", item_list[ct].name);
        printf("item sku = %s\n", item_list[ct].sku);
        printf("item category = %s\n", item_list[ct].category);
        printf("item price = %f\n", item_list[ct].price);
    }
    else // item not found
    {
        printf("item not found\n");
    }

    free_items(item_list, 5); // free all memory

    return 0;
}
