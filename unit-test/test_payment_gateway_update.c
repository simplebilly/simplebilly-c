#ifndef payment_gateway_update_TEST
#define payment_gateway_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define payment_gateway_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/payment_gateway_update.h"
payment_gateway_update_t* instantiate_payment_gateway_update(int include_optional);



payment_gateway_update_t* instantiate_payment_gateway_update(int include_optional) {
  payment_gateway_update_t* payment_gateway_update = NULL;
  if (include_optional) {
    payment_gateway_update = payment_gateway_update_create(
      null,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      1,
      stripe,
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    payment_gateway_update = payment_gateway_update_create(
      null,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      1,
      stripe,
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return payment_gateway_update;
}


#ifdef payment_gateway_update_MAIN

void test_payment_gateway_update(int include_optional) {
    payment_gateway_update_t* payment_gateway_update_1 = instantiate_payment_gateway_update(include_optional);

	cJSON* jsonpayment_gateway_update_1 = payment_gateway_update_convertToJSON(payment_gateway_update_1);
	printf("payment_gateway_update :\n%s\n", cJSON_Print(jsonpayment_gateway_update_1));
	payment_gateway_update_t* payment_gateway_update_2 = payment_gateway_update_parseFromJSON(jsonpayment_gateway_update_1);
	cJSON* jsonpayment_gateway_update_2 = payment_gateway_update_convertToJSON(payment_gateway_update_2);
	printf("repeating payment_gateway_update:\n%s\n", cJSON_Print(jsonpayment_gateway_update_2));
}

int main() {
  test_payment_gateway_update(1);
  test_payment_gateway_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // payment_gateway_update_MAIN
#endif // payment_gateway_update_TEST
