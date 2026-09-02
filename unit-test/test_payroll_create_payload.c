#ifndef payroll_create_payload_TEST
#define payroll_create_payload_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define payroll_create_payload_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/payroll_create_payload.h"
payroll_create_payload_t* instantiate_payroll_create_payload(int include_optional);



payroll_create_payload_t* instantiate_payroll_create_payload(int include_optional) {
  payroll_create_payload_t* payroll_create_payload = NULL;
  if (include_optional) {
    payroll_create_payload = payroll_create_payload_create(
      list_createList(),
      list_createList(),
      56,
      56
    );
  } else {
    payroll_create_payload = payroll_create_payload_create(
      list_createList(),
      list_createList(),
      56,
      56
    );
  }

  return payroll_create_payload;
}


#ifdef payroll_create_payload_MAIN

void test_payroll_create_payload(int include_optional) {
    payroll_create_payload_t* payroll_create_payload_1 = instantiate_payroll_create_payload(include_optional);

	cJSON* jsonpayroll_create_payload_1 = payroll_create_payload_convertToJSON(payroll_create_payload_1);
	printf("payroll_create_payload :\n%s\n", cJSON_Print(jsonpayroll_create_payload_1));
	payroll_create_payload_t* payroll_create_payload_2 = payroll_create_payload_parseFromJSON(jsonpayroll_create_payload_1);
	cJSON* jsonpayroll_create_payload_2 = payroll_create_payload_convertToJSON(payroll_create_payload_2);
	printf("repeating payroll_create_payload:\n%s\n", cJSON_Print(jsonpayroll_create_payload_2));
}

int main() {
  test_payroll_create_payload(1);
  test_payroll_create_payload(0);

  printf("Hello world \n");
  return 0;
}

#endif // payroll_create_payload_MAIN
#endif // payroll_create_payload_TEST
