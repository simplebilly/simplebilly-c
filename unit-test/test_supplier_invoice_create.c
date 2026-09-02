#ifndef supplier_invoice_create_TEST
#define supplier_invoice_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define supplier_invoice_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/supplier_invoice_create.h"
supplier_invoice_create_t* instantiate_supplier_invoice_create(int include_optional);



supplier_invoice_create_t* instantiate_supplier_invoice_create(int include_optional) {
  supplier_invoice_create_t* supplier_invoice_create = NULL;
  if (include_optional) {
    supplier_invoice_create = supplier_invoice_create_create(
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
    supplier_invoice_create = supplier_invoice_create_create(
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

  return supplier_invoice_create;
}


#ifdef supplier_invoice_create_MAIN

void test_supplier_invoice_create(int include_optional) {
    supplier_invoice_create_t* supplier_invoice_create_1 = instantiate_supplier_invoice_create(include_optional);

	cJSON* jsonsupplier_invoice_create_1 = supplier_invoice_create_convertToJSON(supplier_invoice_create_1);
	printf("supplier_invoice_create :\n%s\n", cJSON_Print(jsonsupplier_invoice_create_1));
	supplier_invoice_create_t* supplier_invoice_create_2 = supplier_invoice_create_parseFromJSON(jsonsupplier_invoice_create_1);
	cJSON* jsonsupplier_invoice_create_2 = supplier_invoice_create_convertToJSON(supplier_invoice_create_2);
	printf("repeating supplier_invoice_create:\n%s\n", cJSON_Print(jsonsupplier_invoice_create_2));
}

int main() {
  test_supplier_invoice_create(1);
  test_supplier_invoice_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // supplier_invoice_create_MAIN
#endif // supplier_invoice_create_TEST
