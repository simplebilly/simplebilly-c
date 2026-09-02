#ifndef invoice_match_request_TEST
#define invoice_match_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define invoice_match_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/invoice_match_request.h"
invoice_match_request_t* instantiate_invoice_match_request(int include_optional);



invoice_match_request_t* instantiate_invoice_match_request(int include_optional) {
  invoice_match_request_t* invoice_match_request = NULL;
  if (include_optional) {
    invoice_match_request = invoice_match_request_create(
      "0"
    );
  } else {
    invoice_match_request = invoice_match_request_create(
      "0"
    );
  }

  return invoice_match_request;
}


#ifdef invoice_match_request_MAIN

void test_invoice_match_request(int include_optional) {
    invoice_match_request_t* invoice_match_request_1 = instantiate_invoice_match_request(include_optional);

	cJSON* jsoninvoice_match_request_1 = invoice_match_request_convertToJSON(invoice_match_request_1);
	printf("invoice_match_request :\n%s\n", cJSON_Print(jsoninvoice_match_request_1));
	invoice_match_request_t* invoice_match_request_2 = invoice_match_request_parseFromJSON(jsoninvoice_match_request_1);
	cJSON* jsoninvoice_match_request_2 = invoice_match_request_convertToJSON(invoice_match_request_2);
	printf("repeating invoice_match_request:\n%s\n", cJSON_Print(jsoninvoice_match_request_2));
}

int main() {
  test_invoice_match_request(1);
  test_invoice_match_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // invoice_match_request_MAIN
#endif // invoice_match_request_TEST
