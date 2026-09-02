#ifndef warehouse_stock_TEST
#define warehouse_stock_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define warehouse_stock_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/warehouse_stock.h"
warehouse_stock_t* instantiate_warehouse_stock(int include_optional);



warehouse_stock_t* instantiate_warehouse_stock(int include_optional) {
  warehouse_stock_t* warehouse_stock = NULL;
  if (include_optional) {
    warehouse_stock = warehouse_stock_create(
      "0",
      "0",
      "2013-10-20",
      "0",
      56,
      null,
      "0"
    );
  } else {
    warehouse_stock = warehouse_stock_create(
      "0",
      "0",
      "2013-10-20",
      "0",
      56,
      null,
      "0"
    );
  }

  return warehouse_stock;
}


#ifdef warehouse_stock_MAIN

void test_warehouse_stock(int include_optional) {
    warehouse_stock_t* warehouse_stock_1 = instantiate_warehouse_stock(include_optional);

	cJSON* jsonwarehouse_stock_1 = warehouse_stock_convertToJSON(warehouse_stock_1);
	printf("warehouse_stock :\n%s\n", cJSON_Print(jsonwarehouse_stock_1));
	warehouse_stock_t* warehouse_stock_2 = warehouse_stock_parseFromJSON(jsonwarehouse_stock_1);
	cJSON* jsonwarehouse_stock_2 = warehouse_stock_convertToJSON(warehouse_stock_2);
	printf("repeating warehouse_stock:\n%s\n", cJSON_Print(jsonwarehouse_stock_2));
}

int main() {
  test_warehouse_stock(1);
  test_warehouse_stock(0);

  printf("Hello world \n");
  return 0;
}

#endif // warehouse_stock_MAIN
#endif // warehouse_stock_TEST
