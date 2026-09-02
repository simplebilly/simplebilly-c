#ifndef invoice_TEST
#define invoice_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define invoice_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/invoice.h"
invoice_t* instantiate_invoice(int include_optional);



invoice_t* instantiate_invoice(int include_optional) {
  invoice_t* invoice = NULL;
  if (include_optional) {
    invoice = invoice_create(
      null,
      "2013-10-20",
      "2013-10-20",
      "2013-10-20",
      "0",
      "0",
      "0",
      simplebilly_api_invoice__ADP,
      "0",
      "0",
      56,
      "0",
      simplebilly_api_invoice__invoice,
      56,
      "0",
      1,
      "0",
      "0",
      simplebilly_api_invoice__Invoice,
      1,
      1,
      1,
      1,
      1,
      1,
      "2013-10-20",
      "0",
      null,
      1,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20",
      simplebilly_api_invoice__unpaid,
      "0",
      "0",
      order_confirmation,
      1,
      "0",
      "0",
      null,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20",
      "2013-10-20",
      simplebilly_api_invoice__Draft,
      "0",
      "0",
      "0",
      "0",
      "0",
      ABW,
      "0"
    );
  } else {
    invoice = invoice_create(
      null,
      "2013-10-20",
      "2013-10-20",
      "2013-10-20",
      "0",
      "0",
      "0",
      simplebilly_api_invoice__ADP,
      "0",
      "0",
      56,
      "0",
      simplebilly_api_invoice__invoice,
      56,
      "0",
      1,
      "0",
      "0",
      simplebilly_api_invoice__Invoice,
      1,
      1,
      1,
      1,
      1,
      1,
      "2013-10-20",
      "0",
      null,
      1,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20",
      simplebilly_api_invoice__unpaid,
      "0",
      "0",
      order_confirmation,
      1,
      "0",
      "0",
      null,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20",
      "2013-10-20",
      simplebilly_api_invoice__Draft,
      "0",
      "0",
      "0",
      "0",
      "0",
      ABW,
      "0"
    );
  }

  return invoice;
}


#ifdef invoice_MAIN

void test_invoice(int include_optional) {
    invoice_t* invoice_1 = instantiate_invoice(include_optional);

	cJSON* jsoninvoice_1 = invoice_convertToJSON(invoice_1);
	printf("invoice :\n%s\n", cJSON_Print(jsoninvoice_1));
	invoice_t* invoice_2 = invoice_parseFromJSON(jsoninvoice_1);
	cJSON* jsoninvoice_2 = invoice_convertToJSON(invoice_2);
	printf("repeating invoice:\n%s\n", cJSON_Print(jsoninvoice_2));
}

int main() {
  test_invoice(1);
  test_invoice(0);

  printf("Hello world \n");
  return 0;
}

#endif // invoice_MAIN
#endif // invoice_TEST
