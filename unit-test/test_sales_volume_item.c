#ifndef sales_volume_item_TEST
#define sales_volume_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sales_volume_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sales_volume_item.h"
sales_volume_item_t* instantiate_sales_volume_item(int include_optional);



sales_volume_item_t* instantiate_sales_volume_item(int include_optional) {
  sales_volume_item_t* sales_volume_item = NULL;
  if (include_optional) {
    sales_volume_item = sales_volume_item_create(
      "0",
      "0",
      "0",
      "0",
      56,
      "0"
    );
  } else {
    sales_volume_item = sales_volume_item_create(
      "0",
      "0",
      "0",
      "0",
      56,
      "0"
    );
  }

  return sales_volume_item;
}


#ifdef sales_volume_item_MAIN

void test_sales_volume_item(int include_optional) {
    sales_volume_item_t* sales_volume_item_1 = instantiate_sales_volume_item(include_optional);

	cJSON* jsonsales_volume_item_1 = sales_volume_item_convertToJSON(sales_volume_item_1);
	printf("sales_volume_item :\n%s\n", cJSON_Print(jsonsales_volume_item_1));
	sales_volume_item_t* sales_volume_item_2 = sales_volume_item_parseFromJSON(jsonsales_volume_item_1);
	cJSON* jsonsales_volume_item_2 = sales_volume_item_convertToJSON(sales_volume_item_2);
	printf("repeating sales_volume_item:\n%s\n", cJSON_Print(jsonsales_volume_item_2));
}

int main() {
  test_sales_volume_item(1);
  test_sales_volume_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // sales_volume_item_MAIN
#endif // sales_volume_item_TEST
