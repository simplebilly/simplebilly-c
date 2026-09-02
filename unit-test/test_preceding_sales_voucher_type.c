#ifndef preceding_sales_voucher_type_TEST
#define preceding_sales_voucher_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define preceding_sales_voucher_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/preceding_sales_voucher_type.h"
preceding_sales_voucher_type_t* instantiate_preceding_sales_voucher_type(int include_optional);



preceding_sales_voucher_type_t* instantiate_preceding_sales_voucher_type(int include_optional) {
  preceding_sales_voucher_type_t* preceding_sales_voucher_type = NULL;
  if (include_optional) {
    preceding_sales_voucher_type = preceding_sales_voucher_type_create(
    );
  } else {
    preceding_sales_voucher_type = preceding_sales_voucher_type_create(
    );
  }

  return preceding_sales_voucher_type;
}


#ifdef preceding_sales_voucher_type_MAIN

void test_preceding_sales_voucher_type(int include_optional) {
    preceding_sales_voucher_type_t* preceding_sales_voucher_type_1 = instantiate_preceding_sales_voucher_type(include_optional);

	cJSON* jsonpreceding_sales_voucher_type_1 = preceding_sales_voucher_type_convertToJSON(preceding_sales_voucher_type_1);
	printf("preceding_sales_voucher_type :\n%s\n", cJSON_Print(jsonpreceding_sales_voucher_type_1));
	preceding_sales_voucher_type_t* preceding_sales_voucher_type_2 = preceding_sales_voucher_type_parseFromJSON(jsonpreceding_sales_voucher_type_1);
	cJSON* jsonpreceding_sales_voucher_type_2 = preceding_sales_voucher_type_convertToJSON(preceding_sales_voucher_type_2);
	printf("repeating preceding_sales_voucher_type:\n%s\n", cJSON_Print(jsonpreceding_sales_voucher_type_2));
}

int main() {
  test_preceding_sales_voucher_type(1);
  test_preceding_sales_voucher_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // preceding_sales_voucher_type_MAIN
#endif // preceding_sales_voucher_type_TEST
