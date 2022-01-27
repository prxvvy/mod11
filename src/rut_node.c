/*
* =================================================
*
*       Filename: rut_node
*
*    Description:
*
*        Created: 27/01/2022
*
*        Author:  prxvvy (qsk55464@gmail.com)
*
*
* =================================================
*/

#include "include/rut_node.h"
#include <stdlib.h>
#include "include/rut.h"
#include <string.h>

napi_value NodeObtenerDigitoVerificador(napi_env env, napi_callback_info info) {
    napi_status status;
    size_t argc = 1;
    napi_value argv[1];

    napi_get_cb_info(env, info, &argc, argv, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "1 argument expected.");
        return NULL;
    }

    size_t strSize, strSizeRead;

    status = napi_get_value_string_utf8(env, argv[0], NULL, 0, &strSize);

    if (status != napi_ok) {
        napi_throw_type_error(env, NULL, "String expected.");
        return NULL;
    }

    char *p_buf = calloc(strSize + 1, sizeof(char));
    strSize = strSize + 1;

    status = napi_get_value_string_utf8(env, argv[0], p_buf, strSize, &strSizeRead);
    if (status != napi_ok) {
        napi_throw_type_error(env, NULL, "String expected.");
        return NULL;
    }
    
    char p_digito = ObtenerDigidoVerificador(p_buf);

    napi_value res;

    status = napi_create_string_utf8(env, (char [2]) {(char) p_digito, '\0'}, strlen((char [2]) {(char) p_digito, '\0'}) + 1, &res);

    if (status != napi_ok) {
        napi_throw_error(env, NULL, "Unable to create return value.");
        return NULL;
    }

    free(p_buf);
    return res;
}
