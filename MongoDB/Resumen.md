# MONGO DB

# Indice

- Introduccion e Instalacción
- Lenguaje de Consultas de Datos
- Operadores de consultas

## Que es mongo DB

- **Sistema de Gestor de Base de Datos No SQL** que, significa que no utiliza el modelo de datos relacional, son orientadas a documentos en formato JSON.
  Utiliza JS como lenguge de consulta.

### Donde se almacenan los datos

Cada registro se almacenan en un documentos JSON (JavaScript Object Notation)
Estan compuestos por campos y los documentos se almacenan en colecciones (tablas),

### Esquemas dinamicos

Crean colecciones sin definir una estructura, esto permite crear diferentes estructuras dentro de la misma coleccion.

### Ventajas de Mongo DB

- Modelado Flexible en datos
- Alto rendimiento de escritura y consultas
- Alta escalabilidad
- Dispone de un servicio de gestion de cluster de BD
- Es el mas popular entre los No SQL

# Tipos de datos

- String
- int32
- double
- dates
- Object-Document
  - Permite agrupar varios campos, da igual el tipo de dato.
- Array
  - Tambein se pueden incluir Object-Document

La diferencia entre el Array y Object-Document es que en el array se enumeran.

- Sistemas de coordenadas Geoespaciales
  - No es un tipo de dato, en el Schema tiene un apartado del mapa.

## Vista Schema

Representa cada uno de los datos de la coleccion.

Cada campo se representa por:

- Un nombre
- Tipo de dato
- Un grafico con el rango de valores que ha encontrado sobre el campo
- La proporcion de los documentos que tiene ese campo

## Consultas en Mongo DB

Cada **_campo se compone_** de dos partes:

- **La clave**
- **Valor**

### Filtro de igualdad

Se separan la clave y valor con "**:**"

```Js
{'end station name' : 'Barrow St & Hudson St'}
```

- _end station name_, es el campo / Variable.
- _Barrow St & Hudson St_ es el contenido que queremos filtrar.

### Filtro de fecha

El formato es el mismo que el anterior, pero la diferencia es que en valor es anidado y tiene dos valores

```Js
    {'birth year' : {$gte: 1995, $lt: 1990} }
```

#### Operadores

- $gt
  - Valores mayor
- $gte
  - Valores mayores o igual
- $lt
  - Valores menores
- $lte
  - Valores menores o igual

## Que es un JSON

**_JSON(JavaScript Obtect Notation)_**
Ventajas:

- Facil de leer y editar para los humanos
- Facil de interpretar y generar para los ordenadores
  Se identifica con la extension **.json**

**Mongo DB es una BD orientada a documentos** \* son documentos JSON

### Ejemplo de Documento JSON

![](./ExemepleMongo.png)
Comienzan con una llave de apertura "{" y acaban con una llave de cierre "}"
Minimo tiene que contener un campo
cada campo esta compuesto por dos partes:

- Clave
  - la pondremos entre comillas ""
- Valor
  la clave y el valor se separan con :
  las comas , se usan para separar los campos

#### Valores de los campos

- Cadenas
- Entre "", los espacios y saltos de linea son los tiene en cuenta entre "".
- Array
  - []

**La pestaña representa los documentos de forma individual**
Hay dos vistas:

- Lista
- Json

## Como crear un Cluster

1.  Crear una cuenta en Atlas
    https://www.mongodb.com/cloud/atlas/register

2.  Crear un sandbox cluster
    - Elegimos Amazon
    - Cluster: El M0 Snadbox
    - Nombre a Cluster
      ![](./CreateCluster.png)
    - **6Pi3PE03WPFJhLc4**
3.  Configurar Nuestro Cluster

- Configuraciones:
  - Cambiamos el nombre del proyecto
    ![](./proyectName.png)
  - Permitir acceso desde cualquier IP
    ![](./permitirAccesoAtodasLasIp.png)
  - Crear Usuario y Contraseña
    ![](./createUserCluster.png)

