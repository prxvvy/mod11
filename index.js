"use strict";
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
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
var bindings_1 = __importDefault(require("bindings"));
var addon = (0, bindings_1["default"])('rut_lib');
var limpiarRut = function (rut) {
    if (!rut)
        throw new Error('limpiarRut() espera un parametro.');
    if (typeof rut !== 'string')
        throw new TypeError('El rut debe ser de tipo string.');
    return addon.limpiarRut(rut);
};
var obtenerDigitoVerificador = function (rut) {
    if (!rut)
        throw new Error('obtenerDigitoVerificador() espera un parametro.');
    if (typeof rut !== 'string')
        throw new TypeError('El rut debe ser de tipo string.');
    return addon.obtenerDigitoVerificador(rut);
};
var darFormato = function (rut, puntos) {
    if (!rut)
        throw new Error('darFormato() espera un parametro.');
    if (typeof rut !== 'string')
        throw new TypeError('El rut debe ser de tipo string.');
    if (!puntos)
        return addon.darFormato(rut, false);
    if (puntos && typeof puntos !== 'boolean')
        throw new TypeError('darFormato() espera como segundo parametro un booleano.');
    return addon.darFormato(rut, true);
};
var validarRut = function (rut) {
    if (!rut)
        throw new Error('validarRut() espera un parametro.');
    if (typeof rut !== 'string')
        throw new TypeError('El rut debe ser de tipo string.');
    return addon.validarRut(rut);
};
module.exports = {
    limpiarRut: limpiarRut,
    obtenerDigitoVerificador: obtenerDigitoVerificador,
    darFormato: darFormato,
    validarRut: validarRut
};
