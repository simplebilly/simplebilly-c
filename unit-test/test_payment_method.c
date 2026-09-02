#ifndef payment_method_TEST
#define payment_method_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define payment_method_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/payment_method.h"
payment_method_t* instantiate_payment_method(int include_optional);



payment_method_t* instantiate_payment_method(int include_optional) {
  payment_method_t* payment_method = NULL;
  if (include_optional) {
    payment_method = payment_method_create(
    );
  } else {
    payment_method = payment_method_create(
    );
  }

  return payment_method;
}


#ifdef payment_method_MAIN

void test_payment_method(int include_optional) {
    payment_method_t* payment_method_1 = instantiate_payment_method(include_optional);

	cJSON* jsonpayment_method_1 = payment_method_convertToJSON(payment_method_1);
	printf("payment_method :\n%s\n", cJSON_Print(jsonpayment_method_1));
	payment_method_t* payment_method_2 = payment_method_parseFromJSON(jsonpayment_method_1);
	cJSON* jsonpayment_method_2 = payment_method_convertToJSON(payment_method_2);
	printf("repeating payment_method:\n%s\n", cJSON_Print(jsonpayment_method_2));
}

int main() {
  test_payment_method(1);
  test_payment_method(0);

  printf("Hello world \n");
  return 0;
}

#endif // payment_method_MAIN
#endif // payment_method_TEST
