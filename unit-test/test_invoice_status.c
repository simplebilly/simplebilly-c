#ifndef invoice_status_TEST
#define invoice_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define invoice_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/invoice_status.h"
invoice_status_t* instantiate_invoice_status(int include_optional);



invoice_status_t* instantiate_invoice_status(int include_optional) {
  invoice_status_t* invoice_status = NULL;
  if (include_optional) {
    invoice_status = invoice_status_create(
    );
  } else {
    invoice_status = invoice_status_create(
    );
  }

  return invoice_status;
}


#ifdef invoice_status_MAIN

void test_invoice_status(int include_optional) {
    invoice_status_t* invoice_status_1 = instantiate_invoice_status(include_optional);

	cJSON* jsoninvoice_status_1 = invoice_status_convertToJSON(invoice_status_1);
	printf("invoice_status :\n%s\n", cJSON_Print(jsoninvoice_status_1));
	invoice_status_t* invoice_status_2 = invoice_status_parseFromJSON(jsoninvoice_status_1);
	cJSON* jsoninvoice_status_2 = invoice_status_convertToJSON(invoice_status_2);
	printf("repeating invoice_status:\n%s\n", cJSON_Print(jsoninvoice_status_2));
}

int main() {
  test_invoice_status(1);
  test_invoice_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // invoice_status_MAIN
#endif // invoice_status_TEST
