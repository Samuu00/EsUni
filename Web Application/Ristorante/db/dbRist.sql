CREATE TABLE public.Ristoranti(
    id bigint GENERATED ALWAYS AS IDENTITY NOT NULL,
    nome VARCHAR(255),
    numDip INT NOT NULL,
    CONSTRAINT pk_ristorante PRIMARY KEY (id)
);

CREATE TABLE public.Piatti(
    id bigint GENERATED ALWAYS AS IDENTITY NOT NULL,
    nome VARCHAR(255) NOT NULL UNIQUE,
    prezzo DECIMAL(10,2),
    CONSTRAINT pk_piatto PRIMARY KEY (id)
);

CREATE TABLE public.Ingredienti (
    id bigint GENERATED ALWAYS AS IDENTITY NOT NULL,
    nome VARCHAR(255) NOT NULL UNIQUE,
    CONSTRAINT pk_ingredienti PRIMARY KEY (id)
);

CREATE TABLE public.Menu (
    ristorante_id bigint NOT NULL,
    piatto_id bigint NOT NULL,
    CONSTRAINT fk_ristorante FOREIGN KEY (ristorante_id) REFERENCES public.Ristoranti(id),
    CONSTRAINT fk_piatto FOREIGN KEY (piatto_id) REFERENCES public.Piatti(id),
    CONSTRAINT pk_menu PRIMARY KEY (ristorante_id, piatto_id)
);

CREATE TABLE public.Ricette (
    piatto_id bigint NOT NULL,
    ingrediente_id bigint NOT NULL,
    CONSTRAINT fk_piatto FOREIGN KEY (piatto_id) REFERENCES public.Piatti(id),
    CONSTRAINT fk_ingrediente FOREIGN KEY (ingrediente_id) REFERENCES public.Ingredienti(id),
    CONSTRAINT pk_ricetta PRIMARY KEY (piatto_id, ingrediente_id)
);