#ifndef stock_update_request_TEST
#define stock_update_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define stock_update_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/stock_update_request.h"
stock_update_request_t* instantiate_stock_update_request(int include_optional);



stock_update_request_t* instantiate_stock_update_request(int include_optional) {
  stock_update_request_t* stock_update_request = NULL;
  if (include_optional) {
    stock_update_request = stock_update_request_create(
      56
    );
  } else {
    stock_update_request = stock_update_request_create(
      56
    );
  }

  return stock_update_request;
}


#ifdef stock_update_request_MAIN

void test_stock_update_request(int include_optional) {
    stock_update_request_t* stock_update_request_1 = instantiate_stock_update_request(include_optional);

	cJSON* jsonstock_update_request_1 = stock_update_request_convertToJSON(stock_update_request_1);
	printf("stock_update_request :\n%s\n", cJSON_Print(jsonstock_update_request_1));
	stock_update_request_t* stock_update_request_2 = stock_update_request_parseFromJSON(jsonstock_update_request_1);
	cJSON* jsonstock_update_request_2 = stock_update_request_convertToJSON(stock_update_request_2);
	printf("repeating stock_update_request:\n%s\n", cJSON_Print(jsonstock_update_request_2));
}

int main() {
  test_stock_update_request(1);
  test_stock_update_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // stock_update_request_MAIN
#endif // stock_update_request_TEST
