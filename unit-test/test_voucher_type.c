#ifndef voucher_type_TEST
#define voucher_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define voucher_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/voucher_type.h"
voucher_type_t* instantiate_voucher_type(int include_optional);



voucher_type_t* instantiate_voucher_type(int include_optional) {
  voucher_type_t* voucher_type = NULL;
  if (include_optional) {
    voucher_type = voucher_type_create(
    );
  } else {
    voucher_type = voucher_type_create(
    );
  }

  return voucher_type;
}


#ifdef voucher_type_MAIN

void test_voucher_type(int include_optional) {
    voucher_type_t* voucher_type_1 = instantiate_voucher_type(include_optional);

	cJSON* jsonvoucher_type_1 = voucher_type_convertToJSON(voucher_type_1);
	printf("voucher_type :\n%s\n", cJSON_Print(jsonvoucher_type_1));
	voucher_type_t* voucher_type_2 = voucher_type_parseFromJSON(jsonvoucher_type_1);
	cJSON* jsonvoucher_type_2 = voucher_type_convertToJSON(voucher_type_2);
	printf("repeating voucher_type:\n%s\n", cJSON_Print(jsonvoucher_type_2));
}

int main() {
  test_voucher_type(1);
  test_voucher_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // voucher_type_MAIN
#endif // voucher_type_TEST
