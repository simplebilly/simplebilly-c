#ifndef balance_sheet_TEST
#define balance_sheet_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define balance_sheet_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/balance_sheet.h"
balance_sheet_t* instantiate_balance_sheet(int include_optional);



balance_sheet_t* instantiate_balance_sheet(int include_optional) {
  balance_sheet_t* balance_sheet = NULL;
  if (include_optional) {
    balance_sheet = balance_sheet_create(
      list_createList(),
      1,
      list_createList(),
      "0",
      "0"
    );
  } else {
    balance_sheet = balance_sheet_create(
      list_createList(),
      1,
      list_createList(),
      "0",
      "0"
    );
  }

  return balance_sheet;
}


#ifdef balance_sheet_MAIN

void test_balance_sheet(int include_optional) {
    balance_sheet_t* balance_sheet_1 = instantiate_balance_sheet(include_optional);

	cJSON* jsonbalance_sheet_1 = balance_sheet_convertToJSON(balance_sheet_1);
	printf("balance_sheet :\n%s\n", cJSON_Print(jsonbalance_sheet_1));
	balance_sheet_t* balance_sheet_2 = balance_sheet_parseFromJSON(jsonbalance_sheet_1);
	cJSON* jsonbalance_sheet_2 = balance_sheet_convertToJSON(balance_sheet_2);
	printf("repeating balance_sheet:\n%s\n", cJSON_Print(jsonbalance_sheet_2));
}

int main() {
  test_balance_sheet(1);
  test_balance_sheet(0);

  printf("Hello world \n");
  return 0;
}

#endif // balance_sheet_MAIN
#endif // balance_sheet_TEST
