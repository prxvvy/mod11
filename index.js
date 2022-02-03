"use strict";
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
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
var bindings_1 = __importDefault(require("bindings"));
var addon = (0, bindings_1["default"])('rut_lib');
/**
 * @description Obtener el digito verificador de un rut.
 * @param {string} rut - El rut (con o sin digito) del cual se quiere saber su digito verificador.
 * @return {string} El digito verificador del rut.
 */
var obtenerDigitoVerificador = function (rut) {
    if (!rut)
        throw new Error('Se require un parametro.');
    if (typeof rut !== 'string')
        throw new TypeError('El rut debe ser un string.');
    return addon.obtenerDigitoVerificador(rut);
};
/**
 * @description Limpiar un rut de caracteres no numericos.
 * @param {string} rut - El rut que se quiere limpiar.
 * @return {string} El rut sin caracteres no numericos.
 */
var limpiarRut = function (rut) {
    if (!rut)
        throw new Error('Se require un parametro.');
    if (typeof rut !== 'string')
        throw new TypeError('El rut debe ser un string.');
    return addon.limpiarRut(rut);
};
/**
 * @description Dar formato a un rut. El tipico 12.345.678-9
 * @example
 * // 15576215-2
 * darFormato("55762152");
 * @example
 * // 15.57.6215-2
 * darFormato("15.576.215-2", puntos: true);
 * @example
 * // 15576215-2
 * darFormato("15576215");
 * @example
 * // 15.576.215-2
 * darFormato("15*576.215-", true);
 * @param {string} rut - El rut al que se le quiere dar formato.
 * @param {boolean|undefined} puntos - Si el formato deberia llevar puntos.
 * @return {string} El rut formateado.
 */
var darFormato = function (rut, puntos) {
    if (!rut)
        throw new Error('Se require un parametro.');
    if (!puntos)
        return addon.darFormato(rut, false);
    if (typeof rut !== 'string')
        throw new TypeError('El rut debe ser un string.');
    if (puntos && typeof puntos != 'boolean')
        throw new TypeError('Si se va a dar formato al rut con puntos, el segundo parametro debe ser un booleano.');
    return addon.darFormato(rut, true);
};
module.exports = {
    obtenerDigitoVerificador: obtenerDigitoVerificador,
    limpiarRut: limpiarRut,
    darFormato: darFormato
};
