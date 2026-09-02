#ifndef reorder_proposal_response_TEST
#define reorder_proposal_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reorder_proposal_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reorder_proposal_response.h"
reorder_proposal_response_t* instantiate_reorder_proposal_response(int include_optional);



reorder_proposal_response_t* instantiate_reorder_proposal_response(int include_optional) {
  reorder_proposal_response_t* reorder_proposal_response = NULL;
  if (include_optional) {
    reorder_proposal_response = reorder_proposal_response_create(
      "2013-10-20T19:20:30+01:00",
      list_createList(),
      56
    );
  } else {
    reorder_proposal_response = reorder_proposal_response_create(
      "2013-10-20T19:20:30+01:00",
      list_createList(),
      56
    );
  }

  return reorder_proposal_response;
}


#ifdef reorder_proposal_response_MAIN

void test_reorder_proposal_response(int include_optional) {
    reorder_proposal_response_t* reorder_proposal_response_1 = instantiate_reorder_proposal_response(include_optional);

	cJSON* jsonreorder_proposal_response_1 = reorder_proposal_response_convertToJSON(reorder_proposal_response_1);
	printf("reorder_proposal_response :\n%s\n", cJSON_Print(jsonreorder_proposal_response_1));
	reorder_proposal_response_t* reorder_proposal_response_2 = reorder_proposal_response_parseFromJSON(jsonreorder_proposal_response_1);
	cJSON* jsonreorder_proposal_response_2 = reorder_proposal_response_convertToJSON(reorder_proposal_response_2);
	printf("repeating reorder_proposal_response:\n%s\n", cJSON_Print(jsonreorder_proposal_response_2));
}

int main() {
  test_reorder_proposal_response(1);
  test_reorder_proposal_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // reorder_proposal_response_MAIN
#endif // reorder_proposal_response_TEST
