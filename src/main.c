//
// Created by prxvvy on 28-01-22.
//

/**
 * This file is not meant to be added to cmake targets .
 */

#include <node/node_api.h>
#include "include/rut_node.h"

napi_value Init(napi_env env, napi_value exports) {

    napi_status status;
    napi_value func;

    status = napi_create_function(env, NULL, 0, NodeGetDigit, NULL, &func);
    if (status != napi_ok) {
        napi_throw_error(env, NULL, "Unable to wrap native function.");
    }
    status = napi_set_named_property(env, exports, "obtenerDigitoVerificador", func);
    if (status != napi_ok) {
        napi_throw_error(env, NULL, "Unable to populate exports.");
    }

    status = napi_create_function(env, NULL, 0, NodeClean, NULL, &func);
    if (status != napi_ok) {
        napi_throw_error(env, NULL, "Unable to wrap native function.");
    }
    status = napi_set_named_property(env, exports, "limpiarRut", func);
    if (status != napi_ok) {
        napi_throw_error(env, NULL, "Unable to populate exports.");
    }

    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)