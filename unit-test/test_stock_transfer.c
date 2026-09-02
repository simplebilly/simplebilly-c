#ifndef stock_transfer_TEST
#define stock_transfer_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define stock_transfer_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/stock_transfer.h"
stock_transfer_t* instantiate_stock_transfer(int include_optional);



stock_transfer_t* instantiate_stock_transfer(int include_optional) {
  stock_transfer_t* stock_transfer = NULL;
  if (include_optional) {
    stock_transfer = stock_transfer_create(
      null,
      "0",
      "0",
      draft,
      "0",
      "2013-10-20",
      "0"
    );
  } else {
    stock_transfer = stock_transfer_create(
      null,
      "0",
      "0",
      draft,
      "0",
      "2013-10-20",
      "0"
    );
  }

  return stock_transfer;
}


#ifdef stock_transfer_MAIN

void test_stock_transfer(int include_optional) {
    stock_transfer_t* stock_transfer_1 = instantiate_stock_transfer(include_optional);

	cJSON* jsonstock_transfer_1 = stock_transfer_convertToJSON(stock_transfer_1);
	printf("stock_transfer :\n%s\n", cJSON_Print(jsonstock_transfer_1));
	stock_transfer_t* stock_transfer_2 = stock_transfer_parseFromJSON(jsonstock_transfer_1);
	cJSON* jsonstock_transfer_2 = stock_transfer_convertToJSON(stock_transfer_2);
	printf("repeating stock_transfer:\n%s\n", cJSON_Print(jsonstock_transfer_2));
}

int main() {
  test_stock_transfer(1);
  test_stock_transfer(0);

  printf("Hello world \n");
  return 0;
}

#endif // stock_transfer_MAIN
#endif // stock_transfer_TEST