4.  Conectar el cluster desde Compass

    - Seleccionamos Compass
      ![](./ConccinonCompas1.png)
    - **Pegaremos el siguiente codigo en nueva coneccion en Compass.**
      - mongodb+srv://usuario_rp:1234@joelvegasromerocluster.et1baiy.mongodb.net/
    - Connect desde Compass y Darle a Favorito Con un nombre

5.  Conectar el cluster desde la Shell
    - Seleccionamos Shell
      ![](./ConccinonCompas1.png)
    - En la consola insertamos los siguiente:
      - mongosh "mongodb+srv://joelvegasromerocluster.et1baiy.mongodb.net/" --apiVersion 1 --username <usuario_rp>

## Por que necesitamos crear nuestro propio cluster de BD

Ya que el de mongo db solo nos da el permiso unico de lectura y para ello queremos utilizar el cluster para realizar pruebas

# Videos por Ver 6-2-8

# Lenguage de Consultas

**CRUD**:

- **Create**
- **Read**
- **Update**
- **Delete**

## Crear Documentos

1.  Add Data
2.  Insert Document

### Atraves de Comando

#### insertOne()

- Sirve para inserta un solo documento en una coleccion

```mongodb
use nombre_BD
db.nombreColec.insertOne({
        campo1:"valor",
        campo2:"valor",
        ...
    }
)

```

**_db: es la base en uso_**
**_nombreColec: es el nombre de la coleccion donde añadiremos el documento_**
Si no proporcionamos el ID se genera solo y nos lo genera con el **ObjectID**,pero si lo proporcionamos nostros podemos poner el valor que queramos

\*\*Pueden haber dos colecciones iguales con los mismos campos y valores pero con ID diferente.

### Mostrar todos los Documentos

**db.nombreColec.find()**

#### insertMany()

- Sirve para inserta mas de un documento en una coleccion

```
use db
db.nombreColec,InsertMany(
    [
        {
            Documento1
            "campo":"Valor,
        },

        {
            Documento2
            "campo":"Valor
        },

        {
            Documento3
            "campo":"Valor
        },
    ]
)
```

Para indicar que la inserccion sea ordenada pondremos:

- **ordered: <boolean>**

Si no indicamos el use se creara en la tabla _text_
Si hay documentos duplicados, dara un error y no los insertara, ya que por defecto esta ordenada eso quiere decir que ira insertando en el orden que lo vamos ponien si encuentrar un error no inserta el resto.

### Insertar de forma desordenada

- "ordered": false
  - Indica que queremos insertar de forma **No ordenada**, nos interesa cuando queremos insertar todo lo posible aunque hayan campos duplicadso esto quiere decir que aunque hayan duplicados insertara el resto sin parar.

```
use db
db.nombreColec,InsertMany(
    [
        {
            Documento1
            "campo":"Valor,
        },

        {
            Documento2
            "campo":"Valor
        },

        {
            Documento3
            "campo":"Valor
        },
    ],
    {
        "ordered": false
    }
)
```

## Importar Datos en MongoDB

### Importar Ficheros en Studio 3T

1.  Clic en el icono Import
2.  JSON,ok
3.  Si estamos desconectados en Target Conection le damos clic para conectarnos
    - Eligiremos nuestro Cluster de DB
4.  "+" Elegimos el archivo del formato JSON
5.  En el apartado de Targe DataBase pondremos el nombre de la base de datos deonde que queramos insertar los datos
    - Target Collection, pondremos el nombre de la coleccion
    - Insertation Mode, modo de inserccion(comportamiento a la hora de la inserccion) eligiremos _Drop Collection first..._ esto sirve para eliminar la coleccion si es existente.
6.  Execute
    El archivo JSON tiene que tener un standar, el cual es [ de aperturra y ] y uno de cerrada cada {} es un documento y cada documento tiene que estar separado por una coma

### Importar Documentos en Robo 3T

1.  Conectarnos al Cluster de DB en el que queremos importar los datos
2.  Clicaremos en la DB Donde queremos insertar los Datos
    - Clic derecho
      - Crea nueva coleccion
