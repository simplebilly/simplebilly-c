#ifndef invoice_type_TEST
#define invoice_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define invoice_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/invoice_type.h"
invoice_type_t* instantiate_invoice_type(int include_optional);



invoice_type_t* instantiate_invoice_type(int include_optional) {
  invoice_type_t* invoice_type = NULL;
  if (include_optional) {
    invoice_type = invoice_type_create(
    );
  } else {
    invoice_type = invoice_type_create(
    );
  }

  return invoice_type;
}


#ifdef invoice_type_MAIN

void test_invoice_type(int include_optional) {
    invoice_type_t* invoice_type_1 = instantiate_invoice_type(include_optional);

	cJSON* jsoninvoice_type_1 = invoice_type_convertToJSON(invoice_type_1);
	printf("invoice_type :\n%s\n", cJSON_Print(jsoninvoice_type_1));
	invoice_type_t* invoice_type_2 = invoice_type_parseFromJSON(jsoninvoice_type_1);
	cJSON* jsoninvoice_type_2 = invoice_type_convertToJSON(invoice_type_2);
	printf("repeating invoice_type:\n%s\n", cJSON_Print(jsoninvoice_type_2));
}

int main() {
  test_invoice_type(1);
  test_invoice_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // invoice_type_MAIN
#endif // invoice_type_TEST
