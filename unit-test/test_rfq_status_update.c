#ifndef rfq_status_update_TEST
#define rfq_status_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define rfq_status_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/rfq_status_update.h"
rfq_status_update_t* instantiate_rfq_status_update(int include_optional);



rfq_status_update_t* instantiate_rfq_status_update(int include_optional) {
  rfq_status_update_t* rfq_status_update = NULL;
  if (include_optional) {
    rfq_status_update = rfq_status_update_create(
      "0"
    );
  } else {
    rfq_status_update = rfq_status_update_create(
      "0"
    );
  }

  return rfq_status_update;
}


#ifdef rfq_status_update_MAIN

void test_rfq_status_update(int include_optional) {
    rfq_status_update_t* rfq_status_update_1 = instantiate_rfq_status_update(include_optional);

	cJSON* jsonrfq_status_update_1 = rfq_status_update_convertToJSON(rfq_status_update_1);
	printf("rfq_status_update :\n%s\n", cJSON_Print(jsonrfq_status_update_1));
	rfq_status_update_t* rfq_status_update_2 = rfq_status_update_parseFromJSON(jsonrfq_status_update_1);
	cJSON* jsonrfq_status_update_2 = rfq_status_update_convertToJSON(rfq_status_update_2);
	printf("repeating rfq_status_update:\n%s\n", cJSON_Print(jsonrfq_status_update_2));
}

int main() {
  test_rfq_status_update(1);
  test_rfq_status_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // rfq_status_update_MAIN
#endif // rfq_status_update_TEST
