#ifndef stock_transfer_status_TEST
#define stock_transfer_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define stock_transfer_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/stock_transfer_status.h"
stock_transfer_status_t* instantiate_stock_transfer_status(int include_optional);



stock_transfer_status_t* instantiate_stock_transfer_status(int include_optional) {
  stock_transfer_status_t* stock_transfer_status = NULL;
  if (include_optional) {
    stock_transfer_status = stock_transfer_status_create(
    );
  } else {
    stock_transfer_status = stock_transfer_status_create(
    );
  }

  return stock_transfer_status;
}


#ifdef stock_transfer_status_MAIN

void test_stock_transfer_status(int include_optional) {
    stock_transfer_status_t* stock_transfer_status_1 = instantiate_stock_transfer_status(include_optional);

	cJSON* jsonstock_transfer_status_1 = stock_transfer_status_convertToJSON(stock_transfer_status_1);
	printf("stock_transfer_status :\n%s\n", cJSON_Print(jsonstock_transfer_status_1));
	stock_transfer_status_t* stock_transfer_status_2 = stock_transfer_status_parseFromJSON(jsonstock_transfer_status_1);
	cJSON* jsonstock_transfer_status_2 = stock_transfer_status_convertToJSON(stock_transfer_status_2);
	printf("repeating stock_transfer_status:\n%s\n", cJSON_Print(jsonstock_transfer_status_2));
}

int main() {
  test_stock_transfer_status(1);
  test_stock_transfer_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // stock_transfer_status_MAIN
#endif // stock_transfer_status_TEST
