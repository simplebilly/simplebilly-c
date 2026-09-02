#ifndef invoice_line_item_TEST
#define invoice_line_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define invoice_line_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/invoice_line_item.h"
invoice_line_item_t* instantiate_invoice_line_item(int include_optional);



invoice_line_item_t* instantiate_invoice_line_item(int include_optional) {
  invoice_line_item_t* invoice_line_item = NULL;
  if (include_optional) {
    invoice_line_item = invoice_line_item_create(
      "0",
      "Electricity Work Price",
      "0",
      "0",
      1,
      "0",
      1,
      1,
      "0",
      "19.9",
      "0",
      "0",
      "0",
      0,
      null,
      "0",
      "0",
      "10.0",
      "0",
      "19.0",
      null,
      "1.99",
      "0",
      "0",
      "0"
    );
  } else {
    invoice_line_item = invoice_line_item_create(
      "0",
      "Electricity Work Price",
      "0",
      "0",
      1,
      "0",
      1,
      1,
      "0",
      "19.9",
      "0",
      "0",
      "0",
      0,
      null,
      "0",
      "0",
      "10.0",
      "0",
      "19.0",
      null,
      "1.99",
      "0",
      "0",
      "0"
    );
  }

  return invoice_line_item;
}


#ifdef invoice_line_item_MAIN

void test_invoice_line_item(int include_optional) {
    invoice_line_item_t* invoice_line_item_1 = instantiate_invoice_line_item(include_optional);

	cJSON* jsoninvoice_line_item_1 = invoice_line_item_convertToJSON(invoice_line_item_1);
	printf("invoice_line_item :\n%s\n", cJSON_Print(jsoninvoice_line_item_1));
	invoice_line_item_t* invoice_line_item_2 = invoice_line_item_parseFromJSON(jsoninvoice_line_item_1);
	cJSON* jsoninvoice_line_item_2 = invoice_line_item_convertToJSON(invoice_line_item_2);
	printf("repeating invoice_line_item:\n%s\n", cJSON_Print(jsoninvoice_line_item_2));
}

int main() {
  test_invoice_line_item(1);
  test_invoice_line_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // invoice_line_item_MAIN
#endif // invoice_line_item_TEST
