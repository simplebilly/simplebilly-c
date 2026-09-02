#ifndef payment_condition_TEST
#define payment_condition_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define payment_condition_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/payment_condition.h"
payment_condition_t* instantiate_payment_condition(int include_optional);



payment_condition_t* instantiate_payment_condition(int include_optional) {
  payment_condition_t* payment_condition = NULL;
  if (include_optional) {
    payment_condition = payment_condition_create(
      56,
      1.337,
      "0",
      "0",
      56
    );
  } else {
    payment_condition = payment_condition_create(
      56,
      1.337,
      "0",
      "0",
      56
    );
  }

  return payment_condition;
}


#ifdef payment_condition_MAIN

void test_payment_condition(int include_optional) {
    payment_condition_t* payment_condition_1 = instantiate_payment_condition(include_optional);

	cJSON* jsonpayment_condition_1 = payment_condition_convertToJSON(payment_condition_1);
	printf("payment_condition :\n%s\n", cJSON_Print(jsonpayment_condition_1));
	payment_condition_t* payment_condition_2 = payment_condition_parseFromJSON(jsonpayment_condition_1);
	cJSON* jsonpayment_condition_2 = payment_condition_convertToJSON(payment_condition_2);
	printf("repeating payment_condition:\n%s\n", cJSON_Print(jsonpayment_condition_2));
}

int main() {
  test_payment_condition(1);
  test_payment_condition(0);

  printf("Hello world \n");
  return 0;
}

#endif // payment_condition_MAIN
#endif // payment_condition_TEST
