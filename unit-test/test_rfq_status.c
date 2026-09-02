#ifndef rfq_status_TEST
#define rfq_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define rfq_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/rfq_status.h"
rfq_status_t* instantiate_rfq_status(int include_optional);



rfq_status_t* instantiate_rfq_status(int include_optional) {
  rfq_status_t* rfq_status = NULL;
  if (include_optional) {
    rfq_status = rfq_status_create(
    );
  } else {
    rfq_status = rfq_status_create(
    );
  }

  return rfq_status;
}


#ifdef rfq_status_MAIN

void test_rfq_status(int include_optional) {
    rfq_status_t* rfq_status_1 = instantiate_rfq_status(include_optional);

	cJSON* jsonrfq_status_1 = rfq_status_convertToJSON(rfq_status_1);
	printf("rfq_status :\n%s\n", cJSON_Print(jsonrfq_status_1));
	rfq_status_t* rfq_status_2 = rfq_status_parseFromJSON(jsonrfq_status_1);
	cJSON* jsonrfq_status_2 = rfq_status_convertToJSON(rfq_status_2);
	printf("repeating rfq_status:\n%s\n", cJSON_Print(jsonrfq_status_2));
}

int main() {
  test_rfq_status(1);
  test_rfq_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // rfq_status_MAIN
#endif // rfq_status_TEST
