#ifndef payroll_pay_payload_TEST
#define payroll_pay_payload_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define payroll_pay_payload_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/payroll_pay_payload.h"
payroll_pay_payload_t* instantiate_payroll_pay_payload(int include_optional);



payroll_pay_payload_t* instantiate_payroll_pay_payload(int include_optional) {
  payroll_pay_payload_t* payroll_pay_payload = NULL;
  if (include_optional) {
    payroll_pay_payload = payroll_pay_payload_create(
      "2013-10-20"
    );
  } else {
    payroll_pay_payload = payroll_pay_payload_create(
      "2013-10-20"
    );
  }

  return payroll_pay_payload;
}


#ifdef payroll_pay_payload_MAIN

void test_payroll_pay_payload(int include_optional) {
    payroll_pay_payload_t* payroll_pay_payload_1 = instantiate_payroll_pay_payload(include_optional);

	cJSON* jsonpayroll_pay_payload_1 = payroll_pay_payload_convertToJSON(payroll_pay_payload_1);
	printf("payroll_pay_payload :\n%s\n", cJSON_Print(jsonpayroll_pay_payload_1));
	payroll_pay_payload_t* payroll_pay_payload_2 = payroll_pay_payload_parseFromJSON(jsonpayroll_pay_payload_1);
	cJSON* jsonpayroll_pay_payload_2 = payroll_pay_payload_convertToJSON(payroll_pay_payload_2);
	printf("repeating payroll_pay_payload:\n%s\n", cJSON_Print(jsonpayroll_pay_payload_2));
}

int main() {
  test_payroll_pay_payload(1);
  test_payroll_pay_payload(0);

  printf("Hello world \n");
  return 0;
}

#endif // payroll_pay_payload_MAIN
#endif // payroll_pay_payload_TEST
