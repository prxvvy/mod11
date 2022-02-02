# Modulo 11 (mod11)

Liberia para validar un rut (Chile) y más cosas para [Node.js](https://nodejs.org/en/).

---

###### _Tener en cuenta que este programa es gratis y está bajo la licencia GPL, cualquiera puede ver/modificar el codigo fuente si asi lo desea y además puede contribuir al programa._

## Instalacion

```
npm i mod11
```

**_La liberia, por ahora, cuenta con 3 funciones_**:

-   **_limpiarRut(rut)_** -> Limpia un rut pasado como argumento. Por limpiar, se refiere a, quitar caracteres no
    numericos.
-   **_obtenerDigitoVerificador(rut)_** -> Obtenga el dígito verificador de un rut pasado como argumento. No importa si ya
    se le pasa el dígito verificador, la function hara la tarea de cortar el rut con la cantidad de numeros necesaria para
    trabajar.
-   **_darFormato(rut)_** -> Con esta funcion podra darle formato a un rut.
    El formato default es "12345678-9".
    Si se le pasa el parametro OPCIONAL de `puntos` como `true`, dara como resultado el formato "12.345.678-9".

## Uso

Usar mod11 es facil.

```js
const mod11 = require('mod11'); // Simplemente requierelo en tu archivo .js de Node
```

Ahora...

Para limpiar un rut...

```js
console.log(mod11.limpiarRut('15,576.215-2')); // 155762152
```

Para obtener el digito verificador de un rut...

```js
console.log(mod11.obtenerDigitoVerificador('15.576.215')); // 2
```

O también

```js
console.log(mod11.obtenerDigitoVerificador('15576215')); // 2
```

Y claro, por supuesto...

```js
console.log(mod11.obtenerDigitoVerificador('15.576.215-2')); // 2
/**
 * Ya que solo tomara la cantidad de numeros necesaria sin el digito.
 */
```

Esta libreria aún está en desarrollo, pero las dos funciones disponibles, están para produccion, por asi decirlo.
Cualquier inconveniente con respecto a la liberia, hacer un issue en este repo.

## Licensing (Licencia)

`mod11` is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.
