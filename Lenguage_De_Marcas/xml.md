# XML

(eXtensible Markup Language)
Es un **metalenguatge** --> llenguatge per definir altre llenguatges de **marques**
S'utilitza per crear **vocabularis especifics**

- AutoDescriptiu
- S'utilitza molt en l'intercanvi de dades entre aplicacions i sistemes.

## Regles

1.  Element arrels unic.

```xml
<!--Ejemplo de que estaria Mal-->
<libros>
    <libros> </libros>
</libros>
```

2.  Etiquetas Tancades correctamente

```xml
<!--Ejemplo correcto-->
<libros> </libros>
```

3.  Etiquetes ben imbricades

```xml
<!--Ejemplo Incorecto-->
<autor>
    <nom>
</autor>
    </nom>

<!--Ejemplo Correcto-->
<autor>
    <nom>
    </nom>
</autor>
```

4.  Atributs entre cometes

```xml
<libro any="2004">
```

## Como validar si XML esta bien formado

- Visual Studio
- Altova XMLSpy
- Eines Online: xmlvalidation.com

## Exemples de vocabularis XML

Els vacabularis es defineixen utilitzant XML per diferents proposits (segons la aplicacio)

- SVG (Scacalable Vector Graphics) --> grafics vecotrials 2D
- XSD (XML Schema Definition) --> per Validar estructures XML
- DOCX --> documents WORD basat en XML

# XSD (XML Schema Defintion)

Llenguage basat en XML, defeniex l'estructura, el contigut i les restriccions d'un XML.
Amb el document XSD pots especificar:

- Elements obligatoris
- Quins atributs poden apareixer
- Tipus de Dades
- Jerarquia d'elements

## XSD Vs DTD(Document Type Definition)

XSD permet tipus de variables avançats i esta escrit amb la sintaxis de XML, XSD permet que els Documents XML compleixin les regles especifiques (contigut i estructura)

# Diferencies entre ben format vs Valid

- Ben Format --> compleix la sintaxis XML
- Valid --> a mes, compleix un esquema XSD

# XPath (XML Path Language)

Llenguatge que permet navegar i localitzar parts dins dun XML _mitjançant expresion de cami_

- Molt utilitzat per accedir a elements atributs i contingut

XPath pot treballar amb estructures jerarquiques i fer consultes especifiques sobre:

- Posicio
- Valor
- Relacions del nodes

## Funcio de XPath

Accedir a nodes dins d'un XML

## Sintaxis XPath

- / --> Arrel
- // --> Qualsevol lloc del document
- @ --> Atribut

### Exemples de Consultes

- /llibres/libro/tiol:
  - Retorna.
    - 1984
    - El Joc d'Ender
    - El nom del Vent
- //autor
  - Retorna:
    - George Orwell
    - Orson Scott Card
    - Patrick Rothfuss
- //Llibre[any>2000]/titol
  - Retorna:
    - El nom del Vent

# XQuery

Llenguatge de consulta funcional creat per interrogar i tranformar dades XML.
Utiliza la sintaxis de XPath, pero ofereix mes potencia:

- incloent estructures de constrol
- condicions
- assignacions de variables
- capacitat de generar nous documents XML com a resultat

S'utiliza en:

- Sistemes de gestio de dades
- Aplicacions Web
- Eines de transformacio massiva

## Funcion XQuery

Realitzar consultes XML mes avançades que XPath.

# Estructura XQuery

```py
for $x in ...
// Itera sobre una colecio de nodes. Cada Element es guarda en $X

let $X :=
// Assigna uan expressio a una variable

Where
// Filtra els resultats obtinguts segons una condicio

order by ...
//Ordena el resultats

return  ...
// Indica que ha de retorna per a cada interacio o coincidecia

if ... then ... else
//Condicional per controlar lestructura dels resultats

```

## Exemple XQuery

```py
for $x in doc("llibres.xml")//llibre
where $x/any > 2000
return $x/titol

//Resultat
<titol> El nom del vento </titol>
```

# Com Vincular un document XML amb un Fitxer XSD

```py
<persona xmlns:xsi = "http://www.w3.org/2001/XMLSchema-instance" xsi:noNamespaceSchemaLocation="esquema.xsd">

    <nom>Unai</nom>
    <edat>30</edat>
</persona>
```

# XSLT (Extensible Stylesheet Language Transformations)

Llenguatge per transformar documents XML en HTML/text pla o nous documents XML.

Molt util quan es vol mostrar el contigut XML de forma mes visual o es vol migrar informacio a altres estructures de dades.

## Com funcion XSLT

mitjançant plantilles que indiquen com processar i mostrar diferents parts del document.

## Com es fa la transformacio

a traves de regles(plantilles) --> es defineixen dins d'un document XSL.
Es pot aplicar al XML mitjançant procesadors XSLT

## Proces de transformar XML en HTML

1.  Crear el document XML --> defineix informacio estructurada
2.  Crear l'estil XSLT --> plantilles de transformacio
3.  Enllaçar XML amb XSLT --> mitjançant una instruccio: <?xml-stylesheet?>
4.  Executar la transformacio amb Altova XMLSpy / BaseX o XSLTProcessor en Js

# Base X

Sistema de gestor de base de dades natiu per a XML,

- lleuger
- molt eficient
  Dissenyat per emmagatzemar gestionar i consultar grans quantitats de dades XML

## Caracteristiques

- Suporta XPath i XQuery
- Optimizat per grans volums de dades
- Interficie i linia de comandes

# Altova XMLSpy

eina de desenvolupament(IDE) especialitzada per treballar amb XML i tecnologies relacionades.
Utilitzada tant sector educatiu como professional

## Funcions Altova XMLSpy

- Edicio visual i textual
- Validacio constra XSD
- Disseny de plantilles XSLT
- Execució de consultes XPath/XQuery
- Visualitzacio d'esquemes
