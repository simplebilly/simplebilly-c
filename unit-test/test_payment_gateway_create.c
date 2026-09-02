#ifndef payment_gateway_create_TEST
#define payment_gateway_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define payment_gateway_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/payment_gateway_create.h"
payment_gateway_create_t* instantiate_payment_gateway_create(int include_optional);



payment_gateway_create_t* instantiate_payment_gateway_create(int include_optional) {
  payment_gateway_create_t* payment_gateway_create = NULL;
  if (include_optional) {
    payment_gateway_create = payment_gateway_create_create(
      null,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      1,
      simplebilly_api_payment_gateway_create__stripe,
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    payment_gateway_create = payment_gateway_create_create(
      null,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      1,
      simplebilly_api_payment_gateway_create__stripe,
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return payment_gateway_create;
}


#ifdef payment_gateway_create_MAIN

void test_payment_gateway_create(int include_optional) {
    payment_gateway_create_t* payment_gateway_create_1 = instantiate_payment_gateway_create(include_optional);

	cJSON* jsonpayment_gateway_create_1 = payment_gateway_create_convertToJSON(payment_gateway_create_1);
	printf("payment_gateway_create :\n%s\n", cJSON_Print(jsonpayment_gateway_create_1));
	payment_gateway_create_t* payment_gateway_create_2 = payment_gateway_create_parseFromJSON(jsonpayment_gateway_create_1);
	cJSON* jsonpayment_gateway_create_2 = payment_gateway_create_convertToJSON(payment_gateway_create_2);
	printf("repeating payment_gateway_create:\n%s\n", cJSON_Print(jsonpayment_gateway_create_2));
}

int main() {
  test_payment_gateway_create(1);
  test_payment_gateway_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // payment_gateway_create_MAIN
#endif // payment_gateway_create_TEST
