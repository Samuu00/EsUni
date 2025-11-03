CREATE TABLE public.ristorante(
    id bigint GENERATED ALWAYS AS IDENTITY NOT NULL,
    nome VARCHAR(255),
    numDip INT NOT NULL,
    nome_piatto VARCHAR(255),
    CONSTRAINT pk_ristorante PRIMARY KEY (id)
    CONSTRAINT fk_piatto FOREIGN KEY (nome_piatto) REFERENCES piatto(nome)
);

CREATE TABLE public.ingredienti(
    id bigint GENERATED ALWAYS AS IDENTITY NOT NULL,
    nome VARCHAR(255),
    CONSTRAINT pk_ingredienti PRIMARY KEY (id)
);

CREATE TABLE public.piatto(
    id bigint GENERATED ALWAYS AS IDENTITY NOT NULL,
    nome VARCHAR(255),
    prezzo DECIMAL(10,2),
    ingredienti VARCHAR(255),
    CONSTRAINT pk_piatto PRIMARY KEY (id)
);
