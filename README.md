# Shell simulador de archivo de sistemas

El presente programa simula un sistema de archivos sin hacer uso de las funciones del sistema operativo.
Por defecto se inicia en la ruta raíz `/`.

## Dependencias

Para poder compilar y ejecutar el siguiente proyecto, se requiere tener instalado `gcc`, `g++` y `make`.
Asi como tener incluido en el `$PATH` dichos comandos.
*IMPORTANTE!* Este proyecto solo puede ser compilado en Linux. Para compilar en windows, usar [`WSL`](https://learn.microsoft.com/en-us/windows/wsl/install).

Para instalar dichas dependencias se pueden usar los siguientes comandos basados en ciertas distros:

En Distros basados en Debian (Ubuntu/Lubuntu/ElementaryOS):

```sh
sudo apt install build-essential gbd
```

En Distros basados en Red Hat (CentOS, Fedora):

```sh
sudo yum install make gcc gcc-c++ kernel-devel
```

En Distros basados en Arch (Manjaro, Arch Linux, SteamOS):

```sh
sudo pacman -Syu base-devel
```

## Contenido del Programa

Los comandos que van a estar disponibles son los siguientes

- mkdir
- cd
- ls
- rm
- cp
- mv
- touch
- ln

Asi mismo, cada comando tendrá disponible algunas banderas.

## mkdir (Hacer directorio)

Parámetro obligatorio: el nombre de la carpeta

### Banderas disponibles

- `directory`: Nombre del directorio, si `-p` no se especifica, solo se acepta el nombre de la carpeta
- `-p, --parents`: Hacer directorios conforme lo requerido, ej: una/ruta/profunda
- `-v, --verbose`: Imprimir cada directorio creado

## cd (Cambiar directorio)

Para moverse en el sistema de archivos.
`dir` no es obligatorio. Si `cd` se invoca sin parámetros, se dirige a `~` (Home).

- `dir`: Entra a `dir`. Falla si `dir` no existe o no es una carpeta.
- `/ruta/absoluta`: Entra a la `/ruta/absoluta`. Dicha ruta debe de existir y ser carpeta.
- `./ruta/relativa`: Entra a la `./ruta/relativa` empezando desde donde se invoco el comando.
- `..`: Regresa a la carpeta anterior, si se encuentra en `/`, no hace nada.
- `/`: Regresa a la raíz del sistema de archivo.

## ls (Listar directorio)

Muestra carpetas, archivos y links simbólicos en el presente directorio o en el directorio especificado.

- `-a, --all`: Muestra todo en el directorio.
- `-A, --almost-all`: No muestra archivos que inician en `.` ni muestra `.` y `..`.
- `-l`: Usa formato largo, mostrando todas las propiedades del archivo
- `-t`: Ordenar por tiempo. Recién creados primero
- `-r`: Usar orden inverso al especificado
- `[ruta]`: Si se especifica, ruta de donde se quiera listar archivos

## rm (Elimina fichero)

Elimina ficheros.
Obligatorio especificar archivo o directorio.

- `-r, --recursive`: Si se especifica un directorio, elimina el directorio y su contenido.
- `-f, --force`: Ignora archivos/directorios no existentes. No hacer prompt. Sobrescribe `-i` y `-I`
- `-d, --dir`: Elimina solo carpetas vacías

## cp (Copiar archivos)

Copia un archivo en `origen` hacia `destino`.
Tanto `origen` como `destino` son obligatorios. Pueden ser rutas absolutas o relativas.

- `-f, --force`: Si el destino existe, sobrescribir.
- `-r, --recursive`: Copia de forma recursiva de `origen` a `destino`

## mv (Mover archivos)

Mueve un archivo en `origen` hacia `destino`.
Tanto `origen` como `destino` son obligatorios. Pueden ser rutas absolutas o relativas.

- `-f, --force`: Si el destino existe, sobrescribir.
- `-r, --recursive`: Mueve de forma recursiva de `origen` a `destino`.

## touch (Crear archivos)

Crea un nuevo archivo.
Obligatorio el nombre del archivo

- `-z, --size`: Tamaño (en bytes) del archivo a crear
- `-f, --force`: Si el destino existe, sobrescribir

## ln (Crear links simbólicos)

Genera un enlace simbólico de un archivo/carpeta a otro.
Obligatorio el modo, el `origen` y el `destino` del link simbólico

- `-s, --symbolic`: Genera un link simbólico
- `-f, --force`: Si el archivo ya existe, sobrescribir
- `-d, --directory`: Genera un "hard" link entre carpetas (Trata el destino como si se monto en esa ubicación)
