#ifndef proforma_invoice_create_TEST
#define proforma_invoice_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define proforma_invoice_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/proforma_invoice_create.h"
proforma_invoice_create_t* instantiate_proforma_invoice_create(int include_optional);



proforma_invoice_create_t* instantiate_proforma_invoice_create(int include_optional) {
  proforma_invoice_create_t* proforma_invoice_create = NULL;
  if (include_optional) {
    proforma_invoice_create = proforma_invoice_create_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      simplebilly_api_proforma_invoice_create__ADP,
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
    proforma_invoice_create = proforma_invoice_create_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      simplebilly_api_proforma_invoice_create__ADP,
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

  return proforma_invoice_create;
}


#ifdef proforma_invoice_create_MAIN

void test_proforma_invoice_create(int include_optional) {
    proforma_invoice_create_t* proforma_invoice_create_1 = instantiate_proforma_invoice_create(include_optional);

	cJSON* jsonproforma_invoice_create_1 = proforma_invoice_create_convertToJSON(proforma_invoice_create_1);
	printf("proforma_invoice_create :\n%s\n", cJSON_Print(jsonproforma_invoice_create_1));
	proforma_invoice_create_t* proforma_invoice_create_2 = proforma_invoice_create_parseFromJSON(jsonproforma_invoice_create_1);
	cJSON* jsonproforma_invoice_create_2 = proforma_invoice_create_convertToJSON(proforma_invoice_create_2);
	printf("repeating proforma_invoice_create:\n%s\n", cJSON_Print(jsonproforma_invoice_create_2));
}

int main() {
  test_proforma_invoice_create(1);
  test_proforma_invoice_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // proforma_invoice_create_MAIN
#endif // proforma_invoice_create_TEST
