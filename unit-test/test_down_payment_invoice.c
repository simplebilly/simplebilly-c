#ifndef down_payment_invoice_TEST
#define down_payment_invoice_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define down_payment_invoice_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/down_payment_invoice.h"
down_payment_invoice_t* instantiate_down_payment_invoice(int include_optional);



down_payment_invoice_t* instantiate_down_payment_invoice(int include_optional) {
  down_payment_invoice_t* down_payment_invoice = NULL;
  if (include_optional) {
    down_payment_invoice = down_payment_invoice_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20",
      "0",
      "0"
    );
  } else {
    down_payment_invoice = down_payment_invoice_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20",
      "0",
      "0"
    );
  }

  return down_payment_invoice;
}


#ifdef down_payment_invoice_MAIN

void test_down_payment_invoice(int include_optional) {
    down_payment_invoice_t* down_payment_invoice_1 = instantiate_down_payment_invoice(include_optional);

	cJSON* jsondown_payment_invoice_1 = down_payment_invoice_convertToJSON(down_payment_invoice_1);
	printf("down_payment_invoice :\n%s\n", cJSON_Print(jsondown_payment_invoice_1));
	down_payment_invoice_t* down_payment_invoice_2 = down_payment_invoice_parseFromJSON(jsondown_payment_invoice_1);
	cJSON* jsondown_payment_invoice_2 = down_payment_invoice_convertToJSON(down_payment_invoice_2);
	printf("repeating down_payment_invoice:\n%s\n", cJSON_Print(jsondown_payment_invoice_2));
}

int main() {
  test_down_payment_invoice(1);
  test_down_payment_invoice(0);

  printf("Hello world \n");
  return 0;
}

#endif // down_payment_invoice_MAIN
#endif // down_payment_invoice_TEST
