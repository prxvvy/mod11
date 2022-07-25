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

#include <napi.h>

extern "C"
{
#include "include/rut_functions.h"
}

using namespace std;
using namespace Napi;

Value
CleanRut (const CallbackInfo &info)
{
  Env env = info.Env ();

  if (info.Length () == 0)
    throw Error::New (env, "limpiarRut() espera 1 parametro.");

  if (!info[0].IsString ())
    throw TypeError::New (env,
                          "limpiarRut() espera un parametro de tipo string.");
  string cppBuffer;
  string rut_input = info[0].As<String> ();

  char *p_rut_input = const_cast<char *> (rut_input.c_str ());
  char *p_cpp_buffer = const_cast<char *> (cppBuffer.c_str ());

  int clean_rut_function_res = mod11_clean_rut (p_cpp_buffer, p_rut_input);

  if (clean_rut_function_res == 0)
    throw Error ::New (
        env, "limpiarRut(): Ocurrio un error al tratar de limpiar el rut.");

  String cleanRut = String::New (env, p_cpp_buffer);
  return cleanRut;
}

Value
GetCheckerDigit (const CallbackInfo &info)
{
  Env env = info.Env ();

  if (info.Length () == 0)
    throw Error::New (env, "obtenerDigitoVerificador() espera 1 parametro.");

  if (!info[0].IsString ())
    throw TypeError::New (
        env, "obtenerDigitoVerificador() espera un parametro de tipo string.");

  string rut_input = info[0].As<String> ();

  char *p_rut_input = const_cast<char *> (rut_input.c_str ());
  char get_checker_digit_function_res = mod11_get_checker_digit (p_rut_input);

  if (get_checker_digit_function_res == -1)
    throw Error::New (env, "obtenerDigitoVerificador(): Ocurrio un error al "
                           "intentar calcular el digito verificador del rut.");

  string digitCharToStr (1, get_checker_digit_function_res);
  String strDigit = String::New (env, digitCharToStr);
  return strDigit;
}

Value
FormatRut (const CallbackInfo &info)
{
  Env env = info.Env ();

  if (info.Length () == 0)
    throw Error::New (env, "darFormato() espera al menos 1 parametro.");

  if (!info[0].IsString ())
    throw TypeError::New (
        env, "darFormato() espera como primer parametro un string.");

  if (!info[1].IsBoolean ())
    throw TypeError::New (
        env, "darFormato() espera como parametro opcional un booleano.");

  string rut_input = info[0].As<String> ();
  bool dots_input = info[1].As<Boolean> ();
  string cppBuffer;

  char *p_rut_input = const_cast<char *> (rut_input.c_str ());
  char *p_cpp_buffer = const_cast<char *> (cppBuffer.c_str ());

  int format_rut_function_res = 0;

  if (dots_input == true)
    format_rut_function_res = mod11_format_rut (p_cpp_buffer, p_rut_input, 1);
  else
    format_rut_function_res = mod11_format_rut (p_cpp_buffer, p_rut_input, 0);

  if (format_rut_function_res == 0)
    throw Error::New (
        env, "darFormato(): Ocurrio un error al tratar de formatear el rut.");

  String formattedRut = String::New (env, p_cpp_buffer);

  return formattedRut;
}

Value
IsRutValid (const CallbackInfo &info)
{
  Env env = info.Env ();

  if (info.Length () == 0)
    throw Error::New (env, "validarRut() espera 1 parametro.");

  if (!info[0].IsString ())
    throw TypeError::New (env,
                          "validarRut() espera un parametro de tipo string.");
  string rutInput = info[0].As<String> ();

  char *p_rut_input = const_cast<char *> (rutInput.c_str ());

  int validate_rut_function_res = mod11_is_rut_valid (p_rut_input);

  if (validate_rut_function_res == -1)
    throw Error::New (
        env, "validarRut(): Ocurrio un error al tratar de validar el rut.");

  return validate_rut_function_res == 1 ? Boolean::New (env, true)
                                        : Boolean::New (env, false);
}

Object
Init (Env env, Object exports)
{
  exports.Set (String::New (env, "limpiarRut"), Function::New (env, CleanRut));
  exports.Set (String::New (env, "obtenerDigitoVerificador"),
               Function::New (env, GetCheckerDigit));
  exports.Set (String::New (env, "darFormato"),
               Function::New (env, FormatRut));
  exports.Set (String::New (env, "validarRut"),
               Function::New (env, IsRutValid));
  return exports;
}

NODE_API_MODULE (NODE_GYP_MODULE_NAME, Init)
