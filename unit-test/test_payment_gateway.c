#ifndef payment_gateway_TEST
#define payment_gateway_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define payment_gateway_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/payment_gateway.h"
payment_gateway_t* instantiate_payment_gateway(int include_optional);



payment_gateway_t* instantiate_payment_gateway(int include_optional) {
  payment_gateway_t* payment_gateway = NULL;
  if (include_optional) {
    payment_gateway = payment_gateway_create(
      null,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      1,
      "0",
      simplebilly_api_payment_gateway__stripe,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    payment_gateway = payment_gateway_create(
      null,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      1,
      "0",
      simplebilly_api_payment_gateway__stripe,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return payment_gateway;
}


#ifdef payment_gateway_MAIN

void test_payment_gateway(int include_optional) {
    payment_gateway_t* payment_gateway_1 = instantiate_payment_gateway(include_optional);

	cJSON* jsonpayment_gateway_1 = payment_gateway_convertToJSON(payment_gateway_1);
	printf("payment_gateway :\n%s\n", cJSON_Print(jsonpayment_gateway_1));
	payment_gateway_t* payment_gateway_2 = payment_gateway_parseFromJSON(jsonpayment_gateway_1);
	cJSON* jsonpayment_gateway_2 = payment_gateway_convertToJSON(payment_gateway_2);
	printf("repeating payment_gateway:\n%s\n", cJSON_Print(jsonpayment_gateway_2));
}

int main() {
  test_payment_gateway(1);
  test_payment_gateway(0);

  printf("Hello world \n");
  return 0;
}

#endif // payment_gateway_MAIN
#endif // payment_gateway_TEST
