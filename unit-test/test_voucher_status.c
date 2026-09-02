#ifndef voucher_status_TEST
#define voucher_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define voucher_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/voucher_status.h"
voucher_status_t* instantiate_voucher_status(int include_optional);



voucher_status_t* instantiate_voucher_status(int include_optional) {
  voucher_status_t* voucher_status = NULL;
  if (include_optional) {
    voucher_status = voucher_status_create(
    );
  } else {
    voucher_status = voucher_status_create(
    );
  }

  return voucher_status;
}


#ifdef voucher_status_MAIN

void test_voucher_status(int include_optional) {
    voucher_status_t* voucher_status_1 = instantiate_voucher_status(include_optional);

	cJSON* jsonvoucher_status_1 = voucher_status_convertToJSON(voucher_status_1);
	printf("voucher_status :\n%s\n", cJSON_Print(jsonvoucher_status_1));
	voucher_status_t* voucher_status_2 = voucher_status_parseFromJSON(jsonvoucher_status_1);
	cJSON* jsonvoucher_status_2 = voucher_status_convertToJSON(voucher_status_2);
	printf("repeating voucher_status:\n%s\n", cJSON_Print(jsonvoucher_status_2));
}

int main() {
  test_voucher_status(1);
  test_voucher_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // voucher_status_MAIN
#endif // voucher_status_TEST
