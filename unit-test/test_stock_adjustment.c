#ifndef stock_adjustment_TEST
#define stock_adjustment_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define stock_adjustment_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/stock_adjustment.h"
stock_adjustment_t* instantiate_stock_adjustment(int include_optional);



stock_adjustment_t* instantiate_stock_adjustment(int include_optional) {
  stock_adjustment_t* stock_adjustment = NULL;
  if (include_optional) {
    stock_adjustment = stock_adjustment_create(
      "0",
      "0",
      "2013-10-20",
      "0",
      56,
      list_createList()
    );
  } else {
    stock_adjustment = stock_adjustment_create(
      "0",
      "0",
      "2013-10-20",
      "0",
      56,
      list_createList()
    );
  }

  return stock_adjustment;
}


#ifdef stock_adjustment_MAIN

void test_stock_adjustment(int include_optional) {
    stock_adjustment_t* stock_adjustment_1 = instantiate_stock_adjustment(include_optional);

	cJSON* jsonstock_adjustment_1 = stock_adjustment_convertToJSON(stock_adjustment_1);
	printf("stock_adjustment :\n%s\n", cJSON_Print(jsonstock_adjustment_1));
	stock_adjustment_t* stock_adjustment_2 = stock_adjustment_parseFromJSON(jsonstock_adjustment_1);
	cJSON* jsonstock_adjustment_2 = stock_adjustment_convertToJSON(stock_adjustment_2);
	printf("repeating stock_adjustment:\n%s\n", cJSON_Print(jsonstock_adjustment_2));
}

int main() {
  test_stock_adjustment(1);
  test_stock_adjustment(0);

  printf("Hello world \n");
  return 0;
}

#endif // stock_adjustment_MAIN
#endif // stock_adjustment_TEST
