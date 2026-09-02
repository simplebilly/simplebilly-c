#ifndef rfq_TEST
#define rfq_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define rfq_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/rfq.h"
rfq_t* instantiate_rfq(int include_optional);



rfq_t* instantiate_rfq(int include_optional) {
  rfq_t* rfq = NULL;
  if (include_optional) {
    rfq = rfq_create(
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
    rfq = rfq_create(
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

  return rfq;
}


#ifdef rfq_MAIN

void test_rfq(int include_optional) {
    rfq_t* rfq_1 = instantiate_rfq(include_optional);

	cJSON* jsonrfq_1 = rfq_convertToJSON(rfq_1);
	printf("rfq :\n%s\n", cJSON_Print(jsonrfq_1));
	rfq_t* rfq_2 = rfq_parseFromJSON(jsonrfq_1);
	cJSON* jsonrfq_2 = rfq_convertToJSON(rfq_2);
	printf("repeating rfq:\n%s\n", cJSON_Print(jsonrfq_2));
}

int main() {
  test_rfq(1);
  test_rfq(0);

  printf("Hello world \n");
  return 0;
}

#endif // rfq_MAIN
#endif // rfq_TEST
