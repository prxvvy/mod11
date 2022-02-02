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

#ifndef ALGORITHM_RUT_NODE_H
#define ALGORITHM_RUT_NODE_H

#include <node/node_api.h>

napi_value NodeGetDigit(napi_env env, napi_callback_info info);

napi_value NodeClean(napi_env env, napi_callback_info info);

napi_value NodeFormatRut(napi_env env, napi_callback_info info);

napi_value NodeFormatRutWithDots(napi_env env, napi_callback_info info);

#endif  // ALGORITHM_RUT_NODE_H
