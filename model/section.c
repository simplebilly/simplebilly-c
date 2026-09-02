#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "section.h"



static section_t *section_create_internal(
    char *body_html,
    char *body_html_en,
    char *id,
    char *title,
    char *title_en
    ) {
    section_t *section_local_var = malloc(sizeof(section_t));
    if (!section_local_var) {
        return NULL;
    }
    memset(section_local_var, 0, sizeof(section_t));
    section_local_var->_library_owned = 1;
    section_local_var->body_html = body_html;
    section_local_var->body_html_en = body_html_en;
    section_local_var->id = id;
    section_local_var->title = title;
    section_local_var->title_en = title_en;
    return section_local_var;
}

__attribute__((deprecated)) section_t *section_create(
    char *body_html,
    char *body_html_en,
    char *id,
    char *title,
    char *title_en
    ) {
    section_t *result = section_create_internal (
        body_html,
        body_html_en,
        id,
        title,
        title_en
        );
    if (!result) {
    }
    return result;
}

void section_free(section_t *section) {
    if(NULL == section){
        return ;
    }
    if(section->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "section_free");
        return ;
    }
    listEntry_t *listEntry;
    if (section->body_html) {
        free(section->body_html);
        section->body_html = NULL;
    }
    if (section->body_html_en) {
        free(section->body_html_en);
        section->body_html_en = NULL;
    }
    if (section->id) {
        free(section->id);
        section->id = NULL;
    }
    if (section->title) {
        free(section->title);
        section->title = NULL;
    }
    if (section->title_en) {
        free(section->title_en);
        section->title_en = NULL;
    }
    free(section);
}

cJSON *section_convertToJSON(section_t *section) {
    cJSON *item = cJSON_CreateObject();

    // section->body_html
    if (!section->body_html) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "bodyHtml", section->body_html) == NULL) {
    goto fail; //String
    }


    // section->body_html_en
    if (!section->body_html_en) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "bodyHtmlEn", section->body_html_en) == NULL) {
    goto fail; //String
    }


    // section->id
    if (!section->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", section->id) == NULL) {
    goto fail; //String
    }


    // section->title
    if (!section->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", section->title) == NULL) {
    goto fail; //String
    }


    // section->title_en
    if (!section->title_en) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "titleEn", section->title_en) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

section_t *section_parseFromJSON(cJSON *sectionJSON){

    section_t *section_local_var = NULL;

    char *body_html_local_str = NULL;

    char *body_html_en_local_str = NULL;

    char *id_local_str = NULL;

    char *title_local_str = NULL;

    char *title_en_local_str = NULL;

    // section->body_html
    cJSON *body_html = cJSON_GetObjectItemCaseSensitive(sectionJSON, "bodyHtml");
    if (cJSON_IsNull(body_html)) {
        body_html = NULL;
    }
    if (!body_html) {
        goto end;
    }

    
    if(!cJSON_IsString(body_html))
    {
    goto end; //String
    }

    // section->body_html_en
    cJSON *body_html_en = cJSON_GetObjectItemCaseSensitive(sectionJSON, "bodyHtmlEn");
    if (cJSON_IsNull(body_html_en)) {
        body_html_en = NULL;
    }
    if (!body_html_en) {
        goto end;
    }

    
    if(!cJSON_IsString(body_html_en))
    {
    goto end; //String
    }

    // section->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(sectionJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // section->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(sectionJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (!title) {
        goto end;
    }

    
    if(!cJSON_IsString(title))
    {
    goto end; //String
    }

    // section->title_en
    cJSON *title_en = cJSON_GetObjectItemCaseSensitive(sectionJSON, "titleEn");
    if (cJSON_IsNull(title_en)) {
        title_en = NULL;
    }
    if (!title_en) {
        goto end;
    }

    
    if(!cJSON_IsString(title_en))
    {
    goto end; //String
    }


    if (body_html && !cJSON_IsNull(body_html)) body_html_local_str = strdup(body_html->valuestring);
    if (body_html_en && !cJSON_IsNull(body_html_en)) body_html_en_local_str = strdup(body_html_en->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (title && !cJSON_IsNull(title)) title_local_str = strdup(title->valuestring);
    if (title_en && !cJSON_IsNull(title_en)) title_en_local_str = strdup(title_en->valuestring);

    section_local_var = section_create_internal (
        body_html_local_str,
        body_html_en_local_str,
        id_local_str,
        title_local_str,
        title_en_local_str
        );

    if (!section_local_var) {
        goto end;
    }

    return section_local_var;
end:
    if (body_html_local_str) {
        free(body_html_local_str);
        body_html_local_str = NULL;
    }
    if (body_html_en_local_str) {
        free(body_html_en_local_str);
        body_html_en_local_str = NULL;
    }
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (title_local_str) {
        free(title_local_str);
        title_local_str = NULL;
    }
    if (title_en_local_str) {
        free(title_en_local_str);
        title_en_local_str = NULL;
    }
    return NULL;

}
