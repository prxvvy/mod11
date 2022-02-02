/* mod11 - A program to validate a Chilean RUT (id).
 * Copyright (C) 2021 prxvvy <qsk55464@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

//
// Created by prxvvy on 28-01-22.
//

/**
 * This file is not meant to be added to cmake targets .
 */

#include "include/rut_node.h"

#include <stdlib.h>
#include <string.h>

#include "include/rut.h"

napi_value NodeGetDigit(napi_env env, napi_callback_info info) {
    napi_status status;
    size_t argc = 1;
    napi_value argv[1];

    napi_get_cb_info(env, info, &argc, argv, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Se espera un argumento.");
        return NULL;
    }

    size_t strSize, strSizeRead;

    status = napi_get_value_string_utf8(env, argv[0], NULL, 0, &strSize);

    if (status != napi_ok) {
        napi_throw_type_error(env, NULL,
                              "No se paso un string como parametro.");
        return NULL;
    }

    char *p_buf = calloc(strSize + 1, sizeof(char));
    strSize = strSize + 1;

    status =
        napi_get_value_string_utf8(env, argv[0], p_buf, strSize, &strSizeRead);
    if (status != napi_ok) {
        napi_throw_type_error(env, NULL,
                              "No se paso un string como parametro.");
        return NULL;
    }

    char p_digit = GetDigit(p_buf);

    napi_value res;

    status = napi_create_string_utf8(env, (char[2]){(char)p_digit, '\0'},
                                     strlen((char[2]){(char)p_digit, '\0'}) + 1,
                                     &res);

    if (status != napi_ok) {
        napi_throw_error(env, NULL, "No se puede crear el valor de retorno.");
        return NULL;
    }

    free(p_buf);
    return res;
}

napi_value NodeClean(napi_env env, napi_callback_info info) {
    napi_status status;
    size_t argc = 1;
    napi_value argv[1];

    napi_get_cb_info(env, info, &argc, argv, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Se espera un argumento.");
        return NULL;
    }

    size_t strSize, strSizeRead;

    status = napi_get_value_string_utf8(env, argv[0], NULL, 0, &strSize);

    if (status != napi_ok) {
        napi_throw_type_error(env, NULL,
                              "No se paso un string como parametro.");
        return NULL;
    }

    char *p_buf = calloc(strSize + 1, sizeof(char));
    strSize = strSize + 1;

    status =
        napi_get_value_string_utf8(env, argv[0], p_buf, strSize, &strSizeRead);
    if (status != napi_ok) {
        napi_throw_type_error(env, NULL,
                              "No se paso un string como parametro.");
        return NULL;
    }

    char *p_cleanRut = Clean(p_buf);

    napi_value res;

    status =
        napi_create_string_utf8(env, p_cleanRut, strlen(p_cleanRut) + 1, &res);

    if (status != napi_ok) {
        napi_throw_error(env, NULL, "No se puede crear el valor de retorno.");
        return NULL;
    }

    free(p_cleanRut);
    free(p_buf);
    return res;
}

napi_value NodeFormatRut(napi_env env, napi_callback_info info) {
    napi_status status;
    size_t argc = 1;
    napi_value argv[1];

    napi_get_cb_info(env, info, &argc, argv, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Se espera un argumento.");
        return NULL;
    }

    size_t strSize, strSizeRead;

    status = napi_get_value_string_utf8(env, argv[0], NULL, 0, &strSize);

    if (status != napi_ok) {
        napi_throw_type_error(env, NULL,
                              "No se paso un string como parametro.");
        return NULL;
    }

    char *p_buf = calloc(strSize + 1, sizeof(char));
    strSize = strSize + 1;

    status =
        napi_get_value_string_utf8(env, argv[0], p_buf, strSize, &strSizeRead);
    if (status != napi_ok) {
        napi_throw_type_error(env, NULL,
                              "No se paso un string como parametro.");
        return NULL;
    }
    char *p_rut = Format(p_buf, FALSE);

    napi_value res;

    status = napi_create_string_utf8(env, p_rut, strlen(p_rut) + 1, &res);

    if (status != napi_ok) {
        napi_throw_error(env, NULL, "No se puede crear el valor de retorno.");
        return NULL;
    }

    free(p_rut);
    free(p_buf);
    return res;
}

napi_value NodeFormatRutWithDots(napi_env env, napi_callback_info info) {
    napi_status status;
    size_t argc = 1;
    napi_value argv[1];

    napi_get_cb_info(env, info, &argc, argv, NULL, NULL);

    if (argc < 1) {
        napi_throw_error(env, NULL, "Se espera un argumento.");
        return NULL;
    }

    size_t strSize, strSizeRead;

    status = napi_get_value_string_utf8(env, argv[0], NULL, 0, &strSize);

    if (status != napi_ok) {
        napi_throw_type_error(env, NULL,
                              "No se paso un string como parametro.");
        return NULL;
    }

    char *p_buf = calloc(strSize + 1, sizeof(char));
    strSize = strSize + 1;

    status =
        napi_get_value_string_utf8(env, argv[0], p_buf, strSize, &strSizeRead);
    if (status != napi_ok) {
        napi_throw_type_error(env, NULL,
                              "No se paso un string como parametro.");
        return NULL;
    }
    char *p_rut = Format(p_buf, TRUE);

    napi_value res;

    status = napi_create_string_utf8(env, p_rut, strlen(p_rut) + 1, &res);

    if (status != napi_ok) {
        napi_throw_error(env, NULL, "No se puede crear el valor de retorno.");
        return NULL;
    }

    free(p_rut);
    free(p_buf);
    return res;
}
