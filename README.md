# Modulo 11 (mod11)

Liberia para validar un rut (Chile) y mas cosas.

---

###### _Tener en cuenta que este programa es gratis y esta bajo la licensia GPL, cualquiera puede ver/modificar el codigo fuente si asi lo desea y ademas puede contribuir al programa._

## Instalacion

```
npm i mod11
```

**_La liberia, por ahora, cuenta con 3 funciones_**:

* ***limpiarRut(rut)*** -> Limpia un rut pasado como argumento. Por limpiar, se refiere a, quitar carecteres no
  numericos.
* ***obtenerDigitoVerificador(rut)*** -> Obtenga el digito verificador de un rut pasado como argumento. No importa si ya
  se le pasa el digito verificador, la funcion hara la tarea de cortar el rut con la cantidad de numeros necesaria para
  trabajar.
* ***validar(rut)*** -> Valide un rut. No importa si ya se le pasa el digito verificador, la funcion hara la tarea de
  cortar el rut con la cantidad de numeros necesaria para trabajar.