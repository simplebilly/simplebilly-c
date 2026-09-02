#ifndef budget_kategorie_TEST
#define budget_kategorie_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define budget_kategorie_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/budget_kategorie.h"
budget_kategorie_t* instantiate_budget_kategorie(int include_optional);



budget_kategorie_t* instantiate_budget_kategorie(int include_optional) {
  budget_kategorie_t* budget_kategorie = NULL;
  if (include_optional) {
    budget_kategorie = budget_kategorie_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    budget_kategorie = budget_kategorie_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return budget_kategorie;
}


#ifdef budget_kategorie_MAIN

void test_budget_kategorie(int include_optional) {
    budget_kategorie_t* budget_kategorie_1 = instantiate_budget_kategorie(include_optional);

	cJSON* jsonbudget_kategorie_1 = budget_kategorie_convertToJSON(budget_kategorie_1);
	printf("budget_kategorie :\n%s\n", cJSON_Print(jsonbudget_kategorie_1));
	budget_kategorie_t* budget_kategorie_2 = budget_kategorie_parseFromJSON(jsonbudget_kategorie_1);
	cJSON* jsonbudget_kategorie_2 = budget_kategorie_convertToJSON(budget_kategorie_2);
	printf("repeating budget_kategorie:\n%s\n", cJSON_Print(jsonbudget_kategorie_2));
}

int main() {
  test_budget_kategorie(1);
  test_budget_kategorie(0);

  printf("Hello world \n");
  return 0;
}

#endif // budget_kategorie_MAIN
#endif // budget_kategorie_TEST
