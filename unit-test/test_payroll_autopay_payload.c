#ifndef payroll_autopay_payload_TEST
#define payroll_autopay_payload_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define payroll_autopay_payload_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/payroll_autopay_payload.h"
payroll_autopay_payload_t* instantiate_payroll_autopay_payload(int include_optional);



payroll_autopay_payload_t* instantiate_payroll_autopay_payload(int include_optional) {
  payroll_autopay_payload_t* payroll_autopay_payload = NULL;
  if (include_optional) {
    payroll_autopay_payload = payroll_autopay_payload_create(
      "0",
      "0",
      "0",
      "2013-10-20"
    );
  } else {
    payroll_autopay_payload = payroll_autopay_payload_create(
      "0",
      "0",
      "0",
      "2013-10-20"
    );
  }

  return payroll_autopay_payload;
}


#ifdef payroll_autopay_payload_MAIN

void test_payroll_autopay_payload(int include_optional) {
    payroll_autopay_payload_t* payroll_autopay_payload_1 = instantiate_payroll_autopay_payload(include_optional);

	cJSON* jsonpayroll_autopay_payload_1 = payroll_autopay_payload_convertToJSON(payroll_autopay_payload_1);
	printf("payroll_autopay_payload :\n%s\n", cJSON_Print(jsonpayroll_autopay_payload_1));
	payroll_autopay_payload_t* payroll_autopay_payload_2 = payroll_autopay_payload_parseFromJSON(jsonpayroll_autopay_payload_1);
	cJSON* jsonpayroll_autopay_payload_2 = payroll_autopay_payload_convertToJSON(payroll_autopay_payload_2);
	printf("repeating payroll_autopay_payload:\n%s\n", cJSON_Print(jsonpayroll_autopay_payload_2));
}

int main() {
  test_payroll_autopay_payload(1);
  test_payroll_autopay_payload(0);

  printf("Hello world \n");
  return 0;
}

#endif // payroll_autopay_payload_MAIN
#endif // payroll_autopay_payload_TEST
