/*
 * packing_video_response.h
 *
 * 
 */

#ifndef _packing_video_response_H_
#define _packing_video_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct packing_video_response_t packing_video_response_t;




typedef struct packing_video_response_t {
    char *message; // string
    char *recording_url; // string
    int *success; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} packing_video_response_t;

__attribute__((deprecated)) packing_video_response_t *packing_video_response_create(
    char *message,
    char *recording_url,
    int *success
);

void packing_video_response_free(packing_video_response_t *packing_video_response);

packing_video_response_t *packing_video_response_parseFromJSON(cJSON *packing_video_responseJSON);

cJSON *packing_video_response_convertToJSON(packing_video_response_t *packing_video_response);

#endif /* _packing_video_response_H_ */

