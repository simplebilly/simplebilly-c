#ifndef payroll_entry_api_TEST
#define payroll_entry_api_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define payroll_entry_api_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/payroll_entry_api.h"
payroll_entry_api_t* instantiate_payroll_entry_api(int include_optional);

#include "test_employee.c"


payroll_entry_api_t* instantiate_payroll_entry_api(int include_optional) {
  payroll_entry_api_t* payroll_entry_api = NULL;
  if (include_optional) {
    payroll_entry_api = payroll_entry_api_create(
      "0",
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_employee(0),
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      56,
      "0",
      simplebilly_api_payroll_entry_api__draft,
      "0",
      "0",
      56
    );
  } else {
    payroll_entry_api = payroll_entry_api_create(
      "0",
      "0",
      "0",
      NULL,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      56,
      "0",
      simplebilly_api_payroll_entry_api__draft,
      "0",
      "0",
      56
    );
  }

  return payroll_entry_api;
}


#ifdef payroll_entry_api_MAIN

void test_payroll_entry_api(int include_optional) {
    payroll_entry_api_t* payroll_entry_api_1 = instantiate_payroll_entry_api(include_optional);

	cJSON* jsonpayroll_entry_api_1 = payroll_entry_api_convertToJSON(payroll_entry_api_1);
	printf("payroll_entry_api :\n%s\n", cJSON_Print(jsonpayroll_entry_api_1));
	payroll_entry_api_t* payroll_entry_api_2 = payroll_entry_api_parseFromJSON(jsonpayroll_entry_api_1);
	cJSON* jsonpayroll_entry_api_2 = payroll_entry_api_convertToJSON(payroll_entry_api_2);
	printf("repeating payroll_entry_api:\n%s\n", cJSON_Print(jsonpayroll_entry_api_2));
}

int main() {
  test_payroll_entry_api(1);
  test_payroll_entry_api(0);

  printf("Hello world \n");
  return 0;
}

#endif // payroll_entry_api_MAIN
#endif // payroll_entry_api_TEST