3.  Una vez creada entraremos
4.  Clic Derecho sobre ella
    - Insertar Documento
    - Pegaremos el contenido del codigo y sin separacion de comas
5.  Validate
6.  Save
7.  Y se empezara a ejecutar, e ira insertando los documentos 1 a 1

No es la mejor herramienta para insertar grandes cantidades de datos.

### Importar Documentos desde la SHELL

1. Coneccion A cluster de Atlas
   - Conect to the mongo shell
   - pengamos el codigo en la shell para conectarnos
2. Nada mas podemos cargar los archivos desde un directorio de trabajo,para saber con que directorio estamos pwd()
3. El documento tiene que ser JS
   - le asigna a db el nombre de la DB
     - db.getSiblingDB
   - eliminar la coleccion en caso de que exista
     - movieDetails.drop()
   - inserta los documentos
     - movieDetails.insertmany([...])
4. Exit y Entramos en carpeta donde estan los archivos
5. Dir muestra todos los archivos del Directorio
6. Importamos el archivo
   - load("archivo.js")
   - si se a importado correctamente nos devolvera true
7. COmprobar que se ha insertado bien
   - show dbs
   - use nombredb
   - db.coleccion.count() nos devuelve el numero de documentos que hay en la coleccion
     - .pretty muestra el contenido de los documentos

## Consultas de Lectura find()

Mostra datos en el que el año sea 2017

```js
{
  year: 2017;
}
```

Mostra los datos en el que el año sea 2017 y el genero sea Action

```js
{year:  2017,genere:'Action'}
```

Por defecto en los selectro se agrupa la logica AND

#### Shell

Mostra los datos en el que el año sea 2017 y el genero sea Action

```js
db.nombreColeccion.find({ year: 2017, genere: "Action" }).pretty();
```

#### Uso de comillas

- title:"Dogs", no da error por que es una el atributo title es una palabra pero cuando sean dos da error, por eso debemos utilizar las comillas.
- Cuando pongamos un entero entre "", como por ejemplo "1245" buscara un tipo String en vez de Int ya que tiene las comillas.

### Busqueda de para tipos documentos

```js
{"nombreCampo.nombrevariable" : "C"}
```

Solo apareceran los campos en la que en la variable x tengo Cç
el punto indica lo que viene despues ejemplo nombre = [ edad = [] ] pues para entrar en la edad tendre que hacer nombre.edad

### Busqueda para tipos Vector

Mostrar el array que tengo x en cualquier posicion del array

```js
{'nombreArrar' : 'Contenido'}
```

Que contenga exactamente como indicamos

```js
{'cast' : ['contenido']}
o
{'cast' : ['contenido1','contenido2']}
```

Que lo contenga en una posicon inidicada

```js
{'cast.1' : 'contenido'}
```

Solo en la posicion 1.

### Cursores con el meetodo find()

Cuando ejecutamos el metodo find() nos devuelve un cursor(puntero), ha si hasta el maximo de Documentos

### Proyecciones

Si hacemos

```js
.find(
  {edad:{$gt:18}},
  {nombre:1,edad:1}
)
```

nombre:1,edad:1 si ponemos uno decimos que incluyan /muestren este campo si hubieramos puesto 0 es lo controraio.
En resumen solamente cogera los datos mas grandes de 18 años e incluira el nombre y la edad.

el .limit() limita la cantidad de documentos a mostrar

si no indicamos nada el ID se mostrar, para que no se muestre deberemos poner ID:0 .

## Operaciones de Actualizacion

Las operacions de actualizacion nos van a permitir modificar los documentos ya existente dentro de una coleccion,metodos:

### UpdateOne

_Modifica un Unico Documento_

```js
db.nombreColec.updateOne(filer, update, option);
```

Cuando el titulo sea the martian inserta un campo poster con una url.

```js
use joel
db.nombreColec.updateOne(
  {titel:"the martain"}//filter,
  {
    $set:
    {poster:"url"}
  }//update
)
```

