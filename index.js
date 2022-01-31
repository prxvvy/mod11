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
var obtenerDigitoVerificador = function (rut) {
    if (!rut)
        throw new Error('Se require un parametro.');
    if (typeof rut !== 'string')
        throw new TypeError('El rut debe ser un string.');
    return addon.obtenerDigitoVerificador(rut);
};
var limpiarRut = function (rut) {
    if (!rut)
        throw new Error('Se require un parametro.');
    if (typeof rut !== 'string')
        throw new TypeError('El rut debe ser un string.');
    return addon.limpiarRut(rut);
};
module.exports = {
    obtenerDigitoVerificador: obtenerDigitoVerificador,
    limpiarRut: limpiarRut
};
