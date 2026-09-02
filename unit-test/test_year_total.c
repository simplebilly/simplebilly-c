#ifndef year_total_TEST
#define year_total_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define year_total_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/year_total.h"
year_total_t* instantiate_year_total(int include_optional);



year_total_t* instantiate_year_total(int include_optional) {
  year_total_t* year_total = NULL;
  if (include_optional) {
    year_total = year_total_create(
      "0",
      56
    );
  } else {
    year_total = year_total_create(
      "0",
      56
    );
  }

  return year_total;
}


#ifdef year_total_MAIN

void test_year_total(int include_optional) {
    year_total_t* year_total_1 = instantiate_year_total(include_optional);

	cJSON* jsonyear_total_1 = year_total_convertToJSON(year_total_1);
	printf("year_total :\n%s\n", cJSON_Print(jsonyear_total_1));
	year_total_t* year_total_2 = year_total_parseFromJSON(jsonyear_total_1);
	cJSON* jsonyear_total_2 = year_total_convertToJSON(year_total_2);
	printf("repeating year_total:\n%s\n", cJSON_Print(jsonyear_total_2));
}

int main() {
  test_year_total(1);
  test_year_total(0);

  printf("Hello world \n");
  return 0;
}

#endif // year_total_MAIN
#endif // year_total_TEST