Si existe un campo poster en la coleccion donde el titulo es the martian, modificaria el campo poster y agregaria el nuevo y si no existe lo crea. Si hay dos colecciones con el nombre de The martian solo se modificara el primero.

\*Para vectores

```js
use joel
db.nombreColec.updateOne(
  {titel:"the martain"}//filter,
  {
    $set:
    {posters:["url1","url2","url3"]}
  }//update
)
```

### UpdateMany

_Modifica mas de un Documento_

```js
.updateMany(filer,update,option)
```

### ReplaceOne

_Remplaza un Unico Documento dentro de una coleccion_

```js
.replaceOne(filer,update,option)
```

_Filter especifica los documentos a actualizar_
_Update especifica que vamos a modificar,tendremos que aplicar algun operador_

## Operadores

### Operadores tipo Campo(fields)

- $set --> establece un valor para los campos de un documneto
- $unset --> Elimina los campos que le especifiquemos de un documento
- $rename --> Modifica el nombre de un campo
- $mul --> Multiplica el valor de un campo por el valor que le especifiquemos
- $min --> Modifica el campo siempre y cuando el valor que le especificamos es menor al valor actual.
- $max --> Lo contrario al min
- $currentDate --> modifica con la fecha actual el campo especificado
- $inc --> Incrementa el valor tantas veces que especiquemos

#### Ejemplos

_Eliminar un campo_

```js
db.nombreColec.updateOne(
  { title: "nombre Pel" },
  { $unset: { year: 00 } } //da igual si ponemos cero o cualquier cosa lo va a eliminar igual
);
```

_Cambiar nombre del campo_

```js
db.nombreColec.updateOne(
  { title: "nombre Pel" },
  { $rename: { year: "año" } } //da igual si ponemos cero o cualquier cosa lo va a eliminar igual
);
```

_Actualiza el campo siempre y cuando que especifacamos es mayor al actual_

```js
db.nombreColec.updateOne({ title: "nombre Pel" }, { $max: { year: 2000 } });
```

_Actualiza el campo siempre y cuando que especifacamos es menor al actual_

```js
db.nombreColec.updateOne({ title: "nombre Pel" }, { $max: { min: 1994 } });
```

_Augmenta el campo indicado_

```js
db.nombreColec.updateOne(
  { title: "nombre Pel" },
  { $inc: { reviews: 3 } } //aumenta el resultado a + 3
);
```

Si ponemos el - decrementa

_Decremta el campo indicado_

```js
db.nombreColec.updateOne(
  { title: "nombre Pel" },
  { $inc: { reviews: -3 } } //decrementa el resultado a - 3
);
```

### Operadore tipo Vectores

- $addToSet --> Añade elementos a un vector solo si el valor no existe todavia
- $pop --> Elimina el primer o ultimo elemento de un vector
- $pull --> Elemina todos los elementos de un vector que coinciden con la consulta
- $pullAll --> Elimina todos los valores que coinciden con un Vector
- $push --> Añade elementos a un vector

#### Ejemplos

_Actualizamos el campo si no existe_

```js
db.nombreColec.updateOne(
  { title: "nombre Pel" },
  {
    $addToSet: {
      actors: "nombre Actor",
    },
  } //decrementa el resultado a - 3
);
```

_añadir un elemento al vecto_

```js
db.nombreColec.updateOne(
  { title: "nombre Pel" },
  {
    $push: {
      reviews: {
        rating: 2.4,
        text: "",
      },
    },
  } //decrementa el resultado a - 3
);
```

_Eliminar el primer o ultimo elemento del vector_
Para eliminar el primer elemento del vector pondremos -1
Para eliminar el ultimo elemento pondremos 1

```js
db.nombreColec.updateOne(
  { title: "nombre Pel" },
  {
    $pop: {
      actors: -1, //Eliminamos el primer elemento del vector
    },
  }
);
```

```js
db.nombreColec.updateOne(
  { title: "nombre Pel" },
  {
    $pop: {
      actors: 1, //Eliminamos el ultimo elemento del vector
    },
  }
);
```

