# Modulo 11 (mod11)

[![Version](https://img.shields.io/npm/v/mod11?color=red&logo=npm)](https://www.npmjs.com/package/mod11)
[![Downloads](https://img.shields.io/npm/dw/mod11?logo=npm)](https://www.npmjs.com/package/mod11)
[![Activity](https://img.shields.io/github/last-commit/prxvvy/mod11?color=blue&logo=github)](https://github.com/prxvvy/mod11)
[![Github](https://img.shields.io/github/package-json/v/prxvvy/mod11?color=yellow&label=github&logo=github)](https://github.com/prxvvy/mod11)
[![License](https://img.shields.io/github/license/prxvvy/mod11?color=brown&logo=GNU)](https://github.com/prxvvy/mod11/blob/master/COPYING)

Libreria para validar un rut (Chile) para [Node.js](https://nodejs.org/en/).

---

## Instalacion

```
npm i mod11
```

## Uso

```js
const mod11 = require('mod11');
```

## Ejemplos

```js
const mod11 = require('mod11');
// import mod11 from 'mod11';

// Para limpiar un rut.

mod11.limpiarRut('15,576.215-2'); // 155762152
mod11.limpiarRut('15.576.215-2'); // 155762152
mod11.limpiarRut('15576.215-2'); // 155762152
mod11.limpiarRut('15*576*215/2'); // 155762152

// Para obtener el digito verificador de un rut.
// Puede proveer el rut de distintas maneras como a usted le plazca.

mod11.obtenerDigitoVerificador('15.576.215'); // 2
mod11.obtenerDigitoVerificador('15.576.215-2'); // 2

// Para darle formato a un rut.
// Puede proveer el rut de distintas maneras como a usted le plazca.
// Si no se le incluye el digito verificador, la funcion lo agregara por usted.

mod11.darFormato('15.576.215-2'); // 15576215-2
mod11.darFormato('15.576*215'); // 15576215-2
mod11.darFormato('15.576.215-2', true); // 15.576.215-2
mod11.darFormato('15.576.215', true); // 15.576.215-2

// Para validar si un rut es correcto o no.
// Por temas de precision, es recomendable que a esta funcion si se le pase un rut completo, osease, con digito verificador. Da igual si se le pasa con puntos o guion.

mod11.validarRut('15.576.215-2'); // true
mod11.validarRut('15.576.2152'); // true
mod11.validarRut('15.576.215-4'); // false
mod11.validarRut('155762154'); // false
```

## Licensing (Licencia)

`mod11` is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.
