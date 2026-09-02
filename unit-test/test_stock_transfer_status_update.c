#ifndef stock_transfer_status_update_TEST
#define stock_transfer_status_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define stock_transfer_status_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/stock_transfer_status_update.h"
stock_transfer_status_update_t* instantiate_stock_transfer_status_update(int include_optional);



stock_transfer_status_update_t* instantiate_stock_transfer_status_update(int include_optional) {
  stock_transfer_status_update_t* stock_transfer_status_update = NULL;
  if (include_optional) {
    stock_transfer_status_update = stock_transfer_status_update_create(
      "0"
    );
  } else {
    stock_transfer_status_update = stock_transfer_status_update_create(
      "0"
    );
  }

  return stock_transfer_status_update;
}


#ifdef stock_transfer_status_update_MAIN

void test_stock_transfer_status_update(int include_optional) {
    stock_transfer_status_update_t* stock_transfer_status_update_1 = instantiate_stock_transfer_status_update(include_optional);

	cJSON* jsonstock_transfer_status_update_1 = stock_transfer_status_update_convertToJSON(stock_transfer_status_update_1);
	printf("stock_transfer_status_update :\n%s\n", cJSON_Print(jsonstock_transfer_status_update_1));
	stock_transfer_status_update_t* stock_transfer_status_update_2 = stock_transfer_status_update_parseFromJSON(jsonstock_transfer_status_update_1);
	cJSON* jsonstock_transfer_status_update_2 = stock_transfer_status_update_convertToJSON(stock_transfer_status_update_2);
	printf("repeating stock_transfer_status_update:\n%s\n", cJSON_Print(jsonstock_transfer_status_update_2));
}

int main() {
  test_stock_transfer_status_update(1);
  test_stock_transfer_status_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // stock_transfer_status_update_MAIN
#endif // stock_transfer_status_update_TEST
