#ifndef proforma_invoice_TEST
#define proforma_invoice_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define proforma_invoice_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/proforma_invoice.h"
proforma_invoice_t* instantiate_proforma_invoice(int include_optional);



proforma_invoice_t* instantiate_proforma_invoice(int include_optional) {
  proforma_invoice_t* proforma_invoice = NULL;
  if (include_optional) {
    proforma_invoice = proforma_invoice_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      simplebilly_api_proforma_invoice__ADP,
      "0",
      null,
      "2013-10-20",
      null,
      "0",
      "0",
      "2013-10-20",
      "0",
      draft,
      "0",
      "0",
      "0"
    );
  } else {
    proforma_invoice = proforma_invoice_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      simplebilly_api_proforma_invoice__ADP,
      "0",
      null,
      "2013-10-20",
      null,
      "0",
      "0",
      "2013-10-20",
      "0",
      draft,
      "0",
      "0",
      "0"
    );
  }

  return proforma_invoice;
}


#ifdef proforma_invoice_MAIN

void test_proforma_invoice(int include_optional) {
    proforma_invoice_t* proforma_invoice_1 = instantiate_proforma_invoice(include_optional);

	cJSON* jsonproforma_invoice_1 = proforma_invoice_convertToJSON(proforma_invoice_1);
	printf("proforma_invoice :\n%s\n", cJSON_Print(jsonproforma_invoice_1));
	proforma_invoice_t* proforma_invoice_2 = proforma_invoice_parseFromJSON(jsonproforma_invoice_1);
	cJSON* jsonproforma_invoice_2 = proforma_invoice_convertToJSON(proforma_invoice_2);
	printf("repeating proforma_invoice:\n%s\n", cJSON_Print(jsonproforma_invoice_2));
}

int main() {
  test_proforma_invoice(1);
  test_proforma_invoice(0);

  printf("Hello world \n");
  return 0;
}

#endif // proforma_invoice_MAIN
#endif // proforma_invoice_TEST
