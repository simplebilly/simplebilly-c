#ifndef invoice_pdf_url_response_TEST
#define invoice_pdf_url_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define invoice_pdf_url_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/invoice_pdf_url_response.h"
invoice_pdf_url_response_t* instantiate_invoice_pdf_url_response(int include_optional);



invoice_pdf_url_response_t* instantiate_invoice_pdf_url_response(int include_optional) {
  invoice_pdf_url_response_t* invoice_pdf_url_response = NULL;
  if (include_optional) {
    invoice_pdf_url_response = invoice_pdf_url_response_create(
      "0"
    );
  } else {
    invoice_pdf_url_response = invoice_pdf_url_response_create(
      "0"
    );
  }

  return invoice_pdf_url_response;
}


#ifdef invoice_pdf_url_response_MAIN

void test_invoice_pdf_url_response(int include_optional) {
    invoice_pdf_url_response_t* invoice_pdf_url_response_1 = instantiate_invoice_pdf_url_response(include_optional);

	cJSON* jsoninvoice_pdf_url_response_1 = invoice_pdf_url_response_convertToJSON(invoice_pdf_url_response_1);
	printf("invoice_pdf_url_response :\n%s\n", cJSON_Print(jsoninvoice_pdf_url_response_1));
	invoice_pdf_url_response_t* invoice_pdf_url_response_2 = invoice_pdf_url_response_parseFromJSON(jsoninvoice_pdf_url_response_1);
	cJSON* jsoninvoice_pdf_url_response_2 = invoice_pdf_url_response_convertToJSON(invoice_pdf_url_response_2);
	printf("repeating invoice_pdf_url_response:\n%s\n", cJSON_Print(jsoninvoice_pdf_url_response_2));
}

int main() {
  test_invoice_pdf_url_response(1);
  test_invoice_pdf_url_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // invoice_pdf_url_response_MAIN
#endif // invoice_pdf_url_response_TEST
