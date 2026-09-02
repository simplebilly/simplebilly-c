#ifndef payment_status_TEST
#define payment_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define payment_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/payment_status.h"
payment_status_t* instantiate_payment_status(int include_optional);



payment_status_t* instantiate_payment_status(int include_optional) {
  payment_status_t* payment_status = NULL;
  if (include_optional) {
    payment_status = payment_status_create(
    );
  } else {
    payment_status = payment_status_create(
    );
  }

  return payment_status;
}


#ifdef payment_status_MAIN

void test_payment_status(int include_optional) {
    payment_status_t* payment_status_1 = instantiate_payment_status(include_optional);

	cJSON* jsonpayment_status_1 = payment_status_convertToJSON(payment_status_1);
	printf("payment_status :\n%s\n", cJSON_Print(jsonpayment_status_1));
	payment_status_t* payment_status_2 = payment_status_parseFromJSON(jsonpayment_status_1);
	cJSON* jsonpayment_status_2 = payment_status_convertToJSON(payment_status_2);
	printf("repeating payment_status:\n%s\n", cJSON_Print(jsonpayment_status_2));
}

int main() {
  test_payment_status(1);
  test_payment_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // payment_status_MAIN
#endif // payment_status_TEST