_Elimina todos los elementos que coincidan con la consulta(valor indicado en el update)_

```js
db.nombreColec.updateOne(
  { title: "nombre Pel" },
  {
    $pull: {
      actors: 3, //Eliminamos los elementos que contenga de valor 3
    },
  }
);
```

_Eliminamos todos los elementos mayor o igual($gte) al valor indicado._

```js
db.nombreColec.updateOne(
  { title: "nombre Pel" },
  {
    $pull: {
      actors: { $gte: 3 }, //Eliminamos los elementos que tenga el elemento 3 o mayor
    },
  }
);
```

_Elimina los campos con el valor indicado_

```js
db.nombreColec.updateOne(
  { title: "nombre Pel" },
  {
    $pullAll: {
      actors: [0, 5], //Eliminamos los elementos que tenga el elemento 0 o 5
    },
  }
);
```

#### Difenrencia entre push vs set

con $set solamente modificamos lo que tenemos y no añadimos ningun elemento.

#### Diferencia entre pull vs pullAll

en el pull busca los campo indicados si ponemos coma se piensa que forma parte de un numero decimal, en cambio en pullAll cuando ponemos comas decimos "este , y este".

### Modificadores

Operadores que podemos utilizar con los operadores de Vector

- $each --> modificamos el comportamiento de $push o $addToSet
- $position --> modificamos el comportamiento de $push
- $slice --> modificamos el comportamiento de $push
- $sort --> modificamos el comportamiento de $push

#### Ejemplos

_posibilidad de agregar mas de un elemento_

```js
db.nombreColec.updateOne(
  { title: "nombre Pel" },
  {
    $push: {
      actors:{
        $each[{ //nos permite Insertar varios documentos dentro de un Vector
            nombre:"joel",
            apellido:"vegas"
          },
          {
            edad: 20,
            estudio: "Daw"
          }
        ]
      }
    },
  }
);
```

_Indica en que posicion del Vector podemos insertar el nuevo elemento_
Siempre y cuando usamos el $position tenemos que usar siempre el $each

```js
db.nombreColec.updateOne(
  { title: "nombre Pel" },
  {
    $push: {
      actors:{
        $each[7], //Inserta un 7
        $position:2 //en la posicion 2 del Vector 0,1,2
      }
    },
  }
);
```

### UpdateMany

_Se usa en tareas de limpieza de datos_

```js
db.nombreColec.updateMany(
  {rated: null},
  {$unset:
    rated: "" //si esta en null los eliminamos
  } //eliminamos los campos que indicamos
)
```

_mostramos todos los campos que no tiene el campo rated_

```js
db.nombreColec.find({ rated: { $exists: false } });
```

## UPSERTS (UPdate +inSERT)

Operaciones que insertan documentos
el parametro que se inserta es boolean
Si es true:

- Si no encuentra el documento lo crea y si lo encuentra los modifica.
  por defecto viene en false

```js
db.nombreColec.updateMany(
  { id: "tt012343" },
  {
    $set: {
      title: "nombrePeli",
      year: 2004,
      director: "quentin tarantino",
    },
  },
  { update: true } //Si el documento con el id tt123454 modificara sus datos para insertar esto y si no lo enceuntra lo creara.
);
```

_viene bien cuando queremos insertar documentos y no sabemos si existe o no para insertarlo_

## ReplaceOne reemplazar un Documento

Remplaza un documento dentro de una coleccion

```js
db.colecction.replaceOne(filter, replacement, options);
```

Tambien incluye la opcion upsert.
replacement: no puede contener operadores de actulizacion, ya que lo que hacemos es reemplazar documentos.

### Ejemplo

```js
db.colection.replaceOne(
  {"title":"nombre Actual"},//es un campo del documento a reemplazar
  {"documento nuevo"}//los datos del nuevo del docuemento manteniendo el ID
)
```

El Identificador sera el mismo, ya que solamente lo reemplazamos.

### Ejemplo

