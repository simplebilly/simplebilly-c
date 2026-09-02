#ifndef supplier_invoice_status_TEST
#define supplier_invoice_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define supplier_invoice_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/supplier_invoice_status.h"
supplier_invoice_status_t* instantiate_supplier_invoice_status(int include_optional);



supplier_invoice_status_t* instantiate_supplier_invoice_status(int include_optional) {
  supplier_invoice_status_t* supplier_invoice_status = NULL;
  if (include_optional) {
    supplier_invoice_status = supplier_invoice_status_create(
    );
  } else {
    supplier_invoice_status = supplier_invoice_status_create(
    );
  }

  return supplier_invoice_status;
}


#ifdef supplier_invoice_status_MAIN

void test_supplier_invoice_status(int include_optional) {
    supplier_invoice_status_t* supplier_invoice_status_1 = instantiate_supplier_invoice_status(include_optional);

	cJSON* jsonsupplier_invoice_status_1 = supplier_invoice_status_convertToJSON(supplier_invoice_status_1);
	printf("supplier_invoice_status :\n%s\n", cJSON_Print(jsonsupplier_invoice_status_1));
	supplier_invoice_status_t* supplier_invoice_status_2 = supplier_invoice_status_parseFromJSON(jsonsupplier_invoice_status_1);
	cJSON* jsonsupplier_invoice_status_2 = supplier_invoice_status_convertToJSON(supplier_invoice_status_2);
	printf("repeating supplier_invoice_status:\n%s\n", cJSON_Print(jsonsupplier_invoice_status_2));
}

int main() {
  test_supplier_invoice_status(1);
  test_supplier_invoice_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // supplier_invoice_status_MAIN
#endif // supplier_invoice_status_TEST
