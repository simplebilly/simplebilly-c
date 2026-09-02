#ifndef supplier_invoice_update_TEST
#define supplier_invoice_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define supplier_invoice_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/supplier_invoice_update.h"
supplier_invoice_update_t* instantiate_supplier_invoice_update(int include_optional);



supplier_invoice_update_t* instantiate_supplier_invoice_update(int include_optional) {
  supplier_invoice_update_t* supplier_invoice_update = NULL;
  if (include_optional) {
    supplier_invoice_update = supplier_invoice_update_create(
      "0",
      "0",
      "2013-10-20",
      "0",
      null,
      "0",
      "0",
      draft,
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    supplier_invoice_update = supplier_invoice_update_create(
      "0",
      "0",
      "2013-10-20",
      "0",
      null,
      "0",
      "0",
      draft,
      "0",
      "0",
      "0",
      "0"
    );
  }

  return supplier_invoice_update;
}


#ifdef supplier_invoice_update_MAIN

void test_supplier_invoice_update(int include_optional) {
    supplier_invoice_update_t* supplier_invoice_update_1 = instantiate_supplier_invoice_update(include_optional);

	cJSON* jsonsupplier_invoice_update_1 = supplier_invoice_update_convertToJSON(supplier_invoice_update_1);
	printf("supplier_invoice_update :\n%s\n", cJSON_Print(jsonsupplier_invoice_update_1));
	supplier_invoice_update_t* supplier_invoice_update_2 = supplier_invoice_update_parseFromJSON(jsonsupplier_invoice_update_1);
	cJSON* jsonsupplier_invoice_update_2 = supplier_invoice_update_convertToJSON(supplier_invoice_update_2);
	printf("repeating supplier_invoice_update:\n%s\n", cJSON_Print(jsonsupplier_invoice_update_2));
}

int main() {
  test_supplier_invoice_update(1);
  test_supplier_invoice_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // supplier_invoice_update_MAIN
#endif // supplier_invoice_update_TEST
