#ifndef payroll_summary_TEST
#define payroll_summary_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define payroll_summary_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/payroll_summary.h"
payroll_summary_t* instantiate_payroll_summary(int include_optional);



payroll_summary_t* instantiate_payroll_summary(int include_optional) {
  payroll_summary_t* payroll_summary = NULL;
  if (include_optional) {
    payroll_summary = payroll_summary_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      "0",
      56
    );
  } else {
    payroll_summary = payroll_summary_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      "0",
      56
    );
  }

  return payroll_summary;
}


#ifdef payroll_summary_MAIN

void test_payroll_summary(int include_optional) {
    payroll_summary_t* payroll_summary_1 = instantiate_payroll_summary(include_optional);

	cJSON* jsonpayroll_summary_1 = payroll_summary_convertToJSON(payroll_summary_1);
	printf("payroll_summary :\n%s\n", cJSON_Print(jsonpayroll_summary_1));
	payroll_summary_t* payroll_summary_2 = payroll_summary_parseFromJSON(jsonpayroll_summary_1);
	cJSON* jsonpayroll_summary_2 = payroll_summary_convertToJSON(payroll_summary_2);
	printf("repeating payroll_summary:\n%s\n", cJSON_Print(jsonpayroll_summary_2));
}

int main() {
  test_payroll_summary(1);
  test_payroll_summary(0);

  printf("Hello world \n");
  return 0;
}

#endif // payroll_summary_MAIN
#endif // payroll_summary_TEST
