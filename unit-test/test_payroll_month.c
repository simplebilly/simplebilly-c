#ifndef payroll_month_TEST
#define payroll_month_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define payroll_month_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/payroll_month.h"
payroll_month_t* instantiate_payroll_month(int include_optional);



payroll_month_t* instantiate_payroll_month(int include_optional) {
  payroll_month_t* payroll_month = NULL;
  if (include_optional) {
    payroll_month = payroll_month_create(
      "0",
      0,
      "0"
    );
  } else {
    payroll_month = payroll_month_create(
      "0",
      0,
      "0"
    );
  }

  return payroll_month;
}


#ifdef payroll_month_MAIN

void test_payroll_month(int include_optional) {
    payroll_month_t* payroll_month_1 = instantiate_payroll_month(include_optional);

	cJSON* jsonpayroll_month_1 = payroll_month_convertToJSON(payroll_month_1);
	printf("payroll_month :\n%s\n", cJSON_Print(jsonpayroll_month_1));
	payroll_month_t* payroll_month_2 = payroll_month_parseFromJSON(jsonpayroll_month_1);
	cJSON* jsonpayroll_month_2 = payroll_month_convertToJSON(payroll_month_2);
	printf("repeating payroll_month:\n%s\n", cJSON_Print(jsonpayroll_month_2));
}

int main() {
  test_payroll_month(1);
  test_payroll_month(0);

  printf("Hello world \n");
  return 0;
}

#endif // payroll_month_MAIN
#endif // payroll_month_TEST
