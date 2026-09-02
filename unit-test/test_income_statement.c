#ifndef income_statement_TEST
#define income_statement_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define income_statement_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/income_statement.h"
income_statement_t* instantiate_income_statement(int include_optional);



income_statement_t* instantiate_income_statement(int include_optional) {
  income_statement_t* income_statement = NULL;
  if (include_optional) {
    income_statement = income_statement_create(
      list_createList(),
      "0",
      list_createList(),
      "0",
      "0"
    );
  } else {
    income_statement = income_statement_create(
      list_createList(),
      "0",
      list_createList(),
      "0",
      "0"
    );
  }

  return income_statement;
}


#ifdef income_statement_MAIN

void test_income_statement(int include_optional) {
    income_statement_t* income_statement_1 = instantiate_income_statement(include_optional);

	cJSON* jsonincome_statement_1 = income_statement_convertToJSON(income_statement_1);
	printf("income_statement :\n%s\n", cJSON_Print(jsonincome_statement_1));
	income_statement_t* income_statement_2 = income_statement_parseFromJSON(jsonincome_statement_1);
	cJSON* jsonincome_statement_2 = income_statement_convertToJSON(income_statement_2);
	printf("repeating income_statement:\n%s\n", cJSON_Print(jsonincome_statement_2));
}

int main() {
  test_income_statement(1);
  test_income_statement(0);

  printf("Hello world \n");
  return 0;
}

#endif // income_statement_MAIN
#endif // income_statement_TEST
