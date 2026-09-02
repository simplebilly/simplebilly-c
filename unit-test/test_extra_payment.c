#ifndef extra_payment_TEST
#define extra_payment_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extra_payment_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extra_payment.h"
extra_payment_t* instantiate_extra_payment(int include_optional);



extra_payment_t* instantiate_extra_payment(int include_optional) {
  extra_payment_t* extra_payment = NULL;
  if (include_optional) {
    extra_payment = extra_payment_create(
      "0",
      "0",
      "0"
    );
  } else {
    extra_payment = extra_payment_create(
      "0",
      "0",
      "0"
    );
  }

  return extra_payment;
}


#ifdef extra_payment_MAIN

void test_extra_payment(int include_optional) {
    extra_payment_t* extra_payment_1 = instantiate_extra_payment(include_optional);

	cJSON* jsonextra_payment_1 = extra_payment_convertToJSON(extra_payment_1);
	printf("extra_payment :\n%s\n", cJSON_Print(jsonextra_payment_1));
	extra_payment_t* extra_payment_2 = extra_payment_parseFromJSON(jsonextra_payment_1);
	cJSON* jsonextra_payment_2 = extra_payment_convertToJSON(extra_payment_2);
	printf("repeating extra_payment:\n%s\n", cJSON_Print(jsonextra_payment_2));
}

int main() {
  test_extra_payment(1);
  test_extra_payment(0);

  printf("Hello world \n");
  return 0;
}

#endif // extra_payment_MAIN
#endif // extra_payment_TEST
