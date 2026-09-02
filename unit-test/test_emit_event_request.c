#ifndef emit_event_request_TEST
#define emit_event_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define emit_event_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/emit_event_request.h"
emit_event_request_t* instantiate_emit_event_request(int include_optional);



emit_event_request_t* instantiate_emit_event_request(int include_optional) {
  emit_event_request_t* emit_event_request = NULL;
  if (include_optional) {
    emit_event_request = emit_event_request_create(
      "0",
      null
    );
  } else {
    emit_event_request = emit_event_request_create(
      "0",
      null
    );
  }

  return emit_event_request;
}


#ifdef emit_event_request_MAIN

void test_emit_event_request(int include_optional) {
    emit_event_request_t* emit_event_request_1 = instantiate_emit_event_request(include_optional);

	cJSON* jsonemit_event_request_1 = emit_event_request_convertToJSON(emit_event_request_1);
	printf("emit_event_request :\n%s\n", cJSON_Print(jsonemit_event_request_1));
	emit_event_request_t* emit_event_request_2 = emit_event_request_parseFromJSON(jsonemit_event_request_1);
	cJSON* jsonemit_event_request_2 = emit_event_request_convertToJSON(emit_event_request_2);
	printf("repeating emit_event_request:\n%s\n", cJSON_Print(jsonemit_event_request_2));
}

int main() {
  test_emit_event_request(1);
  test_emit_event_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // emit_event_request_MAIN
#endif // emit_event_request_TEST
