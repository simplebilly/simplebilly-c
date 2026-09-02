#ifndef public_posting_TEST
#define public_posting_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define public_posting_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/public_posting.h"
public_posting_t* instantiate_public_posting(int include_optional);



public_posting_t* instantiate_public_posting(int include_optional) {
  public_posting_t* public_posting = NULL;
  if (include_optional) {
    public_posting = public_posting_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      list_createList(),
      "0",
      56,
      56,
      "0"
    );
  } else {
    public_posting = public_posting_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      list_createList(),
      "0",
      56,
      56,
      "0"
    );
  }

  return public_posting;
}


#ifdef public_posting_MAIN

void test_public_posting(int include_optional) {
    public_posting_t* public_posting_1 = instantiate_public_posting(include_optional);

	cJSON* jsonpublic_posting_1 = public_posting_convertToJSON(public_posting_1);
	printf("public_posting :\n%s\n", cJSON_Print(jsonpublic_posting_1));
	public_posting_t* public_posting_2 = public_posting_parseFromJSON(jsonpublic_posting_1);
	cJSON* jsonpublic_posting_2 = public_posting_convertToJSON(public_posting_2);
	printf("repeating public_posting:\n%s\n", cJSON_Print(jsonpublic_posting_2));
}

int main() {
  test_public_posting(1);
  test_public_posting(0);

  printf("Hello world \n");
  return 0;
}

#endif // public_posting_MAIN
#endif // public_posting_TEST
