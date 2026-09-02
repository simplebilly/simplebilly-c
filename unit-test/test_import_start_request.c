#ifndef import_start_request_TEST
#define import_start_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define import_start_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/import_start_request.h"
import_start_request_t* instantiate_import_start_request(int include_optional);



import_start_request_t* instantiate_import_start_request(int include_optional) {
  import_start_request_t* import_start_request = NULL;
  if (include_optional) {
    import_start_request = import_start_request_create(
      "0",
      "0",
      list_createList()
    );
  } else {
    import_start_request = import_start_request_create(
      "0",
      "0",
      list_createList()
    );
  }

  return import_start_request;
}


#ifdef import_start_request_MAIN

void test_import_start_request(int include_optional) {
    import_start_request_t* import_start_request_1 = instantiate_import_start_request(include_optional);

	cJSON* jsonimport_start_request_1 = import_start_request_convertToJSON(import_start_request_1);
	printf("import_start_request :\n%s\n", cJSON_Print(jsonimport_start_request_1));
	import_start_request_t* import_start_request_2 = import_start_request_parseFromJSON(jsonimport_start_request_1);
	cJSON* jsonimport_start_request_2 = import_start_request_convertToJSON(import_start_request_2);
	printf("repeating import_start_request:\n%s\n", cJSON_Print(jsonimport_start_request_2));
}

int main() {
  test_import_start_request(1);
  test_import_start_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // import_start_request_MAIN
#endif // import_start_request_TEST
