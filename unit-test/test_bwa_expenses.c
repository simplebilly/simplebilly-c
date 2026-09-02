#ifndef bwa_expenses_TEST
#define bwa_expenses_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define bwa_expenses_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/bwa_expenses.h"
bwa_expenses_t* instantiate_bwa_expenses(int include_optional);



bwa_expenses_t* instantiate_bwa_expenses(int include_optional) {
  bwa_expenses_t* bwa_expenses = NULL;
  if (include_optional) {
    bwa_expenses = bwa_expenses_create(
      list_createList(),
      "0"
    );
  } else {
    bwa_expenses = bwa_expenses_create(
      list_createList(),
      "0"
    );
  }

  return bwa_expenses;
}


#ifdef bwa_expenses_MAIN

void test_bwa_expenses(int include_optional) {
    bwa_expenses_t* bwa_expenses_1 = instantiate_bwa_expenses(include_optional);

	cJSON* jsonbwa_expenses_1 = bwa_expenses_convertToJSON(bwa_expenses_1);
	printf("bwa_expenses :\n%s\n", cJSON_Print(jsonbwa_expenses_1));
	bwa_expenses_t* bwa_expenses_2 = bwa_expenses_parseFromJSON(jsonbwa_expenses_1);
	cJSON* jsonbwa_expenses_2 = bwa_expenses_convertToJSON(bwa_expenses_2);
	printf("repeating bwa_expenses:\n%s\n", cJSON_Print(jsonbwa_expenses_2));
}

int main() {
  test_bwa_expenses(1);
  test_bwa_expenses(0);

  printf("Hello world \n");
  return 0;
}

#endif // bwa_expenses_MAIN
#endif // bwa_expenses_TEST
