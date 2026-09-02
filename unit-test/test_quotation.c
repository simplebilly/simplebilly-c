#ifndef quotation_TEST
#define quotation_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define quotation_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/quotation.h"
quotation_t* instantiate_quotation(int include_optional);



quotation_t* instantiate_quotation(int include_optional) {
  quotation_t* quotation = NULL;
  if (include_optional) {
    quotation = quotation_create(
      null,
      "0",
      "0",
      "0",
      "2013-10-20",
      null,
      "0",
      null,
      "0",
      order_confirmation,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20",
      simplebilly_api_quotation__open
    );
  } else {
    quotation = quotation_create(
      null,
      "0",
      "0",
      "0",
      "2013-10-20",
      null,
      "0",
      null,
      "0",
      order_confirmation,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20",
      simplebilly_api_quotation__open
    );
  }

  return quotation;
}


#ifdef quotation_MAIN

void test_quotation(int include_optional) {
    quotation_t* quotation_1 = instantiate_quotation(include_optional);

	cJSON* jsonquotation_1 = quotation_convertToJSON(quotation_1);
	printf("quotation :\n%s\n", cJSON_Print(jsonquotation_1));
	quotation_t* quotation_2 = quotation_parseFromJSON(jsonquotation_1);
	cJSON* jsonquotation_2 = quotation_convertToJSON(quotation_2);
	printf("repeating quotation:\n%s\n", cJSON_Print(jsonquotation_2));
}

int main() {
  test_quotation(1);
  test_quotation(0);

  printf("Hello world \n");
  return 0;
}

#endif // quotation_MAIN
#endif // quotation_TEST
