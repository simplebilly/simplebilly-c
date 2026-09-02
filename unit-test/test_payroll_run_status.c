#ifndef payroll_run_status_TEST
#define payroll_run_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define payroll_run_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/payroll_run_status.h"
payroll_run_status_t* instantiate_payroll_run_status(int include_optional);



payroll_run_status_t* instantiate_payroll_run_status(int include_optional) {
  payroll_run_status_t* payroll_run_status = NULL;
  if (include_optional) {
    payroll_run_status = payroll_run_status_create(
    );
  } else {
    payroll_run_status = payroll_run_status_create(
    );
  }

  return payroll_run_status;
}


#ifdef payroll_run_status_MAIN

void test_payroll_run_status(int include_optional) {
    payroll_run_status_t* payroll_run_status_1 = instantiate_payroll_run_status(include_optional);

	cJSON* jsonpayroll_run_status_1 = payroll_run_status_convertToJSON(payroll_run_status_1);
	printf("payroll_run_status :\n%s\n", cJSON_Print(jsonpayroll_run_status_1));
	payroll_run_status_t* payroll_run_status_2 = payroll_run_status_parseFromJSON(jsonpayroll_run_status_1);
	cJSON* jsonpayroll_run_status_2 = payroll_run_status_convertToJSON(payroll_run_status_2);
	printf("repeating payroll_run_status:\n%s\n", cJSON_Print(jsonpayroll_run_status_2));
}

int main() {
  test_payroll_run_status(1);
  test_payroll_run_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // payroll_run_status_MAIN
#endif // payroll_run_status_TEST