```js
//Let es una variable
let filter = {title:"titulo actual"}

let doc = {"Documento nuevo"}

db.colection.replaceOne(filter,doc); //En vez de escribir todo hay lo escribimos en las variables.
```

Dentro de una variable podemos almacenar el resultado de una consulta, ya que lo que devuelve el resultado es un documento

```js
let peli = db.colection.find("title":"nombrePeli");

//Ver el contenido de una variable
peli
```

### updateOne vs replaceOne

updateOne si o si utiliza un operador, no reemplaza el documento solo añade o modifica pero no elimina campos que no le añamos indicado.

## Eliminar Documentos

deleteOne elimina un documento
deleteMany elimina varios documentos

```js
db.colection.deleteone;
{
  filter; //que documento tiene que coincidir para eliminar
}
```

```js
db.colection.deleteOne({ _id: "tt12343s" }); //elimina la coleccion que tenga ese id
```

```js
db.colection.deleteMany({ director: "nombreDirector" }); //elimina todos los documnetos que concuerden con el nombre directores.
```

podemos utilizar los operadore

```js
db.colection.deleteOne({ year: { $gt: 2000 } }); //elimina una coleccion la cual sea mas grande que el año 2000
//tambien funciona con el many
```

## Cargar un fichero desde la consola

1.  nos conectamos al cluster
2.  tener el archivo guardado en el mismo direcotorio de donde ejecutamos mongoDB
3.  insertaremos el siguiente comandos

```bash
mongo "mongodb+srv://cluster0-2wsc8.mongodb.net/test" --joel m001-student nombreArchivo.js
```

## Operadores de comparacion

Hay dos grupos.

Relacionales:

- $eq --> = --> Igual que
- $ne --> <> --> Distinto que
- $gt --> > --> Mayor que
- $gte --> >= --> Mayor o Igual que
- $lt --> < --> Menor que
- $lte --> Menor o igual que

Pertenencia de Conjunto:

- $in --> IN --> Pertenece
- $nin --> NOT IN--> no pertenece

### Ejemplos

```js
//IGUAL QUE
db.colection.find({ title: { $eq: "nombreTitulos" } });
// Muy parecido a no poner nada, es una equivalencia a title: "nombreTitulo"

//DISTINTO QUE
db.colection.find({ rated: { $ne: "UNRATED" } }); //UNRATED no calificada
// mostrara todos aquellas que no tenga el texto de UNRATED el NULL si que lo mustra

//MAYOR QUE
db.colection.find({runtime: {$gt: 90},{_id:0,title:1,runtime:1}});
//muestra todas la peliculas la cual su runtime es mayor que 90

//},{_id:0,title:1,runtime:1} --> significa que muestre los campo title y runtime y que no muestre el campo de id

//MAYOR Y MENOR QUE
db.colection.find({runtime: {$gt: 90,$lt: 120},{_id:0,title:1,runtime:1}});
//{$gt: 90,$lt: 120} --> Muestra las que son mayor a 90 y menor a 120

//MAYOR IGUAL Y MENOR IGUAL QUE
db.colection.find({runtime: {$gte: 90,$lte: 120},{_id:0,title:1,runtime:1}});
// {$gte: 90,$lte: 120} --> Muestran aquellas mayor o igual a 90 y menor o igual a 120

// Comparacion en dos campos diferentes
db.colection.find({runtime: {$gte: 90},"tomato.meter":{$gte:95},{_id:0,title:1,runtime:1,"tomato.meter":1}});
// Mostrara todos aquellso que el runtime sea mayor o igual a 90 y que el campo tomato.meter sea mayor igual a 95

//OPERADORES DE PERTENECIA
//se pasa un vector de vectores para indicar los valores coincidentes
db.colection.find({rated: {$in: ['G','PG']}});
//Muestra todas aquellas peliculas que tiene G o PG en el campo rated.

db.colection.find({rated: {$in: ['G','PG']}});
// Muestra todas aquellas que no tiene G o PG en el campo rated.
```
## Operadores de elementos
Mongo db usa un equema flexible, eso significa que no hace falta que tengan los mismo campos
* $exists, muestra todos aquellos documentos que tengan o no aquellos campos especificados.
* $type, permite tener mismo campos pero con diferentes tipos para ello podemos utilizar este operador, nos delvolvera aquellos campos con un determinado tipo pero con el tipo de dato especificado. 

