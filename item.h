#ifndef ITEM_H
#define ITEM_H

struct _Item // defining item structure
{
  double price;
  char *sku;
  char *name;
  char *category;
};
typedef struct _Item Item; // changing name of structure to item

#endif
