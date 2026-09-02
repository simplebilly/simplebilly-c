#ifndef budget_ergebnis_TEST
#define budget_ergebnis_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define budget_ergebnis_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/budget_ergebnis.h"
budget_ergebnis_t* instantiate_budget_ergebnis(int include_optional);



budget_ergebnis_t* instantiate_budget_ergebnis(int include_optional) {
  budget_ergebnis_t* budget_ergebnis = NULL;
  if (include_optional) {
    budget_ergebnis = budget_ergebnis_create(
      56,
      0,
      list_createList(),
      list_createList()
    );
  } else {
    budget_ergebnis = budget_ergebnis_create(
      56,
      0,
      list_createList(),
      list_createList()
    );
  }

  return budget_ergebnis;
}


#ifdef budget_ergebnis_MAIN

void test_budget_ergebnis(int include_optional) {
    budget_ergebnis_t* budget_ergebnis_1 = instantiate_budget_ergebnis(include_optional);

	cJSON* jsonbudget_ergebnis_1 = budget_ergebnis_convertToJSON(budget_ergebnis_1);
	printf("budget_ergebnis :\n%s\n", cJSON_Print(jsonbudget_ergebnis_1));
	budget_ergebnis_t* budget_ergebnis_2 = budget_ergebnis_parseFromJSON(jsonbudget_ergebnis_1);
	cJSON* jsonbudget_ergebnis_2 = budget_ergebnis_convertToJSON(budget_ergebnis_2);
	printf("repeating budget_ergebnis:\n%s\n", cJSON_Print(jsonbudget_ergebnis_2));
}

int main() {
  test_budget_ergebnis(1);
  test_budget_ergebnis(0);

  printf("Hello world \n");
  return 0;
}

#endif // budget_ergebnis_MAIN
#endif // budget_ergebnis_TEST
