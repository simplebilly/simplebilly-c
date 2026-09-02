#ifndef invoice_create_TEST
#define invoice_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define invoice_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/invoice_create.h"
invoice_create_t* instantiate_invoice_create(int include_optional);



invoice_create_t* instantiate_invoice_create(int include_optional) {
  invoice_create_t* invoice_create = NULL;
  if (include_optional) {
    invoice_create = invoice_create_create(
      null,
      "2013-10-20",
      "2013-10-20",
      "2013-10-20",
      "0",
      "0",
      "0",
      simplebilly_api_invoice_create__ADP,
      "0",
      "0",
      56,
      "0",
      simplebilly_api_invoice_create__invoice,
      56,
      "0",
      1,
      "0",
      "0",
      simplebilly_api_invoice_create__Invoice,
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
      simplebilly_api_invoice_create__unpaid,
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
      simplebilly_api_invoice_create__Draft,
      "0",
      "0",
      "0",
      "0",
      "0",
      ABW,
      "0"
    );
  } else {
    invoice_create = invoice_create_create(
      null,
      "2013-10-20",
      "2013-10-20",
      "2013-10-20",
      "0",
      "0",
      "0",
      simplebilly_api_invoice_create__ADP,
      "0",
      "0",
      56,
      "0",
      simplebilly_api_invoice_create__invoice,
      56,
      "0",
      1,
      "0",
      "0",
      simplebilly_api_invoice_create__Invoice,
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
      simplebilly_api_invoice_create__unpaid,
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
      simplebilly_api_invoice_create__Draft,
      "0",
      "0",
      "0",
      "0",
      "0",
      ABW,
      "0"
    );
  }

  return invoice_create;
}


#ifdef invoice_create_MAIN

void test_invoice_create(int include_optional) {
    invoice_create_t* invoice_create_1 = instantiate_invoice_create(include_optional);

	cJSON* jsoninvoice_create_1 = invoice_create_convertToJSON(invoice_create_1);
	printf("invoice_create :\n%s\n", cJSON_Print(jsoninvoice_create_1));
	invoice_create_t* invoice_create_2 = invoice_create_parseFromJSON(jsoninvoice_create_1);
	cJSON* jsoninvoice_create_2 = invoice_create_convertToJSON(invoice_create_2);
	printf("repeating invoice_create:\n%s\n", cJSON_Print(jsoninvoice_create_2));
}

int main() {
  test_invoice_create(1);
  test_invoice_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // invoice_create_MAIN
#endif // invoice_create_TEST
