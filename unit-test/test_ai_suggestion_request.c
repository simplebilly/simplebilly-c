#ifndef ai_suggestion_request_TEST
#define ai_suggestion_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ai_suggestion_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ai_suggestion_request.h"
ai_suggestion_request_t* instantiate_ai_suggestion_request(int include_optional);



ai_suggestion_request_t* instantiate_ai_suggestion_request(int include_optional) {
  ai_suggestion_request_t* ai_suggestion_request = NULL;
  if (include_optional) {
    ai_suggestion_request = ai_suggestion_request_create(
      "0",
      "0",
      "0"
    );
  } else {
    ai_suggestion_request = ai_suggestion_request_create(
      "0",
      "0",
      "0"
    );
  }

  return ai_suggestion_request;
}


#ifdef ai_suggestion_request_MAIN

void test_ai_suggestion_request(int include_optional) {
    ai_suggestion_request_t* ai_suggestion_request_1 = instantiate_ai_suggestion_request(include_optional);

	cJSON* jsonai_suggestion_request_1 = ai_suggestion_request_convertToJSON(ai_suggestion_request_1);
	printf("ai_suggestion_request :\n%s\n", cJSON_Print(jsonai_suggestion_request_1));
	ai_suggestion_request_t* ai_suggestion_request_2 = ai_suggestion_request_parseFromJSON(jsonai_suggestion_request_1);
	cJSON* jsonai_suggestion_request_2 = ai_suggestion_request_convertToJSON(ai_suggestion_request_2);
	printf("repeating ai_suggestion_request:\n%s\n", cJSON_Print(jsonai_suggestion_request_2));
}

int main() {
  test_ai_suggestion_request(1);
  test_ai_suggestion_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // ai_suggestion_request_MAIN
#endif // ai_suggestion_request_TEST
