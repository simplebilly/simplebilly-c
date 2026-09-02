#ifndef expense_item_TEST
#define expense_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define expense_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/expense_item.h"
expense_item_t* instantiate_expense_item(int include_optional);



expense_item_t* instantiate_expense_item(int include_optional) {
  expense_item_t* expense_item = NULL;
  if (include_optional) {
    expense_item = expense_item_create(
      "0",
      "0",
      1.337
    );
  } else {
    expense_item = expense_item_create(
      "0",
      "0",
      1.337
    );
  }

  return expense_item;
}


#ifdef expense_item_MAIN

void test_expense_item(int include_optional) {
    expense_item_t* expense_item_1 = instantiate_expense_item(include_optional);

	cJSON* jsonexpense_item_1 = expense_item_convertToJSON(expense_item_1);
	printf("expense_item :\n%s\n", cJSON_Print(jsonexpense_item_1));
	expense_item_t* expense_item_2 = expense_item_parseFromJSON(jsonexpense_item_1);
	cJSON* jsonexpense_item_2 = expense_item_convertToJSON(expense_item_2);
	printf("repeating expense_item:\n%s\n", cJSON_Print(jsonexpense_item_2));
}

int main() {
  test_expense_item(1);
  test_expense_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // expense_item_MAIN
#endif // expense_item_TEST
