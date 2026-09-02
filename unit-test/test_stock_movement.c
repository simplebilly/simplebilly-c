#ifndef stock_movement_TEST
#define stock_movement_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define stock_movement_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/stock_movement.h"
stock_movement_t* instantiate_stock_movement(int include_optional);



stock_movement_t* instantiate_stock_movement(int include_optional) {
  stock_movement_t* stock_movement = NULL;
  if (include_optional) {
    stock_movement = stock_movement_create(
      56,
      goods_receipt,
      "0",
      56,
      "0",
      "0",
      goods_receipt,
      "0"
    );
  } else {
    stock_movement = stock_movement_create(
      56,
      goods_receipt,
      "0",
      56,
      "0",
      "0",
      goods_receipt,
      "0"
    );
  }

  return stock_movement;
}


#ifdef stock_movement_MAIN

void test_stock_movement(int include_optional) {
    stock_movement_t* stock_movement_1 = instantiate_stock_movement(include_optional);

	cJSON* jsonstock_movement_1 = stock_movement_convertToJSON(stock_movement_1);
	printf("stock_movement :\n%s\n", cJSON_Print(jsonstock_movement_1));
	stock_movement_t* stock_movement_2 = stock_movement_parseFromJSON(jsonstock_movement_1);
	cJSON* jsonstock_movement_2 = stock_movement_convertToJSON(stock_movement_2);
	printf("repeating stock_movement:\n%s\n", cJSON_Print(jsonstock_movement_2));
}

int main() {
  test_stock_movement(1);
  test_stock_movement(0);

  printf("Hello world \n");
  return 0;
}

#endif // stock_movement_MAIN
#endif // stock_movement_TEST
