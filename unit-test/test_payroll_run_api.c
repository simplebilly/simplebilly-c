#ifndef payroll_run_api_TEST
#define payroll_run_api_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define payroll_run_api_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/payroll_run_api.h"
payroll_run_api_t* instantiate_payroll_run_api(int include_optional);



payroll_run_api_t* instantiate_payroll_run_api(int include_optional) {
  payroll_run_api_t* payroll_run_api = NULL;
  if (include_optional) {
    payroll_run_api = payroll_run_api_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20T19:20:30+01:00",
      list_createList(),
      56,
      "2013-10-20",
      "0",
      "0",
      simplebilly_api_payroll_run_api__draft,
      "0",
      56,
      "0",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      56
    );
  } else {
    payroll_run_api = payroll_run_api_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20T19:20:30+01:00",
      list_createList(),
      56,
      "2013-10-20",
      "0",
      "0",
      simplebilly_api_payroll_run_api__draft,
      "0",
      56,
      "0",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      56
    );
  }

  return payroll_run_api;
}


#ifdef payroll_run_api_MAIN

void test_payroll_run_api(int include_optional) {
    payroll_run_api_t* payroll_run_api_1 = instantiate_payroll_run_api(include_optional);

	cJSON* jsonpayroll_run_api_1 = payroll_run_api_convertToJSON(payroll_run_api_1);
	printf("payroll_run_api :\n%s\n", cJSON_Print(jsonpayroll_run_api_1));
	payroll_run_api_t* payroll_run_api_2 = payroll_run_api_parseFromJSON(jsonpayroll_run_api_1);
	cJSON* jsonpayroll_run_api_2 = payroll_run_api_convertToJSON(payroll_run_api_2);
	printf("repeating payroll_run_api:\n%s\n", cJSON_Print(jsonpayroll_run_api_2));
}

int main() {
  test_payroll_run_api(1);
  test_payroll_run_api(0);

  printf("Hello world \n");
  return 0;
}

#endif // payroll_run_api_MAIN
#endif // payroll_run_api_TEST
