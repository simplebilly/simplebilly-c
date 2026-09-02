#ifndef bwa_revenue_TEST
#define bwa_revenue_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define bwa_revenue_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/bwa_revenue.h"
bwa_revenue_t* instantiate_bwa_revenue(int include_optional);



bwa_revenue_t* instantiate_bwa_revenue(int include_optional) {
  bwa_revenue_t* bwa_revenue = NULL;
  if (include_optional) {
    bwa_revenue = bwa_revenue_create(
      list_createList(),
      "0"
    );
  } else {
    bwa_revenue = bwa_revenue_create(
      list_createList(),
      "0"
    );
  }

  return bwa_revenue;
}


#ifdef bwa_revenue_MAIN

void test_bwa_revenue(int include_optional) {
    bwa_revenue_t* bwa_revenue_1 = instantiate_bwa_revenue(include_optional);

	cJSON* jsonbwa_revenue_1 = bwa_revenue_convertToJSON(bwa_revenue_1);
	printf("bwa_revenue :\n%s\n", cJSON_Print(jsonbwa_revenue_1));
	bwa_revenue_t* bwa_revenue_2 = bwa_revenue_parseFromJSON(jsonbwa_revenue_1);
	cJSON* jsonbwa_revenue_2 = bwa_revenue_convertToJSON(bwa_revenue_2);
	printf("repeating bwa_revenue:\n%s\n", cJSON_Print(jsonbwa_revenue_2));
}

int main() {
  test_bwa_revenue(1);
  test_bwa_revenue(0);

  printf("Hello world \n");
  return 0;
}

#endif // bwa_revenue_MAIN
#endif // bwa_revenue_TEST
