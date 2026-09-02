#ifndef ai_suggestion_TEST
#define ai_suggestion_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ai_suggestion_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ai_suggestion.h"
ai_suggestion_t* instantiate_ai_suggestion(int include_optional);



ai_suggestion_t* instantiate_ai_suggestion(int include_optional) {
  ai_suggestion_t* ai_suggestion = NULL;
  if (include_optional) {
    ai_suggestion = ai_suggestion_create(
      1.337,
      "0",
      "0",
      "0",
      "0",
      list_createList()
    );
  } else {
    ai_suggestion = ai_suggestion_create(
      1.337,
      "0",
      "0",
      "0",
      "0",
      list_createList()
    );
  }

  return ai_suggestion;
}


#ifdef ai_suggestion_MAIN

void test_ai_suggestion(int include_optional) {
    ai_suggestion_t* ai_suggestion_1 = instantiate_ai_suggestion(include_optional);

	cJSON* jsonai_suggestion_1 = ai_suggestion_convertToJSON(ai_suggestion_1);
	printf("ai_suggestion :\n%s\n", cJSON_Print(jsonai_suggestion_1));
	ai_suggestion_t* ai_suggestion_2 = ai_suggestion_parseFromJSON(jsonai_suggestion_1);
	cJSON* jsonai_suggestion_2 = ai_suggestion_convertToJSON(ai_suggestion_2);
	printf("repeating ai_suggestion:\n%s\n", cJSON_Print(jsonai_suggestion_2));
}

int main() {
  test_ai_suggestion(1);
  test_ai_suggestion(0);

  printf("Hello world \n");
  return 0;
}

#endif // ai_suggestion_MAIN
#endif // ai_suggestion_TEST
