#ifndef public_return_response_TEST
#define public_return_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define public_return_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/public_return_response.h"
public_return_response_t* instantiate_public_return_response(int include_optional);



public_return_response_t* instantiate_public_return_response(int include_optional) {
  public_return_response_t* public_return_response = NULL;
  if (include_optional) {
    public_return_response = public_return_response_create(
      "2013-10-20T19:20:30+01:00",
      null,
      "0",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    public_return_response = public_return_response_create(
      "2013-10-20T19:20:30+01:00",
      null,
      "0",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return public_return_response;
}


#ifdef public_return_response_MAIN

void test_public_return_response(int include_optional) {
    public_return_response_t* public_return_response_1 = instantiate_public_return_response(include_optional);

	cJSON* jsonpublic_return_response_1 = public_return_response_convertToJSON(public_return_response_1);
	printf("public_return_response :\n%s\n", cJSON_Print(jsonpublic_return_response_1));
	public_return_response_t* public_return_response_2 = public_return_response_parseFromJSON(jsonpublic_return_response_1);
	cJSON* jsonpublic_return_response_2 = public_return_response_convertToJSON(public_return_response_2);
	printf("repeating public_return_response:\n%s\n", cJSON_Print(jsonpublic_return_response_2));
}

int main() {
  test_public_return_response(1);
  test_public_return_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // public_return_response_MAIN
#endif // public_return_response_TEST
