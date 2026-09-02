#ifndef proforma_invoice_status_TEST
#define proforma_invoice_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define proforma_invoice_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/proforma_invoice_status.h"
proforma_invoice_status_t* instantiate_proforma_invoice_status(int include_optional);



proforma_invoice_status_t* instantiate_proforma_invoice_status(int include_optional) {
  proforma_invoice_status_t* proforma_invoice_status = NULL;
  if (include_optional) {
    proforma_invoice_status = proforma_invoice_status_create(
    );
  } else {
    proforma_invoice_status = proforma_invoice_status_create(
    );
  }

  return proforma_invoice_status;
}


#ifdef proforma_invoice_status_MAIN

void test_proforma_invoice_status(int include_optional) {
    proforma_invoice_status_t* proforma_invoice_status_1 = instantiate_proforma_invoice_status(include_optional);

	cJSON* jsonproforma_invoice_status_1 = proforma_invoice_status_convertToJSON(proforma_invoice_status_1);
	printf("proforma_invoice_status :\n%s\n", cJSON_Print(jsonproforma_invoice_status_1));
	proforma_invoice_status_t* proforma_invoice_status_2 = proforma_invoice_status_parseFromJSON(jsonproforma_invoice_status_1);
	cJSON* jsonproforma_invoice_status_2 = proforma_invoice_status_convertToJSON(proforma_invoice_status_2);
	printf("repeating proforma_invoice_status:\n%s\n", cJSON_Print(jsonproforma_invoice_status_2));
}

int main() {
  test_proforma_invoice_status(1);
  test_proforma_invoice_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // proforma_invoice_status_MAIN
#endif // proforma_invoice_status_TEST