### $exist Ejemplo
```js
// EXIST
db.colection.find({poster: {$exist: true}})
//Nos delvovera todos aquellos documentos que tiene ese campo y ademas los que tienen true 

// NO EXIST
db.colection.find({poster: {$exist: false}})
// Nos delvolver todos aquellos documentos que no tengan este campo solo los que no existen

db.colection.find({poster: null})
//Mostrara aquellos en los que no exista y los que tenga null
```
### $type Ejemplo
el tipo debera estar entre '' 
```js
db.colection.find({videorating: {$type:'int'}})
//Mostrar los campo de videorating que tenga el campo tipo int
```
## Operadores Logicos
* $and, devueve los documentos que cumplan todas las condiciones
* $not, cambia el efecto de un operador de consulta
* $nor, devuelve los documento que no cumplan con ninguna de las condiciones 
* $or, devuelve los documentos que almenos cumplan una de las condiciones 

### Ejemplos
```js
//OR
db.colection.find({$or:[{'director':'joel'},{'director':'miguel'}]}) // Siempre hay que poner [{condicion1},{condicion2}]
// Mostrara todos los documentos que tenga en el campo con joel o miguel.
 db.colection.find({$or:[{'director':'joel'},{'runtime':{$gt:300}}]}) // que se llame joel o runtime sea mayor a 300

//AND
db.colection.find({$and:[{'director':'joel'},{'director':'miguel'}]}) 
//Mostrara todos los documentos que contengan al director joel y miguel

//NOT
db.colection.find({$not:[{'director':'joel'},{'director':'miguel'}]})
//Me devolvera todas aquellos documentos que no tenga ni a Joel ni a Miguel
```

## Operadores de Vectores
* $all, muestra los campos que tiene el tipo vector con todos los valores que especificamos.
* $elemMatch, mostrar los campos que coincida tal cual con lo q le especificamos
* $size, mostrar todos aquellos campos que sean del tamaño indicado

### Ejemplos
```js
//$all
db.colection.find({countries: {$all: ['USA','spain']}})
//Mostrara todos los vectores que tengan USA y spain, si o si tienen que estar lo que se mencionan el orden da igual

//$size
db.colection.find({countries: {$size:2}})
// muestra todos los vectores que tengan el tamaño de 2/ tengan 2 elementos

//$elemMatch
db.colection.find({boxoffice: {$elemMatch: {"pais":"españa","ingreso":20}}})
//Mostrara el vector en el cual en el mismo elemento tenga a españa y un ingreso mas grande a 20

```
### elemMatch vs find
el find busca en todo el vector pero si dentro de otra posicion encuentra el resultado lo devolvera y no queremos eso, lo que queremos es que dentro del mismo elemento esten los campos especificados. Por ejemplo si ponemos el ejemplo de elemMatch con solamente find a lo mejor nos muestra que en un elemento tenemos un ingreso mas grade a 20 pero el pais es portugal y otro elemento con españa pero ingreso de 10 eso esa es la diferencia entre find y elemMatch.

## Operador de evaluacio  
* $regex

Es keySensitive, hay diferencia entre mayus y minus, si no ponemos ^ buscara en la frase y significa que no empezara por el que indicamos, puede empezar por cualquier otra cosa pero que contenga ese texto. 
```js
db.colection.find({"award.txt":{$regex: /^Won.*/}})
// / --> Dilimitamos que es una expresion regular
// ^ --> Significa que tiene q comenzar desde el principio
// Won son el contenido del elemento y significa que empiece por Won y lo q continua da igual
// . --> Comodin que cualquier caracter una vez
// * --> Comodin que cualquier caracter varias veces
// Mostra los elementos que empicen por Won 
```
