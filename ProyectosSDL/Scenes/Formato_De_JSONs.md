Formato de los archivos de cargado/guardadoç

[] denota array
{}denota objeto

pj.json

	{
	"mainPj": {
    	"Texture": 0, // numero de la textura segun el ImageID
    	"h": 145.0, // alto del mainpj

    	// Array con los objetos del inventario del personaje 
    	// (de tenerlos) antes de iniciar el acto
    	"itemList": [
    		{"x":368, "y":122, "w":64, "h":64, "descripcion":"Esta es mi descripcion", "tag":"Este es mi tag", "Texture":0}, // datos de cada objeto
    		{...},
    		{...}
    		],

    	"w": 40.0, // ancho del mainpj
    	"x": 835.0, // posicion inicial x
    	"y": 460.0 // posicion inicial y
		}
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

SceneX.json // X = numero de la escena

	{
		// Array con los datos de los objetos "cogibles" por el jugador existentes en la escena
    	"ItemInventario":[
        	{"x":368,"y":122,"w":64,"h":64,"descripcion":"Esta es mi descripcion","tag":"Este es mi tag","Texture":0},
        	{"x":100,"y":544,"w":64,"h":64,"descripcion":"key","tag":"key","Texture":15},
        	{"x":668,"y":0,"w":64,"h":64,"descripcion":"adafsfdf","tag":"ffftag","Texture":14},
            {...},
            {...}

    	],

    	// Array con los datos de los objetos "abribles" con llaves existentes en la escena
    	"GODoors":[
			{"x":200,"y":500,"w":200,"h":300,"Texture":9,"tag":"key","scneNum":1},
            {...},
            {...}
    	],

    	// Array con los datos de los objetos colisionables existentes en la escena
    	"Collisions":[
    		{"x":0, "y": 0, "h": 0, "w": 0, "Texture": 0},
            {...},
            {...}
    	],

    	// Array con los datos de los objetos que conectan una escena con otra y permiten paso entre escenas
    	"GOTransiciones":[
			{"x":200,"y":500,"w":200,"h":300,"Texture":9,"tag":"key","scneNum":1},
            {...},
            {...}
    	]
	}
