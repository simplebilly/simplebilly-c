#ifndef allocate_payment_request_TEST
#define allocate_payment_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define allocate_payment_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/allocate_payment_request.h"
allocate_payment_request_t* instantiate_allocate_payment_request(int include_optional);



allocate_payment_request_t* instantiate_allocate_payment_request(int include_optional) {
  allocate_payment_request_t* allocate_payment_request = NULL;
  if (include_optional) {
    allocate_payment_request = allocate_payment_request_create(
      1.337,
      "0",
      "0"
    );
  } else {
    allocate_payment_request = allocate_payment_request_create(
      1.337,
      "0",
      "0"
    );
  }

  return allocate_payment_request;
}


#ifdef allocate_payment_request_MAIN

void test_allocate_payment_request(int include_optional) {
    allocate_payment_request_t* allocate_payment_request_1 = instantiate_allocate_payment_request(include_optional);

	cJSON* jsonallocate_payment_request_1 = allocate_payment_request_convertToJSON(allocate_payment_request_1);
	printf("allocate_payment_request :\n%s\n", cJSON_Print(jsonallocate_payment_request_1));
	allocate_payment_request_t* allocate_payment_request_2 = allocate_payment_request_parseFromJSON(jsonallocate_payment_request_1);
	cJSON* jsonallocate_payment_request_2 = allocate_payment_request_convertToJSON(allocate_payment_request_2);
	printf("repeating allocate_payment_request:\n%s\n", cJSON_Print(jsonallocate_payment_request_2));
}

int main() {
  test_allocate_payment_request(1);
  test_allocate_payment_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // allocate_payment_request_MAIN
#endif // allocate_payment_request_TEST
