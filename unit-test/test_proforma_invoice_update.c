#ifndef proforma_invoice_update_TEST
#define proforma_invoice_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define proforma_invoice_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/proforma_invoice_update.h"
proforma_invoice_update_t* instantiate_proforma_invoice_update(int include_optional);



proforma_invoice_update_t* instantiate_proforma_invoice_update(int include_optional) {
  proforma_invoice_update_t* proforma_invoice_update = NULL;
  if (include_optional) {
    proforma_invoice_update = proforma_invoice_update_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      ADP,
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
    proforma_invoice_update = proforma_invoice_update_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      ADP,
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

  return proforma_invoice_update;
}


#ifdef proforma_invoice_update_MAIN

void test_proforma_invoice_update(int include_optional) {
    proforma_invoice_update_t* proforma_invoice_update_1 = instantiate_proforma_invoice_update(include_optional);

	cJSON* jsonproforma_invoice_update_1 = proforma_invoice_update_convertToJSON(proforma_invoice_update_1);
	printf("proforma_invoice_update :\n%s\n", cJSON_Print(jsonproforma_invoice_update_1));
	proforma_invoice_update_t* proforma_invoice_update_2 = proforma_invoice_update_parseFromJSON(jsonproforma_invoice_update_1);
	cJSON* jsonproforma_invoice_update_2 = proforma_invoice_update_convertToJSON(proforma_invoice_update_2);
	printf("repeating proforma_invoice_update:\n%s\n", cJSON_Print(jsonproforma_invoice_update_2));
}

int main() {
  test_proforma_invoice_update(1);
  test_proforma_invoice_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // proforma_invoice_update_MAIN
#endif // proforma_invoice_update_TEST
