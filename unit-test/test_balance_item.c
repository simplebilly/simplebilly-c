#ifndef balance_item_TEST
#define balance_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define balance_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/balance_item.h"
balance_item_t* instantiate_balance_item(int include_optional);



balance_item_t* instantiate_balance_item(int include_optional) {
  balance_item_t* balance_item = NULL;
  if (include_optional) {
    balance_item = balance_item_create(
      "0",
      "0",
      "0"
    );
  } else {
    balance_item = balance_item_create(
      "0",
      "0",
      "0"
    );
  }

  return balance_item;
}


#ifdef balance_item_MAIN

void test_balance_item(int include_optional) {
    balance_item_t* balance_item_1 = instantiate_balance_item(include_optional);

	cJSON* jsonbalance_item_1 = balance_item_convertToJSON(balance_item_1);
	printf("balance_item :\n%s\n", cJSON_Print(jsonbalance_item_1));
	balance_item_t* balance_item_2 = balance_item_parseFromJSON(jsonbalance_item_1);
	cJSON* jsonbalance_item_2 = balance_item_convertToJSON(balance_item_2);
	printf("repeating balance_item:\n%s\n", cJSON_Print(jsonbalance_item_2));
}

int main() {
  test_balance_item(1);
  test_balance_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // balance_item_MAIN
#endif // balance_item_TEST
