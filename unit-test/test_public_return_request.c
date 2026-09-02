#ifndef public_return_request_TEST
#define public_return_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define public_return_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/public_return_request.h"
public_return_request_t* instantiate_public_return_request(int include_optional);



public_return_request_t* instantiate_public_return_request(int include_optional) {
  public_return_request_t* public_return_request = NULL;
  if (include_optional) {
    public_return_request = public_return_request_create(
      "0",
      list_createList(),
      "0",
      "0"
    );
  } else {
    public_return_request = public_return_request_create(
      "0",
      list_createList(),
      "0",
      "0"
    );
  }

  return public_return_request;
}


#ifdef public_return_request_MAIN

void test_public_return_request(int include_optional) {
    public_return_request_t* public_return_request_1 = instantiate_public_return_request(include_optional);

	cJSON* jsonpublic_return_request_1 = public_return_request_convertToJSON(public_return_request_1);
	printf("public_return_request :\n%s\n", cJSON_Print(jsonpublic_return_request_1));
	public_return_request_t* public_return_request_2 = public_return_request_parseFromJSON(jsonpublic_return_request_1);
	cJSON* jsonpublic_return_request_2 = public_return_request_convertToJSON(public_return_request_2);
	printf("repeating public_return_request:\n%s\n", cJSON_Print(jsonpublic_return_request_2));
}

int main() {
  test_public_return_request(1);
  test_public_return_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // public_return_request_MAIN
#endif // public_return_request_TEST
