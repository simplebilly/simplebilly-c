#ifndef coupon_validation_TEST
#define coupon_validation_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define coupon_validation_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/coupon_validation.h"
coupon_validation_t* instantiate_coupon_validation(int include_optional);



coupon_validation_t* instantiate_coupon_validation(int include_optional) {
  coupon_validation_t* coupon_validation = NULL;
  if (include_optional) {
    coupon_validation = coupon_validation_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      1
    );
  } else {
    coupon_validation = coupon_validation_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      1
    );
  }

  return coupon_validation;
}


#ifdef coupon_validation_MAIN

void test_coupon_validation(int include_optional) {
    coupon_validation_t* coupon_validation_1 = instantiate_coupon_validation(include_optional);

	cJSON* jsoncoupon_validation_1 = coupon_validation_convertToJSON(coupon_validation_1);
	printf("coupon_validation :\n%s\n", cJSON_Print(jsoncoupon_validation_1));
	coupon_validation_t* coupon_validation_2 = coupon_validation_parseFromJSON(jsoncoupon_validation_1);
	cJSON* jsoncoupon_validation_2 = coupon_validation_convertToJSON(coupon_validation_2);
	printf("repeating coupon_validation:\n%s\n", cJSON_Print(jsoncoupon_validation_2));
}

int main() {
  test_coupon_validation(1);
  test_coupon_validation(0);

  printf("Hello world \n");
  return 0;
}

#endif // coupon_validation_MAIN
#endif // coupon_validation_TEST
