#ifndef discount_type_TEST
#define discount_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define discount_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/discount_type.h"
discount_type_t* instantiate_discount_type(int include_optional);



discount_type_t* instantiate_discount_type(int include_optional) {
  discount_type_t* discount_type = NULL;
  if (include_optional) {
    discount_type = discount_type_create(
    );
  } else {
    discount_type = discount_type_create(
    );
  }

  return discount_type;
}


#ifdef discount_type_MAIN

void test_discount_type(int include_optional) {
    discount_type_t* discount_type_1 = instantiate_discount_type(include_optional);

	cJSON* jsondiscount_type_1 = discount_type_convertToJSON(discount_type_1);
	printf("discount_type :\n%s\n", cJSON_Print(jsondiscount_type_1));
	discount_type_t* discount_type_2 = discount_type_parseFromJSON(jsondiscount_type_1);
	cJSON* jsondiscount_type_2 = discount_type_convertToJSON(discount_type_2);
	printf("repeating discount_type:\n%s\n", cJSON_Print(jsondiscount_type_2));
}

int main() {
  test_discount_type(1);
  test_discount_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // discount_type_MAIN
#endif // discount_type_TEST
