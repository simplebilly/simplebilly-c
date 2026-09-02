#ifndef payment_create_TEST
#define payment_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define payment_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/payment_create.h"
payment_create_t* instantiate_payment_create(int include_optional);



payment_create_t* instantiate_payment_create(int include_optional) {
  payment_create_t* payment_create = NULL;
  if (include_optional) {
    payment_create = payment_create_create(
      "0",
      null,
      "0",
      "0",
      "0",
      null,
      simplebilly_api_payment_create__bank_transfer,
      "2013-10-20T19:20:30+01:00",
      "0"
    );
  } else {
    payment_create = payment_create_create(
      "0",
      null,
      "0",
      "0",
      "0",
      null,
      simplebilly_api_payment_create__bank_transfer,
      "2013-10-20T19:20:30+01:00",
      "0"
    );
  }

  return payment_create;
}


#ifdef payment_create_MAIN

void test_payment_create(int include_optional) {
    payment_create_t* payment_create_1 = instantiate_payment_create(include_optional);

	cJSON* jsonpayment_create_1 = payment_create_convertToJSON(payment_create_1);
	printf("payment_create :\n%s\n", cJSON_Print(jsonpayment_create_1));
	payment_create_t* payment_create_2 = payment_create_parseFromJSON(jsonpayment_create_1);
	cJSON* jsonpayment_create_2 = payment_create_convertToJSON(payment_create_2);
	printf("repeating payment_create:\n%s\n", cJSON_Print(jsonpayment_create_2));
}

int main() {
  test_payment_create(1);
  test_payment_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // payment_create_MAIN
#endif // payment_create_TEST
