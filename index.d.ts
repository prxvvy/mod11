declare namespace rut_lib {
	export function limpiarRut(rut: string): string;

	export function obtenerDigitoVerificador(rut: string): string;

	export function validar(rut: string): boolean;
}

export = rut_lib;
export as namespace rut_lib;
