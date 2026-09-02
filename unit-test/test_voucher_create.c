#ifndef voucher_create_TEST
#define voucher_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define voucher_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/voucher_create.h"
voucher_create_t* instantiate_voucher_create(int include_optional);



voucher_create_t* instantiate_voucher_create(int include_optional) {
  voucher_create_t* voucher_create = NULL;
  if (include_optional) {
    voucher_create = voucher_create_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      null,
      null,
      null,
      "0",
      "0",
      "2013-10-20",
      unpaid,
      null,
      "0",
      "0",
      "0",
      "2013-10-20",
      "0",
      simplebilly_api_voucher_create__open,
      simplebilly_api_voucher_create__invoice
    );
  } else {
    voucher_create = voucher_create_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      null,
      null,
      null,
      "0",
      "0",
      "2013-10-20",
      unpaid,
      null,
      "0",
      "0",
      "0",
      "2013-10-20",
      "0",
      simplebilly_api_voucher_create__open,
      simplebilly_api_voucher_create__invoice
    );
  }

  return voucher_create;
}


#ifdef voucher_create_MAIN

void test_voucher_create(int include_optional) {
    voucher_create_t* voucher_create_1 = instantiate_voucher_create(include_optional);

	cJSON* jsonvoucher_create_1 = voucher_create_convertToJSON(voucher_create_1);
	printf("voucher_create :\n%s\n", cJSON_Print(jsonvoucher_create_1));
	voucher_create_t* voucher_create_2 = voucher_create_parseFromJSON(jsonvoucher_create_1);
	cJSON* jsonvoucher_create_2 = voucher_create_convertToJSON(voucher_create_2);
	printf("repeating voucher_create:\n%s\n", cJSON_Print(jsonvoucher_create_2));
}

int main() {
  test_voucher_create(1);
  test_voucher_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // voucher_create_MAIN
#endif // voucher_create_TEST
