#ifndef proposed_assignment_TEST
#define proposed_assignment_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define proposed_assignment_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/proposed_assignment.h"
proposed_assignment_t* instantiate_proposed_assignment(int include_optional);



proposed_assignment_t* instantiate_proposed_assignment(int include_optional) {
  proposed_assignment_t* proposed_assignment = NULL;
  if (include_optional) {
    proposed_assignment = proposed_assignment_create(
      "0",
      1.337,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    proposed_assignment = proposed_assignment_create(
      "0",
      1.337,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return proposed_assignment;
}


#ifdef proposed_assignment_MAIN

void test_proposed_assignment(int include_optional) {
    proposed_assignment_t* proposed_assignment_1 = instantiate_proposed_assignment(include_optional);

	cJSON* jsonproposed_assignment_1 = proposed_assignment_convertToJSON(proposed_assignment_1);
	printf("proposed_assignment :\n%s\n", cJSON_Print(jsonproposed_assignment_1));
	proposed_assignment_t* proposed_assignment_2 = proposed_assignment_parseFromJSON(jsonproposed_assignment_1);
	cJSON* jsonproposed_assignment_2 = proposed_assignment_convertToJSON(proposed_assignment_2);
	printf("repeating proposed_assignment:\n%s\n", cJSON_Print(jsonproposed_assignment_2));
}

int main() {
  test_proposed_assignment(1);
  test_proposed_assignment(0);

  printf("Hello world \n");
  return 0;
}

#endif // proposed_assignment_MAIN
#endif // proposed_assignment_TEST
