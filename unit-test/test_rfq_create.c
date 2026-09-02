#ifndef rfq_create_TEST
#define rfq_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define rfq_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/rfq_create.h"
rfq_create_t* instantiate_rfq_create(int include_optional);



rfq_create_t* instantiate_rfq_create(int include_optional) {
  rfq_create_t* rfq_create = NULL;
  if (include_optional) {
    rfq_create = rfq_create_create(
      "0",
      null,
      "0",
      "2013-10-20",
      "2013-10-20",
      "0",
      draft,
      "0",
      "0"
    );
  } else {
    rfq_create = rfq_create_create(
      "0",
      null,
      "0",
      "2013-10-20",
      "2013-10-20",
      "0",
      draft,
      "0",
      "0"
    );
  }

  return rfq_create;
}


#ifdef rfq_create_MAIN

void test_rfq_create(int include_optional) {
    rfq_create_t* rfq_create_1 = instantiate_rfq_create(include_optional);

	cJSON* jsonrfq_create_1 = rfq_create_convertToJSON(rfq_create_1);
	printf("rfq_create :\n%s\n", cJSON_Print(jsonrfq_create_1));
	rfq_create_t* rfq_create_2 = rfq_create_parseFromJSON(jsonrfq_create_1);
	cJSON* jsonrfq_create_2 = rfq_create_convertToJSON(rfq_create_2);
	printf("repeating rfq_create:\n%s\n", cJSON_Print(jsonrfq_create_2));
}

int main() {
  test_rfq_create(1);
  test_rfq_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // rfq_create_MAIN
#endif // rfq_create_TEST
