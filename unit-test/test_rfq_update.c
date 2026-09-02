#ifndef rfq_update_TEST
#define rfq_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define rfq_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/rfq_update.h"
rfq_update_t* instantiate_rfq_update(int include_optional);



rfq_update_t* instantiate_rfq_update(int include_optional) {
  rfq_update_t* rfq_update = NULL;
  if (include_optional) {
    rfq_update = rfq_update_create(
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
    rfq_update = rfq_update_create(
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

  return rfq_update;
}


#ifdef rfq_update_MAIN

void test_rfq_update(int include_optional) {
    rfq_update_t* rfq_update_1 = instantiate_rfq_update(include_optional);

	cJSON* jsonrfq_update_1 = rfq_update_convertToJSON(rfq_update_1);
	printf("rfq_update :\n%s\n", cJSON_Print(jsonrfq_update_1));
	rfq_update_t* rfq_update_2 = rfq_update_parseFromJSON(jsonrfq_update_1);
	cJSON* jsonrfq_update_2 = rfq_update_convertToJSON(rfq_update_2);
	printf("repeating rfq_update:\n%s\n", cJSON_Print(jsonrfq_update_2));
}

int main() {
  test_rfq_update(1);
  test_rfq_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // rfq_update_MAIN
#endif // rfq_update_TEST
