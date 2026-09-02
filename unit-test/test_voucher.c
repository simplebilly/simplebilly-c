#ifndef voucher_TEST
#define voucher_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define voucher_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/voucher.h"
voucher_t* instantiate_voucher(int include_optional);



voucher_t* instantiate_voucher(int include_optional) {
  voucher_t* voucher = NULL;
  if (include_optional) {
    voucher = voucher_create(
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
      simplebilly_api_voucher__open,
      simplebilly_api_voucher__invoice
    );
  } else {
    voucher = voucher_create(
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
      simplebilly_api_voucher__open,
      simplebilly_api_voucher__invoice
    );
  }

  return voucher;
}


#ifdef voucher_MAIN

void test_voucher(int include_optional) {
    voucher_t* voucher_1 = instantiate_voucher(include_optional);

	cJSON* jsonvoucher_1 = voucher_convertToJSON(voucher_1);
	printf("voucher :\n%s\n", cJSON_Print(jsonvoucher_1));
	voucher_t* voucher_2 = voucher_parseFromJSON(jsonvoucher_1);
	cJSON* jsonvoucher_2 = voucher_convertToJSON(voucher_2);
	printf("repeating voucher:\n%s\n", cJSON_Print(jsonvoucher_2));
}

int main() {
  test_voucher(1);
  test_voucher(0);

  printf("Hello world \n");
  return 0;
}

#endif // voucher_MAIN
#endif // voucher_TEST
