#ifndef reorder_proposal_line_TEST
#define reorder_proposal_line_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reorder_proposal_line_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reorder_proposal_line.h"
reorder_proposal_line_t* instantiate_reorder_proposal_line(int include_optional);



reorder_proposal_line_t* instantiate_reorder_proposal_line(int include_optional) {
  reorder_proposal_line_t* reorder_proposal_line = NULL;
  if (include_optional) {
    reorder_proposal_line = reorder_proposal_line_create(
      56,
      56,
      56,
      "0",
      "0",
      56,
      "0",
      56
    );
  } else {
    reorder_proposal_line = reorder_proposal_line_create(
      56,
      56,
      56,
      "0",
      "0",
      56,
      "0",
      56
    );
  }

  return reorder_proposal_line;
}


#ifdef reorder_proposal_line_MAIN

void test_reorder_proposal_line(int include_optional) {
    reorder_proposal_line_t* reorder_proposal_line_1 = instantiate_reorder_proposal_line(include_optional);

	cJSON* jsonreorder_proposal_line_1 = reorder_proposal_line_convertToJSON(reorder_proposal_line_1);
	printf("reorder_proposal_line :\n%s\n", cJSON_Print(jsonreorder_proposal_line_1));
	reorder_proposal_line_t* reorder_proposal_line_2 = reorder_proposal_line_parseFromJSON(jsonreorder_proposal_line_1);
	cJSON* jsonreorder_proposal_line_2 = reorder_proposal_line_convertToJSON(reorder_proposal_line_2);
	printf("repeating reorder_proposal_line:\n%s\n", cJSON_Print(jsonreorder_proposal_line_2));
}

int main() {
  test_reorder_proposal_line(1);
  test_reorder_proposal_line(0);

  printf("Hello world \n");
  return 0;
}

#endif // reorder_proposal_line_MAIN
#endif // reorder_proposal_line_TEST
