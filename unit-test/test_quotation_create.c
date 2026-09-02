#ifndef quotation_create_TEST
#define quotation_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define quotation_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/quotation_create.h"
quotation_create_t* instantiate_quotation_create(int include_optional);



quotation_create_t* instantiate_quotation_create(int include_optional) {
  quotation_create_t* quotation_create = NULL;
  if (include_optional) {
    quotation_create = quotation_create_create(
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
      "2013-10-20",
      simplebilly_api_quotation_create__open
    );
  } else {
    quotation_create = quotation_create_create(
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
      "2013-10-20",
      simplebilly_api_quotation_create__open
    );
  }

  return quotation_create;
}


#ifdef quotation_create_MAIN

void test_quotation_create(int include_optional) {
    quotation_create_t* quotation_create_1 = instantiate_quotation_create(include_optional);

	cJSON* jsonquotation_create_1 = quotation_create_convertToJSON(quotation_create_1);
	printf("quotation_create :\n%s\n", cJSON_Print(jsonquotation_create_1));
	quotation_create_t* quotation_create_2 = quotation_create_parseFromJSON(jsonquotation_create_1);
	cJSON* jsonquotation_create_2 = quotation_create_convertToJSON(quotation_create_2);
	printf("repeating quotation_create:\n%s\n", cJSON_Print(jsonquotation_create_2));
}

int main() {
  test_quotation_create(1);
  test_quotation_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // quotation_create_MAIN
#endif // quotation_create_TEST
