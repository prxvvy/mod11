/* mod11 - A program to validate a Chilean RUT (id).
 * Copyright (C) 2022 prxvvy <qsk55464@gmail.com>
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

#include <napi.h>

extern "C" {
#include <stdlib.h>

#include "include/rut.h"
}

using namespace std;
using namespace Napi;

Value CleanRutNode(const CallbackInfo &info) {
   Env env = info.Env();
   if (info.Length() == 0) {
      throw TypeError::New(env, "limpiarRut() espera 1 parametro.");
   }

   if (!info[0].IsString()) {
      throw TypeError::New(env,
                           "limpiarRut() espera un parametro de tipo string.");
   }
   string input = info[0].As<String>();
   char *p_input = const_cast<char *>(input.c_str()); /* I hate C++ */
   char *p_cleanRut = Clean(p_input);
   String cleanRut = String::New(env, p_cleanRut);
   free(p_cleanRut);
   return cleanRut;
}

Value GetDigitNode(const CallbackInfo &info) {
   Env env = info.Env();
   if (info.Length() == 0) {
      throw TypeError::New(env,
                           "obtenerDigitoVerificador() espera 1 parametro.");
   }

   if (!info[0].IsString()) {
      throw TypeError::New(
          env,
          "obtenerDigitoVerificador() espera un parametro de tipo string.");
   }

   string input = info[0].As<String>();
   if (input.length() > 13) {
      throw Error::New(env,
                       "obtenerDigitoVerificador() revice un string de no mas "
                       "de 13 caracteres.");
   }

   char *p_input = const_cast<char *>(input.c_str());

   char digit = GetDigit(p_input);
   string tmp_string(1, digit);
   String strDigit = String::New(env, tmp_string);
   return strDigit;
}

Value FormatRutNode(const CallbackInfo &info) {
   Env env = info.Env();
   if (info.Length() == 0) {
      throw TypeError::New(env, "darFormato() espera 1 parametro.");
   }

   if (!info[0].IsString()) {
      throw TypeError::New(
          env, "darFormato() recive como primer parametro un string.");
   }

   if (!info[1].IsBoolean()) {
      throw TypeError::New(
          env, "darFormato() recive como segundo parametro un booleano.");
   }

   string input1 = info[0].As<String>();

   bool input2 = info[1].As<Boolean>();

   if (input1.length() > 13) {
      throw Error::New(env,
                       "darFormato() revice un string de no mas "
                       "de 13 caracteres.");
   }

   char *p_input = const_cast<char *>(input1.c_str());

   char *p_formattedRut = NULL;

   if (input2 == true) {
      p_formattedRut = Format(p_input, TRUE);
   } else
      p_formattedRut = Format(p_input, FALSE);

   String formattedRut = String::New(env, p_formattedRut);

   free(p_formattedRut);

   return formattedRut;
}

Value ValidateRutNode(const CallbackInfo &info) {
   Env env = info.Env();
   if (info.Length() == 0) {
      throw TypeError::New(env, "validarRut() espera 1 parametro.");
   }

   if (!info[0].IsString()) {
      throw TypeError::New(
          env, "validarRut() recive como primer parametro un string.");
   }

   string input = info[0].As<String>();

   char *p_input = const_cast<char *>(input.c_str());

   Bool isValid = ValidateRut(p_input);

   return isValid == TRUE ? Boolean::New(env, true) : Boolean::New(env, false);
}

Object Init(Env env, Object exports) {
   exports.Set(String::New(env, "limpiarRut"),
               Function::New(env, CleanRutNode));
   exports.Set(String::New(env, "obtenerDigitoVerificador"),
               Function::New(env, GetDigitNode));
   exports.Set(String::New(env, "darFormato"),
               Function::New(env, FormatRutNode));
   exports.Set(String::New(env, "validarRut"),
               Function::New(env, ValidateRutNode));
   return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
