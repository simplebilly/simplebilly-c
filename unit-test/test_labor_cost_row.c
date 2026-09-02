#ifndef labor_cost_row_TEST
#define labor_cost_row_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define labor_cost_row_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/labor_cost_row.h"
labor_cost_row_t* instantiate_labor_cost_row(int include_optional);



labor_cost_row_t* instantiate_labor_cost_row(int include_optional) {
  labor_cost_row_t* labor_cost_row = NULL;
  if (include_optional) {
    labor_cost_row = labor_cost_row_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    labor_cost_row = labor_cost_row_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return labor_cost_row;
}


#ifdef labor_cost_row_MAIN

void test_labor_cost_row(int include_optional) {
    labor_cost_row_t* labor_cost_row_1 = instantiate_labor_cost_row(include_optional);

	cJSON* jsonlabor_cost_row_1 = labor_cost_row_convertToJSON(labor_cost_row_1);
	printf("labor_cost_row :\n%s\n", cJSON_Print(jsonlabor_cost_row_1));
	labor_cost_row_t* labor_cost_row_2 = labor_cost_row_parseFromJSON(jsonlabor_cost_row_1);
	cJSON* jsonlabor_cost_row_2 = labor_cost_row_convertToJSON(labor_cost_row_2);
	printf("repeating labor_cost_row:\n%s\n", cJSON_Print(jsonlabor_cost_row_2));
}

int main() {
  test_labor_cost_row(1);
  test_labor_cost_row(0);

  printf("Hello world \n");
  return 0;
}

#endif // labor_cost_row_MAIN
#endif // labor_cost_row_TEST
